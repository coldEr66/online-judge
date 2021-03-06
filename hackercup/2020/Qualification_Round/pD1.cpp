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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

void setIO(string pname){
    IOS();
    freopen((pname+".txt").c_str(),"r",stdin);
    freopen((pname+".out").c_str(),"w",stdout);
}
ll d[MAXn],dp[MAXn];
ll dq[MAXn];
ll kk;
int main(){
    setIO("running_on_fumes_chapter_1_input");
    int T;
    cin >> T;
    while (T--) {
        kk++;
        ll n,m;
        cin >> n >> m;
        REP (i,n) {
            cin >> d[i];
            if (d[i] == 0) d[i] = INF;
            if (i == n-1) d[i] = 0;
            dp[i] = INF;
        }

        ll l = 0, r = -1;
        dp[0] = 0;
        dq[++r] = 0;
        REP1 (i,n-1) {
            while (l < r && dq[l] < i-m) l++;
            if (d[i] == INF || dp[dq[l]] >= INF) dp[i] = 2*INF;
            else dp[i] = dp[dq[l]] + d[i];
            while (l < r && dp[i] < dp[dq[r]]) r--;
            dq[++r] = i;
        }
        cout << "Case #" << kk << ": ";
        ll ans = dp[n-1];
        if (ans >= INF) cout << -1 << endl;
        else cout << ans << endl;
    }
}
