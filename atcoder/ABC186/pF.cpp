#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordset;
pll d[MAXN];
vector<ll> dx[MAXN], dy[MAXN];
vector<pll> dt;
signed main(){
    IOS();
    ll n,m,k;
    cin >> n >> m >> k;
    ll nn = n, mm = m;
    for (int i=0;i<k;++i) {
        cin >> d[i].X >> d[i].Y;
        d[i].X--, d[i].Y--;
        if (d[i].X == 0) mm = min(mm, d[i].Y);
        if (d[i].Y == 0) nn = min(nn, d[i].X);
    }

    for (int i=0;i<k;++i) {
        dx[d[i].X].eb(d[i].Y);
        dy[d[i].Y].eb(d[i].X);
        dt.eb(d[i].X, d[i].Y);
    }
    debug(dt,n,m);
    for (int i=0;i<MAXN;++i) {
        sort(ALL(dx[i]));
        sort(ALL(dy[i]));
    }

    debug("alive");
    ll ans = 0;
    for (int i=0;i<nn;++i) {
        if (SZ(dx[i])) ans += dx[i][0];
        else ans += m;
    }
    
    sort(ALL(dt), [&](const pll a, const pll b){
        if (a.Y != b.Y) return a.Y < b.Y;
        return a.X < b.X;
    });
    debug(ans);
    ordset st;
    ll lst = -1;
    for (int i=0;i<SZ(dt);++i) {
        int idx = i;
        lst = dt[i].Y;
        if (dt[i].Y == mm) break;
        while (idx < SZ(dt) && dt[idx].Y == dt[i].Y) {
            if (dt[idx].X < nn) st.insert(dt[idx].X);
            idx++;
        }
        debug(i);
        if (idx == SZ(dt) || dt[idx].Y == mm) break;
        ans += (dt[idx].Y - dt[i].Y - 1) * (SZ(st) + n - nn);
        ll cur = dy[dt[idx].Y][0];
        ans += st.order_of_key(cur);
        if (cur > nn) ans += (cur - nn);
        i = idx-1;
        debug(ans);
    }
    if (SZ(dt)) {
        ans += (mm - lst - 1) * (SZ(st) + n - nn);
    }
    cout << ans << endl;
}
