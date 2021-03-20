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

ll id[MAXN], dsu[MAXN], sz[MAXN], sum[MAXN], cnt;
int fnd(int x){
    if (dsu[x] == x) return x;
    return dsu[x] = fnd(dsu[x]);
}
void mrg(int x,int y){
    x = fnd(x), y = fnd(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x,y);
    dsu[y] = x;
    sz[x] += sz[y], sum[x] += sum[y];
}
signed main(){
    IOS();
    int n,m;
    while (cin >> n >> m) {
        cnt = 0;
        for (int i=0;i<n;++i) {
            id[i] = cnt++;
            dsu[i] = i, sz[i] = 1, sum[i] = i+1;
        }

        while (m--) {
            int cmd;
            cin >> cmd;
            if (cmd == 1) {
                ll p,q;
                cin >> p >> q;
                p--, q--;
                mrg(id[p], id[q]);
            }
            else if (cmd == 2) {
                ll p,q;
                cin >> p >> q;
                p--, q--;
                int fap = fnd(id[p]), faq = fnd(id[q]);
                if (fap == faq) continue;
                sz[fap]--, sum[fap] -= (p+1);

                id[p] = cnt++;
                dsu[id[p]] = id[p], sz[id[p]] = 1, sum[id[p]] = p+1;
                mrg(id[p], id[q]);
            }
            else {
                ll p;
                cin >> p;
                p--;
                cout << sz[fnd(id[p])] << ' ' << sum[fnd(id[p])] << endl;
            }
        }
    }
}
