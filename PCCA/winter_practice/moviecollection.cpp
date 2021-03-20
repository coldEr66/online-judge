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

const ll MAXN=2e5+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,q;
int d[MAXN],lst[MAXN];
int bit[MAXN];
int lowbit(int x){
    return x & (-x);
}
void ins(int pos,int val){
    for (pos++;pos<MAXN;pos+=lowbit(pos)) {
        bit[pos] += val;
    }
}
int qr(int pos){
    int ret = 0;
    for (pos++;pos;pos-=lowbit(pos)) {
        ret += bit[pos];
    }
    return ret;
}
int qr(int l,int r){
    return qr(r) - qr(l-1);
}
signed main(){
    IOS();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i=1;i<=n;++i) {
            lst[n-i+1] = i;
            d[i] = n-i+1;
            ins(i, 1);
        }
        for (int i=n+1;i<=n+q;++i) {
            cin >> d[i];
            cout << qr(lst[d[i]] + 1, i) << endl;
            ins(lst[d[i]], -1);
            ins(i, 1);
            cout << " \n"[i==n+q];
            lst[d[i]] = i;
        }
        for (int i=1;i<=n;++i) {
            ins(lst[i], -1);
        }
    }
}
