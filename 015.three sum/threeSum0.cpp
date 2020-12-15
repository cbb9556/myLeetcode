#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, const int& target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int len = nums.size(), left, right, sum;
        if(len < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > target) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            left = i+1, right = len - 1;
            while(left < right)
            {   
                sum = nums[i] + nums[left] + nums[right];
                if(sum == target)
                {   
                    tmp = {nums[i], nums[left], nums[right]};
                    res.emplace_back(tmp);
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum > target) right--;
                else left++;
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v;
    int target = 3;
    for (int i = 0; i < 10; ++i)
    {
        /* code */
        v.push_back(i - 3);
        cout<<v[i]<<",";
    }
    cout<<endl;
    Solution s;
    std::vector<vector<int>> x = s.threeSum(v,target);
    for (int i = 0; i < x.size(); ++i)
    {
        /* code */
        for(unsigned j = 0; j < x[i].size(); ++j) {
            /* code */
            cout<<x[i][j]<<",";
        }
    cout<<endl;
    }
    return 0;
}
