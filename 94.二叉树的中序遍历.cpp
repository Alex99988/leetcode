/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *1、访问节点
 *2、处理节点

 访问和处理的元素不同
 * [94] 二叉树的中序遍历
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
    // void travelsal(TreeNode* cur, vector<int>& res) {
    //     //定义终止条件
    //     if (cur==nullptr) return;
    //     //定义单层递归逻辑——左中右
    //     travelsal(cur->left,res);
    //     res.push_back(cur->val);
    //     travelsal(cur->right, res);

    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     travelsal(root,res);
    //     return res;
    // }
    //迭代的方式实现中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;//重点——用栈来记录遍历过的元素
        TreeNode* cur = root;//重点——定义一个指针来遍历二叉树
        while (cur != NULL || !st.empty()) {
            //首先判断当前节点是否为空，不为空那么处理左节点,并且进行入栈操作
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            }
            else {
                //从栈中取出元素，还用cur来进行记录
                cur = st.top();
                st.pop();//及时弹出
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
// @lc code=end

