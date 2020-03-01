#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RREP(i,n) for (ll i=n-1;i>=0;i--)
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

const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ii d[MAXn];
map<iii,ll> mp;
map<ii,ll> mp1;
ll gt(ll x){
    return x*(x-1)/2;
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) cin >> d[i].X >> d[i].Y;
    REP (i,n) {
        for (ll j = i + 1;j < n;j++) {
            ll dx = d[i].X - d[j].X;
            ll dy = d[i].Y - d[j].Y;
            bool fx = 1, fy = 1;
            if (dx < 0) fx = -1;
            if (dy < 0) fy = -1;
            ll gcd = __gcd(dx*fx,dy*fy);
            ll x = ((dx*fx)/gcd)*fx;
            ll y = ((dy*fy)/gcd)*fy;
            if (x < 0) x *= -1, y *= -1;
            ll k = d[i].Y * x - d[i].X * y;
            iii slope = iii(ii(x,y),k);
            mp[slope]++;
        }
    }
    ll ans = gt(SZ(mp));
    debug(ans);
    for (auto it:mp) {
        mp1[it.X.X]++;
    }
    for (auto it:mp1) {
        ans -= gt(it.Y);
    }
    cout << ans << endl;
}
