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
template<class T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<class T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

const ll MAXn=2e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

set<int> st;
int d[MAXn];
signed main(){
    IOS();
    int n,k;
    cin >> n >> k;
    vector<int> ans;
    for (int i=1;i<=n;++i) st.insert(i);
    for (int i=0;i<k;++i) {
        cin >> d[i];
        ans.eb(d[i]);
        st.erase(d[i]);
    }

    int cur = 1;
    vector<int> stk;
    for (int i=0;i<k;++i) {
        if (!SZ(stk)) stk.eb(d[i]);
        else {
            if (stk.back() < d[i]) {
                return cout << -1 << endl,0;
            }
            else {
                stk.eb(d[i]);
            }
        }
        while (SZ(stk) && stk.back() == cur) {
            stk.pop_back();
            cur++;
        }
    }
    for (int i=0;i<n-k-1;++i) {
        auto it = st.lower_bound(stk.back());
        if (!SZ(stk)) it = st.end();
        it--;
        int tmp = *it;
        st.erase(it);
        ans.eb(tmp);
        stk.eb(tmp);
        while (SZ(stk) && stk.back() == cur) {
            cur++;
            stk.pop_back();
        }
    }
    ans.eb(*st.begin());
    for (int i=0;i<SZ(ans);++i) {
        cout << ans[i] << " \n"[i==SZ(ans)-1];
    }
}
