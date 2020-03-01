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
const ll MAXm=1e6+5;
const ll MOD=1000000007;
const ll INF=1000000000;

ll n,m;
ll u[MAXm],v[MAXm],w[MAXm];
ll id[MAXm];
bool tr_edge[MAXm];
ll dsu[MAXn],sz[MAXn];
ll trsz[MAXn],son[MAXn],tp[MAXn],dep[MAXn],dfn[MAXn],t;
ll seg[MAXn*2];
ll anc[MAXn][MAXlg],mx[MAXn][MAXlg];
vector<ii> tr[MAXn];
ll fnd(ll x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(ll x,ll y){
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
void dfs(ll x,ll p,ll W){
    if (x != p) dep[x] = dep[p]+1;
    anc[x][0] = p;
    mx[x][0] = W;
    for (ll i=1;i<MAXlg;i++) {
        anc[x][i] = anc[anc[x][i-1]][i-1];
        mx[x][i] = max(mx[x][i-1],mx[anc[x][i-1]][i-1]);
    }
    trsz[x] = 1;
    son[x] = -1;
    for (auto i:tr[x]) {
        if (i.X == p) continue;
        dfs(i.X,x,i.Y);
        trsz[x] += trsz[i.X];
        if (son[x] == -1 || trsz[son[x]] < trsz[i.X]) son[x] = i.X;
    }
}
void dfs1(ll x,ll p){
    tp[x] = p;
    dfn[x] = ++t;
    if (son[x] != -1) dfs1(son[x],p);
    for (auto i:tr[x]) {
        if (i.X == anc[x][0] || i.X == son[x]) continue;
        dfs1(i.X,i.X);
    }
}
void ins(ll l,ll r,ll val){
    for (l+=t,r+=t;l<r;l>>=1,r>>=1) {
        if (l&1) {
            seg[l] = min(seg[l],val);
            l++;
        }
        if (r&1) {
            r--;
            seg[r] = min(seg[r],val);
        }
    }
}
ll qr(ll l){
    ll ret = INF;
    for (l+=n;l>0;l>>=1) ret = min(ret,seg[l]);
    return ret;
}
ll query(ll a,ll b){
    ll ret = 0;
    if (dep[a] < dep[b]) swap(a,b);
    for (ll i=0;i<MAXlg;i++) {
        if (((dep[a]-dep[b])>>i)&1) {
            ret = max(ret,mx[a][i]);
            a = anc[a][i];
        }
    }
    if (a == b) return ret;
    for (ll i=MAXlg-1;i>=0;i--) {
        if (anc[a][i] != anc[b][i]) {
            ret = max({ret,mx[a][i],mx[b][i]});
            a = anc[a][i], b = anc[b][i];
        }
    }
    ret = max({ret,mx[a][0],mx[b][0]});
    return ret;
}
int main(){
    IOS();
    cin >> n >> m;
    REP (i,n) dsu[i] = i,sz[i] = 1;
    REP (i,m) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }
    iota(id,id+m,0);
    sort(id,id+m,[&](const ll a,const ll b){return w[a] < w[b];});
    REP (i,m) {
        ll cur = id[i];
        if (fnd(u[cur]) == fnd(v[cur])) continue;
        tr_edge[cur] = true;
        mrg(u[cur],v[cur]);
        tr[u[cur]].eb(v[cur],w[cur]);
        tr[v[cur]].eb(u[cur],w[cur]);
    }
    dfs(0,0,0);
    dfs1(0,0);

    REP (i,2*MAXn) seg[i] = INF;
    REP (i,m) {
        if (!tr_edge[i]) {
            ll a = u[i], b = v[i];
            ll tpa = tp[a], tpb = tp[b];
            while (tpa != tpb) {
                if (dep[tpa] < dep[tpb]) {
                    swap(a,b);
                    swap(tpa,tpb);
                }
                ins(dfn[tpa],dfn[a]+1,w[i]);
                a = anc[tpa][0];
                tpa = tp[a];
            }
            if (dfn[a] > dfn[b]) swap(a,b);
            if (dfn[a] < dfn[b]) ins(dfn[a]+1,dfn[b]+1,w[i]);
        }
    }
    REP (i,m) {
        if (tr_edge[i]) {
            if (dfn[u[i]] < dfn[v[i]]) swap(u[i],v[i]);
            cout << qr(dfn[u[i]]) << endl;
        }
        else cout << query(u[i],v[i]) << endl;
    }
}
