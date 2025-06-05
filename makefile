#itamarbabai98@gmail.com
C = g++
HEADERS =MyContainer.hpp doctest.h AscendingOrder.hpp MiddleOutOrder.hpp ReverseOrder.hpp SideCrossOrder.hpp Order.hpp
TARGET = main
TEST_TARGET = test
FLAGS = -c -g -Wall
OBJECT = Demo.o
TEST_OBJ = Test.o

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJECT)
	$(C) -Wall -o $(TARGET) $(OBJECT)

$(TEST_TARGET): $(TEST_OBJ)
	$(C) -Wall -o $(TEST_TARGET) $(TEST_OBJ)

Demo.o: Demo.cpp $(HEADERS)
	$(C) $(FLAGS) Demo.cpp -o Demo.o

test.o: test.cpp $(HEADERS)
	$(C) $(FLAGS) test.cpp -o test.o

Test: $(TEST_TARGET)
	./$(TEST_TARGET)

Main: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

valgrind_tests: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

.PHONY: $(TARGET) clean $(TEST_TARGET) Test Main valgrind valgrind_tests

clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)