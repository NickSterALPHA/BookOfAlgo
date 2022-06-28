#define CATCH_CONFIG_MAIN
#include <iostream>
#include "count_sort.h"
#include "../../../catch_testing/catch.hpp"

TEST_CASE("SpecialCases", "[count_sort]") {
    SECTION("OneElement") {
        std::vector<int> temp = {1};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {1});
    }
    SECTION("ZeroVector"){
        std::vector<int> temp (10);
        std::vector<int> sorted_array = temp;
        count_sort<int>(sorted_array);
        REQUIRE(temp == sorted_array);
    }
    SECTION("EmptyVector") {
        std::vector<int> temp(0);
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int>{});
    }
}

TEST_CASE("Random Sorting", "[count_sort]") {
    SECTION("Different numbers") {
        std::vector<int> temp = {1, 6, 2, 9, 8, 11, 19, 15, 14};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {1, 2, 6, 8, 9, 11, 14, 15, 19});
        temp = {2, 3, 1, 4, 5, 7, 6, 9, 8, 10, 0, 11};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
        temp = {999, 1100, 2200, 1150, 888, 717, 322};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {322, 717, 888, 999, 1100, 1150, 2200,});
    }
    SECTION("there are the same numbers") {
        std::vector<int> temp = {1 , 1 , 3, 2, 1, 3, 2, 2, 3};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {1, 1, 1, 2, 2, 2, 3, 3, 3});
        temp = {9, 9, 8, 2, 2, 3, 13, 24, 24, 15, 15, 1110};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {2, 2, 3, 8, 9, 9, 13, 15, 15, 24, 24, 1110});
        temp = {1, 0, 1, 2, 1999, 1999, 2020};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {0, 1, 1, 2, 1999, 1999, 2020});
    }
    SECTION("Negative numbers") {
        std::vector<int> temp = {-2, -9, -1, -3, -2, -2};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int>{-9, -3, -2, -2, -2, -1});
        temp = {-2, -8, 1, 3, 1, -2, -9, 10, -8, -8, 110};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int>{-9, -8, -8, -8, -2, -2, 1, 1, 3, 10, 110});
        temp = {29, 28, 31, 25, 38, 29, 28, -5, 6, 7};
        count_sort<int>(temp);
        REQUIRE(temp == std::vector<int> {-5, 6, 7, 25, 28, 28, 29, 29, 31, 38});
    }
}

TEST_CASE("Different Types sorting", "[count_sort]") {
    SECTION("long") {
        std::vector<long> temp = {2l, -3l, -4l, 10l, 6l, -9l, 11l, -11l, 11l, 12l, 12l};
        count_sort<long>(temp);
        REQUIRE(temp == std::vector<long>{-11l, -9l, -4l, -3l, 2l, 6l, 10l, 11l, 11ll, 12l, 12l});
    }
    SECTION("long long") {
        std::vector<long long> temp = {-2ll, -2ll, -4ll, -4ll, -3ll, -3ll, 10ll, 0ll, 0ll, -4ll};
        count_sort<long long>(temp);
        REQUIRE(temp == std::vector<long long>{-4ll, -4ll, -4ll, -3ll, -3ll, -2ll, -2ll, 0ll, 0ll, 10ll});
    }
    SECTION("unsigned long long") {
        std::vector<unsigned long long> temp = {18446744073709551613ull, 18446744073709551610ull,
        18446744073709551614ull, 18446744073709551611ull};
        count_sort<unsigned long long>(temp);
        REQUIRE(temp == std::vector<unsigned long long> {18446744073709551610ull,
        18446744073709551611ull, 18446744073709551613ull, 18446744073709551614ull});
    }
}