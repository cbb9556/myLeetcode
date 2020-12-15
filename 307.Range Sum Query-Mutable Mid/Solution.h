#include <vector>
using namespace std;

class NumArray {
public:
    
    vector<int> tr;
    int n;
    vector<int> data;
    
    //返回当前数字x的最低的bit位的1所表示的十进制数字，使用这个数字可以更新和查询，树状数组的值
    // -x是有符号的值求负数，那么就需要“反码 + bit 1“，也就是从左到右，第一个1不变，第一个1左边的
    //全部取反，这样与原数&，就得到最低的 1 所代表的十进制数字
    int lowbit(int x) {
        return x & -x;
    }
    
    //树状数组 c[x]的值 等于a[0] 到 a[x]的和，详细见 readme
    int sum(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
    //在c[x]的父系 上都增加值c 维持数组的性质
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        tr = vector<int>(n + 1, 0);

        //对树状数组初始化，c[1] = c[0]
        for (int i = 0; i < n; i ++) {
            add(i + 1, nums[i]);
        }
        data = nums;
        // for (int i = 1; i <= n; i ++) cout << tr[i] << " ";
        // cout << endl;
    }
    
    //更改 被更新位置的值 然后更新所有父系上的值
    void update(int i, int val) {
        add(i + 1, val - data[i]);
        data[i] = val;
    }
    
    //返回 数组范围内 值之和 a[i] a[j]在范围内 
    int sumRange(int i, int j) {
        // sum[j + 1]加了一次a[j]加了一次a[i]；sum[i]又加了一次a[i]，那么加了两次；
        return sum(j + 1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */