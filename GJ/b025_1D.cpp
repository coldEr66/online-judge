#include <iostream>
using namespace std;
typedef long long ll;

ll dp[35];

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<35;i++) dp[i]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[j]=dp[j-1]+dp[j];
    }
  }
  cout<<dp[m]<<endl;
}
