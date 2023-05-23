/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *利用c++中的优先级队列
 * [347] 前 K 个高频元素
 */
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
 // #include <priority_queue>
using namespace std;
// @lc code=start
class Solution {
public:
    //定义自己的小顶堆比较函数
    class myComparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //如何求每个数字出现的频率[key,val]
        unordered_map<int, int>map;
        for (int a : nums) {
            map[a]++;
        }
        //如何进行排序[val]维护k个有序的集合——大顶堆，小顶堆heap（二叉树根节点是最大的元素）
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> que;
        //用迭代器的方式来对小顶堆进行插入和删除操作
        for(auto it=map.begin();it!=map.end();it++){
            que.push(*it);
            if(que.size()>k){
                que.pop();
            }
        }

        //将小顶堆输入到结果数组当中
        vector<int> res(k);//只有k个数字元素
        //从后往前依次填充
        for(int i = k-1;i>=0;i--){
            res[i]=que.top().first;
            que.pop();
        }
        return res;



    }
};
// @lc code=end

