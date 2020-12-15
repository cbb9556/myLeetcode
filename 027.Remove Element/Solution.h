#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0; 
        
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  
            if (val != nums[fastIndex]) { 
                nums[slowIndex++] = nums[fastIndex]; 
            }
        }
        return slowIndex;
    }
};

