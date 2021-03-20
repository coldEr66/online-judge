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


int n,q;
struct query{
    int l,r,id;
    bool operator < (const query &a) const {
        return r < a.r;
    }
} Q[MAXN];
int d[MAXN];
struct node {
    int id,prv,tg;
    bool operator < (const node &a) const {
        if (tg != a.tg) return tg < a.tg;
        return prv < a.prv;
    }
} seg[MAXN*2];
int pos[MAXN],ans[MAXN];
void build(){
    for (int i=n-1;i;--i) {
        seg[i] = min(seg[i<<1],seg[i<<1|1]);
    }
}
void ins(int i,int prv,int tg){
    i += n;
    seg[i].prv = prv, seg[i].tg = tg;
    for (;i;i>>=1) {
        seg[i>>1] = min(seg[i],seg[i^1]);
    }
}
node qr(int l,int r){
    node ret = (node){-1,INF,INF};
    for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
        if (l&1) ret = min(ret,seg[l++]);
        if (r&1) ret = min(ret,seg[--r]);
    }
    return ret;
}
signed main(){
    IOS();
    cin >> n;
    RST(pos,-1);
    for (int i=0;i<n;++i) {
        cin >> d[i];
        seg[i+n] = (node){i,INF,1};
    }
    build();
    cin >> q;
    for (int i=0;i<q;++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }
    sort(Q,Q+q);
    int lst = -1;
    for (int i=0;i<q;++i) {
        int l = Q[i].l, r = Q[i].r;
        for (int j=lst+1;j<=r;++j) {
            if (pos[d[j]] != -1) ins(pos[d[j]],-INF,1);
            ins(j,pos[d[j]],0);
            pos[d[j]] = j;
        }
        lst = r;

        node tmp = qr(l,r+1);
        if (tmp.id == -1 || tmp.tg != 0 || tmp.prv >= l) {
            ans[Q[i].id] = 0;
        }
        else {
            ans[Q[i].id] = d[tmp.id];
        }
    }
    for (int i=0;i<q;++i) cout << ans[i] << endl;
}
