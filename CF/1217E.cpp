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

const ll MAXn=2e5+5,MAXlg=11;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct node{
    ll data;
    ll mn[MAXlg];
} seg[MAXn*4];
ll d[MAXn];
void go(ll id,ll val){
    ll tmp = val;
    REP (i,MAXlg) {
        if (tmp % 10 != 0) {
            seg[id].mn[i] = val;
        }
        tmp /= 10;
    }
}
node pull(node &a,node &b){
    node ret;
    ret.data = min(a.data,b.data);
    REP (i,MAXlg) {
        ret.mn[i] = min(a.mn[i],b.mn[i]);
        if (a.mn[i] < INF && b.mn[i] < INF) {
            ret.data = min(ret.data,a.mn[i] + b.mn[i]);
        }
    }
    return ret;
}
void build(ll id,ll l,ll r){
    seg[id].data = INF;
    REP (i,MAXlg) seg[id].mn[i] = INF;
    if (l == r-1) {
        go(id,d[l]);
        return;
    }
    ll mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    seg[id] = pull(seg[id*2+1],seg[id*2+2]);
}
void ins(ll id,ll l,ll r,ll pos,ll val){
    if (l == r-1) {
        seg[id].data = INF;
        REP (i,MAXlg) seg[id].mn[i] = INF;
        go(id,val);
        return;
    }
    ll mid = (l+r)>>1;
    if (pos < mid) ins(id*2+1,l,mid,pos,val);
    else ins(id*2+2,mid,r,pos,val);
    seg[id] = pull(seg[id*2+1],seg[id*2+2]);
}
node qr(ll id,ll L,ll R,ll l,ll r){
    if (L == l && R == r) return seg[id];
    ll mid = (L+R)>>1;
    if (r <= mid) return qr(id*2+1,L,mid,l,r);
    if (l >= mid) return qr(id*2+2,mid,R,l,r);
    node lc = qr(id*2+1,L,mid,l,mid);
    node rc = qr(id*2+2,mid,R,mid,r);
    return pull(lc,rc);
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    REP (i,n) cin >> d[i];
    build(0,0,n);
    while (m--) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll x,v;
            cin >> x >> v;
            x--;
            ins(0,0,n,x,v);
        }
        else {
            ll l,r;
            cin >> l >> r;
            l--;
            node ans = qr(0,0,n,l,r);
            if (ans.data >= INF) cout << -1 << endl;
            else cout << ans.data << endl;
        }
    }
}
