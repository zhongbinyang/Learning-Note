
/*
data-time 2020-03-12 14:14:53
题目描述:
287. 寻找重复数

给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2
示例 2:

输入: [3,1,3,4,2]
输出: 3
说明：

不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-duplicate-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/* 主要思路：1. 暴力大法：直接遍历每个数查看后面的数是否又重复。没有则下一个，有就直接返回
时间复杂度O(n^2);空间复杂度O(1);
2. 使用快慢指针；将数组设置成环，使用快慢指针，当两者指向的结果相同时，找到重复
此时必定在环内。因此再从起点开始，遍历所有的直到相遇
时间复杂度O(n);空间复杂度O(1);

 */
#include <cmath>
#include <cctype>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <cstdint>

using namespace std;


//关闭流输出
static auto static_lambda = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;++i){
            int temp_k=nums[i];
            for(int j=i+1;j<len;++j){
                if(temp_k==nums[j]){
                    return temp_k;
                }
            }
        }
        return 1;
    };
    int findDuplicate(vector<int>& nums){
        //查找相遇点
        int fast=0,slow=0;
        /* 注意这里的条件控制，直接写条件会跳过开始 */
        while(true){
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow) break;
        }
        fast=0;
        while(true){
            fast=nums[fast];
            slow=nums[slow];
            if(fast==slow) break;
        }
        return slow;
    }
};

int main(int argc char* argv[]){
    Solution a;
    a.numSquares(10);
    return 0;
}

/**
优质代码1：使用二分法统计数目并进行查找；
时间复杂度O(nlogn) 空间复杂度O(0)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (int num:nums) {
                if (num <= mid) {
                    cnt++;
                }
            }

            if (cnt > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
//官方题解：
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/
//优质解析：
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/jie-ti-guan-jian-ru-he-zhuan-huan-wei-floyd-suan-f/

*/
