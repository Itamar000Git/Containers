#itamarbabai98@gmail.com
C = g++

HEADERS =MyContainer.hpp doctest.h AscendingOrder.hpp MiddleOutOrder.hpp ReverseOrder.hpp SideCrossOrder.hpp Order.hpp
Target = main
TEST_TARGET = Test
FLAGS = -c -g -Wall
OBJECT = Demo.o
TEST_OBJ = test.o

$(Target): $(OBJECT)
	$(C) -Wall -o $(Target) $(OBJECT)

$(TEST_TARGET): $(TEST_OBJ)
	$(C) -Wall -o $(TEST_TARGET) $(TEST_OBJ)

# MyContainer.o: MyContainer.cpp $(HEADERS)
# 	$(C) $(FLAGS) MyContainer.cpp -o MyContainer.o

Demo.o: Demo.cpp $(HEADERS)
	$(C) $(FLAGS) Demo.cpp -o Demo.o

test.o:test.cpp $(HEADERS)
	$(C) $(FLAGS) test.cpp -o test.o

test: $(TEST_TARGET)
	./$(TEST_TARGET)

Main: $(Target)
	./$(Target)

valgrind: $(Target)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(Target)

valgrind_tests: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

.PHONY: $(Target) clean

clean:
	rm -f $(PATH_CPP)*.o $(Target) $(TEST_TARGET)