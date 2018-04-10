#include <iostream>
using namespace std;
typedef long long ll;

ll dp[35][35];

ll f(ll n,ll m){
  if(n==0 || m==0) return 1;
  if(dp[n][m]!=-1) return dp[n][m];
  else return dp[n][m]=f(n-1,m)+f(n,m-1);
}

int main(){
  ll x,y;
  cin>>x>>y;
  for(int i=0;i<=x;i++){
    for(int j=0;j<=y;j++){
      dp[i][j]=-1;
    }
  }
  ll ans=f(x,y);
  cout<<ans<<endl;
}
