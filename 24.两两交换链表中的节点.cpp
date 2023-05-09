/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;//虚拟头节点
        ListNode* cur = dummyhead;
        //交换就是判断1，2节点应该不为空
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode* tmp1 = cur->next;
            ListNode* tmp3 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp3;
            //将cur向前移动两位
            cur = cur->next->next;
        }
        return dummyhead->next;


    }
};
// @lc code=end

