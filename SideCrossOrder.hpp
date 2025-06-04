#ifndef SIDE_CROSS_ORDER_HPP 
#define SIDE_CROSS_ORDER_HPP 
#include <vector>
#include <algorithm>
namespace Containers{
template <typename T = int>

class SideCrossOrder{

private:
    const std::vector<T>* data;           // Pointer to the original data
    std::vector<size_t> sorted_indices;   // Indices in ascending order
    size_t pos;                           // Current position in sorted_indices

public:

    /**
     * @brief Constructs a side cross order iterator from a vector.
     * @param vec The vector to iterate over.
     * @param start_pos The starting position in the sorted order (default is 0).
     */
    SideCrossOrder(const std::vector<T>& vec ,size_t start_pos = 0)
            : data(&vec), pos(start_pos) {
        std::vector<size_t> ascending(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {// Initialize indices for sorting
                ascending[i] = i;
        }
        std::sort(ascending.begin(), ascending.end(),
            [&vec](size_t a, size_t b) { return vec[a] < vec[b]; });// Sort indices based on the values in vec

        sorted_indices.clear();
        size_t left = 0;
        size_t right=0;
        if(vec.size()>0){ // If the vector is not empty, set right to the last index
            right = vec.size() - 1;
        }
        bool flip = true; // Start with the smallest element
        while (left <= right) {  // While there are elements to process
            if (flip) {
                sorted_indices.push_back(ascending[left]);// Add the smallest element
                ++left; // Move to the next smallest element
            } else {
                sorted_indices.push_back(ascending[right]);// Add the largest element
                --right; // Move to the next largest element
            }
            flip = !flip; // Alternate between smallest and largest
            
        }
    }
  
    /**
     * @brief Dereference operator.
     * @return Reference to the current element.
     */
    T& operator*() { return const_cast<T&>((*data)[sorted_indices[pos]]); }    
   
    /**
     * @brief Moves the iterator to the next element (side cross order).
     * @return Reference to this iterator.
     */
    SideCrossOrder& operator++() { ++pos; return *this; }

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const SideCrossOrder& other) const { return pos != other.pos; }
    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, false otherwise.
     */
    bool operator==(const SideCrossOrder& other) const { return pos == other.pos; }



};

}
#endif