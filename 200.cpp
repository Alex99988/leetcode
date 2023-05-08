#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //先遍历数组当中的所有元素
        int cnt = 0;
        for (int i = 0;i < grid.size();++i) {
            for (int j = 0;j < grid[0].size();++j) {
                if (grid[i][j] == '1') {
                    //岛屿数量加1并且开始进行深度遍历操作
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        //开始使用深度优先搜索进行遍历操作
        int m = grid.size();
        int n = grid[0].size();
        //判断是否越界或数值为0进行返回操作
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0') {
            return;
        }
        //需要将特定值化为0
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }
};
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