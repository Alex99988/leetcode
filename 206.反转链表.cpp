/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
 //双指针法
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* cur = head;//避免丢失数据
//         ListNode* pre = NULL;
//         ListNode* tmp;//放在循环外进行初始化
//         while (cur != NULL)
//         {
//             tmp = cur->next;
//             cur->next = pre;//反转的核心
//             pre = cur;//更新pre前
//             cur = tmp;//更新cur后
//         }
//         return pre;

//     }
// };
//递归法-在函数中引用自己这个函数本身
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur==NULL){
            return pre;
        }
        //忘记反转操作,先保存后反转       
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur,tmp);
    }
    ListNode* reverseList(ListNode* head) {

        return reverse(NULL,head);

    }
};
// @lc code=end

