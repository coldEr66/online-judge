#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct E{
    int u,v,w,nxt;
} e[MAXn*2];
struct PQ{
    priority_queue<int> pq1,pq2;
    int sz = 0;
    void insert(int x){
        pq1.emplace(x);
        sz++;
    }
    void erase(int x){
        pq2.emplace(x);
        sz--;
    }
    void pop(){
        clear_top();
        pq1.pop();
        sz--;
    }
    int size(){return sz;}
    void clear_top(){
        while (SZ(pq1) && SZ(pq2) && pq1.top() == pq2.top()) {
            pq1.pop(), pq2.pop();
        }
    }
    int top(){
        clear_top();
        return pq1.top();
    }
} ans,child[MAXn],cen[MAXn];
int it,head[MAXn];
int dep[MAXn];
int sz[MAXn],fa[MAXn],mx[MAXn];
int dis[MAXlg][MAXn];
vector<int> tmp;
bool col[MAXn];
void addedge(int u,int v,int w){
    e[it].u = u;
    e[it].v = v;
    e[it].w = w;
    e[it].nxt = head[u];
    head[u] = it++;
}
void SZdfs(int x,int p){
    sz[x] = 1, mx[x] = 0;
    tmp.eb(x);
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p || fa[to] != INF) continue;
        SZdfs(to,x);
        mx[x] = max(mx[x],sz[to]);
        sz[x] += sz[to];
    }
}
void gtdis(int x,int p,int d,int lev,int root){
    dis[lev][x] = d;
    if (lev != 0) cen[root].insert(dis[lev-1][x]);
    for (int i=head[x];i!=-1;i=e[i].nxt) {
        int to = e[i].v, w = e[i].w;
        if (to == p || fa[to] != INF) continue;
        gtdis(to,x,d+w,lev,root);
    }
}
void gtcentroid(int x,int p){
    vector<int>().swap(tmp);
    SZdfs(x,p);
    int root = -1;
    for (auto i:tmp) {
        if (max(mx[i],SZ(tmp) - sz[i]) <= SZ(tmp)/2) {
            root = i;
        }
    }
    debug(x,p,root);
    fa[root] = p;
    if (p == -1) dep[root] = 0;
    else dep[root] = dep[p] + 1;
    gtdis(root,root,0,dep[root],root);
    debug("ALIVE",x);

    for (int i=head[root];i!=-1;i=e[i].nxt) {
        int to = e[i].v;
        if (to == p || fa[to] != INF) continue;
        gtcentroid(to,root);
    }
}
int gtmax(int x){
    if (child[x].size() < 2) return -INF;
    int tp = child[x].top();
    child[x].pop();
    int ret = tp + child[x].top();
    child[x].insert(tp);
    return ret;
}
void upd(int x){
    ans.erase(gtmax(x));
    if (!col[x]) child[x].erase(0);
    for (int cur=x;fa[cur] != -1;cur=fa[cur]) {
        ans.erase(gtmax(fa[cur]));
        if (cen[cur].size() != 0) child[fa[cur]].erase(cen[cur].top());
        if (!col[x]) cen[cur].erase(dis[dep[fa[cur]]][x]);
    }

    col[x] = !col[x];
    if (!col[x]) child[x].insert(0);
    ans.insert(gtmax(x));

    for (int cur=x;fa[cur] != -1;cur=fa[cur]) {
        if (!col[x]) cen[cur].insert(dis[dep[fa[cur]]][x]);
        if (cen[cur].size() != 0) child[fa[cur]].insert(cen[cur].top());
        ans.insert(gtmax(fa[cur]));
    }
}
int main(){
    IOS();
    int n;
    cin >> n;
    RST(head,-1);
    RST(fa,INF);
    REP (i,n-1) {
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        addedge(u,v,w);
        addedge(v,u,w);
    }

    gtcentroid(0,-1);
    REP (i,n) {
        child[i].insert(0);
        if (fa[i] == -1) continue;
        if (cen[i].size() > 0) child[fa[i]].insert(cen[i].top());
    }
    REP (i,n) {
        int cur = gtmax(i);
        debug(cur);
        if (cur == -INF) continue;
        ans.insert(cur);
    }

    int cnt = n;
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'A') {
            if (cnt == 0) cout << "They have disappeared." << endl;
            else if (cnt == 1) cout << 0 << endl;
            else cout << max(ans.top(),0) << endl;
        }
        else {
            int x;
            cin >> x;
            x--;
            if (col[x]) cnt++;
            else cnt--;
            upd(x);
        }
    }
}
