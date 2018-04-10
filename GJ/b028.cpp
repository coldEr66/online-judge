#include <iostream>
using namespace std;
typedef long long ll;

ll money[]={1,5,10,12,16,20};
ll dp[105][6];

ll sol(ll x,ll t){
  if(t==0) return x;
  if(dp[x][t]!=-1) return dp[x][t];
  else{
    ll mn=1e12;
    for(int i=0;i*money[t]<=x;i++){
      mn=min(mn,sol(x-i*money[t],t-1)+i);
    }
    return dp[x][t]=mn;
  }
}

int main(){
  ll n;
  cin>>n;
  for(int i=0;i<105;i++){
    for(int j=0;j<6;j++){
      dp[i][j]=-1;
    }
  }
  ll ans=sol(n,5);
  cout<<ans<<endl;
}
