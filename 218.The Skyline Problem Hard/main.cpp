#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main(int argc, char const *argv[]) {
	std::vector<std::vector<int>> v = {{2,9,10},{3,7,30},{5,12,12},{15,20,10},{19,24,8}};
	Solution tet;
	auto res = tet.getSkyline(v);
	cout<<"[";
	int j = 0;
	for(; j < res.size() - 1; j++) {
		cout<<"[";
		int i = 0;
		for (; i < res[j].size() - 1; i++) {
			cout<<res[j][i]<<",";
		}
		cout<<res[j][i];
		cout<<"]";
		cout<<",";
	}
	cout<<"["<<res[j][0]<<","<<res[j][1]<<"]";
	cout<<"]"<<endl;
	return 0;
}