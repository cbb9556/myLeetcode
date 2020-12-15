#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right)/2;
            if(mid == nums[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};