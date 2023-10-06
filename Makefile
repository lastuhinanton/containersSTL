
.PHONY : all clean test gcov_report rebuild

CFLAGS=-Wall -Werror -Wextra
CPPFLAGS=-lstdc++ -std=c++17
LIBS=-lgtest -lgcov

all: gcov_report

test: 
	@gcc -g $(CFLAGS) $(LIBS) $(CPPFLAGS) --coverage unit_tests.cc -o test
	@./test

gcov_report: test
	#@lcov -t "./gcov" -o report.info --no-external -c -d .
	@lcov --ignore-errors mismatch -t "./gcov" -o report.info --no-external -c -d .
	#@genhtml -o report report.info
	@genhtml --ignore-errors mismatch -o report report.info
	@open ./report/index.html

clean:
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf report
	@rm -rf gcov_report
	@rm -rf valgrind_test
	@rm -rf *.dSYM

rebuild:
	@make clean
	@make all

leaks:
	leaks -atExit -- ./test

style:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -n

gost:
	find . -name "*.h" -o -name "*.cc" -o -name "*.tpp" | xargs clang-format --style=google -i

