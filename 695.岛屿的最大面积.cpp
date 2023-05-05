/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        // 遍历整个网格
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 当遇到陆地时，进行深度优先搜索
                if (grid[i][j] == 1) {
                    
                    //count++; // 岛屿数量加一
                    ans = max(ans,dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
    // 深度优先搜索函数
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // 当下标越界或遇到水域时，返回
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        //初始化当前岛屿面积为1
        int cnt = 1;
        grid[i][j] = 0; // 标记为已访问
        // 对上下左右四个方向进行深度优先搜索
        cnt += dfs(grid, i - 1, j);
        cnt += dfs(grid, i + 1, j);
        cnt += dfs(grid, i, j - 1);
        cnt += dfs(grid, i, j + 1);
        return cnt;
    }

};
// @lc code=end

