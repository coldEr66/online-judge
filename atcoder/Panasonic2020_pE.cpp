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
const ll M=2000;

bool ab[MAXn],bc[MAXn],ac[MAXn];
bool chk(char a,char b){
    return a == '?' || b == '?' || a == b;
}
int main(){
    IOS();
    string a,b,c;
    cin >> a >> b >> c;
    int A = SZ(a), B = SZ(b), C = SZ(c);
    REP (i,A) REP (j,B) if (!chk(a[i],b[j])) ab[i-j+50000] = true;
    REP (i,B) REP (j,C) if (!chk(b[i],c[j])) bc[i-j+50000] = true;
    REP (i,A) REP (j,C) if (!chk(a[i],c[j])) ac[i-j+50000] = true;

    int ans = INF;
    for (int i=-2*M;i<=2*M;i++) {
        for (int j=-2*M;j<=2*M;j++) {
            if ((!ab[i+50000]) && (!ac[j+50000]) && (!bc[j-i+50000])) {
                int L = min({0,i,j});
                int R = max({A,i+B,j+C});
                ans = min(ans,R-L);
            }
        }
    }
    cout << ans << endl;
}
