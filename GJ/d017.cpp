#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char d[15];
int main(){
  cin>>d;
  int n=strlen(d);
  sort(d,d+n,greater<char>());
  for(int i=0;i<n;i++) cout<<d[i];
  cout<<endl;
}
