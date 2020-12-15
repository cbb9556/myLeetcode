#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int eatCake(vector<int> & pt, int n){
        int sum = 0;
        for(int pos = 0; pos < n; pos++) {
            vector<int> temp = pt;
            int i = 0, max = 0;
            while(temp[i] != 0){
                if (i > pos) {
                    i =0;
                }
                max += 1;
                temp[i]--;
                i++;
            }
            if (sum < max) {
                sum = max;
            }
        }        
        return sum;
    }
};

int main() {
    vector<int> pt;
    int n,x;
    cin>>n;
    for (int i; i < n ; i++) {
        cin>>x;
        pt.push_back(x);
    }
    Solution s;
    cout<<s.eatCake(pt,n);
    return 0;
}