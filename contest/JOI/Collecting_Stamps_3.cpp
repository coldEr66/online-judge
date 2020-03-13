#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RREP(i,n) for (ll i=n-1;i>=0;i--)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
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

const ll MAXn=205,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dp[MAXn][MAXn][MAXn][2];
ll x[MAXn],T[MAXn];
int main(){
    IOS();
    ll n,L;
    cin >> n >> L;
    x[0] = 0, x[n+1] = L;
    T[0] = T[n+1] = -1;
    REP1 (i,n) cin >> x[i];
    REP1 (i,n) cin >> T[i];

    REP (i,n+2) REP (j,n+2) REP (k,n+2) REP (l,2) dp[i][j][k][l] = INF;
    dp[n+1][0][0][0] = 0;
    ll ans = 0;
    REP (len,n+1) {
        REP (j,n+1) {
            ll i = (j - len + n+1);
            if (i > n+1) continue;
            REP (k,n+1) {
                if (dp[i][j][k][0] != INF || dp[i][j][k][1] != INF) {
                    ans = max(ans,k);
                }
                if (j + 1 == i) continue;
                ll tmp;
                if (dp[i][j][k][0] != INF) {
                    debug(i,j,k);
                    ans = max(ans,k);
                    if (i > 0) {
                        tmp = dp[i][j][k][0] + x[j] + L - x[i-1];
                        dp[i-1][j][k+(tmp<=T[i-1])][1] = min(dp[i-1][j][k+(tmp<=T[i-1])][1],tmp);
                    }
                    if (j <= n) {
                        tmp = dp[i][j][k][0] + x[j+1] - x[j];
                        dp[i][j+1][k+(tmp<=T[j+1])][0] = min(dp[i][j+1][k+(tmp<=T[j+1])][0],tmp);
                    }
                }
                if (dp[i][j][k][1] != INF) {
                    debug(i,j,k);
                    ans = max(ans,k);
                    if (i > 0) {
                        tmp = dp[i][j][k][1] + x[i] - x[i-1];
                        dp[i-1][j][k+(tmp<=T[i-1])][1] = min(dp[i-1][j][k+(tmp<=T[i-1])][1],tmp);
                    }
                    if (j <= n) {
                        tmp = dp[i][j][k][1] + x[j+1] + L - x[i];
                        dp[i][j+1][k+(tmp<=T[j+1])][0] = min(dp[i][j+1][k+(tmp<=T[j+1])][0],tmp);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
