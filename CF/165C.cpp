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

const ll MAXn=1e6+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

#define int ll
deque<int> dq;
ll gt() {
    if (SZ(dq) == 1) return dq.front() + 1;
    return (dq.front() + 1) * (dq.back() + 1);
}
signed main(){
    IOS();
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = SZ(s);
    if (k == 0) {
        ll tmp = 0, tc = 0;
        for (int i=0;i<n;++i) {
            if (s[i] == '0') tc++;
            else {
                tmp += tc * (tc+1) / 2;
                tc = 0;
            }
        }
        tmp += tc * (tc+1) / 2;
        return cout << tmp << endl,0;
    }
    ll ans = 0, cur = 0;
    int cnt = 0;
    for (int i=0;i<n;++i) {
        if (s[i] == '0') cnt++;
        else {
            dq.eb(cnt);
            cnt = 0;
            cur++;
            if (cur == k+1) {
                ans += gt();
                debug(gt());
                if (SZ(dq)) dq.pop_front();
                cur--;
            }
        }
    }
    dq.eb(cnt);
    debug(gt(),cur,SZ(dq));
    if (cur == k) ans += gt();
    cout << ans << endl;
}
