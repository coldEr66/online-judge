#include <iostream>
#include <algorithm>
using namespace std;

long long cnt;

long long f(int x){
  cnt++;
  if(x<2) return x;
  else return f(x-1)+f(x-2);
}

int main(){
  int n;
  cin>>n;
  long long ans=f(n);
  cout<<ans<<' '<<cnt<<endl;
}
