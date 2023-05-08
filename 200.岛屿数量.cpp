/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 * 知识：深度优先搜索，浸没操作
 * 注意：要有返回值
 * 注意：使用递归的思想要有防止栈溢出的思想
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        // 遍历整个网格
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 当遇到陆地时，进行深度优先搜索
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++; // 岛屿数量加一
                }
            }
        }
        return count;
    }

    // 深度优先搜索函数
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // 当下标越界或遇到水域时，返回（终止条件）
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0'; // 标记为已访问
        // 对上下左右四个方向进行深度优先搜索
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

// @lc code=end

int main() {
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int a = solution.numIslands(grid);
    cout << "Number of islands: " << a << endl;

    return 0;
}