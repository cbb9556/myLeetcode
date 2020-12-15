#include <vector>
#include <set>
#include <queue>
using namespace std;

#define MP make_pair
#define PAIR pair<int,vector<int>>

class Solution {
public:
    struct cmp{
       bool operator()(const PAIR &a,const PAIR  &b)
       {
               return a.first>b.first; // 小根堆
       }     
    };

    int kthSmallest(vector<vector<int>>& mat, int k) {
            //PAIR的 first：{sum(mat[i][second[i]])   0<=i<n}  ；second[i]=index ：第i+1行选择下标为index的数
                priority_queue<PAIR,vector<PAIR>,cmp> q; 
             //repeat查重 每种状态只遍历一次  状态就是每行选择的数的下标  在second中保存   
                set<vector<int> > repeat;

                int n=mat.size(),m=mat[0].size();
                int init=0;
            //init是每行都选择第一个 一定是就是最小的
                for(auto &i:mat) init+=i.front();
            //push起始状态   sum=init   n行，每一行选择的下标都是0
                q.push(MP(init,vector<int>(n,0)));
                for(int j=1;j<k;++j)
                {
                        auto temp=q.top();
                        q.pop();
                        for(int i=0;i<n;++i) if(temp.second[i]+1<m)  //如果第i行的下标  +1之后不会越界
                        {
                                        vector<int> temp_v=temp.second;
                                      //新的状态 第i行的选择后移一步
                                        temp_v[i]+=1;          
                                      //如果这种状态已经到达过了 continue
                                        if(!repeat.insert(temp_v).second) continue;  
                                        // 更新sum 并push
                                        int sum=temp.first+mat[i][temp_v[i]]-mat[i][temp_v[i]-1];
                                        q.push(MP(sum,temp_v));
                         }
                }
            
            return q.top().first;
    }
};