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
#define SZ(a) (ll)a.size()
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

ll p[MAXn],a[MAXn];
int pos[MAXn];
ll sum[MAXn];
ll seg[MAXn*4],tg[MAXn*4];
void pull(int id){
    seg[id] = min(seg[id*2+1] + tg[id*2+1],seg[id*2+2] + tg[id*2+2]);
}
void push(int id){
    if (!tg[id]) return;
    seg[id] += tg[id];
    tg[id*2+1] += tg[id];
    tg[id*2+2] += tg[id];
    tg[id] = 0;
}
void build(int id,int l,int r){
    if (l == r-1) {
        seg[id] = sum[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    pull(id);
}
void ins(int id,int L,int R,int l,int r,ll v){
    if (l >= r) return;
    if (L == l && R == r) {
        if (l == 0 && r == 0)debug(tg[id]);
        tg[id] += v;
        return;
    }
    push(id);
    int mid = (L+R)>>1;
    if (r <= mid) ins(id*2+1,L,mid,l,r,v);
    else if (l >= mid) ins(id*2+2,mid,R,l,r,v);
    else {
        ins(id*2+1,L,mid,l,mid,v);
        ins(id*2+2,mid,R,mid,r,v);
    }
    pull(id);
}
ll qr(int id,int L,int R,int l,int r){
    if (l >= r) return INF;
    if (L == l && R == r) {
        return seg[id] + tg[id];
    }
    push(id);
    int mid = (L+R)>>1;
    if (r <= mid) return qr(id*2+1,L,mid,l,r);
    else if (l >= mid) return qr(id*2+2,mid,R,l,r);
    else {
        return min(qr(id*2+1,L,mid,l,mid),qr(id*2+2,mid,R,mid,r));
    }
}
int main(){
    IOS();
    int n;
    cin >> n;
    REP (i,n) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    REP (i,n) {
        cin >> a[i];
        if (i) sum[i] = sum[i-1] + a[i];
        else sum[i] = a[i];
    }

    build(0,0,n);
    ll ans = min(a[0],a[n-1]);
    REP1 (i,n-1) {
        int cur = pos[i];
        ins(0,0,n,0,cur,a[cur]);
        ins(0,0,n,cur,n,-a[cur]);
        ans = min(ans,qr(0,0,n,0,n-1));
    }
    cout << ans << endl;
}
