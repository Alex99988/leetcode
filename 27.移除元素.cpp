/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int size = nums.size();
        for (int fast = 0;fast < size;fast++) {
            if (nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

