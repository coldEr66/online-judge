#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

ll add(ll a,ll b){
    ll ret = a + b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a - b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll mul(ll a,ll b){
    return a*b%MOD;
}
ll pw[MAXn];
struct node{
    ll dt,tg,p;
} seg[MAXn*4];
void build(int id,int l,int r){
    if (l == r-1) {
        seg[id].p = pw[l];
        seg[id].dt = pw[l];
        seg[id].tg = 0;
        return;
    }
    int mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    seg[id].p = add(seg[id*2+1].p,seg[id*2+2].p);
    seg[id].dt = seg[id].p;
    seg[id].tg = 0;
}
void push(int id){
    if (seg[id].tg == 0) return;
    seg[id*2+1].tg = seg[id].tg;
    seg[id*2+2].tg = seg[id].tg;
    seg[id].dt = mul(seg[id].p,seg[id].tg); 
    seg[id].tg = 0;
}
void ins(int id,int L,int R,int l,int r,int d){
    debug(L,R,l,r);
    if (L == l && R == r) {
        seg[id].tg = d;
        seg[id].dt = mul(seg[id].tg,seg[id].p);
        // debug(id,L,R,seg[id].dt,seg[id].tg);
        return;
    }
    push(id);
    int mid = (L+R)>>1;
    if (l >= mid) ins(id*2+2,mid,R,l,r,d);
    else if (r <= mid) ins(id*2+1,L,mid,l,r,d);
    else {
        ins(id*2+1,L,mid,l,mid,d);
        ins(id*2+2,mid,R,mid,r,d);
    }
    ll lc = (seg[id*2+1].tg == 0 ?seg[id*2+1].dt:mul(seg[id*2+1].p,seg[id*2+1].tg));
    ll rc = (seg[id*2+2].tg == 0 ?seg[id*2+2].dt:mul(seg[id*2+2].p,seg[id*2+2].tg));
    seg[id].dt = add(lc,rc);
    // debug(id,L,R,l,r,d,seg[id].tg,seg[id].dt,seg[id].p,lc,rc);
}
int main(){
    IOS();
    int n,q;
    cin >> n >> q;
    pw[n-1] = 1;
    for (int i=n-2;i>=0;--i) pw[i] = mul(pw[i+1],10);
    build(0,0,n);
    while (q--) {
        int l,r,d;
        cin >> l >> r >> d;
        l--;
        ins(0,0,n,l,r,d);
        cout << seg[0].dt << endl;
    }
}
