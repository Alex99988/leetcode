/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //用map来定义一个哈希表
        unordered_map<int, int> umap;//初始化的数值为0
        int count = 0;//定义返回数值为0
        //遍历数组A和数组B想加之和
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - c - d) != umap.end()) {
                    count += umap[0 - c - d];
                }
            }
        }
        return count;
    }
};
// @lc code=end

