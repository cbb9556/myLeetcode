#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    while(getline(cin,input)){
        istringstream iss(input);
        string str;
        vector<string>v;
        while(getline(iss,str,','))
            v.push_back(str);
        sort(v.begin(),v.end());
        unsigned long len = v.size();
        for(int i = 0; i < len; i++){
            if(i != 0)
                cout<<",";
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}