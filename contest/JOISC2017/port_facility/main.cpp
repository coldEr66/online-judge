#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
ii d[MAXn];
int dl[MAXn*2],dr[MAXn*2];
ii mxseg[MAXn*4],mnseg[MAXn*4];
bitset<MAXn> vis;
bool col[MAXn];
int id[MAXn*2];
ll mul(ll a,ll b){
    return a*b%MOD;
}
ll fpow(ll a,ll b){
    ll ret = 1;
    while (b) {
        if (b&1) ret = mul(ret,a);
        a = mul(a,a);
        b >>= 1;
    }
    return ret;
}
void build(){
    for (int i=2*n-1;i;i--) {
        mnseg[i] = min(mnseg[i<<1],mnseg[i<<1|1]);
        mxseg[i] = max(mxseg[i<<1],mxseg[i<<1|1]);
    }
}
void mnins(int x,int val){
    mnseg[x+2*n].X = val;
    for (int i=x+2*n;i>1;i>>=1) {
        mnseg[i>>1] = min(mnseg[i],mnseg[i^1]);
    }
}
void mxins(int x,int val){
    mxseg[x+2*n].X = val;
    for (int i=x+2*n;i>1;i>>=1) {
        mxseg[i>>1] = max(mxseg[i],mxseg[i^1]);
    }
}
ii mnqr(int l,int r){
    ii ret = ii(2*n,2*n);
    for (l+=2*n,r+=2*n;l<r;l>>=1,r>>=1) {
        if (l&1) ret = min(ret,mnseg[l++]);
        if (r&1) ret = min(ret,mnseg[--r]);
    }
    return ret;
}
ii mxqr(int l,int r){
    ii ret = ii(-1,-1);
    for (l+=2*n,r+=2*n;l<r;l>>=1,r>>=1) {
        if (l&1) ret = max(ret,mxseg[l++]);
        if (r&1) ret = max(ret,mxseg[--r]);
    }
    return ret;
}
void gogo(int x){
    queue<int> q;
    q.push(x);
    mxins(d[x].X,-1), mnins(d[x].Y,2*n);
    while (SZ(q)) {
        int cur = q.front();
        q.pop();
        vis[cur] = true;
        int l = d[cur].X, r = d[cur].Y;
        ii tmp = mxqr(l,r+1);
        while (tmp.X > r) {
            int nxt = id[tmp.Y];
            col[nxt] = !col[cur];
            int tl = d[nxt].X, tr = d[nxt].Y;
            mxins(tl,-1), mnins(tr,2*n);
            tmp = mxqr(l,r+1);
            q.push(nxt);
        }
        tmp = mnqr(l,r+1);
        while (tmp.X < l) {
            int nxt = id[tmp.Y];
            col[nxt] = !col[cur];
            int tl = d[nxt].X, tr = d[nxt].Y;
            mxins(tl,-1), mnins(tr,2*n);
            tmp = mnqr(l,r+1);
            q.push(nxt);
        }
    }
}
bool chk(){
    vector<ii> port(2*n+1);
    REP (i,n) {
        port[d[i].X] = ii(i,col[i]);
        port[d[i].Y] = ii(-i,col[i]);
    }
    vector<int> stk[2];
    REP (i,2*n) {
        if (port[i].X >= 0) {
            stk[port[i].Y].eb(port[i].X);
        }
        else {
            if (stk[port[i].Y].back() != -port[i].X) return false;
            stk[port[i].Y].pob();
        }
    }
    return true;
}
int main(){
    IOS();
    cin >> n;
    REP (i,n) {
        cin >> d[i].X >> d[i].Y;
        d[i].X--, d[i].Y--;
    }
    sort(d,d+n);
    REP (i,2*n) {
        dl[i] = -1;
        dr[i] = 2*n;
    }
    REP (i,n) {
        id[d[i].X] = id[d[i].Y] = i;
        dl[d[i].X] = d[i].Y;
        dr[d[i].Y] = d[i].X;
    }
    REP (i,2*n) {
        mxseg[i+2*n] = ii(dl[i],i);
        mnseg[i+2*n] = ii(dr[i],i);
    }
    build();
    ll ans = 0;
    REP (i,n) {
        if (!vis[i]) {
            gogo(i);
            ans++;
        }
    }
    pary(col,col+n);
    if (chk()) cout << fpow(2LL,ans) << endl;
    else cout << 0 << endl;
}
