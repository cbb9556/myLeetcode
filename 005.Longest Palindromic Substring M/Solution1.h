#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution1 {

private:

    int centerSpread(string s, int center) {
        int len = s.size();
        int i = center - 1;
        int j = center + 1;
        int step = 0;
        while (i >= 0 && j < len && s[i] == s[j]) {
            i--;
            j++;
            step++;
        }
        return step;
    }

public:


    string longestPalindrome(string s) {
        // 特判
        int size = s.size();
        if (size < 2) {
            return s;
        }

        // 得到预处理字符串
        string str = "#";
        for (int i = 0; i < s.size(); ++i) {
            str += s[i];
            str += "#";
        }
        int sSize = 2 * size + 1;
        int maxLen = 1;

        int start = 0;
        for (int i = 0; i < sSize; i++) {
            int curLen = centerSpread(str, i);
            if (curLen > maxLen) {
                maxLen = curLen;
                start = (i - maxLen) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};