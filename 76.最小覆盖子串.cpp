/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //定义两个数组，其中chars存放T中每个字符存在的个数；
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);
        //先统计T中的字符情况（遍历）
        for (int i = 0;i < t.size();++i) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        //移动滑动窗口，不断更改统计数据
        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        //利用滑动窗口的方式遍历s字符串这边的r表示字符串S的右边界
        for (int r = 0;r < s.size();++r) {
            if (flag[s[r]]) {
                if (--chars[s[r]] >= 0) {
                    ++cnt;
                }
                //如果这会s中已经全部满足包含T中的所有条件--更新左边界和最小size
                while (cnt == t.size()) {
                    if (r - l + 1 < min_size) {
                        min_l = l;
                        min_size = r - l + 1;
                    }
                    //尝试移动左边界，在不影响结果的情况下获得最短字符子串
                    if (flag[s[l]] && ++chars[s[l]] > 0) {
                        cnt--;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
// @lc code=end
int main()
{
    string s = "afhkfha";
    string t = "dgvgad";
    Solution so;
    string h = so.minWindow(s, t);
}