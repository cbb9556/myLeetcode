#include "Solution.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v = {{0,0,0},
  {0,1,0},
  {0,0,0}};
	Solution tet;
	cout<<tet.uniquePathsWithObstacles(v)<<endl;
	return 0;
}