#include <iostream>
#include <vector>
#include <map>
using namespace std;

//压缩树状数组与方法1是一样的，讲数组去重排序作为树状数组的叶子结点
class Solution {
private:
    vector<int> c;
    vector<int> a;

    void Init(int length) {
        c.resize(length, 0);
    }

    int LowBit(int x) {
        return x & (-x);
    }

    void Update(int pos) {
        while (pos < c.size()) {
            c[pos] += 1;
            pos += LowBit(pos);
        }
    }

    int Query(int pos) {
        int ret = 0;

        while (pos > 0) {
            ret += c[pos];
            pos -= LowBit(pos);
        }

        return ret;
    }

    void Discretization(vector<int>& nums) {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
    
    int getId(int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resultList;

        Discretization(nums);

        Init(nums.size() + 5);
        
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            resultList.push_back(Query(id - 1));
            Update(id);
        }

        reverse(resultList.begin(), resultList.end());

        return resultList;
    }
};



class Solution1 {
public:

    //返回数字x，二进制化后，取最低位1代表的十进制数字
    int lowbit(int x){
        return x & (-x);
    }


    void update(int i, vector<int>&C){
        while (i < C.size()) {
            C[i]++;
            i += lowbit(i);
        }
    }

    void query(int i, int j, vector<int>&C, vector<int>&counts){
        while (i >= 1) {
            counts[j] += C[i];
            i -= lowbit(i);
        }
    }

    //输入为数组{7, 5, 6, 5, 2, 6, 5, 1} 有重复项
    //
    vector<int> countSmaller(vector<int>& nums) {
        
        //最终返回的count
        vector<int>counts(nums.size(), 0);
        
        if (nums.size() < 1) {
            return counts;
        }
        
        //复制数组
        vector<int>N(nums);
               
        // Sort and unique
        sort(N.begin(), N.end());
        
        int slow = 1;
        int fast = 1;
        
        //去重复
        while(fast< N.size()) {
            if (N[fast] != N[slow - 1]) {
                N[slow] = N[fast];
                slow++;
                fast++;
            }else{
                fast++;
            }
        }
        
        //缩小N的大小去除重复后
        N.resize(slow);
        
        // key: number, value: i
        map<int, int>m;
        for (int j = 1; j < 1 + N.size(); ++j) {
            m[N[j - 1]] = j;
        }
        
        // traverse，从右向左记录，每个数字比右边数字
        vector<int>C(N.size() + 1, 0); //  C[i] is necessary, but A[i] not
        
        int i;
        for (int j = nums.size() - 1; j >= 0; --j) {
            //最右边的第一个数字开始，找到这个数字的 下标位置，以更新数组C
            i = m[nums[j]];

            //更新树状数组，即向上找父节点 i + lowbit(i)
            update(i, C);

            if (i != 1) {
                //更新gountu数组
                query(i - 1, j, C, counts);
            }else{
                counts[j] = 0;
            }
        }
        return counts;
    }
};

