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

const ll MAXN=4e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<pii> dt[MAXN];
vector<ll> L;
ll a[MAXN], b[MAXN], c[MAXN];
map<ll,ll> mp, rmp;
ll gtPOS(ll x){
    return (ll)(lower_bound(ALL(L), x) - L.begin());
}
signed main(){
    IOS();
    ll n,C;
    cin >> n >> C;
    for (int i=0;i<n;++i) {
        cin >> a[i] >> b[i] >> c[i];
        L.eb(a[i]), L.eb(b[i]);
    }
    sort(ALL(L));
    L.resize(unique(ALL(L)) - L.begin());
    for (int i=0;i<n;++i) {
        ll ta = a[i], tb = b[i];
        a[i] = gtPOS(a[i]), b[i] = gtPOS(b[i]);
        mp[a[i]] = ta, mp[b[i]] = tb;
        rmp[ta] = a[i], rmp[tb] = b[i];

        dt[a[i]].eb(c[i], 1);
        dt[b[i]].eb(c[i],-1);
    }
    ll ans = 0;
    ll sum = 0;
    for (int i=0;i<SZ(L);++i) {
        ll curl = rmp[L[i]];
        sort(ALL(dt[curl]), [&](const pii A, const pii B){
            return A.Y > B.Y;         
        });
        
        int idx;
        for (idx = 0; idx < SZ(dt[curl]) && dt[curl][idx].Y != -1; ++idx) {
            ll cost = dt[curl][idx].X;
            sum += cost;
        }
        ans += min(C, sum);

        if (i == SZ(L) - 1) break;
        ll nxtl = rmp[L[i+1]];
        for (;idx < SZ(dt[curl]); ++idx) {
            ll cost = dt[curl][idx].X;
            sum -= cost;
        }
        ans += min(C, sum) * (mp[nxtl] - mp[curl] - 1);
    }
    cout << ans << endl;
}
