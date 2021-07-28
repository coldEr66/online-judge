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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll C = 2000;
const ll M = 4e3+5;

int a[MAXn],b[MAXn];
int dp[M][M], grid[M][M];
int mod2 = 500000004;
int add(int x,int y){
    int ret = x + y;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x,int y){
    int ret = x - y;
    if (ret < 0) ret += MOD;
    return ret;
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) {
        cin >> a[i] >> b[i];
        dp[a[i]+C][b[i]+C]++;
    }
    for (int i=2*C;i>=0;i--) {
        for (int j=2*C;j>=0;j--) {
            dp[i][j] = add(dp[i][j],add(dp[i+1][j],dp[i][j+1]));
        }
    }
    grid[0][0] = 1;
    REP (i,2*C+1) REP (j,2*C+1) {
        if (i) grid[i][j] = add(grid[i][j],grid[i-1][j]);
        if (j) grid[i][j] = add(grid[i][j],grid[i][j-1]);
    }

    ll ans = 0;
    REP (i,n) {
        ans = add(ans,dp[C-a[i]][C-b[i]]);
        ans = sub(ans,grid[2*a[i]][2*b[i]]);
    }
    ans = ans*mod2 % MOD;
    cout << ans << endl;
}