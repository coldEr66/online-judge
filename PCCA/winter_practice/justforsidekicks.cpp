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

ll bit[6][MAXN];
ll v[6];
int d[MAXN];
int lowbit(int x){return x&(-x);}
void ins(int id,int pos,ll val){
    for (pos++;pos<MAXN;pos+=lowbit(pos)) {
        bit[id][pos] += val;
    }
}
ll qr(int id,int pos){
    ll ret = 0;
    for (pos++;pos;pos-=lowbit(pos)) {
        ret += bit[id][pos];
    }
    return ret;
}
ll qr(int id,int l,int r){
    return qr(id,r) - qr(id,l-1);
}
signed main(){
    IOS();
    int n,q;
    cin >> n >> q;
    for (int i=0;i<6;++i) cin >> v[i];
    string s;
    cin >> s;
    debug("alive");
    for (int i=0;i<n;++i) {
        d[i] = s[i] - '0' - 1;
        ins(d[i],i,1);
    }

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k,p;
            cin >> k >> p;
            k--, p--;
            ins(d[k],k,-1), ins(p,k,1);
            d[k] = p;
        }
        else if (cmd == 2) {
            ll p,V;
            cin >> p >> V;
            p--;
            v[p] = V;
        }
        else {
            int l,r;
            cin >> l >> r;
            l--, r--;
            ll ans = 0;
            for (int i=0;i<6;++i) {
                ans += qr(i,l,r) * v[i];
            }
            cout << ans << endl;
        }
    }
}
