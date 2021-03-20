#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;


int d[20];
ll fac[20];
int n,q;
void build(ll cur) {
    int idx = max(n-14,1);
    int num[20];
    for (int i=1;i<=min(15,n);++i) {
        num[i] = idx++;
    }
    for (int i=1;i<=min(15,n);++i) {
        ll tmp = cur/fac[min(15,n)-i];
        cur -= tmp * fac[min(15,n)-i];
        d[i] = num[tmp+1];
        for (ll j=tmp+2;j<=min(15,n);++j) {
            num[j-1] = num[j];
        }
    }
    pary(d+1,d+min(n,15)+1);
}
signed main(){
    IOS();
    cin >> n >> q;
    ll cur = 0;
    ll margin = max(1,n-14);
    fac[0] = 1;
    for (ll i=1;i<=15;++i) fac[i] = fac[i-1] * i;
    build(cur);
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll l,r;
            cin >> l >> r;
            if (r < margin) {
                cout << (l+r) * (r-l+1) / 2 << endl;
            }
            else {
                ll ans = 0;
                if (l < margin) ans += (l+margin-1) * (margin-l) / 2;
                for (ll i=max(l,margin);i<=r;++i) ans += d[i-margin+1];
                cout << ans << endl;
            }
        }
        else {
            ll x;
            cin >> x;
            cur += x;
            build(cur);
        }
    }
}
