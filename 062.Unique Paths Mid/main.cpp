#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	int m,n;
	cout<<"m = ";
	cin>>m;
	cout<<"n = ";
	cin>>n;
	Solution tet;
	cout<<tet.uniquePaths(m,n)<<endl;
	return 0;
}