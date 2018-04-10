#include <iostream>
#include <algorithm> //min,max要用這個
using namespace std;
typedef long long ll;

ll dp[505][505];

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ll x;
      cin>>x;
      if(x==0) dp[i][j]=1;
    }
  }
  ll ans=-1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(!dp[i][j]) continue;
      dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
      ans=max(ans,dp[i][j]);
    }
  }
  cout<<ans*ans<<endl;
}
