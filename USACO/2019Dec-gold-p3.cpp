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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int c[31][31];
int dp[MAXn][31];
int dpmin[MAXn];
int sum[MAXn][31];
int main(){
    IOS();
    freopen("cowmbat.in","r",stdin);
    freopen("cowmbat.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    REP (i,m) REP (j,m) {
        cin >> c[i][j];
    }
    REP (u,m) REP (i,m) REP (j,m) {
        c[i][j] = min(c[i][j],c[i][u] + c[u][j]);
    }

    REP (j,m) {
        REP (i,n) {
            sum[i][j] = c[s[i]-'a'][j];
            if (i) sum[i][j] += sum[i-1][j];
            debug(sum[i][j],i,j);
        }
    }

    RST(dp,INF);
    RST(dpmin,INF);

    REP (i,n) {
        REP (j,m) {
            dp[i][j] = min(dp[i][j],dp[i-1][j] + c[s[i]-'a'][j]);
            if (i-k >= 0) dp[i][j] = min(dp[i][j],dpmin[i-k]+sum[i][j]-sum[i-k][j]);
            else if (i-k+1 >= 0) dp[i][j] = min(dp[i][j],sum[i][j]);
            dpmin[i] = min(dpmin[i],dp[i][j]);
        }
    }
    int ans = INF;
    REP (j,m) ans = min(ans,dp[n-1][j]);
    cout << ans << endl;
}
