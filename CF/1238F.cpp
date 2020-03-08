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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

vector<int> e[MAXn];
ii dp[MAXn];
int d[MAXn];
int ans;
void upd(int x,int val){
    if (dp[x].X < val) {
        swap(dp[x].X,dp[x].Y);
        dp[x].X = val;
    }
    else if (dp[x].Y < val) dp[x].Y = val;
}
void dfs(int x,int p){
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
        upd(x,dp[i].X);
    }
    debug(x,dp[x]);
    ans = max(ans,dp[x].X + d[x] + 2);
    ans = max(ans,dp[x].X + dp[x].Y + 2 + d[x]);
    if (dp[x].X == -INF) dp[x].X = d[x];
    else {
        dp[x].X += d[x];
        dp[x].Y += d[x];
    }
    debug(x,ans);
}
int main(){
    IOS();
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        REP (i,n) {
            e[i].clear();
            dp[i] = ii(-INF,-INF);
            d[i] = 0;
        }
        REP (i,n-1) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            e[u].eb(v);
            e[v].eb(u);
        }
        REP (i,n) {
            d[i] = SZ(e[i])-1;
        }
        ans = 0;
        dfs(0,0);
        cout << ans << endl;
    }
}
