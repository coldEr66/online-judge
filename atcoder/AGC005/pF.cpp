#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=1<<21,MAXlg=__lg(MAXn);
const ll MOD=924844033;
const ll INF=0x3f3f3f3f;
const ll RT = 5;

ll n;
vector<int> e[MAXn];
ll f[MAXn],fac[MAXn],invfac[MAXn];
ll a[MAXn],b[MAXn];
ll ans[MAXn];
ll fpow(ll x,ll y){
    ll ret = 1;
    while (y) {
        if (y&1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
ll gtinv(ll x){
    return fpow(x,MOD-2);
}
void build(){
    fac[0] = 1;
    invfac[0] = 1;
    for (ll i=1;i<MAXn;++i) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = gtinv(fac[i]);
    }
}
ll dfs(ll x,ll p){
    ll ret = 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        ll tmp = dfs(i,x);
        f[tmp]--;
        ret += tmp;
    }
    if (x != 0) f[n-ret]--;
    return ret;
}
int revbit(int x){
    int ret = 0;
    for (int i=0;i<MAXlg;++i) {
        if (x & (1<<i)) ret |= (1<<(MAXlg-i-1));
    }
    return ret;
}
void NTT(ll *poly,bool inv = false) {
    for (int i=0;i<MAXn;++i) {
        ll tmp = revbit(i);
        if (i < tmp) swap(poly[i],poly[tmp]);
    }
    for (int len=1;len*2<=MAXn;len<<=1) {
        ll r = fpow(RT,(MOD-1)/(len*2));
        if (inv) r = gtinv(r);
        for (int i=0;i<MAXn;i+=len*2) {
            ll w = 1;
            for (int j=i;j<i+len;++j) {
                ll ta = poly[j], tb = w * poly[j+len] % MOD;
                poly[j] = (ta+tb)%MOD, poly[j+len] = (ta-tb+MOD)%MOD;
                w = w * r % MOD;
            }
        }
    }
    if (inv) {
        ll ninv = gtinv(MAXn);
        for (int i=0;i<MAXn;++i) poly[i] = poly[i] * ninv % MOD;
    }
}
int main(){
    IOS();
    build();
    cin >> n;
    for (int i=0;i<n-1;++i) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(0,0);
    f[n] = n;
    for (int i=0;i<=n;++i) {
        a[n-i] = f[i] * fac[i] % MOD;
        a[n-i] = (a[n-i] + MOD) % MOD;
        b[i] = invfac[i];
    }
    NTT(a), NTT(b);
    for (int i=0;i<MAXn;++i) a[i] = a[i] * b[i] % MOD;
    NTT(a,1);
    for (int i=1;i<=n;++i) cout << a[n-i] * invfac[i] % MOD << endl;
}
