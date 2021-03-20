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

const ll MAXN=2e2+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

int dis[MAXN][MAXN];
int u[3000],v[3000];
signed main(){
    IOS();
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) {
        if (i != j) dis[i][j] = INF;
    }
    for (int i=0;i<m;++i) {
        int b;
        cin >> u[i] >> v[i] >> b;
        u[i]--, v[i]--;
        dis[u[i]][v[i]] = 1;
        dis[v[i]][u[i]] = (b ?-1:1);
    }
    for (int k=0;k<n;++k) {
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (dis[i][k] != INF && dis[k][j] != INF) {
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                    dis[i][j] = max(dis[i][j],-INF);
                }
            }
        }
    }
    pii bst = pii(-1,0);
    for (int i=0;i<n;++i) {
        if (dis[i][i] < 0) return cout << "NO" << endl,0;
        for (int j=0;j<n;++j) {
            bst = max(bst,pii(dis[i][j],i));
        }    
    }
    int cur = bst.Y;
    for (int i=0;i<m;++i) {
        if (dis[cur][u[i]] == dis[cur][v[i]]) {
            return cout << "NO" << endl,0;
        }
    }
    cout << "YES" << endl;
    cout << bst.X << endl;
    for (int i=0;i<n;++i) {
        cout << dis[cur][i] << " \n"[i==n-1];
    }
}
