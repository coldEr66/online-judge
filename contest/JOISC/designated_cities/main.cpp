#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<int,ii> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll n,tot;
ll ans[MAXn],dp1[MAXn][2],dptt;
ii dp2[MAXn][2];
ll in[MAXn],out[MAXn],idx;
ii fa[MAXn];
ii seg[MAXn*4];
ll tg[MAXn*4],num[MAXn];
vector<ii> e[MAXn];
bool vis[MAXn];
ll bst,bstmx;
void push(ll id){
    if (!tg[id]) return;
    seg[id].X += tg[id];
    tg[id*2+1] += tg[id];
    tg[id*2+2] += tg[id];
    tg[id] = 0;
}
void pull(ll id){
    ll lc = seg[id*2+1].X + tg[id*2+1];
    ll rc = seg[id*2+2].X + tg[id*2+2];
    if (lc > rc) {
        seg[id].X = lc;
        seg[id].Y = seg[id*2+1].Y;
    }
    else {
        seg[id].X = rc;
        seg[id].Y = seg[id*2+2].Y;
    }
}
void build(ll id,ll L,ll R){
    if (L == R-1) {
        seg[id] = ii(0,num[L]);
        return;
    }
    ll mid = (L+R)>>1;
    build(id*2+1,L,mid);
    build(id*2+2,mid,R);
}
void ins(ll id,ll L,ll R,ll l,ll r,ll val){
    if (L == l && R == r) {
        tg[id] += val;
        return;
    }
    push(id);
    ll mid = (L+R)>>1;
    if (l >= mid) ins(id*2+2,mid,R,l,r,val);
    else if (r <= mid) ins(id*2+1,L,mid,l,r,val);
    else {
        ins(id*2+1,L,mid,l,mid,val);
        ins(id*2+2,mid,R,mid,r,val);
    }
    pull(id);
}
ii qr(ll id,ll L,ll R,ll l,ll r){
    if (L == l && R == r) {
        return ii(seg[id].X+tg[id],seg[id].Y);
    }
    push(id);
    ll mid = (L+R)>>1;
    if (l >= mid) return qr(id*2+2,mid,R,l,r);
    else if (r <= mid) return qr(id*2+1,L,mid,l,r);
    else {
        return max(qr(id*2+1,L,mid,l,r),qr(id*2+2,mid,R,l,r));
    }
}
void del(ll x){
    debug(x);
    for (;x != -1 && !vis[x];x = fa[x].X) {
        ll w = fa[x].Y;
        debug(x,in[x],out[x],w);
        ins(0,0,n,in[x],out[x],-w);
        vis[x] = true;
    }
}
void dfs1(ll x,ll p){
    for (auto i:e[x]) {
        if (i.X == p) dp1[x][0] = dp1[p][0] + i.Y;
    }
    for (auto i:e[x]) {
        if (i.X == p) continue;
        else {
            dp1[i.X][1] = dp1[x][1] + i.Y;
            dptt += i.Y;
            dfs1(i.X,x);
        }
    }
}
void dfs2(ll x,ll p){
    dp2[x][0] = ii(0,x);
    dp2[x][1] = ii(0,-1);
    for (auto i:e[x]) {
        if (i.X == p) continue;
        dptt += i.Y;
        dfs2(i.X,x);
        ll cur = dp2[i.X][0].X + i.Y;
        if (cur > dp2[x][0].X) {
            swap(dp2[x][0],dp2[x][1]);
            dp2[x][0].X = cur;
            dp2[x][0].Y = dp2[i.X][0].Y;
        }
        else if (cur > dp2[x][1].X) {
            dp2[x][1].X = cur;
            dp2[x][1].Y = dp2[i.X][0].Y;
        }
    }
    debug(x,dp2[x][0].X,dp2[x][1].X,dp1[x][1],dp1[x][0]);
    ll mx = dp2[x][0].X + dp2[x][1].X + dp1[x][1] - dp1[x][0];
    if (bstmx < mx) {
        bst = x;
        bstmx = mx;
    }
}
void dfstime(ll x,ll p){
    in[x] = idx;
    num[idx++] = x;
    fa[x].X = p;
    for (auto i:e[x]) {
        if (i.X == p) continue;
        dfstime(i.X,x);
        fa[i.X].Y = i.Y;
    }
    out[x] = idx;
}
void dfs3(ll x,ll p){
    debug(x,p);
    for (auto i:e[x]) {
        if (i.X == p) continue;
        debug(i,in[i.X],out[i.X],i.Y);
        ins(0,0,n,in[i.X],out[i.X],i.Y);
        dfs3(i.X,x);
    }
}
void gogo(ll x){
    ii ret = qr(0,0,n,0,n);
    ans[x] = ans[x-1] - ret.X;
    debug(x,ret);
    del(ret.Y);
}
int main(){
    IOS();
    cin >> n;
    REP (i,n-1) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--, b--;
        e[a].eb(b,c);
        e[b].eb(a,d);
        tot += c, tot += d;
    }

    dfs1(0,-1);
    ll tmp = dptt;
    REP (i,n) tmp = min(tmp,dptt + dp1[i][0] - dp1[i][1]);
    REP (i,n) debug(dp1[i][0],dp1[i][1]);
    debug(tot,dptt,tmp);
    ans[1] = tmp;
    debug(ans[1]);

    dptt = 0, tmp = 0;
    dfs2(0,0);
    debug(dptt);
    REP (i,n) debug(dp2[i][0],dp2[i][1]);
    debug(dptt,bstmx);
    ans[2] = dptt - bstmx;
    debug(ans[2]);
    pary(fa,fa+n);
    dfstime(dp2[bst][0].Y,dp2[bst][0].Y);
    build(0,0,n);
    dfs3(dp2[bst][0].Y,dp2[bst][0].Y);
    debug("ALIVE");
    debug(dp2[bst][0].Y,dp2[bst][1].Y);
    del(dp2[bst][1].Y);

    for (ll i=3;i<=n;i++) gogo(i);
    ll q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        cout << ans[x] << endl;
    }
}
