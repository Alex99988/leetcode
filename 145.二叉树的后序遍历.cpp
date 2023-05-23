/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // //定义辅助函数
    // void traversal(TreeNode * cur,vector<int>& vec){
    //     //定义终止条件
    //     if(cur==NULL) return;
    //     //定义单层递归逻辑——左右中
    //     traversal(cur->left,vec);
    //     traversal(cur->right, vec);
    //     vec.push_back(cur->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }
    //迭代的方式实现后序遍历
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        //判断节点是否为空
        if(root == NULL) return res;
        st.push(root);
        while (!st.empty())
        {
            TreeNode * node = st.top();
            st.pop();
            res.push_back(node->val);//将数值写入结果中
            if(node->left) st.push(node->left);//右---需要先判断是否为空判断
            if(node->right) st.push(node->right);//左
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};
// @lc code=end

