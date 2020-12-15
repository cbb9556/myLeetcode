#include <vector>
using namespace std;;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int m = rectangles.size(),i,j,k,jj,kk,pre;

        //获取按右边横坐标排序的矩形指针
        vector<int>* idx1[m+1];
        //获取按左边横坐标排序的矩形指针
        vector<int>* idx2[m+1];

        for(int i=0; i<m; i++) {
            idx1[i] = idx2[i] = &rectangles[i];
        }

        sort(idx1,idx1 + m, [&](vector<int>* x,vector<int>* y)->bool{return (*x)[2]<(*y)[2]||((*x)[2]==(*y)[2]&&(*x)[3]<(*y)[3]);});
        //idx1按右侧排序
        sort(idx2,idx2+m,[&](vector<int>* x,vector<int>* y)->bool{return (*x)[0]<(*y)[0]||((*x)[0]==(*y)[0]&&(*x)[1]<(*y)[1]);});
        //idx2按左侧排序
        idx1[m]=idx2[m]=new vector<int>{10000,0,10000,0};
        //在idx1和idx2右侧放哨兵，减少边界检查
        
        for(i=(*idx2[0])[0],j=k=0;;){
            //for循环每次遍历一条竖线
            //找出这条竖线上结束的矩形和新来的矩形
            if(k){
                //每次while循环遍历一个连续的纵坐标区间
                while((*idx1[j])[2]==i){
                    pre=(*idx1[j])[1];
                    for(jj=j;(*idx1[jj])[2]==i&&(*idx1[jj])[1]==pre;jj++){
                        pre=(*idx1[jj])[3];
                    }
                    //从idx1找出结束的矩形：*idx1[j][1]~*idx1[jj-1][3];
                    pre=(*idx2[k])[1];
                    for(kk=k;(*idx2[kk])[0]==i&&(*idx2[kk])[1]==pre;kk++){
                        pre=(*idx2[kk])[3];
                    }
                    //从idx2找出新来的矩形：*idx2[k][1]~*idx2[kk-1][3];
                    if((*idx1[j])[1]!=(*idx2[k])[1])return false;
                    if((*idx1[jj-1])[3]!=(*idx2[kk-1])[3])return false;
                    //结束的矩形和新来的矩形，在y轴的投影必须保持一致
                    j=jj,k=kk;
                }
            }
            else{
                //若k为0，则没有结束的矩形，只有新来的矩形
                pre=(*idx2[0])[1];
                for(kk=0;(*idx2[kk])[0]==i&&(*idx2[kk])[1]==pre;kk++){
                    pre=(*idx2[kk])[3];
                }
                //*idx2[0][1]~*idx2[kk-1][3]
                k=kk;
            }
            if(k<m){
                //如果右侧还有新来的矩形，则继续
                if((*idx2[k])[0]==i)return false;
                i=(*idx2[k])[0];
            }
            else break;
        }
        //退出for循环后检查剩下的矩形是否同时在最右边界结束
        pre=(*idx1[m-1])[2];
        while((*idx1[j])[2]==pre)j++;
        return j==m;
    }
};