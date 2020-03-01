#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for (int i=n-1;i>=0;i--)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
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
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll MAXn=1e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f;

void setIO(string pname){
    IOS();
    freopen((pname+".in").c_str(),"r",stdin);
    freopen((pname+".out").c_str(),"w",stdout);
}
int n,q;
vector<int> e[MAXn];
int st[MAXn],ed[MAXn],t,sz[MAXn];
ll bit1[MAXn],bit2[MAXn];
map<int,int> mp[MAXn];
void dfs(ll x,ll p){
    st[x] = ++t;
    for (auto i:e[x]) {
        if (i == p) continue;
        dfs(i,x);
    }
    ed[x] = t;
    sz[x] = ed[x] - st[x] + 1;
}
int lowbit(int x){
    return x&(-x);
}
void ins(int x,ll v,ll *bit){
    for (;x<MAXn;x+=lowbit(x)) {
        bit[x] += v;
    }
}
void upd(int x,ll v){
    ins(st[x],v,bit1);
    ins(ed[x]+1,-v,bit1);
    ins(st[x],v * sz[x],bit2);
}
ll qr(int x,ll *bit){
    ll ret = 0;
    for (;x>0;x-=lowbit(x)) {
        ret += bit[x];
    }
    return ret;
}
ll sum(int l,int r,ll *bit){
    return qr(r,bit) - qr(l-1,bit);
}
int main(){
    setIO("snowcow");
    cin >> n >> q;
    REP (i,n-1) {
        ll u,v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(1,0);

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x,c;
            cin >> x >> c;
            auto it = mp[c].upper_bound(st[x]);
            if (it != begin(mp[c]) && ed[prev(it)->Y] >= ed[x]) continue;
            while (it != end(mp[c]) && ed[it->Y] <= ed[x]) {
                upd(it->Y,-1);
                mp[c].erase(it++);
            }
            mp[c][st[x]] = x;
            upd(x,1);
        }
        else {
            int x;
            cin >> x;
            cout << sz[x] * qr(st[x],bit1) + sum(st[x]+1,ed[x],bit2) << endl;
        }
    }
}
