#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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

const ll MAXn=22,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
ll dp[2][1<<MAXn],val;
vector<ll> v;
ll d[MAXn][MAXn];
void init(){
    for (ll I=0;I<(1<<n);I++) {
        bool ok = true;
        for (ll i=0;i<n-1;i++) {
            if (I&(1<<i) && I&(1<<(i+1))) ok = false;
        }
        if (ok) v.eb(I);
    }
}
void dfs(ll x,ll mask,ll prev,ll cur){
    if (cur == n) {
        debug(x,mask,prev,val,dp[x&1][prev]);
        dp[(x&1)^1][mask] = max(dp[(x&1)^1][mask],dp[x&1][prev] + val);
        return;
    }
    if (cur == 0) {
        if ((mask&3) == 0) dfs(x,mask,prev|1,cur+1);
    }
    else if ((prev&(1<<(cur-1))) == 0) {
        if ((mask&(7<<(cur-1))) == 0) {
            dfs(x,mask,prev|(1<<cur),cur+1);
        }
    }
    dfs(x,mask,prev,cur+1);
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) REP (j,n) cin >> d[i][j];

    init();
    REP (i,n) {
        RST(dp[(i&1)^1],0);
        for (auto I:v) {
            val = 0;
            for (ll j=0;j<n;j++) if (I&(1<<j)) val += d[i][j];
            dfs(i,I,0,0);
        }
    }
    cout << *max_element(dp[n&1],dp[n&1] + (1<<n)) << endl;
}
