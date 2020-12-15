#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // （1）当前的值x 比 之前的和 pre 还要大，需要比较当前x与pre
        //  (2) 不能 越加越小 需要记录maxans 

        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};