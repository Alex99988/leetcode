/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
// @lc code=start
//暴力解决方法
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int sum = 0, ans = INT64_MAX, sublen = 0;
//         for (int i = 0;i < nums.size();i++) {
//             for (int j = i;j < nums.size();j++) {
//                 sum += nums[j];
//                 if (sum >= target)
//                 {   
//                     sublen = j - i + 1;
//                     ans = ans < sublen ? ans : sublen;
//                     break;
//                 }
//             }           
//         }
//         return ans == INT64_MAX ? 0 : ans;
//     }
// };
//滑动窗口法
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ans = INT32_MAX, sublen = 0;//sublen这里是滑动窗口的大小
        int i = 0;
        for (int j = 0;j < nums.size();j++) {
            sum += nums[j];
            while (sum >= target)
            {
                sublen = j - i + 1;
                ans = ans < sublen ? ans : sublen;
                sum -= nums[i++];//精髓之处
            }

        }
        return ans == INT32_MAX ? 0 : ans;
    }
};
// @lc code=end

