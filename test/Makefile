# @file      Makefile
# @brief     Build the unit tests for the `nice` library.
# @author    J. Arrieta <Juan.Arrieta@nablazerolabs.com>
# @date      November 24, 2016
# @copyright (c) 2016 Nabla Zero Labs
# @license   The MIT License (MIT)

CXX = g++
CXX_FLAGS = -I../include -O2 -march=native -Wall -Wextra -std=c++14
GTEST_FLAGS = -lgtest -lgtest_main -lpthread

test-nice: test-nice.cpp
	${CXX} -o test-nice test-nice.cpp ${CXX_FLAGS} ${GTEST_FLAGS}

.PHONY: clean

clean:
	rm -f test-nice
