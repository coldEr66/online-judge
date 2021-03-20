#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE %d: (%s) = ",__LINE__,#__VA_ARGS__);\
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

const ll MAXn=5e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct node{
    ll tg,mx,data;
} seg[MAXn*4];
ll d[MAXn],ans[MAXn];
vector<ii> q[MAXn];
vector<ll> p[MAXn];
void upd(ll id,ll val){
    seg[id].tg = max(seg[id].tg,val);
    seg[id].mx = max(seg[id].mx,seg[id].data + val);
}
void push(ll id){
    if (seg[id].tg == 0) return;
    upd(id*2+1,seg[id].tg), upd(id*2+2,seg[id].tg);
    seg[id].tg = 0;
}
void build(ll id,ll L,ll R){
    if (L == R-1) {
        seg[id].data = seg[id].mx = d[L];
        seg[id].tg = 0;
        return;
    }
    ll mid = (L+R)>>1;
    build(id*2+1,L,mid);
    build(id*2+2,mid,R);
    seg[id].mx = seg[id].data = max(seg[id*2+1].data,seg[id*2+2].data);
}
void ins(ll id,ll L,ll R,ll l,ll r,ll val){
    if (L >= r || R <= l) return;
    if (L == l && R == r) {
        upd(id,val);
        return;
    }
    push(id);
    ll mid = (L+R)>>1;
    if (r <= mid) ins(id*2+1,L,mid,l,r,val);
    else if (l >= mid) ins(id*2+2,mid,R,l,r,val);
    else {
        ins(id*2+1,L,mid,l,mid,val);
        ins(id*2+2,mid,R,mid,r,val);
    }
    seg[id].mx = max(seg[id*2+1].mx,seg[id*2+2].mx);
}
ll qr(ll id,ll L,ll R,ll l,ll r){
    if (L >= r || R <= l) return 0;
    if (L == l && R == r) {
        return seg[id].mx;
    }
    push(id);
    ll mid = (L+R)>>1;
    if (r <= mid) return qr(id*2+1,L,mid,l,r);
    else if (l >= mid) return qr(id*2+2,mid,R,l,r);
    else {
        return max(qr(id*2+1,L,mid,l,mid),qr(id*2+2,mid,R,mid,r));
    }
}
int main(){
    IOS();
    ll n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i];
    }
    ll m;
    cin >> m;
    for (int i=0;i<m;++i) {
        ll l,r;
        cin >> l >> r;
        l--;
        q[l].eb(r,i);
    }
    vector<ll> stk;
    for (ll i=0;i<n;++i) {
        if (!SZ(stk)) {
            stk.eb(i);
        }
        else {
            while (SZ(stk) && d[stk.back()] < d[i]) {
                p[stk.back()].eb(i);
                stk.pop_back();
            }
            if (SZ(stk)) p[stk.back()].eb(i);
            stk.eb(i);
        }
    }
    
    build(0,0,n);
    for (ll i=n-3;i>=0;i--) {
        for (ll j:p[i]) ins(0,0,n,2*j-i,n,d[i]+d[j]);
        for (ii j:q[i]) ans[j.Y] = qr(0,0,n,i+2,j.X);
    }
    for (int i=0;i<m;++i) cout << ans[i] << endl;
}

