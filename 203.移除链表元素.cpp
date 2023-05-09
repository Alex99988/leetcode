/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}//构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //虚拟节点法
        ListNode* dummyhead = new ListNode(0);//初始化虚拟头节点
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;//删除节点操作
            }else{
                cur = cur->next;
            }
        }
        head = dummyhead->next;//在删除之前进行更新操作
        delete dummyhead;
        return head;

    }
};
// @lc code=end

