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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,k;
vector<pll> e[MAXn];
multiset<ll> st[MAXn];
pll dp[MAXn]; //k,k-1
void dfs(ll x,ll p){
    for (auto i:e[x]) {
        ll to = i.X, w = i.Y;
        if (to == p) continue;
        dfs(to,x);
        if (dp[to].X >= dp[to].Y + w) dp[x].X += dp[to].X;
        else {
            dp[x].X += dp[to].Y + w;
            st[x].insert(dp[to].X - dp[to].Y - w);
        }
        if (SZ(st[x]) > k) {
            auto it = st[x].end();
            it--;
            ll tmp = *it;
            st[x].erase(it);
            dp[x].X += tmp;
        }
    }
    dp[x].Y = dp[x].X;
    if (SZ(st[x]) == k) {
        auto it = st[x].end();
        it--;
        ll tmp = *it;
        dp[x].Y += tmp;
    }
}
signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0;i<n;++i) {
            e[i].clear();
            st[i].clear();
            dp[i] = pii(0,0);
        }
        for (int i=0;i<n-1;++i) {
            ll u,v,w;
            cin >> u >> v >> w;
            u--, v--;
            e[u].eb(v,w);
            e[v].eb(u,w);
        }
        dfs(0,0);
        cout << max(dp[0].X,dp[0].Y) << endl;
    }
}
