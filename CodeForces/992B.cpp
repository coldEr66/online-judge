#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll lcm(ll a,ll b){
  if(__gcd(a,b)==1) return a*b;
  ll tmp = __gcd(a,b);
  a/=tmp;
  b/=tmp;
  ll ret = a*b*tmp;
  return ret;
}
vector<ll> fac;
int main(){
  IOS();
  ll l,r,a,b;
  cin>>l>>r>>a>>b;
  if(b%a!=0) return cout<<0<<'\n',0;
  for(int i=1;i<=sqrt(b);i++){
    if(b%i==0){
      if(i>=l && i<=r) fac.emplace_back(i);
      if((b/i)>=l && (b/i)<=r && (b/i)!=i) fac.emplace_back(b/i);
    }
  }
  // cout<<"hi "<<fac.size()<<endl;
  ll cnt = 0;
  for(int i=0;i<(int)fac.size();i++){
    for(int j=0;j<(int)fac.size();j++){
      // if(i==j) continue;
      if(fac[i]<a || fac[j]<a) continue;
      if(__gcd(fac[i],fac[j])==a && lcm(fac[i],fac[j])==b) cnt++;
    }
  }
  cout<<cnt<<'\n';
}
