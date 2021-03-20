#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,m;
int dp[MAXN][2];
int DP[MAXN][2][2];
vector<int> e[MAXN];
void dfs(int x,int p){
    dp[x][0] = 0;
    dp[x][1] = 1;
    for (auto i:e[x]) {
        if (i == p || i < n) continue;
        dfs(i,x);
        dp[x][0] += dp[i][1];
        dp[x][1] += min(dp[i][0],dp[i][1]);
    }
}
signed main(){
    IOS();
    cin >> n >> m;
    for (int i=0;i<n+m;++i) {
        int u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    for (int i=0;i<n;++i) {
        dfs(i,i);
    }
    DP[0][0][0] = dp[0][0];
    DP[0][1][1] = dp[0][1];
    DP[0][1][0] = DP[0][0][1] = INF;
    for (int i=1;i<n;++i) {
        if (i == n-1) {
            DP[i][0][0] = INF;
        }
        else {
            DP[i][0][0] = DP[i-1][1][0] + dp[i][0];
        }
        DP[i][0][1] = DP[i-1][1][1] + dp[i][0];
        DP[i][1][0] = min(DP[i-1][0][0],DP[i-1][1][0]) + dp[i][1];
        DP[i][1][1] = min(DP[i-1][0][1],DP[i-1][1][1]) + dp[i][1];
    }
    int ans = INF;
    for (int i=0;i<2;++i) for (int j=0;j<2;++j) ans = min(ans,DP[n-1][i][j]);
    cout << ans << endl;
}
