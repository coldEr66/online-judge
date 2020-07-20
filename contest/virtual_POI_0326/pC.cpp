#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define SZ(a) int(a.size())
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0);
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif

const ll MAXn=1e6+5;

int h[MAXn],dp[MAXn];
deque<int> dq;
vector<int> rk;
int GTPOS(int x){
    return int(lower_bound(ALL(rk),x)-rk.begin());
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) {
        cin >> h[i];
        rk.eb(h[i]);
    }
    sort(ALL(rk));
    rk.resize(unique(ALL(rk))-rk.begin());
    REP (i,n) {
        h[i] = GTPOS(h[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        dp[0] = 0;
        dq.clear();
        dq.eb(0);
        REP1 (i,n-1) {
            while (SZ(dq) && dq.front() < i-k) dq.pop_front();
            int bst = dq.front();
            debug(bst,SZ(dq));
            dp[i] = dp[bst] + (h[bst] <= h[i]);
            while (SZ(dq) && dp[i] < dp[dq.back()]) dq.pop_back();
            while (SZ(dq) && dp[i] == dp[dq.back()] && h[i] >= h[dq.back()]) dq.pop_back();
            dq.eb(i);
            debug(i,dp[i]);
        }
        cout << dp[n-1] << endl;
    }
}
