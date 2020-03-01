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

const ll MAXn=3e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int dp[MAXn][MAXn];
int mx[MAXn][MAXn][MAXn];
int w[MAXn*MAXn],l[MAXn*MAXn],r[MAXn*MAXn];
int main(){
    IOS();
    freopen("pieaters.in","r",stdin);
    freopen("pieaters.out","w",stdout);
    int n,m;
    cin >> n >> m;
    REP (i,m) {
        cin >> w[i] >> l[i] >> r[i];
        l[i]--, r[i]--;
        for (int j=l[i];j<=r[i];j++) {
            mx[j][l[i]][r[i]] = w[i];
        }
    }
    REP (i,n) {
        for (int j=i;j>=0;j--) {
            for (int k=i;k<n;k++) {
                if (j) mx[i][j-1][k] = max(mx[i][j-1][k],mx[i][j][k]);
                if (k < n-1) mx[i][j][k+1] = max(mx[i][j][k+1],mx[i][j][k]);
                debug(i,j,k,mx[i][j][k]);
            }
        }
    }

    REP (len,n+1) {
        REP (i,n) {
            int j = i+len;
            if (j >= n) break;
            for (int k=i;k<j;k++) dp[i][j] = max(dp[i][j],dp[i][k] + dp[k+1][j]);
            for (int k=i;k<=j;k++) {
                if (mx[k][i][j]) {
                    int tmp = mx[k][i][j];
                    if (k < j) tmp += dp[k+1][j];
                    if (k > i) tmp += dp[i][k-1];
                    dp[i][j] = max(dp[i][j],tmp);
                }
            }
            debug(i,j,dp[i][j]);
        }
    }
    cout << dp[0][n-1] << endl;
}
