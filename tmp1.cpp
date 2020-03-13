#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn=1e3+5;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dp[MAXn][MAXn];
ll c[MAXn][MAXn];
ll s[MAXn][MAXn];
ll cal(ll l,ll r){
    if (l > r) return 0;
    if (dp[l][r] != -INF) return dp[l][r];
    ll ret = c[l][r] + cal(l+1,r-1);
    for (ll i=l;i<r;i++) {
        ret = max(ret,cal(l,i) + cal(i+1,r));
    }
    return dp[l][r] = ret;
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,MAXn) REP (j,MAXn) dp[i][j] = -INF;
    REP1 (i,n) REP1 (j,n) {
        cin >> c[i][j];
        if (i >= j) dp[i][j] = 0;
    }



    cout << cal(1,n) << endl;
}