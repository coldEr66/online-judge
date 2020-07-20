#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x, S && ..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif

const ll MAXn=5e5+5;

int main(){
    IOS();
    ll n,X;
    cin >> n >> X;
    ll l=0, r=0, lst = 0;
    REP (i,n) {
        ll x,a,b;
        cin >> x >> a >> b;
        a++, b--;
        a += x, b += x;
        if (a&1) a++;
        if (b&1) b--;
        ll dx = x - lst;
        l = max(l,a);
        r = min(r+2*dx,b);
        lst = x;
        if (l > r) return cout << "NIE" << endl,0;
    }
    cout << l/2 << endl;
}
