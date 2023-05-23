/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *利用队列的数据结构
 *三个辅助函数
 *1、pop()
 *2、push()
 *3、getMaxNum
 *不能使用优先级队列
 *注意和优先级队列的区分
 *单调队列（自己维护的一个单调队列）
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <string>
#include <stack>
using namespace std;
// @lc code=start

class Solution {
private:
    //创建一个自定的单调栈
    class myQueue {
    public:
        deque<int> que;
        void pop(int val) {
            if (!que.empty() && val == que.front()) {
                que.pop_front();
            }
        }
        //依次从结尾弹出不需要的元素
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }
        //最大值就是队首的元素
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //选定需要维护的元素
        //只是维护可能成为最大值的元素
        myQueue que;
        vector<int> res;
        //将前k个元素取出放入队列
        for (int i = 0;i < k;i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());//记录前K个元素的最大值
        //开始移动滑动窗口
        for (int i = k;i < nums.size();i++) {
            que.pop(nums[i - k]);//滑动窗口移除最前面的元素
            que.push(nums[i]);//滑动窗口前加入最后面的元素
            res.push_back(que.front());
        }
        return res;
    };

};
// @lc code=end

