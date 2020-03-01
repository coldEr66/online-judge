#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T && _x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#endif

const ll MAXn=1e2+5;
ll d[MAXn][MAXn];
int main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
        REP (i,n) REP (j,m) {
            cin >> d[i][j];
        }
        bool ok = false;
        REP1 (i,n-1) REP1 (j,m-1) {
            debug(d[i-1][j],d[i][j-1],i,j);
            if (d[i-1][j] == d[i][j-1]) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
