/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        //用字符串定义栈
        string res;
        for (char c : s) {
            if (res.empty() || res.back() != c) {
                res.push_back(c);
            }
            else {
                res.pop_back();
            }
            // return res;不在for循环内进行返回
        }
        return res;
    }
};
// @lc code=end

