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

const ll MAXN=1e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const int K = 320;

struct query{
    int l,r,id;
    bool operator < (const query &a) const {
        if (l / K != a.l / K) return l / K < a.l / K;
        return r < a.r;
    }
} Q[MAXN];
int n,q;
ll d[MAXN];
int id[MAXN];
ll ans[MAXN];
ll cnt[MAXN],tcnt[MAXN];
vector<ll> rk;
int gtr(int x){
    int tmp = x / K;
    return min((tmp+1)*K,n);
}
void add(int x,ll &cur){
    cnt[x]++;
    cur = max(cur,cnt[x] * rk[x]);
}
void del(int x){
    cnt[x]--;
}
signed main(){
    IOS();
    cin >> n >> q;
    for (int i=0;i<n;++i) {
        cin >> d[i];
        rk.eb(d[i]);
    }
    sort(ALL(rk));
    rk.resize(unique(ALL(rk)) - rk.begin());
    for (int i=0;i<n;++i) {
        id[i] = int(lower_bound(ALL(rk),d[i]) - rk.begin());
    }
    for (int i=0;i<q;++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }
    sort(Q,Q+q);
    
    int l = 0, r = -1;
    int tl = 0;
    ll cur = 0, tmp;
    int lst = -1;
    for (int i=0;i<q;++i) {
        if (Q[i].l / K == Q[i].r / K) {
            for (int j=Q[i].l;j<=Q[i].r;++j) tcnt[id[j]]++;
            for (int j=Q[i].l;j<=Q[i].r;++j) {
                ans[Q[i].id] = max(ans[Q[i].id],tcnt[id[j]] * rk[id[j]]);
            }
            for (int j=Q[i].l;j<=Q[i].r;++j) tcnt[id[j]]--;
            continue;
        }

        if (lst != Q[i].l/K) {
            int R = gtr(Q[i].l);
            while (r > R-1) del(id[r--]);
            while (l < R) del(id[l++]);
            cur = 0;
            lst = Q[i].l/K;
        }

        while (r < Q[i].r) add(id[++r],cur);
        tl = l, tmp = cur;
        while (tl > Q[i].l) add(id[--tl],tmp);
        ans[Q[i].id] = tmp;
        while (tl < l) del(id[tl++]);
    }
    for (int i=0;i<q;++i) cout << ans[i] << endl;
}
