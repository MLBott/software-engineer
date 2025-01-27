/* Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3 */

#include <stack>
#include <optional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (!stk.empty() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                if (--k == 0)
                    return stk.top()->val;
                cur = stk.top()->right;
                stk.pop();
            }
        }

        return -1;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int init = 0;
        auto opt = dfs(root, k, init);

        return opt ? opt.value() : -1;
    }

private:
    optional<int> dfs(TreeNode* node, int k, int& cur) {
        if (!node)
            return {};

        if (auto opt = dfs(node->left, k, cur))
            return opt;

        if (++cur == k) {
            return { node->val };
        }

        if (auto opt = dfs(node->right, k, cur))
            return opt;

        return {};
    }
};