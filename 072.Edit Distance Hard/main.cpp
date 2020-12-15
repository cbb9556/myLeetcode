#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	string s1 = "horse", s2 = "ros";
	cin>>s1;
	cin>>s2;
	Solution tet;
	cout<<tet.minDistance(s1,s2)<<endl;
	return 0;
}