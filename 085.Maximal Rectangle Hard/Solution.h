#include <vector>
using namespace std;

class Solution {
public:
    // dp(i, j, 3)为三元组（向左走连续1的个数，向上走连续1的个数，包围的最大面积）
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result = 0;
        //矩阵输入
        if (matrix.empty()) {return result;}
        int m = matrix.size();
        int n = matrix[0].size();
        //三维矩阵，m,n是每个坐标的位置，而其中的值 就是 左；高；面积；
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, {0, 0, 0}));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 && j == 0) {  // 左上角的值
                        dp[i][j] = {1, 1, 1};
                    } else if (i == 0) {  // 第一行 通过数组下标[0],[1], [2]代表左l；高h；面积r
                        //当前i,j这个下标位置的 l;          h;        r 
                        //动态规划为i,j-1这个位置的 l;h;r
                        dp[i][j] = {dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1};
                    } else if (j == 0) {  // 第一列
                        //同理
                        dp[i][j] = {1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1};
                    } else {
                        //l 左连续 1 由递推公式 i;j-1的 l发展而来 加上当前 matrix[i][j] == '1'
                        dp[i][j][0] = dp[i][j - 1][0] + 1;  // 向左连续1的个数
                        //r 
                        dp[i][j][1] = dp[i - 1][j][1] + 1;  // 向上连续1的个数
                        // 计算面积
                        int col_min = dp[i][j][0];  // 当前位置向左1的个数
                        int row = dp[i][j][1];  // 当前位置向上1的个数
                        for (int k = 0; k < row; k++) { //现在是从 0 到 k每个 col-min都考虑进去了, 而 k =row 最大的时候都会和col-min相乘；因为有可能中间某个k出现最大值，而此时的col-min不是所有k中的最小的那个
                            col_min = min(col_min, dp[i - k][j][0]);  // 向左最小的1个数，以高为循环变量
                            dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1)); //[2]存的是历史面积最大值，k+1为宽是因为，现在定位到的最小的col-min就在这个k的位置
                        }
                    }
                    result = max(result, dp[i][j][2]); //需要返回全局的最大面积
                }
            }
        }
        return result;
    }
};

