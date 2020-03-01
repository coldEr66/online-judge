#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()
#define eb emplace_back
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S>void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
#define IOS()
#else
#define debug(...)
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const ll MAXn=1e5+5;

ll n,k;
ll a[MAXn],b[MAXn];
vector<ll> tmp;
bool chk(ll x){
    tmp.clear();
    REP (i,n) {
        tmp.eb(x*a[i]);
    }
    ll cnt = 0;
    REP (i,n) {
        if (tmp[i] - b[i] > k) return false;
        cnt += max(0LL,tmp[i] - b[i]);
    }
    debug(cnt);
    return cnt <= k;
}
int main(){
    IOS();
    cin >> n >> k;
    REP (i,n) cin >> a[i];
    REP (i,n) cin >> b[i];

    ll l=0,r=3e9;
    while (l != r-1) {
        ll mid = (l+r)>>1;
        if (chk(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}
