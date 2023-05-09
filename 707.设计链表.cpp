/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
// @lc code=start
class MyLinkedList {
public:
    //定义链表节点结构体
    struct linkedList
    {
        int val;
        linkedList* next;
        //构造函数中应该为val(val)
        linkedList(int val) :val(val), next(nullptr) {};//结构体构造函数
    };
    //构造函数
    MyLinkedList() {
        size = 0;
        dummyhead = new linkedList(0);
    }

    int get(int index) {
        if (index < 0 || index > size - 1) {
            return -1;
        }
        linkedList* cur = dummyhead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        linkedList* newNode = new linkedList(val);
        newNode->next = dummyhead->next;
        dummyhead->next = newNode;
        size++;
    }

    void addAtTail(int val) {
        linkedList* newNode = new linkedList(val);
        linkedList* cur = dummyhead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        //异常判断
        if (index > size) {
            return;
        }
        if (index < 0) {
            index = 0;
        }
        //正常的插入值域操作
        linkedList* newNode = new linkedList(val);
        linkedList* cur = dummyhead;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        linkedList* cur = dummyhead;
        while (index--)
        {
            cur = cur->next;
        }
        linkedList* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        size--;
    }

    void printList() {
        linkedList* cur = dummyhead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << ' ';
            cur = cur->next;
            cout<<endl;
        }

    }

private:
    int size = 0;
    linkedList* dummyhead;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
 // @lc code=end

