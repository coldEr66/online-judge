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
const ll INF=0x3f3f3f3f;

struct p{
    ll a,b,c,id;
    bool operator > (const p &x) const {
        return (a > x.a) && (b > x.b);
    }
} d[MAXn],tmp[MAXn];
ll n;
ll ans[MAXn],bit[MAXn];
bool cmpa(const p &x,const p &y){
    if (x.a != y.a) return x.a > y.a;
    if (x.b != x.b) return x.b > y.b;
    return x.c < y.c;
}
ll lowbit(ll x){return x&(-x);}
void ins(ll x,ll val){
    for (;x>0;x-=lowbit(x)) bit[x] += val;
}
ll qr(ll x){
    ll ret = 0;
    for (;x<=n;x+=lowbit(x)) ret += bit[x];
    return ret;
}
void CDQ(ll l,ll r){
    if (l == r-1) return;
    ll mid = (l+r)>>1;
    CDQ(l,mid);
    CDQ(mid,r);
    ll pl = l, pr = mid;
    ll idx = 0;
    vector<ll> tp;
    while (pl < mid && pr < r) {
        if (d[pl].b > d[pr].b) {
            ins(d[pl].c,1);
            tp.eb(d[pl].c);
            tmp[idx++] = d[pl++];
        }
        else {
            ans[d[pr].id] += qr(d[pr].c+1);
            tmp[idx++] = d[pr++];
        }
    }
    // pary(bit,bit+n);
    while (pl < mid) tmp[idx++] = d[pl++];
    while (pr < r) {
        ans[d[pr].id] += qr(d[pr].c+1);
        tmp[idx++] = d[pr++];
    }
    for (ll i=l;i<r;i++) d[i] = tmp[i-l];
    for (auto i:tp) ins(i,-1);
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) {
        cin >> d[i].a >> d[i].b >> d[i].c;
        d[i].id = i;
    }
    sort(d,d+n,cmpa);
    REP (i,n) debug(d[i].a,d[i].b,d[i].c,d[i].id);
    CDQ(0,n);
    REP (i,n) cout << ans[i] << endl;
}