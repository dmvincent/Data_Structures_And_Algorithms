#include <iostream>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* currNext = nullptr;
        ListNode* lastUnsorted = nullptr;
        ListNode* firstSorted  = nullptr;

        // Iterate throught list at most 'right times'
        int i = 1;
        if(curr->next == nullptr)
            return head;
        if(left == right)
            return head;
        while(i <= right) {
           if(i <= left) {
               if(i == left) {
                 firstSorted = curr;
                 lastUnsorted = prev;
               }
               prev = curr;
               curr = curr->next;
               i++;
           }
           else {
               currNext = curr->next;
               curr->next = prev;
               prev = curr;
               curr = currNext;
               i++;
           }
        }
        if(lastUnsorted != nullptr) {
            lastUnsorted->next = prev;
        }
        else {
            head = prev;
        }
        firstSorted->next = curr;
        return head;
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
