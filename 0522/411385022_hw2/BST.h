#ifndef BST_H
#define BST_H

#include <utility>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST
{
  private:
    TreeNode* root_;

  public:
    explicit BST(TreeNode* root) : root_(root) {}
    void Build(std::vector<int>);
    void Append(int);
    std::pair<int, int> Find(int) const;
};

#endif // BST_H