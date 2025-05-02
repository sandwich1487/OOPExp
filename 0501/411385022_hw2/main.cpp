#include <iostream>

#include "list-node.h"

using namespace std;

int Find_m(int);
bool IsOk(int, int);

int main()
{
    int n = -1;
    int m = 0;
    while (true)
    {
        cin >> n;
        if (n == -1) break;
        if (n < 13) continue;

        m = Find_m(n);

        if (m != 0)
        {
            cout << m << endl;
        }
        else
        {
            cout << "No Answer!" << endl;
        }
        cout << endl;
    }
    return 0;
}

int Find_m(int n)
{
    if (n == 13) return 1;
    int m = 3;
    for ( ; m < n; ++m)
    {
        if (IsOk(n, m))
        {
            return m;
        }
    }
    return 0;
}

bool IsOk(int n, int m)
{
    ListNode* head = new ListNode(1);
    constexpr int target = 13;
    // init areas
    ListNode* current = head;
    for (int i = 2; i <= n; ++i)
    {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = head;
    ListNode* last = current;
    current = current->next;

    while (current != last)
    {
        current = current->next;
        delete last->next;
        last->next = current;
        n -= 1;
        for (int i = 1; i < m; ++i)
        {
            last = last->next;
            current = current->next;
        }
        if (current->val == target) break;
    }

    if (n == 1) return true;
    return false;
}