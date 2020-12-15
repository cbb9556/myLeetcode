#include <vector>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {

        int n = nums.size();
        int ans1=0, ans2=0;
        //
        for (int i=0; i<n; ++i) {
            //把该位置变成比前一个小需要d1步
            int d1 = (i>0 && nums[i]>=nums[i-1]) ? (nums[i] - nums[i-1] + 1) : 0;
            //把该位置变成比后一个小需要d2步
            int d2 = (i<n-1 && nums[i]>=nums[i+1]) ? (nums[i] - nums[i+1] + 1) : 0;
            //取max就把该位置凹下去
            //按奇偶累加
            if (i%2) {
                ans1 += max(d1, d2);
            } else {
                ans2 += max(d1, d2);
            }
        }
        //按奇偶位置凹下去需要比较少的那个方案
        return min(ans1, ans2);
    }
};