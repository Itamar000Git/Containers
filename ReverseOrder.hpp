//itamarbabai98@gmail.com

#ifndef REVERSE_ORDER_HPP 
#define REVERSE_ORDER_HPP 
#include <vector>

namespace Containers{
template <typename T = int>

/**
 * @brief Reverse iterator for a vector-like container.
 * @tparam T The type of elements stored in the container.
 */
class ReverseOrder{

private:
  
    typename std::vector<T>::iterator current;
     typename std::vector<T>::iterator end_iter;
public:
    /**
     * @brief Constructs a reverse iterator from a vector iterator.
     * @param curr The iterator to start from (usually end()-1).
     */
    ReverseOrder(typename std::vector<T>::iterator curr ,typename std::vector<T>::iterator end ) : current(curr) ,end_iter(end){}

    /**
     * @brief Dereference operator.
     * @return Reference to the current element.
     */
    T& operator*() { 
        if (current == end_iter) {
        throw std::out_of_range("Dereferencing end iterator");
        }
        return *current;
     }

       /**
     * @brief Dereference operator (const version).
     * @return Const reference to the current element.
     */
    const T& operator*() const {
        if (current == end_iter) {
        throw std::out_of_range("Dereferencing end iterator");
        }
        return *current;
    }


   
    /**
     * @brief Moves the iterator to the previous element (reverse direction).
     * @return Reference to this iterator.
     */
    ReverseOrder& operator++() { --current; return *this; }

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const ReverseOrder& other) const { return current != other.current; }

    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, false otherwise.
     */
    bool operator==(const ReverseOrder& other) const { return current == other.current; }
     


   


};







}
#endif