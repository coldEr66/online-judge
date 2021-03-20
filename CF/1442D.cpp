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

const ll MAXN=3e3+5,MAXlg=__lg(MAXN)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

int n,k;
int t[MAXN];
vector<ll> d[MAXN];
ll w[MAXN];
ll ans;
ll sum[MAXN];
void gogo(int l,int r,vector<ll> bk){
    debug(l,r);
    if (l == r-1) {
        ll tmp = 0;
        debug(l,bk);
        for (int i=1;i<=k;++i) {
            bk[i] = max(bk[i],bk[i-1]);
        }
        for (int i=0;i<min(SZ(d[l]),k);++i) {
            tmp += d[l][i];
            ans = max(ans,bk[k-i-1] + tmp);
        }
        return;
    }
    int mid = (l+r)>>1;
    vector<ll> tpbk = bk;
    for (int i=l;i<mid;++i) {
        for (int j=k;j>=0;--j) {
            if (j - w[i] < 0) break;
            tpbk[j] = max(tpbk[j],tpbk[j-w[i]] + sum[i]);
        }
    }
    gogo(mid,r,tpbk);
    tpbk = bk;
    for (int i=mid;i<r;++i) {
        for (int j=k;j>=0;--j) {
            if (j - w[i] < 0) break;
            tpbk[j] = max(tpbk[j],tpbk[j-w[i]] + sum[i]);
        }
    }
    gogo(l,mid,tpbk);
}
signed main(){
    IOS();
    cin >> n >> k;
    for (int i=0;i<n;++i) {
        cin >> w[i];
        for (int j=0;j<w[i];++j) {
            ll x;
            cin >> x;
            d[i].eb(x);
            sum[i] += x;
        }
        debug(sum[i],d[i]);
    }
    vector<ll> v(k+1,0);
    gogo(0,n,v);
    cout << ans << endl;
}
