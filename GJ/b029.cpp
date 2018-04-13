#include <iostream>
using namespace std;
typedef long long ll;

int money[]={2,5,10,20,25};
ll dp[1005];

int main(){
  ll n;
  cin>>n;
  dp[0]=1;
  for(int j=0;j<5;j++){
    for(int i=money[j];i<=n;i++){
      dp[i]+=dp[i-money[j]];
    }
  }
  cout<<dp[n]<<endl;
}
