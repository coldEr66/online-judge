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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dp[MAXn][3];
int d[MAXn];
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) cin >> d[i];
    RST(dp,INF);
    REP (i,3) if (d[0] == i-1) dp[0][i] = 0;
    REP1 (i,n-1) {
        if (d[i] == -1) {
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
            dp[i][2] = min(dp[i][2],dp[i-1][2]+2);
        }
        else if (d[i] == 0) {
            dp[i][0] = min(dp[i][0],dp[i-1][0]+1);
            dp[i][1] = min(dp[i][1],dp[i-1][0]);
            dp[i][1] = min(dp[i][1],dp[i-1][1]);
            dp[i][2] = min(dp[i][2],dp[i-1][2]+1);
        }
        else {
            dp[i][0] = min(dp[i][0],dp[i-1][0]+2);
            dp[i][1] = min(dp[i][1],dp[i-1][0]+1);
            dp[i][2] = min(dp[i][2],dp[i-1][0]);
            dp[i][2] = min(dp[i][2],dp[i-1][1]);
            dp[i][2] = min(dp[i][2],dp[i-1][2]);
        }
    }
    int ans = INF;
    REP (i,3) ans = min(ans,dp[n-1][i]);
    if (ans == INF) cout << "BRAK" << endl;
    else cout << ans << endl;
}
