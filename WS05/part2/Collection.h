/*Name: Tanimul Islam
Email: tislam38@myseneca.ca
ID: 129414223
Section: ZAA
Date: 11802/2024
Module Name: Collection.h
********************************
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <string>

namespace seneca
{
    template <typename T>
    class Collection {
        std::string m_name;
        T* m_items;
        size_t m_size;
        void (*m_observer)(const Collection<T>&, const T&);

    public:
        Collection(const std::string& name) : m_name(name), m_items(nullptr), m_size(0), m_observer(nullptr) {}

        ~Collection() {
            if (m_items) {
                delete[] m_items;
                m_items = nullptr;
            }
        }

        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;

        const std::string& name() const {
            return m_name;
        }

        size_t size() const {
            return m_size;
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }

        Collection<T>& operator+=(const T& item) {
            bool _same = false;

            for (auto i = 0u; i < m_size; ++i) {
                if (m_items[i].title() == item.title())
                    _same = true;
            }

            if (!_same) {
                if (m_size == 0u) {
                    m_items = new T[++m_size];
                    m_items[0] = item;
                }
                else {
                    T* _temp = new T[m_size];

                    for (auto i = 0u; i < m_size; ++i)
                        _temp[i] = m_items[i];

                    delete[] m_items;
                    m_items = nullptr;

                    m_items = new T[++m_size];

                    for (auto i = 0u; i < m_size - 1u; ++i)
                        m_items[i] = _temp[i];

                    m_items[m_size - 1u] = item;

                    delete[] _temp;
                    _temp = nullptr;

                    if (m_observer)
                        m_observer(*this, item);
                }
            }

            return *this;
        }


        T& operator[](size_t idx) const {
            if (idx >= size()) {
                std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
                throw std::out_of_range(err);
            }

            return m_items[idx];
        }

        T* operator[](const std::string& title) const {
            bool _found{ false };
            size_t _idx{ 0u };

            for (auto i = 0u; i < m_size && !_found; ++i) {
                if (m_items[i].title() == title) {
                    _idx = i;
                    _found = true;
                }
            }

            if (!_found) { return nullptr; }

            return &m_items[_idx];
        }
    };
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
        for (auto i = 0u; i < src.size(); ++i)
            os << src[i];

        return os;
    }
}
#endif // !SENECA_COLLECTION_H
