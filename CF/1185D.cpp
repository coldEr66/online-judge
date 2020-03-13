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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ii d[MAXn];
ll dt[MAXn];
map<ll,ll> cnt;
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        cin >> d[i].X;
        d[i].Y = i;
    }
    sort(d,d+n);
    ll tt = 0;
    REP1 (i,n-1) {
        dt[i] = d[i].X-d[i-1].X;
        if (!cnt.count(dt[i])) tt++;
        cnt[dt[i]]++;
    }
    pary(dt,dt+n);
    debug(tt);
    if (tt == 1) return cout << d[0].Y+1 << endl,0;
    if (tt > 3) return cout << -1 << endl,0;

    ll tmp = tt;
    cnt[dt[1]]--;
    if (cnt[dt[1]] == 0) tmp--;
    if (tmp == 1) return cout << d[0].Y+1 << endl,0;
    cnt[dt[1]]++;

    tmp = tt;
    cnt[dt[n-1]]--;
    if (cnt[dt[n-1]] == 0) tmp--;
    if (tmp == 1) return cout << d[n-1].Y+1 << endl,0;
    cnt[dt[n-1]]++;

    debug("HI");

    REP1 (i,n-2) {
        ll cur = dt[i] + dt[i+1];
        tmp = tt;
        debug(cur);
        cnt[dt[i]]--;
        if (cnt[dt[i]] == 0) tmp--;
        cnt[dt[i+1]]--;
        if (cnt[dt[i+1]] == 0) tmp--;
        if (cnt[cur] == 0) tmp++;
        if (tmp == 1) return cout << d[i].Y+1 << endl,0;
        cnt[dt[i]]++, cnt[dt[i+1]]++;
    }
    cout << -1 << endl;
}