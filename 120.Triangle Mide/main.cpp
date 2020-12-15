#include <iostream>
#include <vector>
#include "Solutin.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v{{2},{3,4},{4,3,1},{2,6,7,8}};
	Solution tet;
	cout<<tet.minimumTotal(v)<<endl;
	return 0;
}