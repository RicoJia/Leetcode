#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"

using std::string;

TEST_CASE("test", "test_case")
{
	Solution s;
    string str = "PAYPALISHIRING";
    string ret = s.convert(str, 4);
    REQUIRE(ret=="PINALSIGYAHRPI");
//
    str = "PAYPALISHIRING";
    ret = s.convert(str, 3);
    REQUIRE(ret=="PAHNAPLSIIGYIR");
}
