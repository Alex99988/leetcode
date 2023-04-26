/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
 // @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        //定义左右边界,中间值和开方值
        int l = 1, r = x, mid, sqrt;
        while (l <= r) {
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if (sqrt == mid) {
                return mid;
            }
            else if (mid > sqrt) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};
// @lc code=end

