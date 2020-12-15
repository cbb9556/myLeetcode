#include "Solution.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char** argv) {
    Solution s;
    string str = "()()()(){}";
    cout<<s.isValid(str)<<endl;
    return 0;
}