#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2003,MAXlg=__lg(MAXn)+2;
const ll MOD=924844033;
const ll INF=0x3f3f3f3f;

ll dp[MAXn][MAXn];
vector<ll> len;
ll cnt_m[MAXn][MAXn];
vector<ii> item;
ll fac[MAXn];
ll add(ll a,ll b){
    ll ret = a+b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a-b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a*b%MOD;
}
int main(){
    IOS();
    ll n,k;
    cin >> n >> k;
    fac[0] = 1;
    for (ll i=1;i<=n;++i) {
        fac[i] = mul(fac[i-1],i);
    }
    for (ll i=1;i<k+1;i++) {
        ll cnt = 0;
        for (ll j=i;j<=n;j+=k) {
            cnt++;
        }
        if (cnt-1 != 0) {
            len.eb(cnt-1);
            len.eb(cnt-1);
        }
    }
    
    dp[0][0] = 1;
    for (ll i=1;i<=n;++i) {
        dp[i][0] = 1;
        for (ll j=1;j<=i;++j) {
            if (i >= 2) dp[i][j] = add(dp[i-1][j],dp[i-2][j-1]);
            else dp[i][j] = 1;
        }
    }
    cnt_m[0][0] = 1;
    for (int i=0;i<SZ(len);++i) {
        for (ll m=0;m<=n;++m) {
            cnt_m[i+1][m] = cnt_m[i][m];
        }
        ll cur = len[i];
        for (ll j=1;j<=cur;++j) {
            for (ll m=0;m<=n;++m) {
                if (m < j) continue;
                cnt_m[i+1][m] = add(cnt_m[i+1][m],mul(dp[cur][j],cnt_m[i][m-j]));
            }
        }
    }
    
    ll ans = 0;
    for (ll i=0;i<=n;++i) {
        ll cur = mul(cnt_m[SZ(len)][i],fac[n-i]);
        if (i&1) ans = sub(ans,cur);
        else ans = add(ans,cur);
    }
    cout << ans << endl;
}
