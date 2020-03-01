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

const ll MAXn=2e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const int mod = 101;

ll dp[MAXn][MAXn][5][mod];
int tpow[] = {10,100,91,1};
void add(ll &a,ll b){
    a = a + b;
    if (a >= MOD) a -= MOD;
}
void sub(ll &a,ll b){
    a = a - b;
    if (a < 0) a += MOD;
}
int gt(char l,char r,int rem,int len){
    int ret = int(r-'0') + rem * 10 + (int(l-'0') * tpow[len]);
    ret %= mod;
    return ret;
}
int main(){
    IOS();
    int n;
    cin >> n;
    string s;
    cin >> s;
    REP1 (i,n) {
        dp[i+1][i][0][0] = 1;
        dp[i][i][0][0] = 1;
        dp[i][i][1][s[i-1]-'0'] = 1;
    }
    for (int len=2;len<=n;len++) {
        REP1 (l,n) {
            int r = l + len - 1;
            if (r > n) break;
            REP (curlen,4) {
                REP (rem,mod) {
                    add(dp[l][r][curlen][rem],dp[l+1][r][curlen][rem]);
                    add(dp[l][r][curlen][rem],dp[l][r-1][curlen][rem]);
                    sub(dp[l][r][curlen][rem],dp[l+1][r-1][curlen][rem]);
                    if (s[l-1] == s[r-1]) {
                        add(dp[l][r][(curlen+2)%4][gt(s[l-1],s[r-1],rem,curlen)],dp[l+1][r-1][curlen][rem]);
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP (i,4) {
        add(ans,dp[1][n][i][0]);
        debug(dp[1][n][i][0],i);
    }
    sub(ans,1);
    cout << ans << endl;
}
