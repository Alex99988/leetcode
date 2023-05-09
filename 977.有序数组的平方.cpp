/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
//暴力解法
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for (int i = 0;i < nums.size();i++) {
//             nums[i] *= nums[i];
//         }
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };
//双指针解法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1;i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]){
                ans[k--] = nums[i] * nums[i];
                i++;
            }else{
                ans[k--] = nums[j] * nums[j];
                j--;
            }
        }
      
        return ans;
    }
};
// @lc code=end

