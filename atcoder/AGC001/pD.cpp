#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int d[MAXn];
vector<int> odd;
vector<int> a;
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    REP (i,m) {
        cin >> d[i];
        if (d[i]&1) odd.eb(i);
    }
    if (m == 1 && n > 1) {
        cout << n << endl;
        cout << 2 << endl;
        cout << 1 << ' ' << n-1 << endl;
        return 0;
    }
    else if (m == 1 && n == 1) {
        return cout << "1\n1\n1\n",0;
    }
    if (SZ(odd) > 2) return cout << "Impossible" << endl,0;

    if (SZ(odd) >= 1) a.eb(d[odd[0]]);
    REP (i,m) {
        if (d[i]&1) continue;
        a.eb(d[i]);
    }
    if (SZ(odd) == 2) a.eb(d[odd[1]]);

    vector<int> b;
    int cur = 0;
    REP (i,m) {
        if (cur == n) break;
        if (!i) {
            b.eb(a[i]+1);
            cur += (a[i]+1);
        }
        else if (i == m-1) b.eb(a[i]-1);
        else {
            b.eb(a[i]);
            cur += a[i];
        }
    }

    REP (i,m) cout << a[i] << " \n"[i==m-1];
    cout << SZ(b) << endl;
    REP (i,SZ(b)) cout << b[i] << " \n"[i==SZ(b)-1];
}
