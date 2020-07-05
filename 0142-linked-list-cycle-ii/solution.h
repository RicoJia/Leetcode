#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head; //use auto whenever you can

        while (fast -> next != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                while(head != slow){
                    head = head -> next;
                    slow = slow -> next;
                }
                return head;
            }
        }
        return nullptr;
    }
};
