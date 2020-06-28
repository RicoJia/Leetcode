#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("test", "test_case")
{
	Solution s; 
    vector<int> vec{0,2,1,0,1,1};
    vector<int> sol{0,0,1,1,1,2};
    s.sortColors(vec);
    for (int i = 0; i< vec.size(); ++i){
        REQUIRE(vec.at(i) == sol.at(i));
    }
}
