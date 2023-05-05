/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return 0;
        }
        int m = board.size(), n = board[0].size();
        int count = 0;
        // 遍历整个网格
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 当遇到陆地时，进行深度优先搜索
                if (board[i][j] == 'X') {
                    dfs(board, i, j);
                    count++; // 岛屿数量加一
                }
            }
        }
        return count;
    }

    // 深度优先搜索函数
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // 当下标越界或遇到水域时，返回
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '.') {
            return;
        }
        grid[i][j] = '.'; // 标记为已访问
        // 对上下左右四个方向进行深度优先搜索
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
// @lc code=end

