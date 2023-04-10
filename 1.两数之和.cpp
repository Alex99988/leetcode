/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0;i < nums.size();i++){
            int num = nums[i];
            auto pos = hash.find(target - num);//这边的find返回值是一个迭代器，zhi xin a g
            if(pos == hash.end()){
                hash[num] = i;
            }else{
                ans.push_back(pos->second);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

