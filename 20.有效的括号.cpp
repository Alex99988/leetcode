/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char>  parsed;
        //通过C++内置的迭代器来实现对于每一个元素的遍历
        //for(数据类型 变量名称：传入数据串)
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parsed.push(c);
            }
            else {
                if (parsed.empty()) {
                    return false;
                }
                //异常情况，判断是否栈为空
                //其中是判断左括号和右括号是否一致
                char top = parsed.top();             
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')){
                    parsed.pop();//将元素从左括号中取出去
                }else{
                    return false;
                }
            }
        }
        return parsed.empty();
    }
};
// @lc code=end

//首先判断是否是左括号---->入栈