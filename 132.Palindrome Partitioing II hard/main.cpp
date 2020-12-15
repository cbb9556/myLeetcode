#include <iostream>
#include <vector>
#include <string>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	string str;
	cin>>str;
	Solution tet;
	cout<<tet.minCut(str)<<endl;
	return 0;
}