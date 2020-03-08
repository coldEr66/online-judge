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

vector<int> e[MAXn];
vector<ii> edg;
int vis[MAXn];
int sz[MAXn],d[MAXn],nei[MAXn];
int idx;
void dfs(int x){
    debug(x);
    vis[x] = idx;
    sz[idx]++;
    for (auto i:e[x]) {
        if (!vis[i]) dfs(i);
    }
}
int main(){
    IOS();
    int n,m,k;
    cin >> n >> m >> k;
    REP (i,m) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        e[u].eb(v);
        e[v].eb(u);
        nei[u]++, nei[v]++;
    }
    REP (i,k) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        edg.eb(u,v);
    }
    REP (i,n) {
        if (!vis[i]) {
            idx++;
            dfs(i);
        }
    }
    REP (i,SZ(edg)) {
        if (vis[edg[i].X] == vis[edg[i].Y]) {
            d[edg[i].X]++, d[edg[i].Y]++;
        }
    }
    pary(sz+1,sz+idx+1);
    pary(nei,nei+n);
    pary(d,d+n);
    pary(vis,vis+n);
    REP (i,n) {
        cout << sz[vis[i]] - nei[i] - 1 - d[i] << " \n"[i==n-1];
    }
}
