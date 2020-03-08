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

const ll MAXn=(1<<17),MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=1<<28;

int dp[MAXn][4];
int ok[MAXn*2];
int main(){
    IOS();
    int n,K;
    cin >> n >> K;
    REP (i,K) {
        int x;
        cin >> x;
        x--;
        ok[x + (1<<n)] = 1;
    }
    REP (i,MAXn) REP (j,4) {
        dp[i][j] = -1;
    }
    for (int i=(1<<n)-1;i >= (1<<(n-1));i--) {
        int cur = ok[i<<1] + ok[i<<1|1];
        debug(cur);
        if (cur == 2) {
            dp[i][3] = 1;
        }
        else if (cur == 1) {
            dp[i][1] = dp[i][2] = 1;
        }
        else {
            dp[i][0] = 0;
        }
    }
    for (int i=(1<<n)-1;i>=(1<<(n-1));i--) debug(i,dp[i][0],dp[i][1],dp[i][2],dp[i][3]);
    for (int i=(1<<(n-1))-1;i;i--) {
        REP (j,4) REP (k,4) {
            if (dp[i<<1][j] != -1 && dp[i<<1|1][k] != -1) {
                dp[i][(j|k)] = max(dp[i][(j|k)],dp[i<<1][j] + dp[i<<1|1][k] + ((j|k)&1) + ((j|k)&2));
            }
        }
        debug(i);
        pary(dp[i],dp[i]+4);
    }
    int ans = 0;
    REP1 (i,3) ans = max(ans,dp[1][i]+1);
    cout << ans << endl;
}
