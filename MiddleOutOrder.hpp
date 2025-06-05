#ifndef MIDDLE_OUT_ORDER_HPP 
#define MIDDLE_OUT_ORDER_HPP 
#include <vector>
#include <algorithm>
namespace Containers{
template <typename T = int>

class MiddleOutOrder{

private:
    const std::vector<T>* data;           // Pointer to the original data
    std::vector<size_t> sorted_indices;   // Indices in ascending order
    size_t pos;                           // Current position in sorted_indices

public:

    /**
     * @brief Constructs a middle out order iterator from a vector.
     * @param vec The vector to iterate over.
     * @param start_pos The starting position in the sorted order (default is 0).
     */
    MiddleOutOrder(const std::vector<T>& vec ,size_t start_pos = 0)
            : data(&vec), pos(start_pos) {
        std::vector<size_t> ascending(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {// Initialize indices for sorting
                ascending[i] = i;
        }
    
        sorted_indices.clear();
        size_t left = 0;
        size_t right=0;
        if(vec.size() %2 ==0){
            left = vec.size() / 2 - 1; // For even size, start from the middle left
            right = vec.size() / 2; // For even size, start from the middle right
        } else {
            left = vec.size() / 2; // For odd size, start from the middle
            right = vec.size() / 2 + 1; // For odd size, also start from the middle
        }
       
        if(vec.size()==0){ // If the vector is not empty, set right to the last index
           left = 0;
           right = 0;
        }

        if(sorted_indices.size()<vec.size()){ //add the middle element first
            sorted_indices.push_back(ascending[left]);
            if(left > 0) --left;
        }
        bool flip = true; 
        while(sorted_indices.size()<vec.size()) { // While there are elements to process
            if (flip) {
                sorted_indices.push_back(ascending[left]); // Add the left middle element
                if(left > 0) --left;
            } else {
                sorted_indices.push_back(ascending[right]); // Add the right middle element
                if(right < vec.size() - 1) ++right; 
            }
            flip = !flip; 
            
        }
       
    }
  
    /**
     * @brief Dereference operator.
     * @return Reference to the current element.
     */
    T& operator*() { return const_cast<T&>((*data)[sorted_indices[pos]]); }    
   
    /**
     * @brief Moves the iterator to the next element (middle out order).
     * @return Reference to this iterator.
     */
    MiddleOutOrder& operator++() { ++pos; return *this; }

    /**
     * @brief Checks if two iterators are not equal.
     * @param other The other iterator to compare.
     * @return True if not equal, false otherwise.
     */
    bool operator!=(const MiddleOutOrder& other) const { return pos != other.pos; }
    /**
     * @brief Checks if two iterators are equal.
     * @param other The other iterator to compare.
     * @return True if equal, false otherwise.
     */
    bool operator==(const MiddleOutOrder& other) const { return pos == other.pos; }



};

}
#endif