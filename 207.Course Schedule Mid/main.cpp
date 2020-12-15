#include "Solution.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true

int main(int argc, char *argv[]) {
    Solution2 test;
    int nc = 4;
    vector<vector<int>> prec = {{1,0},{2,1},{3,2}};
    //scanf("numCourses = %d, prerequisites = %s", &nc, instr);
    cout<<boolalpha<<test.canFinish(nc,prec)<<endl;
    return 0;
}
