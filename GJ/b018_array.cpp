#include <iostream>
#include <cstring>
using namespace std;

int x[1005][2600];

int main(){
  int n;
  cin>>n;
  x[0][0]=1;
  x[1][0]=1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<2600;j++){
      x[i][j]+=x[i-1][j]*i;
      if(x[i][j]>=10){
        x[i][j+1]+=x[i][j]/10;
        x[i][j]%=10;
      }
    }
  }
  int i=2600;
  for(;x[n][i]==0 && i>0;i--);
  for(;i>=0;i--) cout<<x[n][i];
  cout<<endl;
}
