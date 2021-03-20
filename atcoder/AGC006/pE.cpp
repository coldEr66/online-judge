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

int d[3][MAXn];
vector<ii> v;
int bit1[MAXn],bit2[MAXn];
int pos[MAXn];
int lowbit(int x){return x&(-x);}
void ins(int x,int *bit){
    for (x++;x;x-=lowbit(x)) bit[x]++;
}
int qr(int x,int *bit){
    int ret = 0;
    for (x++;x<MAXn;x+=lowbit(x)) ret += bit[x];
    return ret;
}
int main(){
    int n;
    cin >> n;
    for (int i=0;i<3;++i) {
        for (int j=0;j<n;++j) {
            cin >> d[i][j];
        }
    }
    
    for (int i=0;i<n;++i) {
        if ((d[1][i]-2) % 3 != 0) return cout << "No" << endl,0;
    }
    for (int i=0;i<n;++i) {
        vector<int> tmp;
        for (int j=0;j<3;++j) tmp.eb(d[j][i]);
        sort(ALL(tmp));
        debug(tmp);
        for (int j=0;j<3;++j) {
            if ((tmp[j]-1) % 3 != j) return cout << "No" << endl,0;
        }
        int cur = (tmp[0]-1) / 3;
        if (cur % 2 != i % 2) return cout << "No" << endl,0;
        int rev = 1;
        if (d[0][i] < d[2][i]) rev = 0;
        v.eb(cur,rev);
        pos[cur] = i;
    }

    int flip1 = 0, flip2 = 0, inv1 = 0, inv2 = 0;
    for (int i=0;i<n;++i) {
        ii tmp = v[pos[i]];
        if (i&1) {
            flip2 += tmp.Y;
            inv2 += qr(pos[tmp.X],bit2);
            ins(pos[tmp.X],bit2);
        }
        else {
            flip1 += tmp.Y;
            inv1 += qr(pos[tmp.X],bit1);
            ins(pos[tmp.X],bit1);
        }
        debug(pos[tmp.X],tmp.X);
    }
    debug(flip1,flip2,inv1,inv2);
    if (flip1 % 2 == inv2 % 2 && flip2 % 2 == inv1 % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
