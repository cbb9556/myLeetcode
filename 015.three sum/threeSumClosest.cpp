#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    int threeSum(vector<int>& nums, int target) {
        int len = nums.size(), left, right, sum;
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        if(len < 3) return ans;
        for(int i = 0; i < len; i++)
        {
            //if(nums[i] > target) return ans;
            //if(i>0 && nums[i] == nums[i-1]) continue;
            left = i+1, right = len - 1;

            while(left < right)
            {   
                sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum > target) right--;
                else if(sum < target) left++;
                else return ans;

                //while(left < right && nums[left] == nums[left+1]) left++;
                //while(left < right && nums[right] == nums[right-1]) right--;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v;
    int target = -8;
    for (int i = 0; i < 10; ++i)
    {
        /* code */
        v.push_back(i - 3);
        cout<<v[i]<<",";
    }
    cout<<endl;
    Solution s;
    int x = s.threeSum(v,target);
    cout<<x<<",";
    cout<<endl;
    return 0;
}
