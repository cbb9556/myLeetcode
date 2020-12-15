#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
	/* data */
public:
	int removeDulicate(std::vector<int> &vec) {
		int slow = 1;
		int fast = 1;
		if ( vec.size() == 0) return 0;
		if ( vec.size() == 1) return 1;

		while (fast < vec.size()) {
			if (vec[slow - 1] != vec[fast]) {
				vec[slow] = vec[fast];
				fast++;
				slow++;
			}
			else {
				fast++;
			}
		}
		return slow;
	}
};