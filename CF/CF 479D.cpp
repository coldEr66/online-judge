#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
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

const ll MaxN=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ll d[MaxN];
map<ll,bool> cnt;
bool xx,yy,z;

int main(){
	IOS();
	ll n;
	ll l,x,y;
	cin>>n;
	cin>>l>>x>>y;
	ll ans;
	REP(i,n){
		cin>>d[i];
		cnt[d[i]]=true;
		if(cnt[x]==true) xx=true;
		if(cnt[y]==true) yy=true;
		if(d[i]-x>=0&&cnt[d[i]-x]==true) xx=true;
		if(d[i]-y>=0&&cnt[d[i]-y]==true) yy=true;
		if(d[i]-x-y>=0&&cnt[d[i]-x-y]==true) z=true,ans=d[i]-x;
		if(d[i]+x<=l&&cnt[d[i]+x-y]==true) z=true,ans=d[i]+x;
		if(d[i]+x<=l&&cnt[d[i]+x+y]==true) z=true,ans=d[i]+x;
		if(d[i]-x>=0&&cnt[d[i]-x+y]==true) z=true,ans=d[i]-x;
		if(d[i]-y>=0&&cnt[d[i]-y+x]==true) z=true,ans=d[i]-y;
	}
	if(xx&&yy) cout<<0<<endl;
	else if(xx) cout<<1<<endl<<y<<endl;
	else if(yy) cout<<1<<endl<<x<<endl;
	else if(z) cout<<1<<endl<<ans<<endl;
	else cout<<2<<endl<<x<<' '<<y<<endl;
}

