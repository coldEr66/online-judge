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

const ll MAXN=3e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

struct rp{
    ll len, to, h;
    bool operator < (const rp &a) const {
        return h < a.h;
    }
};
ll up[MAXN], hor[MAXN];
vector<rp> e[MAXN];
signed main(){
    IOS();
    ll n,H,r,b;
    cin >> n >> H >> r >> b;
    for (int i=0;i<r;++i) {
        ll len, u, v, hh;
        cin >> len >> u >> v >> hh;
        u--, v--;
        e[u].eb((rp){len, v, hh});
        e[v].eb((rp){len, u, hh});
    }
    for (int i=0;i<n;++i) {
        cin >> up[i] >> hor[i];
        sort(ALL(e[i]));
    }
    ll ans = 0;
    for (int i=0;i<b;++i) {
        ll pos,h,x,y;
        cin >> pos >> h >> x >> y;
        pos--;
        ll updis = 0, movehor = 0;
        while (1) {
            debug(pos);
            if (!SZ(e[pos])) {
                updis += h;
                break;
            }
            auto p = lower_bound(ALL(e[pos]), (rp){0,0,h});
            if (p == e[pos].begin()) {
                updis += h;
                break;
            }

            rp cur = *prev(p);
            updis += h - cur.h;
            movehor += cur.len;
            pos = cur.to;
            h = cur.h;
        }
        ll sum = updis * up[pos] + movehor * hor[pos];
        ll rem = sum % (x + y);
        if (rem >= 1 && rem <= x) ans++;
    } 
    cout << ans << endl;
}
