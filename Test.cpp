//itamarbabai98@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

    using namespace Containers;

TEST_CASE("Mycontainer Tests") {
    //using namespace Containers;

    MyContainer<int> container;
    /**
     * @brief Tests for MyContainer class
     * This case tests adding elements
     */
    SUBCASE("Add Elements") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        CHECK(container.size() == 3);
        std::cout << container << std::endl;
    }
    
    /**
     * @brief Tests for MyContainer class
     * This case tests removing elements
     */
    SUBCASE("Remove Elements") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.remove(2);
        CHECK(container.size() == 2);
        std::cout << container << std::endl;
    }

    /**
     * @brief Tests for MyContainer class
     * This case tests removing non-existent elements
     */
    SUBCASE("Remove Non-Existent Element") {
        container.addElement(1);
        CHECK_THROWS_AS(container.remove(2), std::runtime_error);
    }
    /**
     * @brief Tests for MyContainer class
     * This case tests the size of an empty container
     */
    SUBCASE("Size of Empty Container") {
        CHECK(container.size() == 0);
    }
    /**
     * @brief Tests for MyContainer class
     * This case tests accessing elements by index
     */
     SUBCASE("Access Element by Index") {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        CHECK(container[0] == 1);
        CHECK(container[1] == 2);
        CHECK(container[2] == 3);
        CHECK_THROWS_AS(container[3], std::out_of_range);
        CHECK_THROWS_AS(container[-2], std::out_of_range);

    }


    MyContainer<double> d_container;
    /**
     * @brief Tests for MyContainer class with double type
     * This case tests adding elements
     */
    SUBCASE("Add Double Elements") {
        d_container.addElement(1.1);
        d_container.addElement(2.2);
        d_container.addElement(3.3);
        CHECK(d_container.size() == 3);
        std::cout << d_container << std::endl;

    }
    /**
     * @brief Tests for MyContainer class with double type
     * This case tests removing elements
     */
    SUBCASE("Remove Double Elements") {
        d_container.addElement(1.1);
        d_container.addElement(2.2);
        d_container.addElement(3.3);
        d_container.remove(2.2);
        CHECK(d_container.size() == 2);
        std::cout << d_container << std::endl;
    }
    /**
     * @brief Tests for MyContainer class with double type
     * This case tests removing non-existent elements
     */
    SUBCASE("Remove Non-Existent Double Element") {
        d_container.addElement(1.1);
        CHECK_THROWS_AS(d_container.remove(2.2), std::runtime_error);
    }
    /**
     * @brief Tests for MyContainer class with double type
     * This case tests the size of an empty container
     */
    SUBCASE("Size of Empty Double Container") {
        CHECK(d_container.size() == 0);
    }
    /**
     * @brief Tests for MyContainer class with double type
     * This case tests accessing elements by index
     */
    SUBCASE("Access Element by Index") {
        d_container.addElement(1.1);
        d_container.addElement(2.2);
        d_container.addElement(3.3);
        CHECK(d_container[0] == 1.1);
        CHECK(d_container[1] == 2.2);
        CHECK(d_container[2] == 3.3);
        CHECK_THROWS_AS(d_container[3], std::out_of_range);
        CHECK_THROWS_AS(d_container[-2], std::out_of_range);

    }

    MyContainer<std::string> string_container;
    /**
     * @brief Tests for MyContainer class with string type
     * This case tests adding elements
     */
    SUBCASE("Add String Elements") {
        string_container.addElement("Hello");
        string_container.addElement("World");
        string_container.addElement("!");
        CHECK(string_container.size() == 3);
        std::cout << string_container << std::endl;
    }
    /**
     * @brief Tests for MyContainer class with string type
     * This case tests removing elements
     */
    SUBCASE("Remove String Elements") {
        string_container.addElement("Hello");
        string_container.addElement("World");
        string_container.addElement("!");
        string_container.remove("World");
        CHECK(string_container.size() == 2);
        std::cout << string_container << std::endl;
    }
    /**
     * @brief Tests for MyContainer class with string type
     * This case tests removing non-existent elements
     */
    SUBCASE("Remove Non-Existent String Element") {
        string_container.addElement("Hello");
        CHECK_THROWS_AS(string_container.remove("NonExistent"), std::runtime_error);
    }
    /**
     * @brief Tests for MyContainer class with string type
     * This case tests the size of an empty container
     */
    SUBCASE("Size of Empty String Container") {
        CHECK(string_container.size() == 0);
    }
    /**
     * @brief Tests for MyContainer class with string type
     * This case tests accessing elements by index
     */
    SUBCASE("Access Element by Index") {
        string_container.addElement("Hello");
        string_container.addElement("World");
        string_container.addElement("!");
        CHECK(string_container[0] == "Hello");
        CHECK(string_container[1] == "World");
        CHECK(string_container[2] == "!");
        CHECK_THROWS_AS(d_container[3], std::out_of_range);
        CHECK_THROWS_AS(d_container[-2], std::out_of_range);

    }
    /**
     * @brief Tests for MyContainer class with int type
     * This case tests printing the container
     */
    SUBCASE("Print String Container") {
        MyContainer<std::string> string1_container;
        std::ostringstream oss;
        string1_container.addElement("Hello");
        string1_container.addElement("World");
        string1_container.addElement("!");
        oss << string1_container;
        CHECK(oss.str() == "[ Hello , World , ! ]");
    }
    /**
     * @brief Tests for MyContainer class with int type
     * This case tests printing an empty container
     * This case tests printing an 1 element container
     */
    SUBCASE("Print Empty Container") {
        MyContainer<int> empty_container;
        std::ostringstream oss;
        oss << empty_container;
        CHECK(oss.str() == "[  ]");
        oss.str(""); // Clear the stream
        oss.clear(); // Clear any error flags
        empty_container.addElement(1);
        oss << empty_container;
        CHECK(oss.str() == "[ 1 ]");
    }
    /**
     * @brief Tests for MyContainer class with int type
     * This case tests adding and removing elements in the container
     * This case tests adding duplicate elements
     * This case tests removing all elements appearing multiple times and asked to remove one of them
     */
    SUBCASE("Add and Remove Elements in int Container") {
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        CHECK(container.size() == 3);
        std::cout << container << std::endl;    
        container.remove(20);
        CHECK(container.size() == 2);
        std::cout << container << std::endl;
        CHECK_THROWS_AS(container.remove(40), std::runtime_error);
        container.addElement(10);
        container.addElement(10);
        container.addElement(10);
        CHECK(container.size() == 5);
        std::cout << container << std::endl;
        container.remove(10);
        CHECK(container.size() == 1);
        std::cout << container << std::endl;

    }
}

/**
 * @brief Tests for MyContainer class with double type
 * This case tests adding and removing elements in the container
 * This case tests adding duplicate elements
 * This case tests removing all elements appearing multiple times and asked to remove one of them
 */
TEST_CASE("Check Order Iterators") {

    MyContainer<int> container;
    container.addElement(7);
    container.addElement(-5);
    container.addElement(3);
    container.addElement(0);
    container.addElement(10);
    container.addElement(15);
    container.addElement(6);
    container.addElement(1);
    container.addElement(2);

    /**
     * @brief Tests Regular Order Iterator
     * This case tests the regular order iterator
     */
    SUBCASE("Regular Order") {
        auto it = container.begin_order();
        CHECK(*it == 7);
        ++it;
        CHECK(*it == -5);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 6);
        ++it;   
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(it == container.end_order());
    }
    /**
     * @brief Tests Regular Order Iterator with empty container
     * This case tests the regular order iterator with an empty container
     */
     SUBCASE("Regular Order Empty") {
        MyContainer<int> empty_container;
        auto it = empty_container.begin_order();
        CHECK(it == empty_container.end_order());
     }
     /**
      * @brief Tests Regular Order Iterator with one element
      * This case tests the regular order iterator with a container containing one element
      */
      SUBCASE("Regular Order one element") {
        MyContainer<int> one_element_container;
        one_element_container.addElement(42);
        auto it = one_element_container.begin_order();
        CHECK(*it == 42);
        ++it;
        CHECK(it == one_element_container.end_order());

      }

    SUBCASE("Dereference after end throws exception") {
        MyContainer<int> container;
        container.addElement(1);
        auto it = container.begin_order();
        ++it; 
        CHECK(it == container.end_order());
        CHECK_THROWS_AS(*it, std::out_of_range); 
    }
}

/**
 * @brief Tests Reverse Order Iterator
 * This case tests the reverse order iterator
*/
TEST_CASE("Check Reverse Iterators"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(-5);
        container.addElement(3);
        container.addElement(0);
        container.addElement(10);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
    
    SUBCASE("Reverse Order") {
        auto it = container.begin_reverse_order();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 6);
        ++it;   
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == -5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(it == container.end_reverse_order());
    }
    /**
     * @brief Tests Reverse Order Iterator with empty container
     * This case tests the reverse order iterator with an empty container
     */
    SUBCASE("Reverse Order Empty") {
        MyContainer<int> empty_container;
        auto it = empty_container.begin_reverse_order();
        CHECK(it == empty_container.end_reverse_order());
    }
    /**
     * @brief Tests Reverse Order Iterator with one element
     * This case tests the reverse order iterator with a container containing one element
     */
    SUBCASE("Reverse Order one element") {
        MyContainer<int> one_element_container;
        one_element_container.addElement(42);
        auto it = one_element_container.begin_reverse_order();
        CHECK(*it == 42);
        ++it;
        CHECK(it == one_element_container.end_reverse_order());
    }
    /**
     * @brief Tests Reverse Order Iterator with dereference after end
     * This case tests dereferencing after the end of the reverse order iterator
     * It should throw an exception
     */
    SUBCASE("Dereference after end throws exception") {
        MyContainer<int> container;
        container.addElement(1);
        auto it = container.begin_reverse_order();
        ++it; 
        CHECK(it == container.end_reverse_order());
        CHECK_THROWS_AS(*it, std::out_of_range); 
    }

}


TEST_CASE("Ascending Order"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(-5);
        container.addElement(3);
        container.addElement(0);
        container.addElement(10);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
    

    /**
     * @brief Tests Ascending Order Iterator
     * This case tests the ascending order iterator
     * It should iterate through the elements in ascending order
     * from the smallest to the largest.
     */
   // TESTCASE("Ascending Order"){
    SUBCASE("Ascending Order") {
        auto it = container.begin_ascending_order();
        CHECK(*it == -5);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 6);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 15);
        ++it;
        CHECK(it == container.end_ascending_order());
    }   
    /**
     * @brief Tests Ascending Order Iterator with empty container
     * This case tests the ascending order iterator with an empty container
     */
    SUBCASE("Ascending Order Empty") {
        MyContainer<int> empty_container;
        auto it = empty_container.begin_ascending_order();
        CHECK(it == empty_container.end_ascending_order());
    }
    /**
     * @brief Tests Ascending Order Iterator with one element
     * This case tests the ascending order iterator with a container containing one element 
     */
    SUBCASE("Ascending Order one element") {
        MyContainer<int> one_element_container;
        one_element_container.addElement(42);
        auto it = one_element_container.begin_ascending_order();
        CHECK(*it == 42);
        ++it;
        CHECK(it == one_element_container.end_ascending_order());
    }
    /**
     * @brief Tests Ascending Order Iterator with dereference after end
     * This case tests dereferencing after the end of the ascending order iterator
     * It should throw an exception
     */
    SUBCASE("Dereference after end throws exception") {
        MyContainer<int> container;
        container.addElement(1);
        auto it = container.begin_ascending_order();
        ++it; 
        CHECK(it == container.end_ascending_order());
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
}

TEST_CASE("Descending Order"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(-5);
        container.addElement(3);
        container.addElement(0);
        container.addElement(10);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
    
    /**
     * @brief Tests Descending Order Iterator
     * This case tests the descending order iterator
     * It should iterate through the elements in descending order
     * from the largest to the smallest.
     */
    SUBCASE("Descending Order") {
        auto it = container.begin_descending_order();
        CHECK(*it == 15);
        ++it;
        CHECK(*it == 10);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 6);
        ++it;   
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == -5);
        ++it;
        CHECK(it == container.end_descending_order());
    }
    /**
     * @brief Tests Descending Order Iterator with empty container
     * This case tests the descending order iterator with an empty container
     */
    SUBCASE("Descending Order Empty") {
        MyContainer<int> empty_container;
        auto it = empty_container.begin_descending_order();
        CHECK(it == empty_container.end_descending_order());
    }
    /**
     * @brief Tests Descending Order Iterator with one element
     * This case tests the descending order iterator with a container containing one element
     */
    SUBCASE("Descending Order one element") {
        MyContainer<int> one_element_container;
        one_element_container.addElement(42);
        auto it = one_element_container.begin_descending_order();
        CHECK(*it == 42);
        ++it;
        CHECK(it == one_element_container.end_descending_order());
    }
    /**
     * @brief Tests Descending Order Iterator with dereference after end
     * This case tests dereferencing after the end of the descending order iterator
     * It should throw an exception
     */ 
    SUBCASE("Dereference after end throws exception") {
        MyContainer<int> container;
        container.addElement(1);
        auto it = container.begin_descending_order();
        ++it; 
        CHECK(it == container.end_descending_order());
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
}

TEST_CASE("Cross Side Order") {
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(8);
    
        SUBCASE("Side Cross Order") {
            auto it = container.begin_side_cross_order();
            CHECK(*it== 1);
            ++it;
            CHECK(*it == 15);
            ++it;
            CHECK(*it == 2);
            ++it;
            CHECK(*it == 8);
            ++it;
            CHECK(*it == 3);
            ++it;
            CHECK(*it == 7);
            ++it;
            CHECK(*it == 4);
            ++it;
            CHECK(*it == 6);
            ++it;
            CHECK(*it == 5);
            ++it;
            CHECK(it == container.end_side_cross_order());
        }
        /**
         * @brief Tests Side Cross Order Iterator with empty container
         * This case tests the side cross order iterator with an empty container
         */
         SUBCASE("Side Cross Order Empty") {
             MyContainer<int> empty_container;
             auto it = empty_container.begin_side_cross_order();
             CHECK(it == empty_container.end_side_cross_order());
         }
      
        /**
         * @brief Tests Side Cross Order Iterator with one element
         * This case tests the side cross order iterator with a container containing one element   
         * */
        SUBCASE("Side Cross Order one element") {
            MyContainer<int> one_element_container;
            one_element_container.addElement(42);
            auto it = one_element_container.begin_side_cross_order();
            CHECK(*it == 42);
            ++it;
            CHECK(it == one_element_container.end_side_cross_order());
        }

        /**
         * @brief Tests Side Cross Order Iterator with dereference after end
         * This case tests dereferencing after the end of the side cross order iterator
         * It should throw an exception
         */
        SUBCASE("Dereference after end throws exception") {
            MyContainer<int> container;
            container.addElement(1);
            auto it = container.begin_side_cross_order();
            ++it;
            CHECK(it == container.end_side_cross_order());
            CHECK_THROWS_AS(*it, std::out_of_range);    
        }
    }

TEST_CASE("Cross Middle Out Order"){
        MyContainer<int> container;
        container.addElement(7);
        container.addElement(15);
        container.addElement(6);
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(8);

    SUBCASE("Middle Out Order") {
        auto it = container.begin_middle_out_order();
         CHECK(*it == 2);
         ++it;
         CHECK(*it == 1);
         ++it;
         CHECK(*it == 3);
         ++it;
         CHECK(*it == 6);
         ++it;
         CHECK(*it == 4);
         ++it;
         CHECK(*it == 15);
         ++it;
         CHECK(*it == 5);
         ++it;
         CHECK(*it == 7);
         ++it;
         CHECK(*it == 8);
         ++it;
        CHECK(it == container.end_middle_out_order());
    }
    /**
     * @brief Tests Middle Out Order Iterator with empty container
     * This case tests the middle out order iterator with an empty container
     */
    SUBCASE("Middle Out Order Empty") {
         MyContainer<int> empty_container;
         auto it = empty_container.begin_middle_out_order();
         CHECK(it == empty_container.end_middle_out_order());
     }
    /**
     * @brief Tests Middle Out Order Iterator with one element
     * This case tests the middle out order iterator with a container containing one element
     */
    SUBCASE("Middle Out Order one element") {
         MyContainer<int> one_element_container;
         one_element_container.addElement(42);
         auto it = one_element_container.begin_middle_out_order();
         CHECK(*it == 42);
         ++it;
         CHECK(it == one_element_container.end_middle_out_order());
     }
    /**
     * @brief Tests Middle Out Order Iterator with dereference after end
     * This case tests dereferencing after the end of the middle out order iterator
     * It should throw an exception
     */
    SUBCASE("Dereference after end throws exception") {
         MyContainer<int> container;
         container.addElement(1);
         auto it = container.begin_middle_out_order();
         ++it; 
         CHECK(it == container.end_middle_out_order());
         CHECK_THROWS_AS(*it, std::out_of_range); 
     }

}
    