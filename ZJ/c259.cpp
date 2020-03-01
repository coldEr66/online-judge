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

const ll MAXn=3e5+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll mn[MAXn*4],scmn[MAXn*4],tg[MAXn*4],mnc[MAXn*4],sum[MAXn*4];
bool leaf[MAXn*4];
ll d[MAXn];
void pull(ll id){
    if (leaf[id]) return;
    sum[id] = sum[id*2+1] + sum[id*2+2];
    if (mn[id*2+1] < mn[id*2+2]) {
        mn[id] = mn[id*2+1];
        mnc[id] = mnc[id*2+1];
        scmn[id] = min(scmn[id*2+1],mn[id*2+2]);
    }
    else if (mn[id*2+1] > mn[id*2+2]) {
        mn[id] = mn[id*2+2];
        mnc[id] = mnc[id*2+2];
        scmn[id] = min(mn[id*2+1],scmn[id*2+2]);
    }
    else {
        mn[id] = mn[id*2+1];
        mnc[id] = mnc[id*2+1] + mnc[id*2+2];
        scmn[id] = min(scmn[id*2+1],scmn[id*2+2]);
    }
}
void push(ll id){
    if (leaf[id]) return;
    if (tg[id] == 0) return;
    debug(id);
    if (mn[id*2+1] >= tg[id]);
    else if (scmn[id*2+1] > tg[id]) {
        sum[id*2+1] += (tg[id] - mn[id*2+1]) * mnc[id*2+1];
        mn[id*2+1] = tg[id*2+1] = tg[id];
    }
    else {
        tg[id*2+1] = tg[id];
        push(id*2+1);
        pull(id*2+1);
    }

    if (mn[id*2+2] >= tg[id]);
    else if (scmn[id*2+2] > tg[id]) {
        sum[id*2+2] += (tg[id] - mn[id*2+2]) * mnc[id*2+2];
        mn[id*2+2] = tg[id*2+2] = tg[id];
    }
    else {
        tg[id*2+2] = tg[id];
        push(id*2+2);
        pull(id*2+2);
    }
    tg[id] = 0;
}
void build(ll id,ll l,ll r){
    if (l == r-1) {
        cin >> mn[id];
        scmn[id] = INF;
        mnc[id] = 1;
        sum[id] = mn[id];
        leaf[id] = true;
        return;
    }
    ll mid = (l+r)>>1;
    build(id*2+1,l,mid);
    build(id*2+2,mid,r);
    pull(id);
}
void ins(ll id,ll L,ll R,ll l,ll r,ll val){
    debug(L,R,l,r);
    if (L >= R) return;
    push(id);
    if (L >= l && R <= r) {
        if (val <= mn[id]) return;
        if (val < scmn[id]) {
            sum[id] += (val - mn[id]) * mnc[id];
            mn[id] = tg[id] = val;
        }
        else {
            tg[id] = val;
            push(id);
            pull(id);
        }
        return;
    }
    ll mid = (L+R)>>1;
    if (l >= mid) ins(id*2+2,mid,R,l,r,val);
    else if (r <= mid) ins(id*2+1,L,mid,l,r,val);
    else {
        ins(id*2+1,L,mid,l,r,val);
        ins(id*2+2,mid,R,l,r,val);
    }
    pull(id);
}
ll qr(ll id,ll L,ll R,ll l,ll r){
    if (L >= R) return 0;
    debug(L,R,l,r);
    push(id);
    if (L >= l && R <= r) return sum[id];
    ll mid = (L+R)>>1;
    if (l >= mid) return qr(id*2+2,mid,R,l,r);
    else if (r <= mid) return qr(id*2+1,L,mid,l,r);
    else {
        return qr(id*2+1,L,mid,l,r) + qr(id*2+2,mid,R,l,r);
    }
    return 0;
}
int main(){
    IOS();
    ll n,m;
    cin >> n >> m;
    build(0,0,n);

    while (m--) {
        ll cmd;
        cin >> cmd;
        if (cmd == 1) {
            ll l,r,v;
            cin >> l >> r >> v;
            l--;
            ins(0,0,n,l,r,v);
        }
        else {
            ll l,r;
            cin >> l >> r;
            l--;
            cout << qr(0,0,n,l,r) << endl;
        }
    }
}
