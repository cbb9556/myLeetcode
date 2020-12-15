#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
public:
    int maxArea(std::vector<int> height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            /* code */
            int area = min(height[l],height[r]) * (r - l);
            ans = max(ans,area);
            if (height[l] <= height[r]) {
                /* code */
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
    
};