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

int main(){
    IOS();
    ll n;
    cin >> n;
    ll a = n/7;
    a *= 2;
    ll b = n%7;
    ll ans1 = a, ans2 = a;
    if (b >= 2) ans2 += 2;
    else ans2 += b;
    if (b >= 6) ans1 += b-5;
    cout << ans1 << ' ' << ans2 << endl;
}
