#include <iostream>
using namespace std;
typedef long long ll;  //這行代表把long long 變成 ll這樣打字才方便  以後要看得懂XD

ll dp[100];

ll f(ll x){
  if(x<2) return dp[x]=1;
  if(dp[x]!=-1) return dp[x];
  else return dp[x]=f(x-1)+f(x-2);
}

int main(){
  ll n;
  cin>>n;
  for(int i=0;i<100;i++) dp[i]=-1;
  ll k=f(n);
  ll ans=f(k%n);
  cout<<k<<' '<<ans<<endl;
}
