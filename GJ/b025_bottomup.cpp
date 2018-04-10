#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[35][35];

int main(){
  ll x,y;
  cin>>x>>y;
  for(int i=0;i<=x;i++) dp[i][0]=1;
  for(int i=0;i<=y;i++) dp[0][i]=1;
  for(int i=1;i<=x;i++){
    for(int j=1;j<=y;j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  cout<<dp[x][y]<<endl;
}
