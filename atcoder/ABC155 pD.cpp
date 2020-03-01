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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll bd=1e18+5;

vector<ll> pos,zero,neg;
ll chk1(ll m){
    ll ret = 0;
    REP (i,SZ(pos)) {
        ll cur = m/pos[i];
        ll it = (ll)(upper_bound(ALL(neg),cur) - neg.begin());
        debug(cur,it);
        ret += SZ(neg) - it;
    }
    debug(m,ret);
    return ret;
}
ll go(ll m,vector<ll> &v){
    ll ret = 0;
    REP (i,SZ(v)) {
        ll cur = (m+v[i]-1) / v[i];
        ll it = (ll)(lower_bound(ALL(v),cur) - v.begin());
        if (i < it) it--;
        ret += it;
    }
    return ret/2;
}
ll chk2(ll m){ // number of < m
    debug(m,go(m,pos),go(m,neg));
    return go(m,pos) + go(m,neg);
}
int main(){
    IOS();
    ll n,k;
    cin >> n >> k;
    REP (i,n) {
        ll x;
        cin >> x;
        if (x > 0) pos.eb(x);
        else if (x == 0) zero.eb(x);
        else neg.eb(-x);
    }

    sort(ALL(pos));
    sort(ALL(neg));
    if (k <= SZ(pos) * SZ(neg)) {
        ll l = 0, r = bd;
        while (l != r-1) {
            debug(l,r);
            ll mid = (l+r)>>1;
            if (chk1(mid) >= k) l = mid;
            else r = mid;
        }
        cout << -r << endl;
        return 0;
    }

    k -= SZ(pos) * SZ(neg);
    if (k <= (SZ(zero)-1)*SZ(zero)/2 + SZ(zero) * (SZ(neg) + SZ(pos))) {
        return cout << 0 << endl,0;
    }

    k -= (SZ(zero)-1)*SZ(zero)/2 + SZ(zero) * (SZ(neg) + SZ(pos));
    debug(k);
    ll l = 0, r = bd;
    // ll tt = (SZ(pos)-1) * SZ(pos)/2 + (SZ(neg)-1) * SZ(neg)/2;
    while (l != r-1) {
        ll mid = (l+r)>>1;
        if (chk2(mid) >= k) r = mid;
        else l = mid;
    }
    cout << l << endl;
}
