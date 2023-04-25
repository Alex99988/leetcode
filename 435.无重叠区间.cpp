/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <iostream>
#include <vector>
#include <list>
using namespace std;
// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            });//将二维数组的每一个区间按照尾部元素的大小升序排列
        int removed = 0, prev = INT_MIN;//初始化要移除的数组和第一个末尾元素
        //遍历数组进行比较
        for (const auto& interval : intervals) {//auto的使用
            if(interval[0]>=prev){
               // ++removed;
                prev = interval[1];
            }else{
                ++removed;
            }
        }
        return removed;



    }
};
// @lc code=end

