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

const ll MAXN=2e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MAXM = 2e5+5;

struct event{
    ll l,r,u,id;
    bool operator < (const event &a) const {
        return u < a.u;
    }
} Q[MAXM];
int n,m;
ll d[MAXN], sum[MAXN];
ll bit[MAXN][MAXN];
vector<event> v;
ll ans[MAXM];
int lowbit(int x){return x&(-x);}
void ins(int x,int y,ll val){
    for (int i=x;i<MAXN;i+=lowbit(i)) {
        for (int j=y;j<MAXN;j+=lowbit(j)) {
            bit[i][j] = max(bit[i][j], val);
        }
    }
}
ll qr(int x,int y){
    ll ret = -INF;
    for (int i=x;i;i-=lowbit(i)) {
        for (int j=y;j;j-=lowbit(j)) {
            ret = max(ret, bit[i][j]);
        }
    }
    return ret;
}
void init(){
    for (int i=0;i<MAXN;++i) {
        for (int j=0;j<MAXN;++j) {
            bit[i][j] = -INF;
        }
    }
}
signed main(){
    IOS();
    cin >> n >> m;
    for (int i=1;i<=n;++i) {
        cin >> d[i];
        sum[i] = d[i] + sum[i-1];
    }
    for (int i=0;i<m;++i) {
        cin >> Q[i].l >> Q[i].r >> Q[i].u;
        Q[i].l = n - Q[i].l + 1;
        Q[i].id = i;
    }
    for (int i=1;i<=n;++i) {
        for (int j=i;j<=n;++j) {
            v.eb((event){n-i+1, j, sum[j] - sum[i-1], -1});
        }
    }
    sort(ALL(v));
    sort(Q,Q+m);

    init();
    int idx = 0;
    for (int i=0;i<m;++i) {
        while (idx < SZ(v) && v[idx].u <= Q[i].u) {
            ins(v[idx].l, v[idx].r, v[idx].u);
            idx++;
        }
        ans[Q[i].id] = qr(Q[i].l, Q[i].r);
    }
    for (int i=0;i<m;++i) {
        if (ans[i] == -INF) cout << "NONE" << endl;
        else cout << ans[i] << endl;
    }
}
