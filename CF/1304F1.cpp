#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=55,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXm=2e4+5;

int sum[MAXn][MAXm];
int dp[MAXn][MAXm];
int lm[MAXn][MAXm],rm[MAXn][MAXm];
int gtsum(int i,int j,int k){
    return sum[i][k] - sum[i][j-1];
}
int main(){
    IOS();
    int n,m,k;
    cin >> n >> m >> k;
    REP1 (i,n) {
        REP1 (j,m) {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j-1];
        }
    }

    REP1 (i,n) {
        for (int j=1;j<=m-k+1;j++) {
            int cnt = gtsum(i,j,j+k-1) + gtsum(i+1,j,j+k-1);
            if (i == 1) {
                dp[i][j] = cnt;
                continue;
            }
            int ret = 0;
            for (int x=max(1,j-k+1);x<=min(m-k+1,j+k-1);x++) {
                ret = max(ret,dp[i-1][x] + cnt - gtsum(i,max(j,x),min(j,x)+k-1));
            }
            dp[i][j] = ret;
            if (j-k > 0) dp[i][j] = max(dp[i][j],lm[i-1][j-k] + cnt);
            if (j+k <= m-k+1) dp[i][j] = max(dp[i][j],rm[i-1][j+k] + cnt);
        }
        REP1 (j,m-k+1) lm[i][j] = max(lm[i][j-1],dp[i][j]);
        for (int j=m-k+1;j>=1;j--) rm[i][j] = max(rm[i][j+1],dp[i][j]);
    }

    int ans = 0;
    REP1 (i,m) ans = max(ans,dp[n][i]);
    cout << ans << endl;
}
