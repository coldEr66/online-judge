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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct Q{
    ll l,r,id;
    bool operator < (const Q &a) const {
        return l < a.l;
    }
};
ll mn[MAXn],mx[MAXn];
ll d[MAXn];
queue<ll> q[MAXn];
ll bit[MAXn];
ll lowbit(ll x){ return x&(-x); }
void ins(ll x,ll v){
    for (x++;x<MAXn;x+=lowbit(x)) bit[x] += v; 
}
ll qr(ll x){
    ll ret = 0;
    for (x++;x>0;x-=lowbit(x)) ret += bit[x];
    return ret;
}
ll qr(ll l,ll r){
    if (l > r) return 0;
    return qr(r) - qr(l-1);
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    for (int i=1;i<=n;++i) mn[i] = mx[i] = i;
    for (int i=1;i<=m;++i) {
        cin >> d[i];
        q[d[i]].emplace(i);
        mn[d[i]] = 1;
    }
    int cnt = 0;
    for (ll i=n;i>0;--i) {
        if (!SZ(q[i])) {
            mx[i] = n-cnt;
            cnt++;
        }
    }
    for (ll i=n;i>0;--i) {
        if (SZ(q[i])) {
            mx[i] = i + qr(0,q[i].front());
            debug(q[i].front());
            ins(q[i].front(),1);
        }
    }
    for (ll i=1;i<=m;++i) {
        if (!SZ(q[d[i]]) || q[d[i]].front() != i) continue;
        q[d[i]].pop();
        ll r = (SZ(q[d[i]]) ?q[d[i]].front()-1:m);
        debug(i,d[i],r,qr(i,r));
        mx[d[i]] = max(mx[d[i]],qr(i,r));
        ins(i,-1);
        if (SZ(q[d[i]])) ins(q[d[i]].front(),1);
    }
    for (int i=1;i<=n;++i) {
        cout << mn[i] << ' ' << mx[i] << endl;
    }
}
