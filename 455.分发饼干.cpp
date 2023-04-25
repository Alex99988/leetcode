/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //对孩子胃口以及饼干大小进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;//孩子索引
        int cookies = 0;//饼干索引
        while (child < g.size() && cookies < s.size()) {
            if (g[child] <= s[cookies]) {
                child++;
            }
            cookies++;
        }
        return child;
    }
};
// @lc code=end

