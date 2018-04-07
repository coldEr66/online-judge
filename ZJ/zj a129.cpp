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

const ll MaxN=1e6+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

struct Edge{
	int a,b,w;
} E[MaxN];
bool operator<(Edge x,Edge y){return x.w<y.w;}
ll g[MaxN];
ll sz[MaxN];
ll find(ll n){
	return n==g[n] ?n:g[n]=find(g[n]);
}
void mer(ll x,ll y){
	sz[find(y)]+=sz[find(x)];
	sz[find(x)]=0;
	debug(sz[find(x)],sz[find(y)]);
	g[find(x)]=find(y);
}

int main(){
	IOS();
	ll n,m;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		REP(i,m){
			cin>>E[i].a>>E[i].b>>E[i].w;
		}
		sort(E,E+m);
		//REP(i,m) cout<<E[i].w<<' ';
		debug("TEST");
		REP(i,n+1) g[i]=i,sz[i]=1;
		int i,j;
		ll ans=0;
		for(i=0,j=0;i<n&&j<m;j++){
			if(find(E[j].a)==find(E[j].b)) continue;
			mer(E[j].a,E[j].b);
			ans+=E[j].w;
			debug(ans);
			i++;
		}
		pary(sz,sz+n+1);
		if(sz[find(1)]!=n){
			cout<<-1<<endl;
		}
		else cout<<ans<<endl;
	}
}

