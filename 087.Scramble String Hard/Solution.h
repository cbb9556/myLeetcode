#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        if (s1.empty()) return true;
        
        int N = s1.size();

        vector<vector<vector<bool> > > dp(N + 1, vector<vector<bool> >(N, vector<bool>(N, false)));
        //边界条件，当长度是1的时候，dp的真假，有单个字符是否相等来决定
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        //长度为2的字符串，
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i < N && i + len - 1 < N; ++i) {
                for (int j = 0; j < N && j + len - 1 < N; ++j) {
                    for (int k = 1; k < len; ++k) {
                        //当前长度为k的 两个划分 是否都是真
                        if (dp[k][i][j] && dp[len - k][i + k][j + k]) {
                            dp[len][i][j] = true;
                            break;
                        }
                        //或者交换之后，是否都是真，也就是j + len -k
                        if (dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[N][0][0];
    }
};