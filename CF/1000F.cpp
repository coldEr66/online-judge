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

const ll MAXN=5e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const int K = 800;

struct query {
    int l,r,id;
} Q[MAXN];
int n,q;
int tt,ok[MAXN],bok[K];
int ans[MAXN];
int cnt[MAXN];
int d[MAXN];
bool cmp(const query &a,const query &b){
    int tmp = a.l / K;
    if (tmp != b.l / K) return a.l < b.l;
    if (tmp&1) return a.r > b.r;
    return a.r < b.r;
}
void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) {
        tt++, ok[x]++, bok[x/K]++;
    }
    else if (cnt[x] == 2) {
        tt--, ok[x]--, bok[x/K]--;
    }
}
void del(int x){
    cnt[x]--;
    if (cnt[x] == 1) {
        tt++, ok[x]++, bok[x/K]++;
    }
    else if (cnt[x] == 0) {
        tt--, ok[x]--, bok[x/K]--;
    }
}
int gt(){
    if (!tt) return 0;
    for (int i=0;i<K;++i) {
        if (bok[i]) {
            for (int j=i*K;j<=(i+1)*K-1;++j) {
                if (ok[j]) return j;
            }
        }
    }
    return 87;
}
signed main(){
    IOS();
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i];
    }
    cin >> q;
    for (int i=0;i<q;++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }
    sort(Q,Q+q,cmp);
    int l = 0, r = -1;
    for (int i=0;i<q;++i) {
        while (l > Q[i].l) add(d[--l]);
        while (r < Q[i].r) add(d[++r]);
        while (l < Q[i].l) del(d[l++]);
        while (r > Q[i].r) del(d[r--]);
        ans[Q[i].id] = gt();
    }
    for (int i=0;i<q;++i) cout << ans[i] << endl;
}
