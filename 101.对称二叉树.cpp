/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    //定义辅助函数，并对其进行操作
    bool compare(TreeNode* left,TreeNode* right) {
        //避免操作空指针
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val!=right->val) return false;

        //此时就是左右节点不为空，并且数值相同的情况
        //此时才开始做递归，开始下一层的判断
        bool  outside = compare(left->left,right->right);
        bool  inside = compare(left->right, right->left);
        bool res = outside && inside;
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;//防止对空指针进行操作
        return compare(root->left,root->right);

    }
};
// @lc code=end

