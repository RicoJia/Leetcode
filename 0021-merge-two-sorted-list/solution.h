#include <iostream>



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    // this solution has O(n) and extra space complexity is S(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(); ListNode* curr = start;
        ListNode* next_l1 = l1; ListNode* next_l2 = l2;
        while(next_l1 && next_l2){
            if(next_l1 -> val <= next_l2 -> val){
                curr -> next = next_l1;
                next_l1 = next_l1 -> next;
            }
            else{
                curr -> next = next_l2;
                next_l2 = next_l2 -> next;
            }
            curr = curr -> next;
        }

        // hook the rest of the string to the back of the list
        curr -> next = (next_l1)? next_l1: next_l2;

        return start->next;
    }
};
