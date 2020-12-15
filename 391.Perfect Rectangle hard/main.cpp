#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v = {{2,9,10,2},{3,7,30,4},{5,12,12,4},{15,20,10,5},{19,24,8,6}};
	Solution tet;
	auto res = tet.isRectangleCover(v);
	cout<<boolalpha<<res<<endl;
	return 0;
}