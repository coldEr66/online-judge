#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
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
const ll MAXm=1e6+5;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

pair<ii,ii> E[MAXm];
vector<ii> e[MAXn],ans;
int n,m;
int dsu[MAXn],sz[MAXn],in[MAXn],out[MAXn],t;
int anc[MAXn][MAXlg],mx[MAXn][MAXlg];
vector<iii> cal;
int fnd(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(int x,int y){
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
void dfs(int x,int p,int w){
    in[x] = ++t;
    anc[x][0] = p, mx[x][0] = w;
    for (int i=1;(1<<i)<n;i++) {
        anc[x][i] = anc[anc[x][i-1]][i-1];
        mx[x][i] = max(mx[x][i-1],mx[anc[x][i-1]][i-1]);
    }
    for (auto i:e[x]) {
        if (i.X == p) continue;
        dfs(i.X,x,i.Y);
    }
    out[x] = ++t;
}
bool chk(ll x,ll y){
    return in[x] <= in[y] && out[x] >= out[y];
}
int gt(int x,int y){
    int ret = 0;
    for (int i=__lg(n)+1;i>=0;i--) {
        if (!chk(anc[x][i],y)) {
            ret = max(ret,mx[x][i]);
            x = anc[x][i];
        }
    }
    if (!chk(x,y)) {
        ret = max(ret,mx[x][0]);
        x = anc[x][0];
    }
    for (int i=__lg(n)+1;i>=0;i--) {
        if (!chk(anc[y][i],x)) {
            ret = max(ret,mx[y][i]);
            y = anc[y][i];
        }
    }
    if (!chk(y,x)) ret = max(ret,mx[y][0]);
    debug(x,y);
    return ret;
}
int main(){
    IOS();
    cin >> n >> m;
    REP (i,n) dsu[i] = i, sz[i] = 1;
    REP (i,m) {
        int a,b,w;
        cin >> a >> b >> w;
        a--, b--;
        E[i] = make_pair(ii(w,i),ii(a,b));
    }
    sort(E,E+m);
    REP (i,m) {
        int u = E[i].Y.X, v = E[i].Y.Y, w = E[i].X.X;
        if (fnd(u) == fnd(v)) cal.eb(ii(u,v),E[i].X.Y);
        else {
            e[u].eb(v,w);
            e[v].eb(u,w);
            mrg(u,v);
        }
    }
    dfs(0,0,0);
    assert(SZ(cal) == m-(n-1));
    REP (i,SZ(cal)) {
        int u = cal[i].X.X, v = cal[i].X.Y;
        debug(u,v);
        int lca = gt(u,v);
        debug(lca);
        ans.eb(cal[i].Y,lca);
    }
    sort(ALL(ans));
    REP (i,m-(n-1)) cout << ans[i].Y << endl;
}
