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

const ll MAXN=1e6+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

ll h[MAXN], ans;
ll a[MAXN], b[MAXN];
ll cal(int x,int y){
    return (h[a[x]] + h[b[y]]) * (b[y] - a[x]);
}
void gogo(int l1,int r1,int l2,int r2){
    if (l1 > r1) return;
    int mid = (l1 + r1) >> 1;
    int pos = l2;
    for (int i=l2+1;i<=r2;++i) {
        if (cal(mid, i) > cal(mid, pos)) pos = i;
    }
    ans = max(ans, cal(mid, pos));
    gogo(l1,mid-1,pos,r2), gogo(mid+1,r1,l2,pos);
}
signed main(){
    IOS();
    ll n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> h[i];
    }
    a[0] = 0, b[0] = n-1;
    int idxa = 0, idxb = 0;
    for (int i=1;i<n;++i) {
        if (h[i] > h[a[idxa]]) a[++idxa] = i;
    }
    for (int i=n-2;i>=0;--i) {
        if (h[i] > h[b[idxb]]) b[++idxb] = i;
    }
    gogo(0,idxa,0,idxb);
    cout << ans << endl;
}
