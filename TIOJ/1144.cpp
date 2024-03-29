#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RREP(i,n) for (ll i=n-1;i>=0;i--)
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

const ll MAXn=2e2+5;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll d[MAXn][MAXn];
ll dp[2][MAXn][MAXn];
ll dt[1005];
int main() {
	ll n;
	cin >> n;
	REP1 (i,n) REP1 (j,n) {
		cin >> d[i][j];
		dp[0][i][j] = INF;
		dp[1][i][j] = INF;
	}
    #ifdef cold66
        ll m;
        cin >> m;
        REP (i,m) cin >> dt[i];
    #else
	    ll m;
	    for(m = 0;cin>>dt[m];m++);
    #endif
	int roll = 0;
	dp[roll^1][2][3] = dp[roll^1][3][2] = d[1][dt[0]];
	dp[roll^1][1][3] = dp[roll^1][3][1] = d[2][dt[0]];
	dp[roll^1][2][1] = dp[roll^1][1][2] = d[3][dt[0]];

	REP (T,m-1) {
		REP1 (i,n) REP1 (j,n) {
			dp[roll][i][j] = min(dp[roll][i][j],dp[roll^1][i][j] + d[dt[T]][dt[T+1]]);
			dp[roll][i][dt[T]] = min(dp[roll][i][dt[T]],dp[roll^1][i][j] + d[j][dt[T+1]]);
			dp[roll][dt[T]][j] = min(dp[roll][dt[T]][j],dp[roll^1][i][j] + d[i][dt[T+1]]);
			dp[roll^1][i][j] = INF;
		}
		roll ^= 1;
	}

	ll ans = INF;
	REP1 (i,n) REP1 (j,n) {
        ans = min(ans,dp[roll^1][i][j]);
    }
	cout << ans << endl;
}
