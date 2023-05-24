/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
 // #include <priority_queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        if (root) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            while (size--)
            {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                //将孩子节点添加到队列
                for (int i = 0;i < node->children.size();i++) {
                    if (node->children[i]) que.push(node->children[i]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @lc code=end

