#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n;
bool vis[MAXN];
pll e[MAXN];
ll a[MAXN],b[MAXN],money[MAXN];
ll in[MAXN],ans;
vector<ll> v;
void gogo(){
    queue<ll> q;
    for (int i=0;i<n;++i) {
        if (!in[i] && !vis[i]) q.emplace(i);
    }
    while (SZ(q)) {
        ll cur = q.front();
        q.pop();
        vis[cur] = true;
        ll to = e[cur].X, w = e[cur].Y;
        money[to] += w;
        if (money[cur] < w) ans += w - money[cur];
        in[to]--;
        if (!in[to] && !vis[to]) {
            q.emplace(to);
        }
    }
}
void cal(ll x){
    queue<ll> q;
    q.emplace(x);
    while (SZ(q)) {
        ll cur = q.front();
        q.pop();
        a[cur] += money[cur];
        v.eb(cur);
        vis[cur] = true;
        ll to = e[cur].X, w = e[cur].Y;
        a[to] += w;
        b[cur] = (w > money[cur] ?w-money[cur]:0);
        if (!vis[to]) {
            q.emplace(to);
        }
    }
    for (auto cur:v) {
        a[cur] = (e[cur].Y > a[cur] ?e[cur].Y - a[cur]:0);
    }
}
signed main(){
    IOS();
    cin >> n;
    for (ll i=0;i<n;++i) {
        ll to,w;
        cin >> to >> w;
        to--;
        e[i] = pll(to,w);
        in[to]++;
    }
    gogo();
    debug(ans);
    for (ll i=0;i<n;++i) {
        if (vis[i]) continue;
        if (money[i] >= e[i].Y) {
            vis[i] = true;
            ll to = e[i].X;
            money[to] += e[i].Y;
            in[to]--;
            gogo();
        }
    }
    for (int i=0;i<n;++i) {
        if (vis[i]) continue;
        assert(money[i] < e[i].Y);
        v.clear();
        cal(i);
        ll tt = 0;
        for (auto cur:v) {
            tt += a[cur];
        }
        ll tmp = INF;
        for (auto cur:v) {
            tmp = min(tmp,tt - a[cur] + b[cur]);
            assert(a[cur] <= b[cur]);
        }
        ans += tmp;
    }
    for (int i=0;i<n;++i) debug(a[i],b[i]);
    cout << ans << endl;
}
