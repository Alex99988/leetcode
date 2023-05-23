/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;//存放结果的数组
        //将数组中的数值排好序
        sort(nums.begin(), nums.end());
        //k,i,left,right定义这4个指针
        for (int k = 0;k < nums.size();k++) {
            //对于k进行剪枝操作
            if (nums[k] > target && nums[k] >= 0) {
                break;
            }
            //k去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k+1 ;i < nums.size();i++) {
                //i减枝
                if ((nums[i] + nums[k] > target) && nums[i] >= 0) {
                    break;
                }
                //i去重
                if (i > k+1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                //进入双指针循环
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    }//防止int溢出
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        //满足条件将数值加入到答案
                        res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        //剪枝操作
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;
                        right--;
                        left++;
                    }
                }
            }            
        }
        return res;
    }
};
// @lc code=end

