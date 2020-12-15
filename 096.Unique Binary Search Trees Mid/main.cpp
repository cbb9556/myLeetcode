#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	int num;
	cin>>num;
	Solution tet;
	auto output = tet.numTrees(num);
	cout<<output<<endl;
	return 0;
}