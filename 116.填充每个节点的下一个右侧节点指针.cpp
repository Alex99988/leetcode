/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <limits>
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
在进行单层遍历的时候的时候记录本层的头部节点，遍历的时候让前一个节点指向本次节点
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            Node* nodePre;
            Node* node;
            for (int i = 0;i < size;i++)
            {
                if(i==0){
                    nodePre = que.front();//取出每一层的头节点
                    que.pop();
                    node = nodePre;//将头节点也是重新赋值给node节点
                }else{//处理不是头节点的情况
                    node = que.front();
                    que.pop();
                    nodePre->next = node;//将本层前一个节点指向本节点
                    nodePre = node;//将前一个节点变成本次节点
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            //本层最后一个节点指向NULL
            nodePre->next = NULL;
        }
        return root;

    }
};
// @lc code=end

