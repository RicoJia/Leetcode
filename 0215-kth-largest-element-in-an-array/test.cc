#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"

#include <iostream>
using std::cout;
using std::endl;

using std::vector;

TEST_CASE("test", "test_case")
{
	Solution s;
    vector<int> vec{3,2,1,5,6,4};
    int k = 2;
	int ret = s.findKthLargest(vec, k);
	REQUIRE(ret == 5);


    vec = {3,2,3,1,2,4,5,5,6};
    k = 4;
    ret = s.findKthLargest(vec, k);
    REQUIRE(ret == 4);
}
