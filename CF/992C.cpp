#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;

const ll MOD = 1e9+7;

ll fpow(ll base,ll t){
  ll ret = 1;
  while(t){
    if(t&1) ret=(ret*base)%MOD;
    base=(base*base)%MOD;
    t>>=1;
  }
  return ret;
}

int main(){
  IOS();
  ll x,k;
  cin>>x>>k;
  if(x==0) return cout<<0<<'\n',0;
  ll f = fpow(2,k+1);
  // cout<<f<<'\n';
  f = f*(x%MOD);
  ll tmp = fpow(2,k)-1;
  if(tmp<0) tmp+=MOD;
  ll ans = f-tmp;
  while(ans<0) ans+=MOD;
  ans%=MOD;
  cout<<ans<<'\n';
}
