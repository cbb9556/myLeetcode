
#include "Solution.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution s;
    const int LEN = 8;
    int arr[LEN] = {7, 5, 6, 5, 2, 6, 5, 1};
    vector<int>vec(arr, arr + LEN);
    auto x = s.removeElement(vec,5);
    cout<<x;
    return 0;
}
