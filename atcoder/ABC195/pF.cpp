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

const ll MAXN=80,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll fpow(ll a,ll b){
    ll ret = 1;
    while (b) {
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}
vector<ll> prime;
int main(){
    IOS();
    ll a,b;
    cin >> a >> b;
    for (int i=2;i<=b-a;++i) {
        bool fg = true;
        for (int j=2;j*j<=i;++j) {
            if (i % j == 0) fg = false;
        }
        if (fg) prime.eb(i);
    }
    debug(prime);
    int np = SZ(prime);
    vector<int> d(b-a+1, 0);
    int zero = 0;
    for (int i=0;i<=b-a;++i) {
        for (int j=0;j<np;++j) {
            if ((a + i) % prime[j] == 0) {
                d[i] += (1<<j);
            }
        }
        if (d[i] == 0) zero++;
    }

    vector<ll> dp(1<<np, 0);
    dp[0] = 1;
    for (int i=0;i<=b-a;++i) {
        for (int mask=0;mask < (1<<np);++mask) {
            if (!d[i] || (mask & d[i])) continue;
            int nxt = mask | d[i];
            dp[nxt] += dp[mask];
        }
    }

    ll ans = 0;
    for (int mask=0;mask < (1<<np);++mask) {
        ans += dp[mask];
    }
    ans *= fpow(2, zero);
    cout << ans << endl;
}
