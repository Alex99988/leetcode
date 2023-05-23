/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    //使用队列的方式进行广度优先搜索
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;//定义一个队列
        //vector<int> vec;不能定义在具体的操作函数之外
        vector<vector<int>> res;
        //初始化que,需要传入root节点
        if(root) que.push(root);
        while (!que.empty()) {
            int size = que.size();//定义半静态的队列大小
            vector<int> vec;
            while (size--)
            {
                TreeNode *node = que.front();
                vec.push_back(node->val);//拿出队列中的特定的数值
                que.pop();
                if(node->left) que.push(node->left);//需要防止对空节点进行操作
                if(node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
    // vector<vector<int>> levelOrder(TreeNode* root) {

    // }
};
// @lc code=end

