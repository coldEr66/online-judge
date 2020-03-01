#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n;
ll d[MAXn],ans[MAXn],sz[MAXn];
vector<ii> stk;
vector<ll> e[MAXn];
ii nei[MAXn];
void dfs(ll x,ll p){
    sz[x] = 1;
    ans[x] = n-1;
    ll ret = 0;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
        sz[x] += sz[i];
        ret += (n-1-sz[i]) * sz[i];
    }
    ret += (n-sz[x]) * (sz[x]-1);
    ret >>= 1;
    ans[x] += ret;
    debug(x,ans[x]);
}
int main(){
    IOS();
    cin >> n;
    d[0] = INF;
    REP1 (i,n) {
        cin >> d[i];
        while (SZ(stk) && d[i] > stk.back().X) {
            nei[stk.back().Y].X = i;
            stk.pob();
        }
        stk.eb(d[i],i);
    }
    stk.clear();
    for (ll i=n;i>=1;i--) {
        while (SZ(stk) && d[i] > stk.back().X) {
            nei[stk.back().Y].Y = i;
            stk.pob();
        }
        stk.eb(d[i],i);
    }
    pary(nei+1,nei+n+1);
    REP1 (i,n) {
        ll cur;
        if (d[nei[i].X] < d[nei[i].Y]) cur = nei[i].X;
        else cur = nei[i].Y;
        if (cur == 0) continue;
        e[i].eb(cur);
        e[cur].eb(i);
    }
    REP1 (i,n) debug(e[i]);
    debug("ALIVE");
    dfs(1,1);
    pary(ans+1,ans+n+1);
    pary(sz+1,sz+n+1);
    ll it = 0;
    REP1 (i,n) {
        if (!it || ans[i] > ans[it]) it = i;
    }
    cout << ans[it]*2 << ' ' << it << endl;
}
