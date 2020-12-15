#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
private:
	bool valide(string s, int left, int right) {
		while(left < right) {
			/* code */
			if(s[left] != s[right]) {
				/* code */
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
public:
	//Solution();
	string longestPalindrome(string s) {
		int size = s.size();
		if(size < 2) {
			/* code */
			return s;
		}

		int maxLen = 1;
		string res = s.substr(0,1);

		for(unsigned i = 0; i < size - 1; ++i) {
			/* code */
			for(unsigned j = i + 1; j < size; ++j) {
				/* code */
				if( j - i + 1 > maxLen && valide(s,i,j)) {
					/* code */
					maxLen = j - i + 1;
					res = s.substr(i,maxLen);
				}
			}
		}
		return res;
	}
	//~Solution();
	
};
