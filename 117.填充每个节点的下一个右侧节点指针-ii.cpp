/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//将完全二叉树变成了普通二叉树，本质上没有区别
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* nodePre;
            Node* node;
            for(int i = 0; i < size; i++){
                if(i == 0){
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    //更新nodePre节点
                    nodePre = node;
                    // if(node->left) que.push(node->left);
                    // if(node->right) que.push(node->right);
                }
                //将左右节点入栈再进行之后的操作
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                // nodePre->next = NULL;
            }
            nodePre->next = NULL;
        }
        return root;
    }
};
// @lc code=end

