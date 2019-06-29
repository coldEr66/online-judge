#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(a,i) memset(a,i,sizeof a)
#define SZ(a) ll(a.size())
#define X first
#define Y second
#define eb emplace_back
#define pob pop_back
#define ALL(a) a.begin(),a.end()
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T> void _do(T &&_x){cerr << _x << endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr << _x << ", ";_do(_t...);}
#define IOS()
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#endif

const ll MAXn=2e5+5;

typedef pair<ll,ii> iii;
vector<ll> e1[MAXn],e2[MAXn];
ii d1[MAXn],d2[MAXn],a[MAXn];
ll in1[MAXn],in2[MAXn],bit[MAXn];
bitset<MAXn> tp1,tp2;
vector<ll> v1,v2;
ll t;
ll pos[MAXn];
ll lowbit(ll x){return x&(-x);}
void ins(ll x,ll v){
    for (;x<MAXn;x+=lowbit(x)) {
        bit[x] += v;
    }
}
ll qr(ll x){
    ll ret = 0;
    for (;x>0;x-=lowbit(x)) {
        ret += bit[x];
    }
    return ret;
}
void dfs(ll x,vector<ll> *e,vector<ll> &v,ii *d){
    v.eb(x);
    d[x].X = ++t;
    for (auto i:e[x]) dfs(i,e,v,d);
    d[x].Y = t;
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        e1[u].eb(v);
        in1[v]++;
    }
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        e2[u].eb(v);
        in2[v]++;
    }

    if (n <= 55) {
        ll ans = 0;
        REP1 (i,n) {
            tp1.reset();
            tp2.reset();
            v1.clear(), v2.clear();
            dfs(i,e1,v1,d1);
            dfs(i,e2,v2,d2);
            debug(i);
            REP (j,SZ(v1)) {
                tp1[v1[j]] = true;
                debug(v1[j]);
            }
            REP (j,SZ(v2)) {
                tp2[v2[j]] = true;
                debug(v2[j]);
            }
            ans += (tp1 & tp2).count()-1;
            debug(ans);
        }
        cout << ans << endl;
    }
    else {
        ll root = -1;
        REP1 (i,n) if (!in1[i]) root = i;
        dfs(root,e1,v1,d1);
        REP1 (i,n) if (!in2[i]) root = i;
        t = 0;
        dfs(root,e2,v2,d2);
        REP (i,SZ(v1)) pos[v1[i]] = i+1;
        REP (i,SZ(v2)) v2[i] = pos[v2[i]];
        REP (i,SZ(v1)) debug(v1[i]);
        REP (i,SZ(v2)) debug(v2[i]);
        REP1 (i,n) debug(d1[i].X,d1[i].Y);
        REP1 (i,n) debug(d2[i].X,d2[i].Y);
        vector<iii> q;
        REP1 (i,n) {
            if (d2[i].X-1 > 0) q.eb(d2[i].X-1,ii(0,i));
            q.eb(d2[i].Y,ii(1,i));
        }
        sort(ALL(q));
        ll idx = 0;
        REP (i,SZ(q)) debug(q[i].X,q[i].Y.X,q[i].Y.Y);
        REP (i,SZ(v2)) {
            if (q[idx].X != i+1) continue;
            ins(v2[i],1);
            while (idx < SZ(q) && q[idx].X == i+1) {
                ll cur = q[idx].Y.Y;
                ll tmp = qr(d1[cur].Y) - qr(d1[cur].X-1);
                if (q[idx].Y.X == 0) a[cur].Y = tmp;
                else a[cur].X = tmp;
                idx++;
            }
            debug(v2[i]);
        }
        REP1 (i,n) debug(a[i].X,a[i].Y);
        ll ans = 0;
        REP1 (i,n) ans += a[i].X - a[i].Y;
        ans -= n;
        cout << ans << endl;
    }
}
