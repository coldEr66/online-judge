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
#define SZ(a) (int)a.size()
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

const ll MAXn=2e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=0x3f3f3f3f3f3f3f3f;
const lf eps = 1e-8;

int n,k;
lf x[61],y[61],c[61],r[61];
lf sq(lf a){
    return a * a;
}
lf gtdis(pair<lf,lf> a,pair<lf,lf> b){
    return sqrt(sq(a.X-b.X) + sq(a.Y-b.Y));
}
vector<pair<lf,lf> > gt(lf ax,lf ay,lf ar,lf bx,lf by,lf br){
    ax -= bx, ay -= by;
    lf dis = sq(ax) + sq(ay);
    lf hor = (dis + sq(br) - sq(ar)) / 2;
    lf ver = dis * sq(br) - sq(hor);
    if (ver < 0) return {};
    ver = sqrt(ver);
    lf a1 = ax * hor, a2 = ay * ver;
    lf b1 = ay * hor, b2 = ax * ver;
    pair<lf,lf> reta = pair<lf,lf>(bx + (a1 + a2) / dis, by + (b1 - b2) / dis);
    pair<lf,lf> retb = pair<lf,lf>(bx + (a1 - a2) / dis, by + (b1 + b2) / dis);
    return {reta,retb};
}
bool chk(lf T){
    vector<pair<lf,lf> > dt;
    REP (i,n) r[i] = T/c[i];
    REP (i,n) {
        dt.eb(x[i],y[i]);
        for (int j=i+1;j<n;j++) {
            auto tmp = gt(x[i],y[i],r[i],x[j],y[j],r[j]);
            for (auto it:tmp) dt.eb(it);
        }
    }
    for (auto i:dt) {
        int cnt = 0;
        REP (j,n) {
            if (r[j]+eps >= gtdis(i,ii(x[j],y[j]))) cnt++;
        }
        if (cnt >= k) return true;
    }
    return false;
}
int main(){
    IOS();
    cin >> n >> k;
    REP (i,n) {
        cin >> x[i] >> y[i] >> c[i];
    }
    lf L = 0.0, R = 400000.0;
    REP (i,100) {
        lf mid = (L+R)/2;
        if (chk(mid)) R = mid;
        else L = mid;
    }
    cout << fixed << setprecision(10) << (L+R)/2 << endl;
}
