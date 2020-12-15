#include <string>
#include <vector>
using namespace std;
class Solution {
public:
// 二维DP
int numDistinct(string s, string t) {
    int s_size = s.size(), t_size = t.size();
    vector<vector<long>> dp(t_size + 1, vector<long>(s_size + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 0; i < t_size; ++i) {
        for (int j = 0; j < s_size; ++j) {
            if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
            else dp[i+1][j+1] = dp[i+1][j]; 
        }
    }
    return dp[t_size][s_size];
}
};

class Solution2 {
public:
// 一维DP
int numDistinct(string s, string t) {
    int s_size = s.size(), t_size = t.size();
    vector<long> dp(s_size + 1, 1);
    for (auto c : t) {
        auto last = dp[0]; // 记录上一个值
        dp[0] = 0;
        for (int j = 0; j < s_size; ++j) {
            auto record = dp[j+1];
            if (s[j] == c) dp[j+1] = last + dp[j];
            else dp[j+1] = dp[j];
            last = record;
        }
    }
    return dp.back();
}
};