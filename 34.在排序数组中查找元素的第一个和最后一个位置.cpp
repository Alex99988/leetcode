/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int> { -1, -1 };
        int lower = lower_bound(nums, target);
        int higher = upper_bound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target) {
            return vector<int> { -1, -1 };
        }
        return vector<int> { lower, higher };
    }
    //寻找下限的辅助函数
    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid + 1;//加一是为了排除mid
            }
        }
        return l;
    }
    //寻找上限的辅助函数
    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;//加一是为了排除mid
            }
        }
        return l;
    }

};
// @lc code=end

