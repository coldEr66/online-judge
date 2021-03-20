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
const ll INF=0x3f3f3f3f3f3f3f3f;


struct state{
    ll v,mx,mn;
    bool operator < (const state &a) const {
        if (v != a.v) return v < a.v;
        if (mx != a.mx) return mx < a.mx;
        return mn < a.mn;
    }
};
ll dis[MAXN][2][2];
vector<pll> e[MAXN];
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<m;++i) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        e[u].eb(v,w);
        e[v].eb(u,w);
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<2;++j) {
            for (int k=0;k<2;++k) {
                dis[i][j][k] = INF;
            }
        }
    }

    set<pair<ll, state> > st;
    st.insert({0, (state){0,0,0}});
    dis[0][0][0] = 0;
    while (SZ(st)) {
        auto it = st.begin();
        ll cur = it->Y.v, mx = it->Y.mx, mn = it->Y.mn;
        st.erase(it);
        for (auto i:e[cur]) {
            ll to = i.X;
            ll w = i.Y;
            for (int j=0;j<=1-mx;++j) {
                for (int k=0;k<=1-mn;++k) {
                    if (dis[to][mx | j][mn | k] > dis[cur][mx][mn] + w * (1 - j + k)) {
                        pair<ll,state> tp = {dis[to][mx | j][mn | k], (state){to, mx|j, mn|k}};
                        auto tmp = st.find(tp);
                        if (tmp != st.end()) st.erase(tmp);
                        dis[to][mx | j][mn | k] = dis[cur][mx][mn] + w * (1 - j + k);
                        st.insert({dis[to][mx | j][mn | k], (state){to, mx|j, mn|k}});
                    }
                }
            }
        }
    }

    for (int i=1;i<n;++i) cout << dis[i][1][1] << " \n"[i==n-1];
}
