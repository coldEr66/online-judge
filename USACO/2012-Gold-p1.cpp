#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(a) (int)a.size()
#define X first
#define Y second
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"LINE: %d (%s) = ",__LINE__,#__VA_ARGS__);\
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

const ll MAXn=5e4+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const int INF=0x3f3f3f3f;

ll c[MAXn],p[MAXn];
priority_queue<ii,vector<ii>, greater<ii> > big,small;
priority_queue<ll,vector<ll>, greater<ll> > tmp;
bool vis[MAXn];
int main(){
    IOS();
    ll n,k,m;
    cin >> n >> k >> m;
    REP (i,n) {
        cin >> p[i] >> c[i];
        big.emplace(p[i],i);
        small.emplace(c[i],i);
    }

    REP (i,k) tmp.emplace(0LL);
    int cnt = 0;
    while (m > 0 && cnt < n) {
        debug(cnt,m);
        while (SZ(big) && vis[big.top().Y]) big.pop();
        while (SZ(small) && vis[small.top().Y]) small.pop();
        if (small.top().X + tmp.top() < big.top().X) {
            ll val = small.top().X, id = small.top().Y;
            if (m < val) break;
            m -= val;
            vis[id] = true;
            tmp.pop();
            tmp.emplace(p[id] - c[id]);
        }
        else {
            ll val = big.top().X, id = big.top().Y;
            if (m < val) break;
            m -= val;
            vis[id] = true;
        }
        cnt++;
    }
    cout << cnt << endl;
}
