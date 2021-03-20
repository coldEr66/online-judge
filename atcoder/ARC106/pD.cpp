#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MAXk = 3e2+5;

ll n,k;
ll d[MAXn];
ll sum[MAXk];
ll fac[MAXk],inv[MAXk];
ll mul(ll a,ll b){
    return a * b % MOD;
}
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a-b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll fpow(ll a,ll b){
    ll ret = 1;
    while (b) {
        if (b&1) ret = mul(ret,a);
        a = mul(a,a);
        b >>= 1;
    }
    return ret;
}
void build(){
    fac[0] = inv[0] = 1;
    for (ll i=1;i<MAXk;++i) {
        fac[i] = mul(fac[i-1],i);
        inv[i] = fpow(fac[i],MOD-2);
    }
    for (ll i=0;i<MAXk;++i) {
        for (ll j=0;j<n;++j) {
            sum[i] = add(sum[i],mul(fpow(d[j],i),inv[i]));
        } 
    }
}
signed main(){
    IOS();
    cin >> n >> k;
    for (int i=0;i<n;++i) cin >> d[i];
    build();
    for (int x=1;x<=k;++x) {
        ll ans = 0;
        ll sb = 0;
        for (int i=0;i<n;++i) {
            sb = add(sb,fpow(d[i],x));
        }
        sb = mul(sb,fpow(2,x));
        ans = sub(ans,sb);
        ll cur = 0;
        for (ll i=0;i<=x;++i) {
            ll tmp = mul(sum[i],sum[x-i]);
            cur = add(cur,tmp);
        }
        cur = mul(cur,fac[x]);
        ans = add(ans,cur);
        ans = mul(ans,fpow(2,MOD-2));
        cout << ans << endl;
    }
}
