#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
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
const ll MOD=998244353;
const ll INF=0x3f3f3f3f;

map<ll,ll> mpx,mpy;
ll xp[MAXn],bit[MAXn];
ll rkx[MAXn],rky[MAXn],dtx[MAXn],dty[MAXn];
ll lowbit(ll x){return x&(-x);}
void ins(ll x){
    for (;x<MAXn;x+=lowbit(x)) bit[x]++;
}
ll qr(ll x){
    ll ret = 0;
    for (;x>0;x-=lowbit(x)) ret += bit[x];
    return ret;
}
ll add(ll a,ll b){
    ll ret = a+b;
    if (ret >= MOD) ret -= MOD;
    return ret;
}
ll sub(ll a,ll b){
    ll ret = a-b;
    if (ret < 0) ret += MOD;
    return ret;
}
ll mul(ll a,ll b){
    return (a*b)%MOD;
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
int main(){
    IOS();
    ll n;
    cin >> n;
    REP1 (i,n) {
        ll x,y;
        cin >> x >> y;
        rkx[i] = dtx[i] = x;
        rky[i] = dty[i] = y;
    }
    sort(rkx+1,rkx+n+1);
    sort(rky+1,rky+n+1);
    REP1 (i,n) {
        mpx[rkx[i]] = i;
        mpy[rky[i]] = i;
    }
    REP1 (i,n) xp[mpx[dtx[i]]] = mpy[dty[i]];
    pary(xp+1,xp+n+1);
    ll ans = 0;
    REP1 (i,n) {
        ans = add(ans,fpow(2,n));

        ans = sub(ans,fpow(2,i-1));
        ans = sub(ans,fpow(2,n-i));
        ans = sub(ans,fpow(2,xp[i]-1));
        ans = sub(ans,fpow(2,n-xp[i]));

        ll tmp = qr(xp[i]-1); // x below y below
        ll tmp1 = qr(n) - qr(xp[i]); // x below y above
        ans = add(ans,fpow(2,tmp));
        ans = add(ans,fpow(2,tmp1));
        ans = add(ans,fpow(2,xp[i]-1-tmp));
        ans = add(ans,fpow(2,n-xp[i]-tmp1));

        ans = sub(ans,1);
        ins(xp[i]);
    }
    cout << ans << endl;
}
