#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int n = 0) : val(n), next(nullptr) {}
};


#endif // LISTNODE_H