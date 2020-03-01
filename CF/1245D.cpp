#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RREP(i,n) for (ll i=n-1;i>=0;i--)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
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

const ll MAXn=2035,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct edg{
    ll u,v,w;
    bool operator < (const edg &a) const {
        return w < a.w;
    }
};
ii d[MAXn];
ll c[MAXn];
ll k[MAXn];
ll dsu[MAXn],sz[MAXn];
ll gt(ll x,ll y){
    ll dis = abs(d[x].X - d[y].X) + abs(d[x].Y - d[y].Y);
    debug(x,y,dis * (k[x] + k[y]));
    return dis * (k[x] + k[y]);
}
ll fnd(ll x){
    if (x == dsu[x]) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(ll x,ll y){
    x = fnd(x), y = fnd(y);
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y];
}
int main(){
    IOS();
    ll n;
    cin >> n;
    sz[0] = 1;
    REP1 (i,n) {
        cin >> d[i].X >> d[i].Y;
        dsu[i] = i, sz[i] = 1;
    }
    vector<edg> edge;
    REP1 (i,n) {
        cin >> c[i];
        edge.eb((edg){0,i,c[i]});
    }
    REP1 (i,n) cin >> k[i];
    REP1 (i,n) for (ll j=i+1;j<=n;j++) {
        edge.eb((edg){i,j,gt(i,j)});
    }
    sort(ALL(edge));
    ll ans = 0;
    vector<ii> wire;
    vector<ll> city;
    REP (i,SZ(edge)) {
        ll u = edge[i].u, v = edge[i].v;
        ll w = edge[i].w;
        if (fnd(u) == fnd(v)) continue;
        mrg(u,v);
        ans += w;
        if (u != 0 && v != 0) {
            wire.eb(u,v);
        }
        else {
            if (u == 0) swap(u,v);
            city.eb(u);
        }
    }
    cout << ans << endl;
    cout << SZ(city) << endl;
    REP (i,SZ(city)) cout << city[i] << " \n"[i==SZ(city)-1];
    cout << SZ(wire) << endl;
    REP (i,SZ(wire)) cout << wire[i].X << ' ' << wire[i].Y << endl;
}
