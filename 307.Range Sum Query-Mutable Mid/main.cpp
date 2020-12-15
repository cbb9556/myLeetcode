#include "Solution.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    //int nc = 4;
    vector<int> prec = {3,2,4,2,1,6};
    NumArray test(prec);
    // //scanf("numCourses = %d, prerequisites = %s", &nc, instr);
    // auto tmp = test.findOrder(nc,prec);
    // for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
    // 	cout<< *it<<" ";
    // }
    cout<<test.sumRange(4,5);
    return 0;
}
