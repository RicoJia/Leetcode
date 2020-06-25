#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"

TEST_CASE("test", "test_case")
{
	Solution s; 

	std::vector<int> v1 {3,0,1}; 
	REQUIRE(s.missingNumber(v1) == 2);

}
