#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"

TEST_CASE("test", "test_case")
{
	Solution s; 

    std::string a1 = "";
	REQUIRE(s.longestPalindrome(a1) == "");

    a1 = "string";
    REQUIRE(s.longestPalindrome(a1).length() == 1);

    a1 = "s";
    REQUIRE(s.longestPalindrome(a1).length() == 1);

    a1 = "aba";
    REQUIRE(s.longestPalindrome(a1) == "aba");

    a1 = "abba";
    REQUIRE(s.longestPalindrome(a1) == "abba");

    a1 = "abbacdf";
    REQUIRE(s.longestPalindrome(a1) == "abba");

    a1 = "abacdf";
    REQUIRE(s.longestPalindrome(a1) == "aba");

    a1 = "abbacdfaba";
    REQUIRE(s.longestPalindrome(a1) == "abba");

}
