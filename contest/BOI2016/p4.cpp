#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops,O3")
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif

const int MAXn=20;
const int INF=0x3f3f3f3f;

int n,k,m;
int dp[1<<MAXn];
int I;
vector<ii> e[MAXn];
int ans = INF;
void cal(int mask){
    if ((mask&I) == I) ans = min(ans,dp[mask]);
    if (dp[mask] != INF) return;
    REP (i,n) {
        if (mask&(1<<i)) {
            for (auto it:e[i]) {
                int nxt = it.X, w = it.Y;
                if (mask&(1<<nxt)) {
                    cal(mask^(1<<nxt));
                    dp[mask] = min(dp[mask],dp[mask^(1<<nxt)] + w);
                }
            }
        }
    }
    if ((mask&I) == I) ans = min(ans,dp[mask]);
}
int main(){
    IOS();
    cin >> n >> k >> m;
    REP (i,k) {
        int x;
        cin >> x;
        x--;
        I |= (1<<x);
    }
    REP (i,m) {
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        e[u].eb(v,w);
        e[v].eb(u,w);
    }
    debug(I);
    REP (i,1<<n) dp[i] = INF;
    dp[0] = 0;
    REP (i,n) dp[1<<i] = 0;
    cal((1<<n)-1);
    cout << ans << endl;
}
