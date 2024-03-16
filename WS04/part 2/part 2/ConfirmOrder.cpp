/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11/02/2024
Module Name: confirmOrder.cpp
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#include<iostream>
#include<string>
#include<algorithm>
#include"ConfirmOrder.h"

namespace seneca {

        ConfirmOrder::ConfirmOrder() : mToys(nullptr),mCount(0), mCapacity(0) {}

        ConfirmOrder::ConfirmOrder(const ConfirmOrder& src) : mToys(nullptr), mCapacity(0) {
            *this = src;
        }

        ConfirmOrder::ConfirmOrder(ConfirmOrder&& src) noexcept : mToys(nullptr), mCount(0), mCapacity(0) {
            *this = std::move(src);
        }

        ConfirmOrder::~ConfirmOrder() {
            delete[] mToys;
            mCapacity = 0;
            mCount = 0;
        }

        ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src) {
            if (this != &src) {
                mCapacity = src.mCapacity;
                mCount = src.mCount;
                delete[] mToys;
                mToys = new const Toy * [mCapacity];
                for (size_t i = 0; i < mCount; ++i) {
                    mToys[i] = new Toy(*(src.mToys[i])); // Deep copy each Toy
                }
            }
            return *this;
        }

        ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src) noexcept {
            if (this != &src) {
                mCapacity = src.mCapacity;
                mCount = src.mCount;
                delete[] mToys;
                mToys = src.mToys;
                src.mToys = nullptr;
                src.mCapacity = 0;
                src.mCount = 0;
            }
            return *this;
        }

        ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
            // Check if the toy already exists
            if (std::find(mToys, mToys + mCount, &toy) == mToys + mCount) {
                if (mCount == mCapacity) {
                    // Resize the array if necessary
                    resizeArray();
                }
                // Add the toy
                mToys[mCount++] = &toy;
            }
            return *this;
        }

        ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
            // Find and remove the toy
            auto it = std::find(mToys, mToys + mCount, &toy);
            if (it != mToys + mCount) {
                std::swap(*it, mToys[--mCount]);
            }
            return *this;
        }

        void ConfirmOrder::resizeArray() {
            size_t newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
            const Toy** temp = new const Toy * [newCapacity];
            std::copy(mToys, mToys + mCount, temp);
            delete[] mToys;
            mToys = temp;
            mCapacity = newCapacity;
        }

        std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirmOrder) {
            os << "--------------------------" << std::endl;
            os << "Confirmations to Send" << std::endl;
            os << "--------------------------" << std::endl;
            if (confirmOrder.mCount == 0) {
                os << "There are no confirmations to send!" << std::endl;
            }
            else {
                for (size_t i = 0; i < confirmOrder.mCount; ++i) {
                    if (confirmOrder.mToys[i] != nullptr)
                        os << *confirmOrder.mToys[i];
                }
                os << "--------------------------" << std::endl;
            }
            return os;
        }

}
