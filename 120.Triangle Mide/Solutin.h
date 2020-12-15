#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//二维
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
};

//一维
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            int curr = i % 2;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            }
            f[curr][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }
};