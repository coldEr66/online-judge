#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct query{
    ll l,r,id;
    bool operator < (const query &a) {
        return r < a.r;
    }
};
vector<ll> e[MAXn];
vector<query> Q;
ll ans[MAXn];
vector<ii> op;
vector<ii> d[MAXn];
ll seg[MAXn*4],tg[MAXn*4];
ll cnt,col[MAXn],fa[MAXn];
void push(ll id,ll L,ll R){
    if (!tg[id]) return;
    seg[id] += tg[id] * (R-L);
    tg[id*2+1] += tg[id];
    tg[id*2+2] += tg[id];
    tg[id] = 0;
}
void pull(ll id,ll L,ll R){
    ll mid = (L+R)>>1;
    seg[id] = seg[id*2+1] + seg[id*2+2] + tg[id*2+1] * (mid-L) + tg[id*2+2] * (R-mid);
}
void add(ll id,ll L,ll R,ll l,ll r,ll v){
    if (L == l && R == r) {
        tg[id] += v;
        return;
    }
    push(id,L,R);
    ll mid = (L+R)>>1;
    if (r <= mid) add(id*2+1,L,mid,l,r,v);
    else if (l >= mid) add(id*2+2,mid,R,l,r,v);
    else {
        add(id*2+1,L,mid,l,mid,v);
        add(id*2+2,mid,R,mid,r,v);
    }
    pull(id,L,R);
}
ll qr(ll id,ll L,ll R,ll l,ll r){
    if (L == l && R == r) return seg[id] + tg[id] * (R-L);
    push(id,L,R);
    ll mid = (L+R)>>1;
    if (r <= mid) return qr(id*2+1,L,mid,l,r);
    else if (l >= mid) return qr(id*2+2,mid,R,l,r);
    return qr(id*2+1,L,mid,l,mid) + qr(id*2+2,mid,R,mid,r);
}
void dfs(ll x,ll p){
    if (col[x] == 2) return;
    if (col[x] == 1) {
        ll cur = p;
        ll mn = cur, mx = cur;
        while (cur != x) {
            cur = fa[cur];
            mn = min(mn,cur);
            mx = max(mx,cur);
        }
        op.eb(mn,mx);
        return;
    }

    fa[x] = p;
    col[x] = 1;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
    col[x] = 2;
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    REP (i,m) {
        ll u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    debug("ALIVE");
    ll q;
    cin >> q;
    REP (i,q) {
        ll u,v;
        cin >> u >> v;
        Q.eb((query){u,v,i});
        d[v].eb(1,i);
    }
    debug("ALIVE");
    REP1 (i,n) {
        if (!col[i]) {
            dfs(i,i);
        }
    }
    sort(ALL(op));
    op.resize(unique(ALL(op))-op.begin());
    debug(op);
    REP (i,SZ(op)) {
        ll r = op[i].Y;
        d[r].eb(0,i);
    }
    ll lst = 1;
    REP1 (i,n) {
        sort(ALL(d[i]));
        debug(i,d[i]);
        for (auto it:d[i]) {
            if (it.X == 0) {
                ll l = op[it.Y].X;
                debug(lst,l,i-1);
                if (l >= lst) {
                    debug(lst,l+1);
                    add(0,1,n+1,lst,l+1,i-1);
                    lst = l+1;
                }
            } // lst < i
            else {
                query cur = Q[it.Y];
                ll l = cur.l, id = cur.id;
                ans[id] = qr(0,1,n+1,l,i+1)-(l+i-2)*(i-l+1)/2;
                debug(qr(0,1,n+1,l,lst),l,lst);
                if (l <= lst) ans[id] += (i-lst+1) * i;
                else ans[id] += (i-l+1) * i;
            }
        }
    }
    REP (i,q) cout << ans[i] << endl;
}
