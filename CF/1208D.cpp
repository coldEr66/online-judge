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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct{
    ii data;
    ll l,r;
    ll tag;
} seg[MAXn*4];
ll n;
ll d[MAXn];
ll ans[MAXn];
ii gt(ll id){
    return ii(seg[id].data.X-seg[id].tag,seg[id].data.Y);
}
void build(ll id,ll l,ll r){
    seg[id].l = l, seg[id].r = r;
    seg[id].tag = 0;
    if (l == r-1) {
        seg[id].data = ii(d[l],-l);
        return;
    }
    ll mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    seg[id].data = min(gt(id*2+1),gt(id*2+2));
}
void push(ll id){
    seg[id*2+1].tag += seg[id].tag;
    seg[id*2+2].tag += seg[id].tag;
    seg[id].data.X -= seg[id].tag;
    seg[id].tag = 0;
}
void ins(ll id,ll l,ll r,ll val) {
    if (l >= r) return;
    if (seg[id].l == l && seg[id].r == r) {
        seg[id].tag += val;
        return;
    }
    push(id);
    ll mid = (seg[id].l + seg[id].r)>>1;
    if (l >= mid) ins(id*2+2,l,r,val);
    else if (r <= mid) ins(id*2+1,l,r,val);
    else {
        ins(id*2+1,l,mid,val);
        ins(id*2+2,mid,r,val);
    }
    seg[id].data = min(gt(id*2+1),gt(id*2+2));
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) cin >> d[i];
    build(0,0,n);
    ll cur = 1;
    REP (i,n) {
        ii tmp = seg[0].data;
        debug(tmp);
        ans[-tmp.Y] = cur;
        ins(0,-tmp.Y,-tmp.Y+1,-INF);
        ins(0,-tmp.Y+1,n,cur);
        cur++;
    }
    REP (i,n) cout << ans[i] << " \n"[i==n-1];
}
