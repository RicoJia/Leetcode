#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("test", "test_case")
{
	Solution s;
	string s1 = "123";
	int ret1 = s.myAtoi(s1);
	REQUIRE(ret1 == 123);

    s1 = "   -123";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == -123);

    s1 = "4193 with words";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == 4193);

    s1 = "words and 987";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == 0);

    s1 = "-91283472332";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == -2147483648);

    s1 = "  -0012a42";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == -12);

    s1 = "-2147483648";
    ret1 = s.myAtoi(s1);
    REQUIRE(ret1 == -2147483648);
}
