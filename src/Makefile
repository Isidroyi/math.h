OS=MAC
USERNAME := $(shell uname -s)
OPEN_CMD = open

CC=gcc -Wall -Wextra -Werror -std=c11
FLAGS= -lm -lsubunit -lcheck -lpthread
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GLFLAGS=--coverage

SOURCES=s21_math.c utils.c
OBJECTS=s21_math.o utils.o
EXECUTABLE=s21_math.a
TEST_SOURCES=test.c
TEST_EXECUTABLE=test

ifeq ($(USERNAME),Linux)
	CHECKFLAGS= -lcheck
	ADD_LIB = -lm -lpthread -lrt -lsubunit
	OS = LINUX
endif

ifeq ($(USERNAME),Darwin)
	CHECKFLAGS= $(shell pkg-config --cflags --libs check)
endif

install:
	if [ $(OS) = "LINUX" ]; then \
		sudo apt-get install -y lcov; \
		sudo apt-get install -y check; \
	else \
		brew install lcov; \
	fi

all: s21_math.a

s21_math.a:
	$(CC) $(FLAGS) -c $(SOURCES)
	ar rcs $(EXECUTABLE) $(OBJECTS)
	rm -rf *.o

s21_math.a_coverage:
	$(CC) $(FLAGS) $(GCOVFLAGS) -c $(SOURCES)
	ar rcs $(EXECUTABLE) $(OBJECTS)
	rm -rf *.o

test: s21_math.a_coverage
	$(CC) -fprofile-arcs $(TEST_SOURCES) -L. $(EXECUTABLE) -o $(TEST_EXECUTABLE) -lcheck $(ADD_LIB)
	./test

gcov_report: clean s21_math.a_coverage test
	lcov -o tests.info -c -d .
	genhtml -o report tests.info
	$(OPEN_CMD) report/index.html


clean:
	rm -rf $(EXECUTABLE) $(TEST_EXECUTABLE) report *.o *.a *.gcda *.gcno *.gcov *.html *.css *.info

checks:
	cp ../materials/linters/.clang-format .
	find . -type f \( -name '*.c' -o -name '*.h' \) -exec clang-format -i {} \; -exec cppcheck --enable=all {} \;

rebuild: clean all

.PHONY: all test gcov_report clean checks rebuild s21_math.a s21_math.a_coverage
