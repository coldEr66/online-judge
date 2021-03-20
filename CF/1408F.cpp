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

vector<int> id[15];
vector<pii> ans;
void gogo(vector<int> &tmp,int len) {
    debug(tmp,len);
    for (int i=1;i<len;i<<=1) {
        for (int j=0;j<SZ(tmp);j += i*2) {
            for (int k=j;k<j+i;k++) {
                ans.eb(tmp[k],tmp[k+i]);
            }
        }
    }
}
signed main(){
    IOS();
    int n;
    cin >> n;
    int idx = 0;
    int nn = n, len = 0;
    while (nn) {
        if (nn&1) {
            for (int i=0;i<(1<<len);++i) {
                id[len].eb(idx++);
            }
        }
        nn >>= 1;
        len++;
    }
    int mx = 0, cnt = 0;
    for (int i=0;i<14;++i) {
        if (SZ(id[i])) {
            cnt++;
            gogo(id[i],(1<<i));
            mx = i;
        }
    }
    debug(ans,cnt);
    vector<int> cur;
    cur.eb(id[mx].back());
    id[mx].pop_back();
    for (int i=0;i<mx;++i) {
        if (cnt <= 1) break;
        if (SZ(id[i])) {
            for (int j=0;j<(1<<i);++j) {
                ans.eb(id[i][j],cur[j]);
            }
            for (int j=0;j<(1<<i);++j) {
                cur.eb(id[i][j]);
            }
            cnt--;
        }
        else {
            for (int j=0;j<(1<<i);++j) {
                int tmp = id[mx].back();
                id[mx].pop_back();
                ans.eb(cur[j],tmp);
                cur.eb(tmp);
            }
        }
    }
    cout << SZ(ans) << endl;
    for (int i=0;i<SZ(ans);++i) {
        cout << ans[i].X+1 << ' ' << ans[i].Y+1 << endl;
    }
}
