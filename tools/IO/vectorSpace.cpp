#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 输入有两行，第一行n
// 第二行是n个空格隔开的字符串
// 输出一行排序后的字符串，空格隔开，无结尾空格

int main(int argc, const char * argv[]) {
    int num;
    cin>>num;
    vector<string>v;
    string val;
    while(num--){
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    unsigned long len = v.size();
    for(int i = 0; i < len-1; i++){
        cout<<v[i]<<" ";
    }
    cout<<v[len-1];
    
    return 0;
}

