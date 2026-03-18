CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c++20

SRC_DIR = ./
SRC = $(wildcard $(SRC_DIR)s21_matrix_oop.cpp)
TEST_SRC = $(wildcard tests/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)*.h)
FUNC_OBJECTS = $(SRC:.cpp=.o)
SANITIZE = -fsanitize=address
TEST_LIBS = -lgtest -lpthread -lm
CPP_LIBS = -lstdc++ -lm
TARGET = s21_test

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPP_LIBS)

all: clean build test

s21_matrix_oop.a: s21_matrix_oop.o
	ar r s21_matrix_oop.a s21_matrix_oop.o

build: s21_matrix_oop.a
	$(CC) $(CFLAGS) $(TEST_SRC) -o ./$(TARGET) $(TEST_LIBS) $(CPP_LIBS) -L. -l:s21_matrix_oop.a

test: clean build
	./$(TARGET)

sanitize: clean s21_matrix_oop.a
	$(CC) $(CFLAGS) $(SANITIZE) $(TEST_SRC) -o ./sanitize $(TEST_LIBS) $(CPP_LIBS) -L. -l:s21_matrix_oop.a
	./sanitize

valgrind: clean build
	valgrind --leak-check=yes --tool=memcheck -q ./$(TARGET)

clean:
	rm -f ./$(TARGET) ./sanitize
	rm -f ../src/**/*.[ao] ./*.[ao] ./*.out

cf-check:
	@find . -type f -name "*.[ch]" -exec clang-format -i {} \;
	@find . -type f -name "*.cpp" -exec clang-format -i {} \;
