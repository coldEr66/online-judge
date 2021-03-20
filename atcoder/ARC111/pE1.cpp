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

const ll MAXN=1e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll floor_sum(ll n,ll m,ll a,ll b){
    ll ret = 0;
    if (a >= m) {
        ret += n * (n-1) * (a/m) / 2;
        a %= m;
    }
    if (b >= m) {
        ret += n * (b/m);
        b %= m;
    }

    ll Y = (a * (n-1) + b) / m;
    if (Y == 0) return ret;
    ll X = m * Y - b;
    ret += Y * (n - (X + a - 1) / a);
    ret += floor_sum(Y, a, m, (a - X % a) % a);
    return ret;
}
signed main(){
    IOS();
    ll t;
    cin >> t;
    while (t--) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll k = (d-2) / (c-b);
        ll R = floor_sum(k, d, c, a+c);
        ll L = floor_sum(k, d, b, a-1+b);
        cout << k - R + L << endl;
    }
}
