/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0));//初始化一个n*n的数组
        int startx = 0, starty = 0, count = 1;
        int loop = n / 2;
        int offset = 1;

        while (loop--)
        {
            int i = startx;
            int j = starty;
            for (j = starty; j < n - offset; j++)//边界问题的处理
            {
                ans[i][j] = count++;
            }
            for (i = startx; i < n - offset; i++)
            {
                ans[i][j] = count++;
            }
            for (; j > starty; j--)
            {
                ans[i][j] = count++;
            }
            for (; i > startx; i--)
            {
                ans[i][j] = count++;
            }

            startx++;
            starty++;
            offset++;
        }
        if (n % 2) {
            ans[n / 2][n / 2] =count;
        }
        return ans;

    }
};
// @lc code=end

