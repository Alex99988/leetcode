/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //返回的是数字，利用双指针法进行解决,必须先要排好序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;//返回的是二维数组
        //a=nums[i];b=nums[left];c=nums[right]
        for (int i = 0;i < nums.size();i++) {
            //对a分别进行剪枝和去重
            if (nums[i] > 0) {
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;//跳过当前循环
            }
            //初始化b和c
            int left = i+1;
            int right = nums.size() - 1;
            //双指针常用的条件
            while (left < right)
            {
                //判断大小双向移动的操作；分别进行减枝的操作
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }else{
                    res.push_back(vector<int>{ nums[i] ,nums[left] ,nums[right] });
                    //循环结束的本体,同时移动两个指针
                    //去重的逻辑
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

