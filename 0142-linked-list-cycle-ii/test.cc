#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Solution s;

    // 3 -> 2 -> 0 -> 4 -> 2
    ListNode* head = new ListNode(3);
    ListNode* start = new ListNode(2);
    head ->next = start;
    start -> next = new ListNode(0);
    start -> next -> next = new ListNode(-4);
    start -> next -> next -> next = start;

    ListNode* ret = s.detectCycle(head);
    cout << "ret: " << ret->val << endl;

}