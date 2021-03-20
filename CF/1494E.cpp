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

const ll MAXN=1e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

map<pii, char> mp;
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    int odd = 0, even = 0;
    while (m--) {
        char cmd;
        cin >> cmd;
        if (cmd == '+') {
            int u,v;
            char c;
            cin >> u >> v >> c;
            mp[pii(u,v)] = c;
            if (mp.count(pii(v,u))) {
                odd++;
                if (mp[pii(v,u)] == c) even++;
            }
        }
        else if (cmd == '-') {
            int u,v;
            cin >> u >> v;
            char c = mp[pii(u,v)];
            mp.erase(pii(u,v));
            if (mp.count(pii(v,u))) {
                odd--;
                if (mp[pii(v,u)] == c) even--;
            }
        }
        else {
            int k;
            cin >> k;
            bool fg = false;
            if (k % 2 == 0 && even) fg = true;
            if (k % 2 == 1 && odd) fg = true;
            cout << (fg ?"YES":"NO") << endl;
        }
    }
}
