#include <iostream>
using namespace std;
typedef long long ll;

ll dp[100];

int main(){
  ll n;
  cin>>n;
  dp[0]=dp[1]=1;
  for(int i=2;i<100;i++) dp[i]=dp[i-1]+dp[i-2];
  cout<<dp[n]<<' '<<dp[dp[n]%n]<<endl;
}
