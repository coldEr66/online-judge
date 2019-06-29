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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ii d[MAXn];
vector<ll> _;
struct node{
    ll dt,tag;
} seg[MAXn*4];
ll gt(ll id){
    return seg[id].dt+seg[id].tag;
}
void ins(ll id,ll L,ll R,ll l,ll r,ll v){
    if (L == l && R == r){
        debug(seg[id].tag);
        seg[id].tag += v;
        return;
    }
    ll mid = (L+R)>>1;
    if (r <= mid) ins(id*2+1,L,mid,l,r,v);
    else if (l >= mid) ins(id*2+2,mid,R,l,r,v);
    else {
        ins(id*2+1,L,mid,l,mid,v);
        ins(id*2+2,mid,R,mid,r,v);
    }
    seg[id].dt = (seg[id*2+1].tag ?mid-L:seg[id*2+1].dt) + (seg[id*2+2].tag ?R-mid:seg[id*2+2].dt);
}
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) {
        cin >> d[i].X >> d[i].Y;
        _.eb(d[i].X);
        _.eb(d[i].X+1);
        _.eb(d[i].Y);
        _.eb(d[i].Y+1);
    }
    sort(ALL(_));
    _.resize(unique(ALL(_))-_.begin());
    REP (i,n) {
        d[i].X = lower_bound(ALL(_),d[i].X) - _.begin();
        d[i].Y = lower_bound(ALL(_),d[i].Y) - _.begin();
        ins(0,0,MAXn,d[i].X,d[i].Y+1,1);
    }

    debug(seg[0].dt);
    REP (i,n) {
        ll tmp = seg[0].dt;
        debug(tmp);
        ins(0,0,MAXn,d[i].X,d[i].Y+1,-1);
        debug(seg[0].dt);
        if (seg[0].dt == tmp) return cout << i+1 << endl,0;
        ins(0,0,MAXn,d[i].X,d[i].Y+1,1);
    }
    cout << -1 << endl;
}
