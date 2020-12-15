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
    vector<vector<char>> grad = {{'1','0','1','0'},{'1','1','0','0'},{'1','1','1','1'}};

    //scanf("numCourses = %d, prerequisites = %s", &nc, instr);
    auto tmp = test.numIslands(grad);
    cout<<tmp<<endl;
    return 0;
}
