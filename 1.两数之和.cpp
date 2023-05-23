/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hash;//初始化一个哈希表
//         vector<int> ans;//初始化结构数组
//         for (int i = 0;i < nums.size();i++){
//             int num = nums[i];
//             auto pos = hash.find(target - num);//这边的find返回值是一个迭代器，用auto来接收
//             if(pos == hash.end()){
//                 hash[num] = i;
//             }else{
//                 ans.push_back(pos->second);
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maphash;//初始化一个哈希表
        vector<int> ans;//初始化结构数组
        for (int i = 0;i < nums.size();i++) {
            int num = nums[i];
            auto iter = maphash.find(target - num);//这边的find返回值是一个迭代器，用auto来接收
            if (iter == maphash.end()) {//没有找到
                maphash.insert(pair<int,int>(nums[i],i));//不相等那么插入下
            }
            else {
                return vector<int>{iter->second,i};//大括号直接返回元素
            }
        }
        return {};
    }
};
// @lc code=end
int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    cout << "Indices: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
