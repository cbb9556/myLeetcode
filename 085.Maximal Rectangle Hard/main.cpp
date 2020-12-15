#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<char>> myvec{
    {'1','1','1','1','0'}, 
    {'1','1','0','1','0'}, 
    {'1','1','0','0','0'}, 
    {'0','0','0','0','0'}
    };
    
	Solution tet;
	cout<<tet.maximalRectangle(myvec)<<endl;
	return 0;
}