#include <iostream>
#include <vector>
using namespace std;
int x[300];
bool chk(int x){
  if(x%3==0) return 0;
  while(x){
    if(x%10==3) return 0;
    x/=10;
  }
  return 1;
}
int main(){
  int tmp=1;
  for(int i=1;i<=255;i++){
    if(chk(i)) x[tmp]=i,tmp=i;
  }
  int n;
  cin>>n;
  cout<<x[n]<<endl;
}
