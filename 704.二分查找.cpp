/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left<=right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid]<target)
            {
                left=mid+1;
            }else if(nums[mid]>target){
                right = mid-1;
            }else{
                return mid;
            }
            
        }
        return -1;
        
    }
};
// @lc code=end
int main() {
    Solution solution;
    vector<int> nums = { -1, 0, 3, 5, 9, 12 };
    int target = 9;

    int result = solution.search(nums, target);
    cout << "The target " << target << " is found at index: " << result << endl;

    target = 2;
    result = solution.search(nums, target);
    cout << "The target " << target << " is found at index: " << result << endl;

    return 0;
}
