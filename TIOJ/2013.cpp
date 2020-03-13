#include "lib2013.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct node{
    int pri,sz;
    node *lc,*rc,*par;
    void init(int _pri) {
        pri = _pri;
        sz = 1;
        lc = rc = par = 0;
    }
} mem[MAXn*2];

node *newnode(){
    static int top = 0;
    return &mem[top++];
}
inline int gtsz(node *x){
    return x ?x->sz:0;
}
node *in[MAXn],*out[MAXn],*rt[MAXn];
node *mrg(node *a,node *b){
    if (!a || !b) return a ?a:b;
    if (a->pri > b->pri) {
        a->rc = mrg(a->rc,b);
        if (a->rc) a->rc->par = a;
        a->sz = gtsz(a->lc) + gtsz(a->rc) + 1;
        return a;
    }
    b->lc = mrg(a,b->lc);
    if (b->lc) b->lc->par = b;
    b->sz = gtsz(b->lc) + gtsz(b->rc) + 1;
    return b;
}
void split(node *a,node *&b,node *&c,int k){
    if (!a) b = c = 0;
    else {
        if (gtsz(a->lc) >= k) {
            c = a;
            split(a->lc,b,c->lc,k);
            if (c->lc) c->lc->par = c;
            c->sz = gtsz(c->lc) + gtsz(c->rc) + 1;
        }
        else {
            b = a;
            split(a->rc,b->rc,c,k-gtsz(a->lc)-1);
            if (b->rc) b->rc->par = b;
            b->sz = gtsz(b->lc) + gtsz(b->rc) + 1;
        }
    }
}
int index(node *x){
    int ret = gtsz(x->lc) + 1;
    while (x->par) {
        if (x->par->rc == x) ret += gtsz(x->par->lc) + 1;
        x = x->par;
    }
    return ret;
}
int dsu[MAXn];
int fnd(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void dsu_mrg(int a,int b){
    a = fnd(a), b = fnd(b);
    dsu[b] = a;
}

void init(int N){
    srand(880301);
    REP (i,N) {
        dsu[i] = i;
        in[i] = newnode();
        in[i]->init(rand());
        out[i] = newnode();
        out[i]->init(rand());
        rt[i] = mrg(in[i],out[i]);
    }
}
void explore(int a, int b){
    int tmp = index(in[a]);
    node *l,*r;
    split(rt[fnd(a)],l,r,tmp);
    l = mrg(l,rt[fnd(b)]);
    rt[fnd(a)] = mrg(l,r);
    dsu_mrg(a,b);
}

int run(int a, int b){
    if (fnd(a) != fnd(b)) return 0;
    int l = index(in[a]), r = index(out[a]);
    int tg = index(in[b]);
    if (l <= tg && r >= tg) return 1;
    return 0;
}
