GCC=-Wall -Werror -Wextra -lstdc++ -std=c++17 #-fsanitize=address


all: clean library test

build:
	gcc -c ${GCC} utests.cc -o vector.o

library: build
	rm -rf library.a
	ar rcs library.a vector.o
	ranlib library.a

test: library
	gcc -lgtest -lstdc++ -std=c++17 library.a  -o utests.out
	./utests.out
	make clean

clean:
	rm -rf  *.gcno  *.inf *.info gcov *.gcda *.a *.out ./report  *.o *.dSYM

check:
	clang-format -style=Google -n *.C *.h

