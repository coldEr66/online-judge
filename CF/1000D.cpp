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

const ll MAXN=1e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll dp[MAXN],d[MAXN];
ll C[MAXN][MAXN];
ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a * b % MOD;
}
void build(){
    for (int i=0;i<MAXN;++i) {
        for (int j=0;j<=i;++j) {
            if (!j || j == i) C[i][j] = 1;
            else {
                C[i][j] = add(C[i-1][j],C[i-1][j-1]);
            }
        }
    }
}
signed main(){
    IOS();
    build();
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i=1;i<=n;++i) {
        cin >> d[i];
        dp[i] = dp[i-1];
        for (int j=i-1;j>0;--j) {
            if (d[j] <= 0 || d[j] >= n) continue;
            dp[i] = add(dp[i],mul(C[i-j-1][d[j]-1],dp[j-1]));
        }
    }
    dp[n]--;
    if (dp[n] < 0) dp[n] += MOD;
    cout << dp[n] << endl;
}
