/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;//初始化一个哈希表
        unordered_set<int> numset(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (numset.find(num) != numset.end())
            {
                res.insert(num);
            }

        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

