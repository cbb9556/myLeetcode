#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//3 DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        // 第一维n个状态：n天，第二维2个状态：0（不持有股票）、1（持有股票）
        // 第三维3个状态：0、1、2分别表示完成的交易次数
        int dp[n][2][3];

        // 初始化
        dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 0;
        dp[0][1][0] = dp[0][1][1] = dp[0][1][2] = -prices[0];
        for(int i = 1; i < n; i++)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
            dp[i][1][2] = 0;
        }
        return max(dp[n - 1][0][2], dp[n - 1][0][1]);
    }
};

//2 DP
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;

        // 第一维n个状态：n天
        //第二维5个状态：0-4分别表示 未交易、买入一次、完成交易1次、买入2次、完成交易2次
        int dp[n][5];

        // 初始化
        dp[0][0] = dp[0][2] = dp[0][4] = 0;
        dp[0][1] = dp[0][3] = -prices[0];

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return max(dp[n - 1][2], dp[n - 1][4]);
    }
};

//1 DP
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;

        // 5个状态：0-4分别表示 未交易、买入一次、完成交易1次、买入2次、完成交易2次
        int dp[5];

        // 初始化
        dp[0] = 0;
        dp[1] = -prices[0];
        dp[2] = INT_MIN;
        dp[3] = INT_MIN;
        dp[4] = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            dp[0] = 0;
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return max(dp[2], dp[4]);
    }
};