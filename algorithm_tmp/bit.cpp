#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,j,n,m) for(int i=j;i<n;i+=m)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back

struct BIT{
  ll _n,bit[MAXn];
  BIT(ll n):_n(n){};
  ll lowbit(ll x){return x&(-x);}
  void ins(ll pos,ll val){
    for (;pos<=_n;pos+=lowbit(pos)) bit[pos] += val;
  }
  ll qr(ll pos){
    ll ret = 0;
    for (;pos>0;pos-=lowbit(pos)) ret += bit[pos];
    return ret;
  }
  void build(ll *x){
    REP1 (i,_n) ins(i,x[i]);
  }
};
