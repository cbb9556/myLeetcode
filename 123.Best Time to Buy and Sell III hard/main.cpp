#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<int> v{3,3,5,0,0,3,1,4};
	Solution tet;
	cout<<tet.maxProfit(v)<<endl;
	return 0;
}