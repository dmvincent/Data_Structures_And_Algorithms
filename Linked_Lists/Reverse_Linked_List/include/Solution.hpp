#include <iostream>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = new ListNode();

        // Iterate throught list at most 'right times'
        int i = 1;
        while(i < (right-left+1)) {
            curr = curr->next;
            //if(i == (right-left)) {
            //    prev = curr;
            //}
            i++;
        }
        while(i < right) {
            // Stor the current node as 'prev' so that, once you switch 'curr' to 'curr.next',
            // you can assign the new curr
            prev = curr;
            curr = curr->next;
            curr

            /***** Start reversing *****/
            
              
          
            i++;
        }
        //printSubList(dLeft, dRight);
    }
    
    void printList(ListNode* head) {
        std::cout << "[";
        while(head != nullptr) {
            if(head->next != nullptr) {
                std::cout << head->val << ",";
            } else {
                std::cout << head->val << "]" << std::endl;
            }
            head = head->next;
        }
    }
    void printSubList(ListNode* left, ListNode* right) {
        std::cout << "[";
        while(left != right) {
            std::cout << left->val << ",";
            left = left->next;
        }
        std::cout << left->val << "]";
    }
};
