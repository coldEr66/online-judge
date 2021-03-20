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
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // cold66
//}

const ll MAXN=1<<17,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n;
vector<int> X;
int query(string req,int i,int j){
    cout << req << ' ' << i << ' ' << j << endl;
    int reply;
    cin >> reply;
    return reply;
}
vector<int> rep[MAXN];
int ans[MAXN];
int xr[MAXN];
void ANS(){
    cout << '!';
    for (int i=1;i<=n;++i) {
        cout << ' ' << ans[i];
    }
    cout << endl;
}
signed main(){
    IOS();
    cin >> n;
    for (int i=2;i<=n;++i) {
        int tmp = query("XOR",1,i);
        rep[tmp].eb(i);
        xr[i] = tmp;
    }
    for (int i=0;i<n;++i) {
        if (!i && SZ(rep[i]) >= 1) {
            ans[1] = query("AND",1,rep[i][0]);
            for (int j=2;j<=n;++j) {
                ans[j] = ans[1] ^ xr[j];
            }
            ANS();
            return 0;
        }
        if (SZ(rep[i]) >= 2) {
            ans[rep[i][0]] = query("AND",rep[i][0],rep[i][1]);
            ans[1] = i ^ ans[rep[i][0]];
            for (int j=2;j<=n;++j) {
                if (j == rep[i][0]) continue;
                ans[j] = ans[1] ^ xr[j];
            }
            ANS();
            return 0;
        }
    }
    int a = 1, b = rep[n-1][0], c = (rep[n-1][0] == 2 ?3:2);
    int aa = query("AND",a,c), bb = query("AND",b,c);
    int t1 = n-1;
    int t2 = xr[c] + 2 * aa;
    int ttg = (xr[c] ^ xr[b]) + 2 * bb;
    assert((t1 + t2 + ttg) % 2 == 0);
    int sum = (t1 + t2 + ttg) / 2;
    ans[1] = sum - ttg;
    for (int i=2;i<=n;++i) {
        ans[i] = ans[1] ^ xr[i];
    }
    ANS();
}
