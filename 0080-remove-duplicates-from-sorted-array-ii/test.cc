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
    vector<int> vec{1,1,1,2,2,3};
    vector<int> sol{1, 1, 2, 2, 3};
    auto ans = s.removeDuplicates(vec);
    for (int i = 0; i < sol.size(); ++i){
        REQUIRE(vec.at(i) == sol.at(i));
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
    REQUIRE(ans == sol.size());

    vec = {0,0,1,1,1,1,2,3,3};
    sol = { 0, 0, 1, 1, 2, 3, 3};
    ans = s.removeDuplicates(vec);
    for (int i = 0; i < sol.size(); ++i){
        REQUIRE(vec.at(i) == sol.at(i));
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
    REQUIRE(ans == sol.size());

    vec = {1};
    sol = {1};
    ans = s.removeDuplicates(vec);
    for (int i = 0; i < sol.size(); ++i){
        REQUIRE(vec.at(i) == sol.at(i));
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
    REQUIRE(ans == sol.size());
}
