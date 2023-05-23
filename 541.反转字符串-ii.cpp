/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        //根据规则模拟题型
        for(int i=0;i<s.size();i+=2*k){
            if((i+k)<=s.size()){
                reverse(s.begin()+i,s.begin()+i+k);//注意输入的是迭代器
            }else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};
// @lc code=end

