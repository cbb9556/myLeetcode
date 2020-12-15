#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	string s1 = "horse", s2 = "ros", s3 = "strd";
	cin>>s1;
	cin>>s2;
	cin>>s3;

	Solution tet;
	cout<<boolalpha<<tet.isInterleave(s1,s2,s3)<<endl;
	return 0;
}