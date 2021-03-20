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

int d[MAXn];
signed main(){
    IOS();
    int k1,k2,k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    for (int i=0;i<k1;++i) {
        int x;
        cin >> x;
        d[x] = 1;
    }
    for (int i=0;i<k2;++i) {
        int x;
        cin >> x;
        d[x] = 2;
    }
    for (int i=0;i<k3;++i) {
        int x;
        cin >> x;
        d[x] = 3;
    }
    int cnt1 = k1, cnt2 = k2, cnt3 = k3;
    int ans = cnt2+cnt3;
    int c2 = 0, c3 = 0;
    int cnt = 0;
    for (int l=n;l>0;--l) {
        if (d[l] == 1) {
            cnt1--;
        }
        if (d[l] == 2) {
            cnt2--;
            c2++;
        }
        if (d[l] == 3) {
            cnt3--;
            c3++;
        }
        if (c3 >= c2) {
            cnt += c2;
            c3 = 0, c2 = 0;
        }
        debug(c2,c3,cnt1,cnt2,cnt3);
        ans = min(ans,k1-cnt1 + cnt2 + cnt3 + c3 + cnt);
    }
    cout << ans << endl;
}
