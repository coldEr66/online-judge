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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int mx[MAXn],mn[MAXn];
int dp[MAXn];
vector<int> rk;
signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rk.clear();
        for (int i=0;i<=n;++i) {
            mx[i] = 0, mn[i] = INF;
            dp[i] = 0;
        }
        for (int i=1;i<=n;++i) {
            int x;
            cin >> x;
            rk.eb(x);
            mx[x] = max(mx[x],i);
            mn[x] = min(mn[x],i);
        }
        sort(ALL(rk));
        rk.resize(unique(ALL(rk)) - rk.begin());
        int ans = n+1;
        for (int i=SZ(rk)-1;i>=0;i--) {
            if (i == SZ(rk)-1) dp[i] = 1;
            else {
                if (mx[rk[i]] < mn[rk[i+1]]) dp[i] = dp[i+1] + 1;
                else dp[i] = 1;
            }
            ans = min(ans,SZ(rk) - dp[i]);
        }
        cout << ans << endl;
    }
}