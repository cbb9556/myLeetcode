#include "Solution.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true

int main(int argc, char *argv[]) {
    Solution test;
    int k = 2;
    vector<int> prec = {1,2,4,2,6,5};
    //scanf("numCourses = %d, prerequisites = %s", &nc, instr);
    auto tmp = test.findKthLargest(prec,k);
    cout<<tmp<<endl;
    return 0;
}
