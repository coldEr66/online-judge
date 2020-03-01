#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,m,h;
ll d[MAXn],dp[MAXn],scc[MAXn],sz[MAXn];
vector<ll> e[MAXn],re[MAXn],tp,node[MAXn],dt,tr[MAXn];
bitset<MAXn> vis;
void add_edge(ll u,ll v){
    if ((d[u] + 1) % h == d[v]) {
        e[u].eb(v);
        re[v].eb(u);
    }
}
void dfs1(ll x){
    vis[x] = true;
    for (auto i:e[x]) {
        if (vis[i]) continue;
        dfs1(i);
    }
    tp.eb(x);
}
void dfs2(ll x,ll cnt){
    vis[x] = true;
    scc[x] = cnt;
    sz[cnt]++;
    node[cnt].eb(x);
    for (auto i:re[x]) {
        if (vis[i]) continue;
        dfs2(i,cnt);
    }
}
void dfs3(ll x){
    dp[x] = sz[x];
    for (auto i:tr[x]) {
        if (dp[i] == 0) dfs3(i);
        dp[x] += dp[i];
    }
}
void gt(ll x){
    vis[x] = true;
    for (auto i:node[x]) dt.eb(i);
    for (auto i:tr[x]) {
        if (vis[i]) continue;
        gt(i);
    }
}
int main(){
    IOS();
    cin >> n >> m >> h;
    REP (i,n) cin >> d[i];
    REP (i,m) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        add_edge(u,v);
        add_edge(v,u);
    }
    REP (i,n) {
        sort(ALL(e[i]));
        e[i].resize(unique(ALL(e[i]))-e[i].begin());
        sort(ALL(re[i]));
        re[i].resize(unique(ALL(re[i]))-re[i].begin());
    }
    REP (i,n) if (!vis[i]) dfs1(i);
    reverse(ALL(tp));
    ll cnt = 0;
    vis.reset();
    REP (i,n) if (!vis[tp[i]]) dfs2(tp[i],cnt++);
    REP (i,n) for (auto it:e[i]) {
        if (scc[i] != scc[it]) tr[scc[i]].eb(scc[it]);
    }
    REP (i,cnt) if (dp[i] == 0) dfs3(i);
    ll ans = 0;
    REP (i,cnt) if (dp[ans] > dp[i]) ans = i;
    vis.reset();
    gt(ans);
    sort(ALL(dt));
    cout << SZ(dt) << endl;
    REP (i,SZ(dt)) cout << dt[i]+1 << " \n"[i==SZ(dt)-1];
}
