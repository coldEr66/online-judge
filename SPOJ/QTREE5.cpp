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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
    int u,v,nxt;
} e[MAXn*2];
struct ST{
    priority_queue<int, vector<int>, greater<int> > pq1,pq2;
    int sz;
    void insert(int x){
        pq1.emplace(x);
        sz++;
    }
    void erase(int x){
        pq2.emplace(x);
        sz--;
    }
    void clear(){
        while (SZ(pq1) && SZ(pq2) && pq1.top() == pq2.top()) {
            pq1.pop();
            pq2.pop();
        }
    }
    void pop(){
        clear();
        pq1.pop();
    }
    int size(){return sz;}
    int top(){
        clear();
        return pq1.top();
    }
} pq[MAXn];
int head[MAXn],it;
bool col[MAXn];
int dis[MAXn][MAXlg];
int dep[MAXn],fa[MAXn];
int mx[MAXn],sz[MAXn];
vector<int> comp;
void add(int u,int v){
    e[it].u = u;
    e[it].v = v;
    e[it].nxt = head[u];
    head[u] = it++;
}
void dfs(int x,int p){
    comp.eb(x);
    sz[x] = 1, mx[x] = 0;
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p || fa[to] != INF) continue;
        dfs(to,x);
        mx[x] = max(mx[x],sz[to]);
        sz[x] += sz[to];
    }
}
void gtdis(int x,int p,int d,int lev){
    debug(x,p,d,lev);
    dis[x][lev] = d;
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p || fa[to] != INF) continue;
        gtdis(to,x,d+1,lev);
    }
}
void gtcentroid(int x,int p){
    debug(x,p);
    vector<int>().swap(comp);
    dfs(x,p);
    int root = 0;
    for (auto i:comp) {
        if (max(mx[i],SZ(comp)-sz[i]) <= SZ(comp)/2) root = i;
    }
    debug(root);
    fa[root] = p;
    if (p == -1) dep[root] = 0;
    else dep[root] = dep[p] + 1;

    gtdis(root,root,0,dep[root]);
    for (int i=head[root];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p || fa[to] != INF) continue;
        gtcentroid(to,root);
    }
}
void upd(int x){
    for (int cur=x;cur!=-1;cur=fa[cur]) {
        debug(cur);
        if (col[x]) {
            pq[cur].erase(dis[x][dep[cur]]);
        }
        else {
            pq[cur].insert(dis[x][dep[cur]]);
        }
    }
    col[x] ^= 1;
}
int qr(int x){
    int ret = INF;
    for (int cur=x;cur!=-1;cur=fa[cur]) {
        if (pq[cur].size() != 0) {
            int tmp = dis[x][dep[cur]];
            tmp += pq[cur].top();
            ret = min(ret,tmp);
        }
    }
    return ret;
}
int main(){
    IOS();
    int n;
    cin >> n;
    RST(head,-1);
    REP (i,n-1) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        add(u,v);
        add(v,u);
    }
    RST(fa,INF);
    gtcentroid(0,-1);
    int q;
    cin >> q;
    while (q--) {
        int cmd,v;
        cin >> cmd >> v;
        v--;
        if (cmd == 0) {
            upd(v);
        }
        else {
            int ans = qr(v);
            if (ans == INF) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
}
