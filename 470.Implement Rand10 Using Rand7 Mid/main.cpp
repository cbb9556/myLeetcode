#include "Solution.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
  int n;
  cout<<"n = ";
  cin>>n;
  Solution test;
  cout<<"[";
  while( n < 0) {
    cout<<"please input a value > 0"<<endl<<"n = ";
    cin>>n;
  }

  for (int i = 0; i < n - 1; ++i)
  {
    /* code */
    cout<<test.rand10()<<",";

  }
  cout<<test.rand10();
  cout<<"]";
  return 0;
}
