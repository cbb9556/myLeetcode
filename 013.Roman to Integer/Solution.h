#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> romap={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };//初始化哈希表

        for(int i=0;i<s.length();i++)
        {
            if(romap[s[i]] < romap[s[i+1]])
                result -= romap[s[i]];
            else
            {
                result += romap[s[i]];
            }
        }
        return result;
    }
};