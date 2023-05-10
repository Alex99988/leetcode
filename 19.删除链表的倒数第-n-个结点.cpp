/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
using namespace std;
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
 //利用双指针法进行解决
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummhead = new ListNode(0);
        dummhead->next = head;
        ListNode* fast = dummhead;
        ListNode* slow = dummhead;
        //向后走n步数
        while (n-- && (fast != NULL)) {
            fast = fast->next;
        }
        //再走一步
        fast = fast->next;
        //同时再次移动slow和fast
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next->next;
        slow->next = tmp;
        return dummhead->next;

    }
};
// @lc code=end

