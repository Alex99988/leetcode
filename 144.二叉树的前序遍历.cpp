/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    //递归的方式解决问题
    //定义需要的辅助函数
    // void traversal(TreeNode* cur, vector<int>& vec) {
    //     //确定终止条件
    //     if (cur == NULL) return;
    //     //确定单层递归的逻辑-中左右
    //     vec.push_back(cur->val);
    //     traversal(cur->left, vec);
    //     traversal(cur->right, vec);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root,res);
    //     return res;
    // }

    //迭代的方式实现前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;//定义存放结果的栈
        stack<TreeNode*> st;//定义一个空栈（注意是存放的指针类型）
        if (root == NULL) return res;
        st.push(root);//将根节点压入空栈
        //进入循环直到栈为空
        while (!st.empty())
        {
            //遵循中右左的顺序
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);//写入结果的关键部分
            if (node->right) st.push(node->right);//右
            if (node->left) st.push(node->left);//左
        }
        return res;




    }



};
// @lc code=end

