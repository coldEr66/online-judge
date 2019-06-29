#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;
const ll MAXbit=(1<<20)+1;

typedef pair<ll,ii> iii;
ll n,k;
ll d[MAXn];
ll bit1[MAXbit],bit2[MAXbit];
ll lowbit(ll x){
    return x&(-x);
}
void ins(ll *bit,ll x,ll val){
    for (;x<=MAXbit;x+=lowbit(x)) {
        bit[x] += val;
    }
}
ll qr(ll *bit,ll x){
    ll ret = 0;
    for (;x>0;x-=lowbit(x)) {
        ret += bit[x];
    }
    return ret;
}
iii get(ll x){
    ll ret = 0, sum = 0, tmp = 0;
    for (ll i=20;i>=0;i--) {
        if ((ret|(1<<i)) <= MAXbit && sum + bit1[ret|(1<<i)] < x) {
            ret |= (1<<i);
            sum += bit1[ret];
            tmp += bit2[ret];
        }
    }
    debug(tmp,sum);
    return iii(ret+1,ii(sum,tmp));
}
ll cal(iii x){
    debug(x);
    ll sum1 = x.Y.Y;
    ll sum2 = qr(bit2,MAXbit) - qr(bit2,x.X);
    ll cnt1 = x.Y.X;
    ll cnt2 = qr(bit1,MAXbit) - qr(bit1,x.X);
    return sum2 - sum1 + (cnt1 - cnt2) * x.X;
}
inline void modify(ll x,ll c){
    ins(bit1,x,c);
    ins(bit2,x,c*x);
}
int main(){
    IOS();
    cin >> n >> k;
    REP (i,n) {
        cin >> d[i];
        d[i]++;
    }

    REP (i,k) modify(d[i],1);
    ll tg = (k+1)/2;
    iii kth = get(tg);
    iii ans = iii(cal(kth),ii(0,kth.X));
    debug(kth);
    debug(bit1[MAXbit],bit2[MAXbit]);
    for (ll i=k;i<n;i++) {
        modify(d[i-k],-1);
        modify(d[i],1);
        kth = get(tg);
        ll tmp = cal(kth);
        debug(kth,tmp);
        if (tmp < ans.X) ans = iii(tmp,ii(i-k+1,kth.X));
    }
    cout << ans.X << endl;
    REP (i,n) {
        if (ans.Y.X <= i && i < ans.Y.X + k) cout << ans.Y.Y-1 << endl;
        else cout << d[i]-1 << endl;
    }
}
