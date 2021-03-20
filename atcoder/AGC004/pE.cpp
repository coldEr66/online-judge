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

const ll MAXn=102,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;


int n,m;
char s[MAXn][MAXn];
short dp[MAXn][MAXn][MAXn][MAXn];
short col[MAXn][MAXn],row[MAXn][MAXn];
short ans;
ii st;
bool chk(int l,int r,int u,int d){
    if (st.X-u <= 0 || st.X+d > n || st.Y-l <= 0 || st.Y+r > m) return true;
    return false;
}
void upd(int l,int r,int u,int d){
    int bdl = r;
    int bdr = (int)m-l+1;
    int bdu = d;
    int bdd = (int)n-u+1;
    if (l > 0) dp[l][r][u][d] = max(dp[l][r][u][d],short(dp[l-1][r][u][d] + (st.Y - l > bdl ?col[st.Y-l][min(st.X+d,bdd-1)] - col[st.Y-l][max(st.X-u-1,bdu)]:0)));
    if (r > 0) dp[l][r][u][d] = max(dp[l][r][u][d],short(dp[l][r-1][u][d] + (st.Y + r < bdr ?col[st.Y+r][min(st.X+d,bdd-1)] - col[st.Y+r][max(st.X-u-1,bdu)]:0)));
    if (u > 0) dp[l][r][u][d] = max(dp[l][r][u][d],short(dp[l][r][u-1][d] + (st.X - u > bdu ?row[st.X-u][min(st.Y+r,bdr-1)] - row[st.X-u][max(st.Y-l-1,bdl)]:0)));
    if (d > 0) dp[l][r][u][d] = max(dp[l][r][u][d],short(dp[l][r][u][d-1] + (st.X + d < bdd ?row[st.X+d][min(st.Y+r,bdr-1)] - row[st.X+d][max(st.Y-l-1,bdl)]:0)));
}
int main(){
    IOS();
    cin >> n >> m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin >> s[i][j];
            if (s[i][j] == 'E') {
                st = ii(i,j);
                s[i][j] = '.';
            }
        }
    }

    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            row[i][j] = short(row[i][j-1] + (s[i][j] == 'o'));
        }
    }
    for (int j=1;j<=m;++j) {
        for (int i=1;i<=n;++i) {
            col[j][i] = short(col[j][i-1] + (s[i][j] == 'o'));
        }
    }

    RST(dp,-1);
    dp[0][0][0][0] = 0;
    for (int l=0;l<m;++l) {
        for (int r=0;r<m;++r) {
            for (int u=0;u<n;++u) {
                for (int d=0;d<n;++d) {
                    if (chk(l,r,u,d)) continue;
                    if (dp[l][r][u][d] == -1) upd(l,r,u,d);
                    ans = max(ans,dp[l][r][u][d]);
                }
            }
        }
    }
    cout << ans << endl;
}
