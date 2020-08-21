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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

void setIO(string pname){
    IOS();
    freopen((pname+".txt").c_str(),"r",stdin);
    freopen((pname+".out").c_str(),"w",stdout);
}
struct node{
    ll l,r,ml,mr,data;
    ll tg,lp,rp,cnt;
} seg[MAXn*4];
struct point{
    ll x,yl,yr,type;
} d[MAXn];
bool cmp(const point &a,const point &b){
    return a.x < b.x;
}
ll L[MAXn],H[MAXn],Y[MAXn];
int cc;
void build(int id,ll l,ll r){
    seg[id].l = l, seg[id].r = r;
    seg[id].ml = Y[l], seg[id].mr = Y[r];
    seg[id].data = seg[id].lp = seg[id].rp = seg[id].cnt = 0;
    if (l == r-1) return;
    ll mid = (l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid,r);
}
void update(int id){
    int lc = id<<1, rc = id<<1|1;
    if (seg[id].tg > 0) {
        seg[id].data = seg[id].mr - seg[id].ml;
        seg[id].lp = seg[id].rp = 1;
        seg[id].cnt = 2;
    }
    else if (seg[id].l == seg[id].r-1) {
        seg[id].data = 0;
        seg[id].lp = seg[id].rp = seg[id].cnt = 0;
    }
    else {
        seg[id].data = seg[lc].data+seg[rc].data;
        seg[id].lp = seg[lc].lp;
        seg[id].rp = seg[rc].rp;
        seg[id].cnt = seg[lc].cnt + seg[rc].cnt;
        if (seg[lc].rp && seg[rc].lp) seg[id].cnt -= 2;
    }
}
void add(int id,point a){
    if (seg[id].ml == a.yl && seg[id].mr == a.yr) {
        seg[id].tg += a.type;
        update(id);
        return;
    }
    if (a.yr <= seg[id<<1].mr) add(id<<1,a);
    else if (a.yl >= seg[id<<1|1].ml) add(id<<1|1,a);
    else {
        point tmp = a;
        tmp.yr = seg[id<<1].mr;
        add(id<<1,tmp);
        tmp = a;
        tmp.yl = seg[id<<1|1].ml;
        add(id<<1|1,tmp);
    }
    update(id);
}
int main(){
    // setIO("");
    int t;
    cin >> t;
    while (t--) {
        RST(Y,0);
        cc++;
        ll n,k,w;
        cin >> n >> k >> w;
        for (int i=1;i<=k;++i) {
            cin >> L[i];
        }
        ll a,b,c,dd;
        cin >> a >> b >> c >> dd;
        for (int i=k+1;i<=n;++i) {
            L[i] = (a * L[i-2] + b * L[i-1] + c) % dd + 1;
        }
        for (int i=1;i<=k;++i) {
            cin >> H[i];
        }
        cin >> a >> b >> c >> dd;
        for (int i=k+1;i<=n;++i) {
            H[i] = (a * H[i-2] + b * H[i-1] + c) % dd + 1;
        }
        
        int idx = 0;
        for (int i=1;i<=n;++i) {
            debug(L[i],H[i]);
            idx++;
            Y[idx] = 0;
            d[idx].x = L[i], d[idx].yl = 0, d[idx].yr = H[i], d[idx].type = 1;
            idx++;
            Y[idx] = H[i];
            d[idx].x = L[i]+w, d[idx].yl = 0, d[idx].yr = H[i], d[idx].type = -1;
        }
        sort(Y+1,Y+idx+1);
        ll nn = unique(Y+1,Y+idx+1) - Y - 1;
        debug(nn);
        build(1,1,nn);

        sort(d+1,d+idx+1,cmp);
        ll ans = 1;
        ll cur = 0;
        ll delta = 0;
        for (int i=1;i<=idx;++i) {
            add(1,d[i]);
            cur += (ll)abs(delta - seg[1].data);
            delta = seg[1].data;
            if (i != idx) cur += (ll)(d[i+1].x - d[i].x) * seg[1].cnt;
            debug(cur);
            ans = ans * (cur % MOD) % MOD;
        }
        cout << "Case #" << cc << ": ";
        cout << ans << endl;
    }
}
