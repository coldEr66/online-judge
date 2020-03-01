#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

ll n,b;
ll p[MAXn];
ll mxp(ll x,ll y){
    ll k = min(ll(64 - __builtin_clzll(y)-1),x-2);
    debug(y,k);
    ll tp = y - (1LL<<k)+1;
    if (x <= k) return INF;
    debug(x,y,(x-k) * ((1LL<<k) - tp) + (x-k-1)*2*tp);
    return (x-k) * ((1LL<<k) - tp) + (x-k-1)*2*tp;
}
ll gt(ll x,ll num){
    ll l=0, r = 1000005;
    while (l != r-1) {
        ll mid = (l+r)>>1;
        if (mxp(x,mid) >= num) r = mid;
        else l = mid;
    }
    return r;
}
bool chk(ll x){
    ll cnt = 0;
    REP (i,n) {
        if (p[i] <= x) continue;
        cnt += gt(x,p[i]);
        if (cnt > b) return false;
    }
    return cnt <= b;
}
int main(){
    IOS();
    cin >> n >> b;
    REP (i,n) cin >> p[i];

    ll l = 0, r = 1000005;
    while (l != r-1) {
        // debug(l,r);
        ll mid = (l+r)>>1;
        if (chk(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
