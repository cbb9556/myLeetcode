#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool mChange(vector<int>& bills, int& pos) {
        int m5 = 0, m10 = 0;
        for (int i : bills) {
        	switch(i) {
                case 5: {m5 ++; pos++; continue;} 
                case 10: {m10 ++, m5 --; pos++; break;}
                case 20: if (m10 > 0) {m10 --, m5 --; pos++;}
                         else {m5 -= 3;}
                default: {pos++; return false;}            	
            }
            if (m5 < 0) return false;
            pos--;
        }
        return true;
    }
};

vector<int> split1(string a,char c)
{
    a=a+c;
    int i,len=a.length(),pos;
    vector<int> b;
    for(i=0;i<len;i++)
    {
        pos=a.find(c,i);
        if(pos<len)
        {
            b.push_back(stoi(a.substr(i,pos-i)));
            i=pos;
        }
    }
    return b;
}

int main(int argc, char const *argv[])
{
	string s;
	int pos = 0 ;
	Solution test;
	cin>>s;
    vector<int> a = split1(s,',');
    if (test.mChange(a,pos)) {cout<<"true,"<<pos;} else {cout<<"false,"<<pos;}
}