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

const ll MAXN=3e2+5,MAXlg=__lg(MAXN)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll add(ll a, ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a, ll b){
    ll ret = a - b;
    if (ret < 0) ret += MOD;
    return ret;
}
signed main(){
    IOS();
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> d;
    int cnt = 0, tt = 0;
    for (int i = 0; i < SZ(s); ++i) {
        if (s[i] == '0') {
            d.eb(cnt);
            cnt = 0;
        }
        else {
            cnt++;
            tt++;
        }
    }
    d.eb(cnt);
    reverse(ALL(d));
    k = min(k,tt);
    
    vector<vector<ll>> dp(k+2, vector<ll>(k+2, 0));
    dp[0][0] = 1;
    for (auto cur : d) {
        vector<vector<ll>> dpsum(k+2, vector<ll>(k+2, 0)), dp1(tt+2, vector<ll>(k+2, 0));
        dp1 = dp;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < k; ++j) {
                dp1[i][j] = add(dp1[i][j], dp1[i-1][j+1]);
            }
        }
        debug(cur);
        for (int i = 0; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                dpsum[i][j] = add(dpsum[i][j-1],dp[i][j-1]);
                if (j > cur) dpsum[i][j] = sub(dpsum[i][j], dp[i][j-cur-1]);
            }
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = add(dp1[i][j], dpsum[i][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = add(ans,dp[i][0]);
    }
    cout << ans << endl;
}
