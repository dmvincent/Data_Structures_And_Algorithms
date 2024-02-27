#include <iostream>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = new ListNode();
        ListNode * slow = new ListNode(); 
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
