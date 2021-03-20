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

const ll MAXN=1e2+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXA=1e4+5;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXA]; 
signed main(){
    IOS();
    int n;
    cin >> n;
    int tt = 0, B = 0;
    for (int i=1;i<=n;++i) {
        cin >> a[i] >> b[i];
        tt += a[i], B += b[i];
    }
    memset(dp,-0x3f,sizeof(dp));
    debug(dp[0][0]);
    dp[0][0] = 0;
    for (int i=1;i<=n;++i) {
        for (int j=i;j>=1;--j) {
            for (int A=tt;A>=a[i];--A) {
                dp[j][A] = max(dp[j][A], dp[j-1][A-a[i]] + b[i]);
            }
        }
    }

    cout << fixed << setprecision(15);
    for (int i=1;i<=n;++i) {
        int ans = 0;
        for (int A=0;A<=tt;++A) {
            ans = max(ans, min(dp[i][A] + B, 2 * A));
        }
        cout << (double)ans / 2.0 << endl;
    }
}
