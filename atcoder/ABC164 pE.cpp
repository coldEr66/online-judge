#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
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

const ll MAXn=55,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct edge{
    ll to,a,b;
};
vector<edge> e[MAXn];
ll dp[MAXn][MAXn*MAXn];
ll c[MAXn],d[MAXn];
int main(){
    IOS();
    ll n,m,s;
    cin >> n >> m >> s;
    ll mx = 0;
    REP (i,m) {
        ll u,v;
        cin >> u >> v;
        u--, v--;
        ll a,b;
        cin >> a >> b;
        mx = max(mx,a);
        e[u].eb((edge){v,a,b});
        e[v].eb((edge){u,a,b});
    }
    mx *= (n-1);
    REP (i,n) cin >> c[i] >> d[i];

    priority_queue<iii,vector<iii>,greater<iii> > pq;
    RST(dp,INF);
    dp[0][min(s,mx)] = 0;
    pq.emplace(0,ii(0,min(s,mx)));
    while (SZ(pq)) {
        ll cur = pq.top().Y.X, money = pq.top().Y.Y;
        ll curdis = pq.top().X;
        pq.pop();
        if (dp[cur][money] != curdis) continue;
        if (dp[cur][min(money + c[cur],mx)] > dp[cur][money] + d[cur]) {
            dp[cur][min(money + c[cur],mx)] = dp[cur][money] + d[cur];
            pq.emplace(dp[cur][min(money + c[cur],mx)],ii(cur,min(money + c[cur],mx)));
        }
        for (auto i:e[cur]) {
            ll to = i.to, a = i.a, b = i.b;
            if (money < a) continue;
            if (dp[to][money-a] > dp[cur][money] + b) {
                dp[to][money-a] = dp[cur][money] + b;
                pq.emplace(dp[to][money-a],ii(to,money-a));
            }
        }
    }
    REP1 (i,n-1) {
        ll ans = INF;
        REP (j,mx+1) {
            ans = min(ans,dp[i][j]);
        }
        cout << ans << endl;
    }
}
