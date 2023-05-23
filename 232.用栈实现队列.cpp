/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
public:
    stack<int> stIn;//定义两个栈
    stack<int> stOut;
    
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        //判断出栈是否为空，取出入栈中的所有元素 
        if(stOut.empty()){
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }    
        }
        int result = stOut.top();
        stOut.pop();
        return result;

    }
    
    int peek() {
        int res = this->pop();//直接使用现有的pop函数
        stOut.push(res);
        return res;
    }
    
    bool empty() {
        return stIn.empty()&&stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

