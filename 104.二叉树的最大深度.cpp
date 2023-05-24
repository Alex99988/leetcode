/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
 // #include <priority_queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
// @lc code=start
/**
 * Definition for a binary tree node.
 * 可以用后序遍历，层序遍历
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int maxDepth(TreeNode* root) {
    //     queue<TreeNode*> que;
    //     if(root) que.push(root);
    //     int depth = 0;
    //     while (!que.empty())
    //     {
    //         int size = que.size();
    //         //层序遍历每次向下遍历一层那么depth+1
    //         depth++;
    //         while (size--)
    //         {
    //             TreeNode* node = que.front();
    //             que.pop();
    //             if(node->left) que.push(node->left);
    //             if(node->right) que.push(node->right);
    //         } 
    //     }
    //     return depth;

    // }
    //后序遍历
    //设置辅助函数
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        //递归左子树
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        int depth = 1 + max(leftDepth, rightDepth);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        //确定终止条件
        if (root == NULL) return 0;
        //return getDepth(root);

        //简洁的写法，本质上是后续遍历
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
// @lc code=end

