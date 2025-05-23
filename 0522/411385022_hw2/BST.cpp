#include "BST.h"

using namespace std;

void BST::Build(vector<int> data)
{

    for (const int& num : data)
    {
        Append(num);
    }
}

void BST::Append(int num)
{
    TreeNode* current = root_;

    while (true)
    {
        if (num < current->val)
        {
            if (current->left == nullptr)
            {
                current->left = new TreeNode(num);
                break;
            }
            current = current->left;
        }
        else if (num > current->val)
        {
            if (current->right == nullptr)
            {
                current->right = new TreeNode(num);
                break;
            }
            current = current->right;
        }
    }
    return;
}

pair<int, int> BST::Find(int target) const
{
    TreeNode* current = root_;

    while (true)
    {
        if (target < current->val)
        {
            if (current->left == nullptr)
            {
                break;
            }
            current = current->left;
        }
        else if (target > current->val)
        {
            if (current->right == nullptr)
            {
                break;
            }
            current = current->right;
        }
        else
        {
            int l = current->left == nullptr ? 0 : current->left->val;
            int r = current->right == nullptr ? 0 : current->right->val;
            return {l, r};
        }
    }
    return {-1, -1};
}