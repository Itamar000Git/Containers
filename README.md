itamarbabai98@gmail.com

# Ex4 Containers Library - C++

## General Overview
This project implements a generic Containers implement. The main class, `MyContainer`, supports adding, removing, accessing, printing, and comparing elements, as well as providing a variety of custom iterators for traversing the container in different orders: regular, reverse, ascending, descending, side-cross , and middle-out.  
The library includes handle error handling for edge cases.

---

## Build and Run Instructions

- **Compiler:** g++
- **Build the project:**  
```bash
 make
  ```
 - **Run Demo**
  ```bash
  make Main
  ```
 - **Run Test**
 ```bash
  make Test
 ```
  - **Clean**:
  ```bash
  make clean
  ```
  - **Run valgrined**:
  ```bash
  make valgrined
  ```
  - **Run tests with valgrined**:
  ```bash
  make valgrind_tests
  ```
## Project Structure
```bash
  Ex4_containers/
├── Demo.cpp
├── MyContainer.hpp
├── Order.hpp
├── ReverseOrder.hpp
├── AscendingOrder.hpp
├── SideCrossOrder.hpp
├── MiddleOutOrder.hpp
├── Test.cpp
├── Makefile
└── README.md
```

## File Descriptions

- **Demo.cpp**  
  Example program demonstrating usage of `MyContainer` and all iterator types.

- **MyContainer.hpp**  
  MyContainer is a templated class that wraps a std::vector and provides additional functionality.  
  It supports adding elements with `addElement` and removing all appearences of a value using `remove`,  
  which throws an exception if the element doesn't exist.  
  The `operator[]` gives access to elements by index with bounds checking.  
  The `size` method returns the number of elements.  
  The class overloads the `<<` operator to print the container contents.

  It also provides standard iterators (`begin`/`end`) and several custom iteration methods:  
- `begin_order` / `end_order`: Iterate in insertion order.  
- `begin_reverse_order`: Iterate from last to first.  
- `begin_ascending_order` / `begin_descending_order`: Iterate by sorted values.  
- `begin_side_cross_order`: Alternate between smallest and largest elements.  
- `begin_middle_out_order`: Start from the middle and expand outwards.


- **Order.hpp**  
  Iterator for regular (insertion) order traversal.  
  `Order<T>` is a simple wrapper for iterating over a `std::vector<T>`.  
  It lets you move through the vector and access elements safely.  
  Throws an error if you try to access past the end.  
  Useful for going over elements in the order they were added.

- **ReverseOrder.hpp**  
  Iterator for reverse (from last to first) order traversal.  
  `ReverseOrder<T>` lets you go backwards through a `std::vector<T>`.  
  You give it a starting iterator and an end point.  
  Throws an error if you try to access past the end (before beginning).  


- **AscendingOrder.hpp**  
  Iterator for sorted traversal (ascending or descending) of a vector.  
  `AscendingOrder<T>` lets you go over a `std::vector<T>` in sorted order.  
  You can choose ascending (`ascen = true`) or descending (`ascen = false`) at construction.  
  Internally stores sorted indices, not a copy of the data.  
  Throws an error if trying to access out of range — safe and efficient.


- **SideCrossOrder.hpp**  
  Iterator for "side-cross" traversal: smallest, largest, next-smallest, next-largest until the end.  
  `SideCrossOrder<T>` builds an internal order from a given `std::vector<T>`, starting with the smallest, then largest, alternating inward.  
  You only pass the original vector to the constructor; it automatically sorts and builds the zigzag pattern.  
  Throws an exception if trying to access beyond the end of the sequence.  

- **MiddleOutOrder.hpp**  
  Iterator for "middle-out" traversal: start from the center, then alternate left and right.  
  `MiddleOutOrder<T>` creates a special iteration order from a `std::vector<T>` by starting at the middle index and expanding outward.  
  For even-sized vectors, starts with the two middle elements. For odd-sized, starts with the central one.  
  You don't need to sort the values — this iterator is based purely on index position.  

## Test Coverage Details

The following summarizes the test cases implemented in `Test.cpp`:

### MyContainer Functionality

- **Adding and Removing Elements:**  
  Tested for `int`, `double`, and `std::string` containers.  
  Verifies that elements can be added, removed, and that the container size is updated.  
  Checks that removing a non-existent element throws a `std::runtime_error`.

- **Access by Index:**  
  For all supported types, checks correct access by index and that out-of-range access (negative or too large) throws `std::out_of_range`.

- **Container Size:**  
  Confirms that a new container reports size zero, and that size updates correctly after operations.

- **Printing:**  
  Verifies correct output formatting for empty, single-element, and multi-element containers.

- **Duplicates and Multiple Removals:**  
  Tests adding duplicate elements and removing all appearances, ensuring only the correct elements remain.

---

### Iterator Functionality

- **Order Iterators:**  
  - *Regular Order:* Checks iteration in insertion order, including on empty and single-element containers.
  - *Reverse Order:* Checks iteration from last to first, including on empty and single-element containers.
  - *Ascending Order:* Checks iteration from smallest to largest value, including on empty and single-element containers.
  - *Descending Order:* Checks iteration from largest to smallest value, including on empty and single-element containers.
  - *Side Cross Order:* Checks iteration that alternates between smallest and largest, then next smallest/largest, etc., including on empty and single-element containers.
  - *Middle Out Order:* Checks iteration starting from the middle and expanding outward alternately, including on empty and single-element containers.

- **Dereferencing Past End:**  
  For all iterator types, verifies that dereferencing after reaching the end throws a `std::out_of_range` exception.

- **Begin/End Comparison:**  
  For all iterator types, ensures that `begin` and `end` are equal for empty containers.

- **Order Validation:**  
  For each iterator type, checks that the traversal order matches the expected logic (insertion, reverse, sorted, side-cross, middle-out).

---