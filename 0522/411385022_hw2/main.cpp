#include <iostream>
#include <sstream>

#include "BST.h"

using namespace std;

int main()
{
    vector<int> data;
    string buffer;
    stringstream line;
    cout << "Enter numbers: ";
    getline(cin, buffer);
    line.str(buffer);
    for (int a; line >> a; )
    {
        data.push_back(a);
    }

    BST tree(new TreeNode(data[0]));
    data.erase(data.begin());
    cout << "hi";
    tree.Build(data);
    cout << "hi";
    int target;
    while (true)
    {
        cout << "Find the value you want: ";
        cin >> target;
        if (target == -1) break;

        pair<int, int> ans = tree.Find(target);
        int l = ans.first;
        int r = ans.second;
        if (l == -1)
        {
            cout << "The value is not in this binary search tree.\n\n";
            continue;
        }

        cout << "left: ";
        if (l != 0)
        {
            cout << l;
        }
        else
        {
            cout << "null";
        }
        cout << " right: ";
        if (r != 0)
        {
            cout << r;
        }
        else
        {
            cout << "null";
        }
        cout << "\n\n";
    }
    

    return 0;
}