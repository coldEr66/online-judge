#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000003;
const ll INF=0x3f3f3f3f;

ll fac[MAXn],inv[MAXn];
ll fpow(ll x,ll y){
    ll ret = 1;
    while (y) {
        if (y&1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}
void build(){
    fac[0] = inv[0] = 1;
    REP1 (i,MAXn-1) {
        fac[i] = (fac[i-1] * i) % MOD;
        inv[i] = fpow(fac[i],MOD-2);
    }
}
int main(){
    IOS();
    build();
    ll q;
    cin >> q;
    while (q--) {
        ll x,d,n;
        cin >> x >> d >> n;
        if (d == 0) {
            cout << fpow(x,n) << endl;
            continue;
        }
        ll tmp = fpow(d,n);
        ll a = x * fpow(d,MOD-2) % MOD;
        ll t = (a+n-1)/MOD;
        if (MOD*t >= a-1 && MOD*t <= a+n-1) cout << 0 << endl;
        else cout << tmp * fac[(a+n-1)%MOD] % MOD * inv[a-1] % MOD << endl;
    }
}
