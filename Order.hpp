#ifndef ORDER_HPP 
#define ORDER_HPP 
#include <vector>

namespace Containers{
template <typename T = int>

/**
 * @brief Iterator for a vector-like container.
 * @tparam T The type of elements stored in the container.
 */
class Order{

private:
   // std::vector<T> cont; //< Internal storage for elements
    typename std::vector<T>::iterator current;
public:
    /**
     * @brief Constructs an iterator from a vector iterator.
     * @param curr The iterator to start from (usually begin()).
     */
    Order(typename std::vector<T>::iterator curr) : current(curr) {}

    /**
     * @brief Dereference operator.
     * @return Reference to the current element.
     */
    T& operator*() { return *current; }

    /**
     * @brief Moves the iterator to the next element (forward direction).
     * @return Reference to this iterator.
     */
    Order& operator++() { ++current; return *this; }

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const Order& other) const { return current != other.current; }
    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, false otherwise.
     */
    bool operator==(const Order& other) const { return current == other.current; }




};

}
#endif