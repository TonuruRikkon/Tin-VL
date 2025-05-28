// test_SQARE.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <iostream>

// Refactor the main logic into a function for testing
std::string countPerfectSquares(long long L, long long R) {
    long long st=0, ed=0;
    for (long long i = L; i <= R; i++) {
        if (sqrt(i)*sqrt(i) == i) {
            st = sqrt(i);
            break;
        }
    }
    for (long long i = R; i >= L; i--) {
        if (sqrt(i)*sqrt(i) == i) {
            ed = sqrt(i);
            break;
        }
    }
    std::ostringstream out;
    if (st == ed && st == 0) {
        out << 0;
    } else {
        out << ed - st + 1;
    }
    return out.str();
}

TEST_CASE("No perfect squares in range") {
    REQUIRE(countPerfectSquares(2, 3) == "0");
    REQUIRE(countPerfectSquares(20, 23) == "0");
}

TEST_CASE("One perfect square in range") {
    REQUIRE(countPerfectSquares(4, 4) == "1");
    REQUIRE(countPerfectSquares(9, 10) == "1");
}

TEST_CASE("Multiple perfect squares in range") {
    REQUIRE(countPerfectSquares(1, 9) == "3"); // 1,4,9
    REQUIRE(countPerfectSquares(10, 25) == "2"); // 16,25
    REQUIRE(countPerfectSquares(1, 16) == "4"); // 1,4,9,16
}

TEST_CASE("Large range") {
    REQUIRE(countPerfectSquares(1, 100) == "10");
    REQUIRE(countPerfectSquares(50, 1000) == "22");
}

TEST_CASE("Edge cases") {
    REQUIRE(countPerfectSquares(1, 1) == "1");
    REQUIRE(countPerfectSquares(0, 0) == "1");
    REQUIRE(countPerfectSquares(0, 1) == "2");
}