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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n;
ll d[MAXn];
ll one,ans = INF;
ll tg,p;
ll cal(ll a,ll b){
    ll l = 0;
    ll ret = 0;
    for (ll i=a;i<=b;i++) {
        if (d[i] == 1) l++;
        else ret += l;
    }
    return ret;
}
void sol(){
    ll x = cal(0,n-1), y = cal(n,2*n-1);
    ll l = n-1, r = n;
    ll delta = x-y;
    ans = min(ans,abs(delta));
    ll op = 0;
    while (l >= 0 && r < 2*n) {
        while (l >= 0 && d[l] != tg) l--;
        while (r < 2*n && d[r] != 1-tg) r++;
        if (l < 0 || r >= 2*n) break;
        delta -= p * (n-l-1);
        op += n-l-1;
        delta += p * (r-n);
        op += r-n;
        delta += p * (one-n);
        op++;
        debug(op,delta);
        ans = min(ans,op + abs(delta));
        l--,r++;
    }
}
int main(){
    // IOS();
    freopen("balance.in","r",stdin);
    freopen("balance.out","w",stdout);
    cin >> n;
    REP (i,2*n) {
        cin >> d[i];
        one += d[i];
    }
    debug(one);
    tg = 1, p = 1;
    sol();
    debug("ALIVE");
    tg = 0, p = -1;
    sol();
    cout << ans << endl;
}
