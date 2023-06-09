/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *交换左右孩子交换的是指针利用前序和后续遍历，不能用中序遍历
 递归：
 1、返回值和参数
 2、确定终止条件
 3、单层的处理逻辑
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        //递归的方式
        if(root == NULL) return root;//不一定是根节点
        swap(root->left,root->right);//这边交换的是指针
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

