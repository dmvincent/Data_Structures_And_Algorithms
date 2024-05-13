#include <iostream>
#include "include/Solution.hpp"
//#include "include/ListNode.hpp"
#include <vector>

int main() {
    Solution s1;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = nullptr;

    ListNode* ans = new ListNode();
    ans = s1.middleNode(a);
    std::cout << ans->val << std::endl;
    return 0;
}
