/*
解这道题我们首先要分一下几个步骤来看：

1、确定状态方程

我们使用一个二维数组 dp 来存储答案，dp[i][j]的值是从起始点（也就是(0,0)）走到(i, j)的路径数。

2、确定状态转移方程

上面也说到，dp[i][j]的值就是从起始点（也就是(0,0)）走到(i, j)的路径数，那么如何求出这个值，我们就需要确定状态转移方程，我们思考一下，假设我们全都知道dp[i][j]的值，题目中说到，小机器人只能往右或者往下，那么dp[i][j]的值就是第 i 行第 j 列这个格子的上面那个格子的值加上左边那个格子的值，也就是dp[i][j] = dp[i-1][j] + dp[i][j-1]，因为这两个格子都可以走到dp[i][j]这个格子，那么他们的路径数之和就是dp[i][j]的值。

3、确定边界条件
上面说到状态转移方程是dp[i][j] = dp[i-1][j] + dp[i][j-1]，那么当 i == 0 或者 j == 0 的时候会越界，而我们想一下，当 i == 0 或者 j == 0 的时候无外乎就是最上一行或者最左一列，我们在最上一行的路径数只能是一条（因为只能一直往左走），所以 dp[0][j]的值全为 1，同理最左一列的值也是1（因为只能一直往下走），其余的值按照状态转移方程就可以填满了，最后返回最右下角的值（dp[n-1][m-1]）就可以了。

注意：题目中的 n 是行row，而 m 才是列column。
*/

#include <vector>
using namespace std;

class Solution {
public:
    // 状态定义：dp[i][j]是到达i，j的路径数。
    // 递推方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]。向右走一步或者向下走一步就可以到达i，j的方案数之和
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else  dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
