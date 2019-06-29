#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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

struct treap{
    treap *l,*r;
    ll dt,pri,sz;
    bool rev;
    treap(ll x):l(0),r(0),dt(x),pri((ll)rand()<<31LL | (ll)rand()),sz(1),rev(false){};
    void pull(){
        sz = 1;
        if (l) sz += l->sz;
        if (r) sz += r->sz;
    }
};
void push(treap *o){
    if (o && o->rev) {
        o->rev = false;
        swap(o->l,o->r);
        if (o->l) o->l->rev ^= 1;
        if (o->r) o->r->rev ^= 1;
    }
}
inline ll gt(treap *o){return o ?o->sz:0LL;}
treap *merge(treap *a,treap *b){
    if (!a || !b) return a ?a:b;
    push(a), push(b);
    if (a->pri < b->pri) {
        a->r = merge(a->r,b);
        a->pull();
        return a;
    }
    else {
        b->l = merge(a,b->l);
        b->pull();
        return b;
    }
}
void split(treap *o,treap *&a,treap *&b,ll k){
    if (!o) a=b=0;
    else {
        push(o);
        ll tmp = gt(o->l)+1;
        if (tmp <= k) {
            a = o;
            split(o->r,a->r,b,k-tmp);
        }
        else {
            b = o;
            split(o->l,a,b->l,k);
        }
        o->pull();
    }
}
void ins(treap *&o,ll k){
    if (!o) o = new treap(k);
    else o = merge(o,new treap(k));
}
treap *shift(treap *o,ll l,ll r){
    treap *a,*b,*c,*bb;
    split(o,a,b,l-1);
    split(b,b,c,r-l+1);
    split(b,b,bb,r-l);
    return merge(merge(a,merge(bb,b)),c);
}
void rvs(treap *o,ll l,ll r){
    treap *a,*b,*c;
    split(o,a,b,l-1);
    split(b,b,c,r-l+1);
    b->rev ^= 1;
    merge(merge(a,b),c);
}
ll d[MAXn],idx;
void dfs(treap *root){
    push(root);
    if (root->l) dfs(root->l);
    d[idx++] = root->dt;
    if (root->r) dfs(root->r);
}
int main(){
    IOS();
    srand(clock());
    ll n,q,m;
    cin >> n >> q >> m;
    treap *root = 0;
    REP (i,n) {
        cin >> d[i];
        ins(root,d[i]);
    }
    while (q--) {
        ll cmd;
        cin >> cmd;
        ll l,r;
        cin >> l >> r;
        if (cmd == 1) root = shift(root,l,r);
        else rvs(root,l,r);
    }
    dfs(root);
    REP (i,m) {
        ll id;
        cin >> id;
        cout << d[id-1] << " \n"[i==m-1];
    }
}
