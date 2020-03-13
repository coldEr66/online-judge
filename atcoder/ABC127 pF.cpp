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

const ll MAXn=1<<19,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll bit1[MAXn],bit2[MAXn];
vector<ll> _;
ii Q[MAXn];
map<ll,ll> mp;
void getPOS(ll &x){
    ll tmp = lower_bound(ALL(_),x) - _.begin() + 1;
    mp[tmp] = x;
    x = tmp;
}
ll lowbit(ll x) {
    return x&(-x);
}
void ins(ll x,ll v,ll *bit) {
    for (;x<=MAXn;x+=lowbit(x)) bit[x] += v;
}
ll qr(ll x,ll *bit) {
    ll ret = 0;
    for (;x>0;x-=lowbit(x)) ret += bit[x];
    return ret;
}
ll bs(ll x){
    ll ret = 0, tmp = 0;
    for (ll i=20;i>=0;i--) {
        if (((ret|(1<<i)) < MAXn) && (tmp + bit2[ret|(1<<i)] <= x)) {
            ret |= (1<<i);
            tmp += bit2[ret];
        }
    }
    return ret+1;
}
int main(){
    IOS();
    ll q;
    cin >> q;
    REP (i,q) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll a,b;
            cin >> a >> b;
            Q[i].X = a, Q[i].Y = b;
            _.eb(a), _.eb(b);
        }
        else Q[i].X = -INF;
    }
    sort(ALL(_));
    _.resize(unique(ALL(_))-_.begin());
    REP (i,q) {
        if (Q[i].X != -INF) {
            getPOS(Q[i].X);
            getPOS(Q[i].Y);
        }
    }

    ll cur = 0, cnt = 0;
    REP (i,q) {
        debug("ALIVE");
        if (Q[i].X != -INF) {
            cur += mp[Q[i].Y];
            ins(Q[i].X,mp[Q[i].X],bit1);
            ins(Q[i].X,1,bit2);
            cnt++;
        }
        else {
            ll mid = bs((cnt-1)/2);
            ll lnum = qr(mid-1,bit2), rnum = qr(MAXn-1,bit2) - qr(mid,bit2);
            debug(mid,lnum,rnum);
            ll ans = mp[mid] * (lnum - rnum) - qr(mid-1,bit1) + qr(MAXn-1,bit1) - qr(mid,bit1);
            cout << mp[mid] << " " << ans + cur << endl;
        }
    }
}