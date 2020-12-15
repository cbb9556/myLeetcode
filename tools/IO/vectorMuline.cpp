// 多个测试用例，每个测试用例一行。
// 每行通过空格隔开，有n个字符，n＜100
// 对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
     string input;
    while(getline(cin,input)){
        istringstream iss(input);
        string str;
        vector<string>v;
        while(iss>>str)
            v.push_back(str);
        sort(v.begin(),v.end());
        unsigned long len = v.size();
        for(int i = 0; i < len-1; i++){
            cout<<v[i]<<" ";
        }
        cout<<v[len-1]<<endl;
    }
    return 0;
}
