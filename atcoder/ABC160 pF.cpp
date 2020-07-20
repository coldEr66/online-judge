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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
ll dp[MAXn],sz[MAXn];
ll fac[MAXn],inv[MAXn],pro[MAXn];
ll ans[MAXn];
vector<int> e[MAXn];
ll mul(ll a,ll b){
    return a*b%MOD;
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
ll fpow(ll a,ll b){
    ll ret = fpow(a,b/2);
    if (b&1) return ret * ret * a;
    return ret * ret;
}
void dfs1(ll x,ll p){
    dp[x] = 1, sz[x] = 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs1(i,x);
        sz[x] += sz[i];
        dp[x] = mul(dp[x],mul(dp[i],inv[sz[i]]));
    }
    dp[x] = mul(dp[x],fac[sz[x]-1]);
    pro[x] = mul(fac[sz[x]],fpow(dp[x],MOD-2));
}
void dfs2(ll x,ll p,ll fa){
    debug(x,p,fa);
    ans[x] = 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        ans[x] = mul(ans[x],mul(dp[i],inv[sz[i]]));
    }
    debug(x,ans[x]);
    for (auto i:e[x]) {
        if (i == p) continue;
        debug(i,ans[x]);
        pro[i] = mul(ans[x],pro[i]);
        debug(i,pro[i]);
        ll nxt = mul(fa,pro[i]);
        nxt = mul(nxt,fac[n-sz[i]-1]);
        nxt = mul(nxt,inv[n-sz[i]]);
        debug(x,nxt);
        dfs2(i,x,nxt);
    }
    ans[x] = mul(ans[x],fac[n-1]);
    ans[x] = mul(ans[x],fa);
}
int main(){
    IOS();
    cin >> n;
    fac[0] = inv[0] = 1;
    REP1 (i,MAXn-1) {
        fac[i] = mul(fac[i-1],i);
        inv[i] = fpow(fac[i],MOD-2);
    }
    debug(mul(1,inv[2]));
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs1(0,0);
    pary(dp,dp+n);
    pary(pro,pro+n);
    dfs2(0,0,1);
    REP (i,n) cout << ans[i] << endl;
}
