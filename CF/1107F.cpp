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

const ll MAXn=5e2+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;


struct KM{ // 0-base
    ll w[MAXn][MAXn],hl[MAXn],hr[MAXn],slk[MAXn]; // ll
    int fl[MAXn],fr[MAXn],pre[MAXn],q[MAXn],ql,qr,n;
    bool vl[MAXn],vr[MAXn];
    void init(int _n){
        n = _n;
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) w[i][j] = -INF;
    }
    void add_edge(int a,int b,ll wei) { // ll
        w[a][b] = wei;
    }
    bool chk(int x){
        if (vl[x] = 1, ~fl[x]) return vr[q[qr++] = fl[x]] = 1;
        while (~x) swap(x, fr[fl[x] = pre[x]]);
        return 0;
    }
    void bfs(int s){
        fill(slk,slk+n,INF);
        fill(vl,vl+n,0), fill(vr,vr+n,0);
        ql=qr=0, q[qr++] = s, vr[s] = 1;
        while (true) {
            ll d; // ll
            while (ql < qr) {
                for (int x=0,y=q[ql++];x<n;++x) {
                    if (!vl[x] && slk[x] >= (d = hl[x] + hr[y] - w[x][y])) {
                        if (pre[x] = y, d) slk[x] = d;
                        else if (!chk(x)) return;
                    }
                }
            }
            d = INF;
            for (int x=0;x<n;++x) {
                if (!vl[x] && d > slk[x]) d = slk[x];
            }
            for (int x=0;x<n;++x) {
                if (vl[x]) hl[x] += d;
                else slk[x] -= d;
                if (vr[x]) hr[x] -= d;
            }
            for (int x=0;x<n;++x) {
                if (!vl[x] && !slk[x] && !chk(x)) return;
            }
        }
    }
    ll solve(){ // ll
        fill(fl,fl+n,-1), fill(fr,fr+n,-1), fill(hr,hr+n,0);
        for (int x=0;x<n;++x) hl[x] = *max_element(w[x],w[x] + n);
        for (int x=0;x<n;++x) bfs(x);
        ll ret = 0; // ll
        for (int x=0;x<n;++x) ret += w[x][fl[x]];
        return ret;
    }
} km; 

signed main(){
    IOS();
    int n;
    cin >> n;
    km.init(n);
    for (int i=0;i<n;++i) {
        ll a,b,k;
        cin >> a >> b >> k;
        for (ll j=0;j<n;++j) {
            ll w = a - min(j,k) * b;
            km.add_edge(j,i,max(0LL,w));
            debug(i,j,w);
        }
    }
    cout << km.solve() << endl;
}
