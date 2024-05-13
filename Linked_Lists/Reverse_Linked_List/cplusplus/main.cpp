#include <iostream>
#include "include/Solution.hpp"

int main() {
    // Provide bounds for reversal
    //int left{2}, right{4};
    int left{1}, right{2};
 
    // Create the Linked List
    //ListNode* a = new ListNode(1);
    //ListNode* b = new ListNode(2);
    //ListNode* c = new ListNode(3);
    //ListNode* d = new ListNode(4);
    //ListNode* e = new ListNode(5);
   
    //a->next = b;
    //b->next = c;
    //c->next = d;
    //d->next = e;
    //e->next = nullptr;

    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(5);
    a->next = b;
    b->next = nullptr;


    Solution s1;
    ListNode* ans = s1.reverseBetween(a, left, right);
    
    s1.printList(ans);
    
    return 0;
}
