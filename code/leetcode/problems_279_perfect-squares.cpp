
/*
data-time 2020-03-11 14:14:53
题目描述:
279. 完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/* 主要思路：使用动态规划的办法，计算1-n的所有的最小次数；是和它之差为平方数的和
时间复杂度O(n^2);空间复杂度O(n);

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
    int numSquares(int n) {
        vector<int > res(n+1,0);

        for(int i=1;i<=n;++i){
            /* 查找最小次数 */
            int temp_min=INT_MAX;
            for(int j=1;j*j<=i;++j){
                temp_min=min(temp_min,res[i-j*j]);
            }
            res[i]=temp_min+1;
        }
        return res[n];
    }
};

int main(int argc char* argv[]){
    Solution a;
    a.numSquares(10);
    return 0;
}

/**
优质代码1：广度优先遍历
空间复杂度O(n^2);时间复杂度O()
class Solution {
public:
    int numSquares(int n) {
    vector<bool> v(n,false);//访问数组，标记已经用过的数，避免重复判断
    queue<int> q;//队列
    int step = 0;
    q.push(n);
    step = bfs(q,v,n,step);//bfs
    return step;
    }
    int  bfs(queue<int> &q,vector<bool> &v,int &n,int &step)
    {
        while(!q.empty())
        {
            int size = q.size();
            step++;//每一层+1。多一个步骤
            while(size>0)//一层一层搜索,这里的size是上一层的size,size为0则进入下一层
            {
                int val = q.front();//取出队头
                q.pop();//弹出队头
                //计算对应的头部
                for(int i = 1; val - i * i >= 0;i++)
                {
                    int temp = val - i * i;
                    if(temp == 0)///找到了
                    {
                        return step;
                    }
                    if(!v[temp])////未访问的数入队，进行下一层判断
                    {
                        q.push(temp);
                        v[temp] = true;////置为访问过
                    }
                }
                size--;
            }

        }
        return -1;
    }
};
//官方题解：
//优质解析：
https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/
https://leetcode-cn.com/problems/perfect-squares/solution/bfs-dong-tai-gui-hua-shu-xue-by-powcai/

*/
