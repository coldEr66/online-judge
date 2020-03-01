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

const ll MAXn=2e5+5;

ll d[MAXn];
ii b[MAXn];
map<ll,ll> cnt;
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    ll m;
    cin >> m;
    REP (i,m) cin >> b[i].X;
    REP (i,m) cin >> b[i].Y;

    ll ans = 0;
    REP (i,m) {
        if (cnt[b[i].X] > cnt[b[ans].X]) ans = i;
        else if (cnt[b[i].X] == cnt[b[ans].X] && cnt[b[i].Y] > cnt[b[ans].Y]) ans = i;
    }
    cout << ans+1 << endl;
}
