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

const ll MAXn=1e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

vector<ii> e[MAXn];
vector<ll> tr[MAXn];
ll par[MAXn],dis[MAXn],c[MAXn],dp[MAXn];
priority_queue<ii,vector<ii>,greater<ii> > pq;
bitset<MAXn> vis;
void dfs(ll x,ll p){
    dp[x] = c[x];
    for (auto i:tr[x]) {
        if (i == p) continue;
        dfs(i,x);
        dp[x] += dp[i];
    }
}
int main(){
    IOS();
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    ll n,m,T;
    cin >> n >> m >> T;
    REP (i,n) {
        cin >> c[i];
        dis[i] = INF;
    }
    REP (i,m) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        e[u].eb(v,w);
        e[v].eb(u,w);
    }

    dis[0] = 0;
    pq.emplace(0,0);
    REP (i,n) {
        ll tp = -1;
        while (SZ(pq) && vis[tp = pq.top().Y]) pq.pop();
        if (tp == -1) break;
        vis[tp] = true;
        for (auto it:e[tp]) {
            if (dis[it.X] > dis[tp]+it.Y || (dis[it.X] == dis[tp]+it.Y && tp < par[it.X])) {
                dis[it.X] = dis[tp]+it.Y;
                par[it.X] = tp;
                pq.emplace(dis[it.X],it.X);
            }
        }
    }

    pary(dis,dis+n);
    pary(par,par+n);
    REP1 (i,n-1) {
        tr[i].eb(par[i]);
        tr[par[i]].eb(i);
    }
    dfs(0,0);
    pary(dp,dp+n);

    ll ans = 0;
    REP1 (i,n-1) ans = max(ans,(dis[i]-T)*dp[i]);
    cout << ans << endl;
}
