//==============================================
// Name:           Tanimul Islam
// Student Number: 129414223
// Email:          tislam38@myseneca.ca
// Section:        ZAA
// Date:           March 22, 2024
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;
        for (size_t i = 0u; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    // Create a new Product object dynamically
                    Product* temp = new Product(desc[i].desc, price[j].price);
                    // Validate the product
                    try {
                        temp->validate();
                        priceList += temp;
                    }
                    catch (...) {
                        delete temp;
                        throw;
                    }
                    delete temp;
                    temp = nullptr;
                }
            }
        }

        return priceList;
    }

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i = 0u; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;
				}
			}
		}
		return priceList;
	}
}