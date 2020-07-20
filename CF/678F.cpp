#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (ll)a.size()
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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

struct line{
    ll x,y;
    bool operator < (const line &a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};
ll gt(line a,line b){
    ll dx = (a.x - b.x), dy = (b.y - a.y);
    ll ret = dy / dx - (((dy ^ dx) < 0) && dy % dx);
    return ret;
}
vector<pair<line,ii> > dt;
vector<line> ins[MAXn*4];
vector<ii> q[MAXn*4];
ll ans[MAXn];
void addline(vector<line> &cur,line a){
    while (SZ(cur) >= 2) {
        if (cur.back().x == a.x) {
            cur.pop_back();
        }
        else {
            ll t1 = gt(cur[SZ(cur)-2],a), t2 = gt(cur.back(),a);
            if (t1 > t2) cur.pop_back();
            else break;
        }
    }
    if (SZ(cur) != 0) {
        if (cur.back().x == a.x) {
            cur.pop_back();
        }
    }
    cur.eb(a);
}
void insQ(ll id,ll L,ll R,ll pos,ll i){
    debug(id,L,R);
    q[id].eb(pos,i);
    if (L == R-1) return;
    ll mid = (L+R)>>1;
    if (i < mid) insQ(id*2+1,L,mid,pos,i);
    else insQ(id*2+2,mid,R,pos,i);
}
void insert_line(ll id,ll L,ll R,ll l,ll r,line Line){
    if (L >= l && R <= r) {
        addline(ins[id],Line);
        return;
    }
    if (r <= L || l >= R) return;
    if (L == R-1) return;
    ll mid = (L+R)>>1;
    insert_line(id*2+1,L,mid,l,r,Line);
    insert_line(id*2+2,mid,R,l,r,Line);
}
inline ll gtsum(ll x,line a){
    return a.x * x + a.y;
}
pair<line,ii> d[MAXn];
int main(){
    IOS();
    ll n;
    cin >> n;
    REP (i,n) ans[i] = -INF;
    REP (i,n) {
        int cmd;
        cin >> cmd;
        d[i] = pair<line,ii>((line){-INF,-INF},ii(-1,-1));
        if (cmd == 1) {
            ll x,y;
            cin >> x >> y;
            d[i] = pair<line,ii>((line){x,y},ii(i,n));
            ans[i] = -8e18;
        }
        else if (cmd == 2) {
            ll x;
            cin >> x;
            x--;
            d[x].Y.Y = i;
            ans[i] = -8e18;
        }
        else {
            ll x;
            cin >> x;
            insQ(0,0,n,x,i);
        }
    }
    REP (i,MAXn*4) {
        if (SZ(q[i])) sort(ALL(q[i]));
    }
    REP (i,n) {
        if (d[i].X.x == -INF) continue;
        dt.eb(d[i]);
    }
    sort(ALL(dt));
    // REP (i,SZ(dt)) debug(dt[i].Y,dt[i].X.x,dt[i].X.y);
    REP (i,SZ(dt)) {
        insert_line(0,0,n,dt[i].Y.X,dt[i].Y.Y,dt[i].X);
    }
    REP (id,4*MAXn) {
        if (SZ(ins[id]) != 0 && SZ(q[id]) != 0) {
            int idx = 0;
            REP (i,SZ(ins[id])) {
                ll cor = (i == SZ(ins[id])-1 ?(ll)INF:gt(ins[id][i],ins[id][i+1]));
                // debug(id,i,SZ(ins[id]),cor,gt(ins[id][i],ins[id][i+1]));
                while (idx < SZ(q[id]) && q[id][idx].X <= cor) {
                    // debug(id,idx,q[id][idx],gtsum(q[id][idx].X,ins[id][i]));
                    ans[q[id][idx].Y] = max(ans[q[id][idx].Y],gtsum(q[id][idx].X,ins[id][i]));
                    idx++;
                }
            }
        }
    }
    REP (i,n) {
        if (ans[i] == -8e18) continue;
        if (ans[i] == -INF) cout << "EMPTY SET" << endl;
        else cout << ans[i] << endl;
    }
}
