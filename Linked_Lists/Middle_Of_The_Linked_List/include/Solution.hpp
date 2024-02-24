#include <iostream>
#include "ListNode.hpp"

/**
 * Deftion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = new ListNode();
        ListNode * slow = new ListNode(); 

        fast = head;
        slow = head;

        while(fast->next != nullptr) {
           if(fast->next->next == nullptr) {
               std::cout << "nullptr found" << std::endl;
               break;
           }
           fast->val = fast->next->next->next->val;
           fast->next = fast->next->next->next;
           slow->val = slow->next->val;
           slow->next = slow->next->next;
        }
        std::cout << "Slow->val: " << slow->val;
    }
};
