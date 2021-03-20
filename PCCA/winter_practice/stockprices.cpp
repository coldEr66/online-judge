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

signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll lst = -1;
        map<ll,ll> sell;
        map<ll,ll, greater<ll> > buy;
        for (int i=0;i<n;++i) {
            string s,gar;
            ll x,y;
            cin >> s >> x >> gar >> gar >> y;
            if (s[0] == 'b') buy[y] += x;
            else sell[y] += x;

            while (SZ(buy) && SZ(sell) && buy.begin()->X >= sell.begin()->X) {
                lst = sell.begin()->X;
                ll sz = min(buy.begin()->Y, sell.begin()->Y);
                sell.begin()->Y -= sz, buy.begin()->Y -= sz;
                if (sell.begin()->Y == 0) sell.erase(sell.begin());
                if (buy.begin()->Y == 0) buy.erase(buy.begin());
            }

            if (SZ(sell)) cout << sell.begin()->X;
            else cout << '-';
            cout << ' ';
            if (SZ(buy)) cout << buy.begin()->X;
            else cout << '-';
            cout << ' ';
            if (lst == -1) cout << '-';
            else cout << lst;
            cout << endl;
        }
    }
}
