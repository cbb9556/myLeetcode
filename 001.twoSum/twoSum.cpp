#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hash表的方式存储 key - value；而且是乱序的，和
        unordered_map<int,int> m;

        for(int i = 0; i<nums.size(); i++)
            m[nums[i]] = i;         //向map中添加元素
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)  //如果m中存在对应的键值，且不为i
                return {i, m[target-nums[i]]};
        }
        return {};
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())      //m中存在对应的键值
                return {m[target-nums[i]], i};        
            //  m[target-nums[i]]为已经加入map的元素的索引，所以小于本轮循环中的i，放在前面

            m[nums[i]] = i;       //向map中添加元素
        }
        return {};
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            for ( int j = 0; j < i; ++j) {
                if (nums[i] + nums[j] == target) {
                    res = vector<int> ({j,i});
                    break;
                }
            }
            if (res.size() > 0) break;
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v;
    int target = 10;
    for (int i = 0; i < 10; ++i)
    {
        /* code */
        v.push_back(i + 1);
        cout<<v[i]<<",";
    }
    cout<<endl;
    Solution1 s1;
    std::vector<int> x1 = s1.twoSum(v,target);
    for (int i = 0; i < x1.size(); ++i)
    {
        /* code */
        cout<<x1[i]<<",";
    }
    cout<<endl;

    Solution2 s2;
    std::vector<int> x2 = s2.twoSum(v,target);
    for (int i = 0; i < x2.size(); ++i)
    {
        /* code */
        cout<<x2[i]<<",";
    }
    return 0;
}