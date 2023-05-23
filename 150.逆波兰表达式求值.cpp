/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *后续遍历，方便计算机的顺序计算
 * [150] 逆波兰表达式求值
 */
#include <vector>
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //遇到操作符的方式，就去站里面取出元素
        //进行相关操作之后再次入站
        //初始化栈
        stack<long long> st;
        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (c == "+") st.push(num2 + num1);
                if (c == "-") st.push(num2 - num1);
                if (c == "*") st.push(num2 * num1);
                if (c == "/") st.push(num2 / num1);
            }else{
                st.push(stoll(c));
            }
        }
        long long res = st.top();
        st.pop();
        return res;



        //若是数字元素，那么将取出相关元素，注意类型的转换

        //弹出最后的元素
    }
};
// @lc code=end

