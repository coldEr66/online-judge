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

int d[MAXN];
vector<pair<int,pii>> v[MAXN];
int seg[MAXN<<2][102];
void pull(int id){
    for (int i=1;i<=100;++i) {
        seg[id][i] = seg[id*2+2][seg[id*2+1][i]];
    }
}
void build(int id,int l,int r){
    if (l == r-1) {
        for (int i=1;i<=100;++i) seg[id][i] = i;
        return;
    }
    int mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    pull(id);
}
void ins(int id,int l,int r,int pos,int x,int y){
    if (l == r-1) {
        for (int i=1;i<=100;++i) {
            if (i == x) seg[id][i] = y;
            else seg[id][i] = i;
        }
        return;
    }
    int mid = (l+r)>>1;
    if (pos < mid) ins(id*2+1,l,mid,pos,x,y);
    else ins(id*2+2,mid,r,pos,x,y);
    pull(id);
}
signed main(){
    IOS();
    int n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i];
    }
    int q;
    cin >> q;
    for (int i=0;i<q;++i) {
        int l,r,x,y;
        cin >> l >> r >> x >> y;
        v[l-1].eb(i,pii(x,y));
        v[r].eb(i,pii(x,x));
    }
    build(0,0,q);
    for (int i=0;i<n;++i) {
        for (auto it:v[i]) {
            ins(0,0,q,it.X,it.Y.X,it.Y.Y);
        }
        cout << seg[0][d[i]] << " \n"[i==n-1];
    }
}
