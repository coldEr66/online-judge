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

const ll MAXn=1e5+5,MAXlg=__lg(1000000000000000000)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll d[MAXn],cnt[MAXlg];
ll ans = -1;
bool vis[MAXn];
vector<ll> ee[MAXlg],v;
vector<ii> e[MAXn];
void dfs(ll x,ll root,ll dis,ll p){
    debug(x,dis);
    for (auto i:e[x]) {
        if (i.X == p) continue;
        if (i.X == root) {
            if (ans == -1) ans = dis+1;
            else ans = min(ans,dis+1);
            return;
        }
        if (vis[i.Y]) continue;
        vis[i.Y] = true;
        v.eb(i.Y);
        dfs(i.X,root,dis+1,x);
    }
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        cin >> d[i];
        ll tmp = d[i];
        ll idx = 0;
        while (tmp) {
            if (tmp&1) cnt[idx]++;
            tmp >>= 1;
            idx++;
        }
    }
    REP (i,MAXlg) if (cnt[i] >= 3) return cout << 3 << endl,0;
    REP (i,n) {
        ll tmp = d[i];
        ll idx = 0;
        while (tmp) {
            if (tmp&1) ee[idx].eb(i);
            tmp >>= 1;
            idx++;
        }
    }
    ll idx = 0;
    REP (i,MAXlg) {
        if (SZ(ee[i]) == 2) {
            e[ee[i][0]].eb(ee[i][1],idx++);
            e[ee[i][1]].eb(ee[i][0],idx++);
        }
    }
    REP (i,n) debug(e[i]);
    REP (i,n) {
        dfs(i,i,0,i);
        while (SZ(v)) {
            vis[v.back()] = false;
            v.pop_back();
        }
    }
    cout << ans << endl;
}
