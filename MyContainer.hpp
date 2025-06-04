#ifndef MYCONTAINER_HPP 
#define MYCONTAINER_HPP 
#include <vector>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include "Order.hpp"
#include "ReverseOrder.hpp"
#include "AscendingOrder.hpp"
#include "SideCrossOrder.hpp"

namespace Containers{
template <typename T = int>

/**
 * @brief Generic container class based on std::vector.
 * @tparam T The type of elements stored in the container.
 */
class MyContainer{

private:

    std::vector<T> cont; //< Internal storage for elements

public:

    /**
     * @brief Adds an item to the end of the container.
     * @param item The item to add.
     */
    void addElement(const T& item){
        cont.push_back(item);
    }

    /**
     * @brief Removes all occurrences of an item from the container.
     * @param item The item to remove.
     * @throws std::runtime_error If the item is not found.
     */
    void remove(const T& item){
        bool exist =false;
        for(auto it=cont.begin(); it!=cont.end();){
            if(*it==item){
               it= cont.erase(it); //erase return the pointer to the next value
               exist=true;
            }
            else{
                ++it;
            }
        }
        if(exist==false){
            throw std::runtime_error("Item not found");
        }
    }

    /**
     * @brief Returns the number of elements in the container.
     * @return The size of the container.
     */
    int size() const{
        return cont.size();
    }

    /**
     * @brief Accesses the element at the given index.
     * @param index The index of the element.
     * @return Reference to the element at the given index.
     * @throws std::out_of_range If the index is out of bounds.
     */
    T& operator[](int index){
        return cont.at(index);
    }


    /**
     * @brief Prints the container to the output stream.
     * @param os The output stream.
     * @param container The container to print.
     * @return Reference to the output stream.
     */
   friend std::ostream& operator<<(std::ostream& os , const MyContainer<T>& container ){
        os<<"[ ";
        for (auto it=container.begin();it!=container.end();){
            os<<*it;
            if(std::next(it)!=container.end()){
                os<<" , ";
            }
        }
        os<<" ]";
        return os;
    }

    /**
     * @brief Returns an Order iterator to the beginning of the container.
     * @return An iterator to the first element.
     */
    auto begin_order(){
        return Order<T>(cont.begin());
    }

    /**
     * @brief Returns an Order iterator to the end of the container.
     * @return An iterator to the end of the container.
     */
    auto end_order(){
        return Order<T>(cont.end());
    }

    /**
     * @brief Returns a ReverseOrder iterator to the beginning of the container.
     * @return A ReverseOrder iterator to the first element.
     */
    auto begin_reverse_order(){
        if (cont.empty()) { // If the container is empty, return an iterator to the end
        return ReverseOrder<T>(cont.end());
    }
        return ReverseOrder<T>(--cont.end());
    }

    /**
     * @brief Returns a ReverseOrder iterator to the end of the container.
     * @return A ReverseOrder iterator to the end of the container.
     */
    auto end_reverse_order(){
        if (cont.empty()) { // If the container is empty, return an iterator to the end
            return ReverseOrder<T>(cont.end());
        }
        return ReverseOrder<T>(--cont.begin());
    }


    /**
     * @brief Returns an iterator for ascending order.
     * @return An iterator for ascending order.
     */
    auto begin_ascending_order(){
        return AscendingOrder<T>(cont,true,0);
    }

    /**
     * @brief Returns an iterator for ascending order.
     * @return An iterator for ascending order.
     */
    auto end_ascending_order(){
        return AscendingOrder<T>(cont,true,cont.size());
    }
    /**
     * @brief Returns an iterator for descending order using the same logic as ascending order.
     * @return An iterator for descending order.
     */
    auto begin_descending_order(){
        return AscendingOrder<T>(cont,false,0);
    }
    /**
     * @brief Returns an iterator for descending order using the same logic as ascending order.
     * @return An iterator for descending order.
     */
     auto end_descending_order(){
        return AscendingOrder<T>(cont,false,cont.size());
    }

    /**
     * @brief Returns an iterator for side cross order.
     * @return An iterator for side cross order.
     */
    auto begin_side_cross_order(){
        return SideCrossOrder<T>(cont,0);
    }
    /**
     * @brief Returns an iterator for side cross order.
     * @return An iterator for side cross order.
     */
     auto end_side_cross_order(){
        return SideCrossOrder<T>(cont,cont.size());
    }

};
}


#endif