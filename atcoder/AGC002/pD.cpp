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

struct event{
    vector<int> qid;
    int l,r;
};
struct query{
    int u,v,w;
};
vector<ii> edge;
vector<query> Q;
int ans[MAXn];
int dsu[MAXn],sz[MAXn];
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
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    edge.eb(-1,-1);
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        edge.eb(u,v);
    }

    int q;
    cin >> q;
    vector<int> tmp;
    for (int i=0;i<q;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        Q.eb((query){u,v,w});
        tmp.eb(i);
    }
    for (int i=0;i<n;++i) {
        dsu[i] = i, sz[i] = 1;
    }
    queue<event> BFS;
    BFS.emplace((event){tmp,1,m+1});
    while (SZ(BFS)) {
        event cur = BFS.front();
        BFS.pop();
        int l = cur.l, r = cur.r;
        debug(l,r);
        if (l == r-1) {
            for (auto qq:cur.qid) ans[qq] = l;
            mrg(edge[l].X, edge[l].Y);
            continue;
        }
        
        int mid = (l + r) >> 1;
        for (int i=l;i<mid;i++) {
            mrg(edge[i].X, edge[i].Y);
            debug(i,edge[i].X,edge[i].Y);
        }
        vector<int> ql,qr;
        for (auto qq:cur.qid) {
            debug(Q[qq].u, Q[qq].v, Q[qq].w);
            debug(fnd(Q[qq].u),fnd(Q[qq].v),sz[fnd(Q[qq].u)],sz[fnd(Q[qq].v)]);
            if (fnd(Q[qq].u) == fnd(Q[qq].v)) {
                if (sz[fnd(Q[qq].u)] >= Q[qq].w) {
                    ql.eb(qq);
                }
                else qr.eb(qq);
            }
            else {
                if (sz[fnd(Q[qq].u)] + sz[fnd(Q[qq].v)] >= Q[qq].w) {
                    ql.eb(qq);
                }
                else qr.eb(qq);
            }
        }
        debug(ql,qr,r);
        if (r == m+1) {
            for (int i=0;i<n;++i) {
                dsu[i] = i, sz[i] = 1;
            }
        }
        else {
            for (int i=mid;i<r;++i) {
                mrg(edge[i].X, edge[i].Y);
            }
        }
        BFS.emplace((event){ql,l,mid});
        BFS.emplace((event){qr,mid,r});
    }
    for (int i=0;i<q;++i) {
        cout << ans[i] << endl;
    }
}
