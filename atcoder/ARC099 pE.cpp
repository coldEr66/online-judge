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

const ll MAXn=7e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n,m;
ll adj[MAXn][MAXn];
vector<ll> e[MAXn];
vector<ii> v;
bitset<MAXn> dp[2];
ll color[MAXn];
bool ok;
void dfs(ll x,ii &cur,ll c=0){
    color[x] = c;
    for (auto i:e[x]) {
        if (color[i] == color[x]) ok = true;
        else if (color[i] != -1) continue;
        else {
            if (color[x] == 1) cur.X++;
            else cur.Y++;
            dfs(i,cur,!c);
        }
    }
}
ll cal(ll x){
    ll a = x, b = n-x;
    return a*(a-1)/2 + b*(b-1)/2;
}
int main(){
    IOS();
    cin >> n >> m;
    REP (i,m) {
        ll a,b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }
    REP (i,n) for (ll j=i+1;j<n;j++) {
        if (!adj[i][j]) {
            e[i].eb(j);
            e[j].eb(i);
        }
    }
    REP (i,n) debug(e[i]);

    RST(color,-1);
    REP (i,n) if (color[i] == -1) {
        ii tmp = ii(1,0);
        dfs(i,tmp);
        debug(tmp);
        v.eb(tmp);
    }
    if (ok) return cout << -1 << endl,0;

    bool roll = 0;
    dp[roll][0] = true;
    REP (i,SZ(v)) {
        dp[!roll].reset();
        dp[!roll] |= (dp[roll]<<(v[i].X));
        dp[!roll] |= (dp[roll]<<(v[i].Y));
        roll = !roll;
    }
    debug(dp[roll]);

    ll ans = INF;
    REP (i,MAXn) {
        if (dp[roll][i]) ans = min(ans,cal(i));
    }
    cout << ans << endl;
}
