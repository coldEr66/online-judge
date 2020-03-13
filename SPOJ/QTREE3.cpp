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
    fprintf(stderr,"LINE: %d (%s) = ",__LINE__,#__VA_ARGS__);\
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
    int u,v,nxt;
} e[MAXn*2];
int head[MAXn],it;
int dfn[MAXn],idx,fa[MAXn],tp[MAXn];
int sz[MAXn],son[MAXn],id[MAXn];
int seg[MAXn*2];
int col[MAXn];
void addedge(int u,int v){
    e[it].u = u;
    e[it].v = v;
    e[it].nxt = head[u];
    head[u] = it++;
}
void dfs(int x,int p){
    fa[x] = p;
    son[x] = 0;
    sz[x] = 1;
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p) continue;
        dfs(to,x);
        if (sz[to] > sz[son[x]]) son[x] = to;
        sz[x] += sz[to];
    }
}
void dfs1(int x,int t) {
    // debug(x,fa[x],son[x]);
    dfn[x] = idx;
    id[idx++] = x;
    tp[x] = t;
    if (son[x]) dfs1(son[x],t);
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == fa[x] || to == son[x]) continue;
        dfs1(to,to);
    }
}
void ins(int x,int v){
    for (seg[x+=idx]=v;x>1;x>>=1) {
        seg[x>>1] = max(seg[x],seg[x^1]);
    }
}
int qr(int l,int r){
    int ret = 0;
    for (l+=idx,r+=idx;l<r;l>>=1,r>>=1) {
        if (l&1) ret = max(ret,seg[l++]);
        if (r&1) ret = max(ret,seg[--r]);
    }
    return ret;
}
int cal(int x){
    int ret = -1;
    while (x != 0) {
        debug(x);
        int tx = tp[x];
        int l = dfn[tx], r = dfn[x]+1;
        while (l != r-1) {
            int mid = (l+r)>>1;
            int tmp = qr(l,mid);
            if (tmp == 1) r = mid;
            else l = mid;
        }
        debug(l,id[l]);
        if (qr(l,r) == 1) ret = id[l];
        x = fa[tx];
    }
    return ret;
}
int main(){
    IOS();
    int n,q;
    cin >> n >> q;
    RST(head,-1);
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,0);
    dfs1(1,1);

    while (q--) {
        int cmd,v;
        cin >> cmd >> v;
        if (cmd == 0) {
            col[v] ^= 1;
            ins(dfn[v],col[v]);
        }
        else {
            cout << cal(v) << endl;
        }
    }
}
