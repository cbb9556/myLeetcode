
#include "Solution.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    int arr[LEN] = {1, 2, 3, 4, 5, 5, 5, 8};
    vector<int>vec(arr, arr + LEN);
    auto x = s.removeDulicate(vec);
    cout<<x;
    return 0;
}
