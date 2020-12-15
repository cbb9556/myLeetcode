#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v = {{2,9,10},{3,7,30},{5,12,12},{15,20,10},{19,24,8}};
	Solution tet;
	auto res = tet.kthSmallest(v,5);
	cout<<res<<endl;
	return 0;
}