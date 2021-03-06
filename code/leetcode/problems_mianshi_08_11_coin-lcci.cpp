
/* 
data-time 2020-04-23 18:49:53


题目描述:

面试题 08.11. 硬币

硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:

 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
示例2:

 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 
/**
主要思路:
创建一个长度为n的数组
dp[i]表示其值为i时存在的方法总数
dp[i]=dp[i-1]+dp[i-5]+dp[i-10]+dp[i-25]

注意为了避免重叠的子问题，每次只添加一种数据
时间复杂度O(n);空间复杂度O(n);
 */
#include <string>
#include <cstring>
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


class Solution {
public:
    int dx[4]={1,5,10,25};
    int waysToChange(int n) {
        if(n<1) return 0;
        long dp[n+1];
        memset(&dp,0,(n+1)*sizeof(long));
        //0肯定右方法
        dp[0]=1;
        for(int i=0;i<4;++i){
            for(int j=dx[i];j<=n;++j){
                dp[j]+=dp[j-dx[i]];
                dp[j]%=1000000007;
            }
        }
        return dp[n];
    }
};

//关闭流输出
static auto static_lambda = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

int main(int argc,char* argv[]){
    Solution a;
    vector<int> temp={0,2,1,-6,6,-7,9,1,2,0,1};
    a.waysToChange(5);
    return 0;
}
/*
优质解析1:利用因式分解和组合；因为任何一个数都是1，5，10，25组成；只要计算他们的组成数就可以了
时间复杂度O(n);空间复杂度O(1);

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int waysToChange(int n) {
        int ans = 0;
        //
        for (int i = 0; i * 25 <= n; ++i) {
            //计算除开25之后额剩余因子；即i个25
            int rest = n - i * 25;
            //计算需要10的个数
            int a = rest / 10;
            //计算需要5的个数
            int b = rest % 10 / 5;
            //计算种类数目
            ans = (ans + (long long)(a + 1) * (a + b + 1) % mod) % mod;
        }
        return ans;
    }
};
//官方题解：
https://leetcode-cn.com/problems/coin-lcci/solution/ying-bi-by-leetcode-solution/
//优质解析1:
https://leetcode-cn.com/problems/coin-lcci/solution/c-wan-quan-bei-bao-by-matt-11-2/
*/