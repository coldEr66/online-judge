#include <iostream>
#include <algorithm>
using namespace std;

int d[105];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>d[i];
  sort(d,d+n,greater<int>());             //很多種寫法
  for(int i=0;i<n;i++){                   //也可以用sort(d,d+n);    然後for(int i=n-1;i>=0;i--) cout<<d[i].....;
    if(i!=0) cout<<' ';
    cout<<d[i];
  }
  cout<<endl;
}
