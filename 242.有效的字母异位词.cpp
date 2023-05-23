/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (char c : s){
            record[c-'a']++;
        }
        for (char c : t) {
            record[c - 'a']--;
        }
        for(int i =0;i<26;i++){
            if (record[i])
            {
                return false;
            }
            
        }
        return true;
    }
};
// @lc code=end

