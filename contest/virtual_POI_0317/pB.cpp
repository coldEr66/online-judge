#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define eb emplace_back
#define X first
#define Y second
#define SZ(a) (int)a.size()
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

const ll MAXn=1e6+5;

ll d[MAXn];
int main(){
    IOS();
    ll B,q;
    cin >> B >> q;
    ll mod = 0;
    REP (i,B) {
        cin >> d[i];
        mod = (mod + (d[i] * i) % (B-1)) % (B-1);
    }
    debug(mod);
    if (mod != 0) d[mod]--;
    vector<ii> v;
    REP (i,B) {
        if (d[i] == 0) continue;
        v.eb(d[i],i);
    }
    REP (i,SZ(v)) {
        if (i) v[i].X += v[i-1].X;
        debug(v[i].X,v[i].Y);
    }
    while (q--) {
        ll x;
        cin >> x;
        x++;
        ll l=-1, r=SZ(v);
        while (l != r-1) {
            ll mid = (l+r)>>1;
            if (v[mid].X < x) l = mid;
            else r = mid;
        }
        if (r != SZ(v)) cout << v[r].Y << endl;
        else cout << -1 << endl;
    }
}
