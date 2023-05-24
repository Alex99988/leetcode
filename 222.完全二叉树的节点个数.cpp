/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
//采用后续遍历的方式更加简洁
class Solution {
public:
    //普通二叉树解法
    int countNodes(TreeNode* root) {
        //迭代的终止条件_
        if(root== NULL) return 0;
        //左-右-中   O(n)
        return countNodes(root->left)+countNodes(root->right)+1;

        //完全二叉树解法，比较左右递归深度是否相同，之后通过
        


    }
};
// @lc code=end

