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

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int w[11];
int dis[11];
int main(){
    IOS();
    int n,m;
    cin >> n >> m;
    int mx = 0;
    for (int i=0;i<n;++i) {
        cin >> w[i];
        mx = max(mx,w[i]);
    }
    vector<pii> br;
    for (int i=0;i<m;++i) {
        int l,v;
        cin >> l >> v;
        br.eb(v,l);
        if (v < mx) return cout << -1 << endl,0;
    }
    sort(ALL(br),[&](pii a,pii b){
        if (a.X != b.X) return a.X < b.X;
        return a.Y > b.Y;
    });
    vector<pii> len;
    for (auto i:br) {
        if (SZ(len) && len.back().Y >= i.Y) continue;
        len.eb(i);
    }
    debug(len);
    sort(w,w+n); 
    int ans = INF;
    do {
        for (int i=0;i<n;++i) dis[i] = 0;
        for (int i=0;i<n;++i) {
            int tt = w[i];
            for (int j=i+1;j<n;++j) {
                tt += w[j];
                auto tmp = upper_bound(ALL(len),pii(tt,-1000));
                if (tmp != len.begin()) {
                    tmp = prev(tmp);
                    dis[j] = max(dis[j],dis[i] + (*tmp).Y);
                }
                else {
                    dis[j] = max(dis[j],dis[i]);
                }
            }
        }
        ans = min(ans,dis[n-1]);
    } while (next_permutation(w,w+n));
    cout << ans << endl;
}
