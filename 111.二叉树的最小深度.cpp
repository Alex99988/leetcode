/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *当左右孩子均为空，那么便是遍历到最低点了
 * [111] 二叉树的最小深度
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
    //利用后序遍历进行求解，统计高度
    int minDepth(TreeNode* root) {
        //确定终止条件
        if (root == NULL) return 0;
        //进入递归单层循环
        int leftdepth = minDepth(root->left);//左
        int rightdepth = minDepth(root->right);//右
        //排除一开始的左空但是右不为空的情况
        if (root->left == NULL && root->right != NULL) {
            return 1 + rightdepth;
        }
        if (root->right == NULL && root->left != NULL) {
            return 1 + leftdepth;
        }
        //中
        int res = 1 + min(leftdepth, rightdepth);
        return res;
    }
    //利用层次遍历进行求解
    // int minDepth(TreeNode* root) {
    //     queue<TreeNode*> que;
    //     if (root) que.push(root);
    //     int depth = 0;
    //     while (!que.empty())
    //     {
    //         int size = que.size();
    //         depth++;
    //         while (size--)
    //         {
    //             TreeNode* node = que.front();
    //             que.pop();
    //             if (node->left) que.push(node->left);
    //             if (node->right) que.push(node->right);
    //             if (node->left == NULL && node->right == NULL) return depth;
    //         }
    //     }
    //     return depth;

    // }
};
// @lc code=end

