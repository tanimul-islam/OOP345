/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 30/03/2024
Module Name: TreasureMap.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<thread>
#include<future>
#include<functional>
#include "TreasureMap.h"

namespace seneca {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                std::getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            // Open a binary file stream to the filename
            std::ofstream outFile(filename, std::ios::binary);

            if (outFile.is_open()) {
                try {
                    outFile.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
                    outFile.write(reinterpret_cast<const char*>(&colSize), sizeof(colSize));

                    for (size_t i = 0; i < rows; ++i) {
                        outFile << map[i];
                    }
                    outFile.close();
                }
                catch (...) {
                    outFile.close();
                    throw;
                }
            }
            else {
                throw std::string("Error: Unable to open file for writing " + std::string(filename));
            }
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        std::ifstream inFile(filename, std::ios::binary);

        if (inFile.is_open()) {
            try {
                // Read the number of rows from the file (first 4 bytes)
                inFile.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
                // Read the colSize for the map from the file(second 4 bytes)
                inFile.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));
                map = new std::string[rows];
                // Read each row of the map from the file
                for (size_t i = 0; i < rows; ++i) {
                    map[i].resize(colSize);
                    inFile.read(&map[i][0], colSize);
                }
                inFile.close();
            }
            catch (...) {
                inFile.close();
                delete[] map;
                map = nullptr;
                throw;
            }
        }
        else {
            throw std::runtime_error("Error: Unable to open file for reading: " + std::string(filename));
        }
    }


    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        //partition the data for threads
        size_t partitionSize = rows / 4; //for 4 threads
        std::vector<std::future<size_t>> futures;


        for (size_t i = 0; i < 4; ++i) {
            size_t start = i * partitionSize;
            size_t end = (i == 3) ? rows : (i + 1) * partitionSize;

            //use std::bind to bind a lambda function
            auto task = std::bind([this, mark, start, end]() {
                size_t localCount = 0;
                for (size_t j = start; j < end; ++j) {
                    localCount += digForTreasure(map[j], mark);
                }
                return localCount;
                });

            std::packaged_task<size_t()> packagedTask(task);
            futures.push_back(packagedTask.get_future());
            //start the task in a new thread
            std::thread(std::move(packagedTask)).detach();
        }

        //retrive result from future
        for (auto& future : futures) {
            count += future.get();
        }
        return count;
    }
}

   

