#include<iostream>  
#include <iomanip>  
using namespace std;  
int const n=4;  //确定矩阵的节数  

int main()  
{   
    double fun(double array[n][n]);  
    void temp(double aa[],double bb[],int n);  
    double a[n][n];  
    double det;  
    int i,j,kk=0;  
    cout<<"请输入一个"<<n<<"节方阵"<<endl;  
    for(i=0; i<n; i++)    //一个矩阵的输入  
        for(j=0; j<n; j++)  
            cin>>a[i][j];  
      det = fun(a);       //获取行列式的值  
      cout<<"矩阵的行列式的值为："<<det<<endl;  
      cout<<"转换的上三角矩阵为："<<endl;  
      for(i=0; i<n; i++)  
          for(j=0; j<n; j++)  
          {  
              cout<<setw(7)<<a[i][j];  
              kk = kk + 1;  
              if( kk % n == 0 )   
                  cout<<endl;  
          }  
     cout<<endl;  
          return 0;    
}  
//交换数组指定的两行，即进行行变换（具体为行交换）  
void temp(double aa[],double bb[],int n)  
{     
    int i;  
    double temp1;  
    for(i=0 ; i<n ; i++)  
    {  
        temp1 = aa[i];  
        aa[i] = bb[i];  
        bb[i] = temp1;    
    }    
}  
  
double fun(double array[n][n])  
{     
    int ii,jj,k,u;  
    int iter = 0;  //记录行变换的次数（交换）
    double det1=1,yin;  
 
    for(ii=0 ; ii<n; ii++)  
    {     
        if(array[ii][ii] == 0) 
            
        for(jj=ii; jj<n; jj++)  
        {    
            if(array[jj][ii] != 0)  
            {
                temp(array[ii],array[jj],n);//交换两行  
                iter ++;
            }
        }  
 
        for(k=ii+1; k<n; k++)  
        {    
          yin = -1 * array[k][ii] / array[ii][ii] ;  
 
          for(u=0; u<n; u++)  
          {   
              array[k][u] = array[k][u] + array[ii][u] * yin;  
          }  
        }  
   }  
  for(ii=0; ii<n; ii++)  //求对角线的积 即 行列式的值
      det1 = det1 * array[ii][ii];  
  //行变换偶数次符号不变
  if(iter%2 == 1)
      det1= -det1;
   return (det1);  
}