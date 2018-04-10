#include <iostream>
using namespace std;
typedef long long ll;

ll dp[2][35];

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<=m;i++) dp[0][i]=dp[1][i]=1;
  ll roll=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      dp[!roll][j]=dp[!roll][j-1]+dp[roll][j];
    }
    roll=!roll;
  }
  cout<<dp[roll][m]<<endl;
}
