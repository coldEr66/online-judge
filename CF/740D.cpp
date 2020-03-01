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

ll n;
ll d[MAXn];
ll seg[MAXn*2];
ll dep[MAXn],sz[MAXn],dfn[MAXn],T;
ii son[MAXn];
ll fa[MAXn],tp[MAXn];
vector<ii> e[MAXn];
void dfs1(ll x,ll p){
    fa[x] = p;
    sz[x] = 1;
    son[x].X = -1;
    for (auto i:e[x]) {
        dfs1(i.X,x);
        sz[x] += sz[i.X];
        if (son[x].X == -1 || sz[i.X] > sz[son[x].X]) son[x] = i;
    }
}
void dfs2(ll x,ll rt,ll depth){
    tp[x] = rt;
    dfn[x] = ++T;
    dep[dfn[x]] = dep[dfn[fa[x]]] + depth;
    if (son[x].X != -1) dfs2(son[x].X,rt,son[x].Y);
    for (auto i:e[x]) {
        if (i.X == son[x].X) continue;
        dfs2(i.X,i.X,i.Y);
    }
}
void ins(ll l,ll r){
    for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if (l&1) seg[l++]++;
        if (r&1) seg[--r]++;
    }
}
ll qr(ll x){
    ll ret = 0;
    for (x+=n;x>0;x>>=1) ret += seg[x];
    return ret;
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) cin >> d[i];
    REP (i,n-1) {
        ll p,w;
        cin >> p >> w;
        p--;
        e[p].eb(i+1,w);
    }
    dfs1(0,0);
    dfs2(0,0,0);
    debug("ALIVE");
    pary(son,son+n);
    pary(tp,tp+n);
    pary(dfn,dfn+n);
    REP (i,n) {
        ll cur = i;
        while (1) {
            if (cur == 0 || d[i] <= 0) break;
            ll tmp = tp[cur];
            if (tmp == cur) {
                if (dep[dfn[cur]] - dep[dfn[fa[tmp]]] > d[i]) break;
                else {
                    d[i] -= dep[dfn[cur]] - dep[dfn[fa[tmp]]];
                    cur = fa[tmp];
                    ins(dfn[cur],dfn[cur]+1);
                    continue;
                }
            }
            debug(tmp,i,cur,"HI");
            if (dep[dfn[cur]] - dep[dfn[fa[tmp]]] > d[i]) {
                ll l=dfn[tmp], r=dfn[cur];
                debug(l,r);
                while (l != r-1) {
                    ll mid = (l+r)>>1;
                    if (dep[dfn[cur]] - dep[mid] <= d[i]) r = mid;
                    else l = mid;
                }
                if (dep[dfn[cur]] - dep[l] <= d[i]) r = l;
                ins(r,dfn[cur]);
                break;
            }
            else {
                debug(tmp,i,cur);
                ins(dfn[tmp],dfn[cur]);
                if (tmp != fa[tmp]) ins(dfn[fa[tmp]],dfn[fa[tmp]]+1);
                d[i] -= dep[dfn[cur]] - dep[dfn[fa[tmp]]];
                debug(d[i]);
                cur = fa[tmp];
            }
        }
        debug(qr(dfn[2]),i);
    }
    REP (i,n) cout << qr(dfn[i]) << " \n"[i==n-1];
}
