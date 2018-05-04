#include <iostream>
using namespace std;

int fac[2600];
int main(){
  int n;
  cin>>n;
  fac[0]=1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<2600;j++) fac[j]=fac[j]*i;
    for(int j=0;j<2600;j++){
      if(fac[j]>=10){
        fac[j+1]+=fac[j]/10;
        fac[j]%=10;
      }
    }
  }
  int tmp=2599;
  for(;fac[tmp]==0;tmp--);
  for(;tmp>=0;tmp--) cout<<fac[tmp];
  cout<<endl;
}
