#include <vector>
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int length = nums.size();
        int maxth = 1;
        if ( length == 0) return 0;
        vector<int> dp(length,1);
        for (int i = 1; i < length; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
            else dp[i] = 1;
            maxth = max(maxth,dp[i]);
        }
        return maxth;
    }
};