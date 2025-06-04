#ifndef ASCENDING_ORDER_HPP 
#define ASCENDING_ORDER_HPP 
#include <vector>
#include <algorithm>
namespace Containers{
template <typename T = int>

/**
 * @brief Iterator for a vector-like container in ascending order.
 * @tparam T The type of elements stored in the container.
 */
class AscendingOrder{

private:
    const std::vector<T>* data;           // Pointer to the original data
    std::vector<size_t> sorted_indices;   // Indices in ascending order
    size_t pos;                           // Current position in sorted_indices

public:
    /**
     * @brief Constructs an ascending and descending order iterator from a vector.
     * @param vec The vector to iterate over.
     * @param ascen True for ascending order, false for descending order.
     * @param start_pos The starting position in the sorted order (default is 0).
     */
    AscendingOrder(const std::vector<T>& vec, bool ascen, size_t start_pos = 0)
            : data(&vec), pos(start_pos) {
            sorted_indices.resize(vec.size());
            for (size_t i = 0; i < vec.size(); ++i) {
                sorted_indices[i] = i;
            }
            std::sort(
                sorted_indices.begin(),
                sorted_indices.end(),
                [&vec, ascen](size_t a, size_t b) {
                    return ascen ? (vec[a] < vec[b]) : (vec[a] > vec[b]);
                }
            );
        }
  
    /**
     * @brief Dereference operator.
     * @return Reference to the current element.
     */
    T& operator*() { return const_cast<T&>((*data)[sorted_indices[pos]]); }    
    /**
     * @brief Moves the iterator to the next element (ascending / descending order).
     * @return Reference to this iterator.
     */
    AscendingOrder& operator++() { ++pos; return *this; }

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const AscendingOrder& other) const { return pos != other.pos; }
    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, false otherwise.
     */
    bool operator==(const AscendingOrder& other) const { return pos == other.pos; }



};

}
#endif