#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

ll dis[MAXn][MAXlg];
vector<ii> e[MAXn];
ll fa[MAXn],d[MAXn],ch[MAXn],tf[MAXn];
ll dep[MAXn];
vector<ll> tmp;
ll sz[MAXn],ma[MAXn];
bitset<MAXn> ok;
void dfs(ll x,ll p){
    sz[x] = 1, ma[x] = 0;
    tmp.eb(x);
    for (auto i:e[x]) {
        if (i.X == p || fa[i.X] != INF) continue;
        dfs(i.X,x);
        ma[x] = max(ma[x],sz[i.X]);
        sz[x] += sz[i.X];
    }
}
void gtdis(ll x,ll p,ll D,ll lev){
    dis[x][lev] = D;
    for (auto i:e[x]) {
        debug(i.X);
        if (i.X == p || fa[i.X] != INF) continue;
        gtdis(i.X,x,D+i.Y,lev);
    }
}
void gtc(ll x,ll p){
    tmp.clear();
    tmp.shrink_to_fit();
    dfs(x,p);
    ll root = -1;
    for (auto i:tmp) {
        if (max(ma[i],SZ(tmp)-sz[i]) <= SZ(tmp)/2) root = i;
    }
    debug(root,p);
    fa[root] = p;
    if (p == -1) dep[root] = 0;
    else dep[root] = dep[fa[root]] + 1;
    gtdis(root,root,0,dep[root]);

    debug("ALIVE");
    for (auto i:e[root]) {
        if (i.X == p || fa[i.X] != INF) continue;
        debug(i.X);
        gtc(i.X,root);
    }
}
void build(){
    gtc(0,-1);
}
void ins(ll x){
    if (ok[x]) return;
    ok[x] = true;
    ll cur = x;
    while (fa[cur] != -1) {
        ch[cur]++;
        d[cur] += dis[x][dep[cur]];
        tf[cur] += dis[x][dep[fa[cur]]];
        cur = fa[cur];
    }
    ch[cur]++;
    d[cur] += dis[x][dep[cur]];
}
ll qr(ll x){
    ll ret = d[x];
    ll cur = x;
    while (fa[cur] != -1) {
        ret += d[fa[cur]] + dis[x][dep[fa[cur]]] * (ch[fa[cur]] - ch[cur]) - tf[cur];
        cur = fa[cur];
    }
    return ret;
}
int main(){
    IOS();
    ll n,q;
    cin >> n >> q;
    REP (i,n-1) {
        ll u,v,w;
        cin >> u >> v >> w;
        e[u].eb(v,w);
        e[v].eb(u,w);
    }
    REP (i,n) fa[i] = INF;
    build();
    pary(fa,fa+n);
    pary(dep,dep+n);
    REP (i,n) pary(dis[i],dis[i]+n);
    while (q--) {
        ll cmd,x;
        cin >> cmd >> x;
        if (cmd == 1) ins(x);
        else cout << qr(x) << endl;
        pary(tf,tf+n);
        pary(ch,ch+n);
        pary(d,d+n);
    }
}
/*
8
100
0 1 6
0 5 4
0 2 7
2 3 2
2 4 4
4 7 1
7 6 1
*/
