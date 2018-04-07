#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
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

vector<int> g[MaxN];
ll djs[MaxN];
ll deg[MaxN];
ll sz[MaxN];
ll cnt[MaxN];
ll visited[MaxN];
ll t;
bool cmp(ll a,ll b){return SZ(g[a])<SZ(g[b]);}

ll find(ll x){
	return x==djs[x] ?x:djs[x]=find(djs[x]);
}

int main(){
	IOS();
	ll n,m;
	cin>>n>>m;
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	REP(i,n){
		djs[i]=i;
		deg[i]=i;
	}
	RST(sz,1);
	sort(deg,deg+n,cmp);
	//pary(deg,deg+n);
	REP(i,n){
		t++;
		ll cur=deg[i];
		if(visited[cur]) continue;
		cnt[cur]=t;
		REP(j,SZ(g[cur])) cnt[g[cur][j]]=t;
		REP(j,n)if(cnt[j]!=t&&find(cur)!=find(j)){
			sz[find(cur)]+=sz[find(j)];
			djs[find(j)]=find(cur);
			if(i==0) visited[j]=1;
		}
	}
	t++;
	ll ans=0;
	pary(djs,djs+n);
	REP(i,n)if(cnt[find(i)]!=t){
		ans++;
		cnt[find(i)]=t;
	}
	cout<<ans<<endl;
}

