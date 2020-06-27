#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"
#include "solution.h"

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

TEST_CASE("test", "test_case")
{
	Solution s;

    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
	REQUIRE(s.mergeTwoLists(l1, l2) == nullptr);

	ListNode* l3 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* l4 = new ListNode(2, new ListNode(4, new ListNode(6)));
    auto ret = s.mergeTwoLists(l3, l4);
    vector<int> sol{1,2,3,4,5,6};
    int i = 0;
    while(ret!= nullptr){
        REQUIRE(ret->val == sol.at(i++));
        ret = ret -> next;
    }
}
