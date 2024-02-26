#include <iostream>
#include "include/Solution.hpp"

int main() {
    // Create List Node
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = nullptr;

    // Create Solution object and return Sorted List without
    // any duplicates
    Solution s1;
    ListNode* ans = s1.deleteDuplicates(a);
    std::cout << ans->val << std::endl;
   
    
    return 0;
}
