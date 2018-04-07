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

const ll MaxN=3005;
const ll MOD=1000000007;
const ll INF=ll(1e15);

vector<ll> g[MaxN];
ll s1,t1,l1;
ll s2,t2,l2;
ll dis[MaxN][MaxN];

int main(){
	IOS();
	ll n,m;
	cin>>n>>m;
	REP(i,MaxN)REP(j,MaxN) dis[i][j]=INF;
	REP(i,MaxN) dis[i][i]=0;
	//pary(dis[0],dis[0]+5);
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	cin>>s1>>t1>>l1;
	cin>>s2>>t2>>l2;
	s1--,t1--;
	s2--,t2--;
	REP(i,n){
		queue<ll> q;
		q.push(i);
		while(SZ(q)){
			ll cur=q.front();
			q.pop();
			REP(j,SZ(g[cur])){
				ll x=g[cur][j];
				//debug(i,x,dis[i][x],dis[i][cur]);
				if(dis[i][x]>=INF){
					dis[i][x]=dis[i][cur]+1;
					q.push(x);
				}
			}
		}
	}
	REP(i,n) pary(dis[i],dis[i]+n);
	ll ans=-INF;
	REP(k,2){
		swap(s1,t1);
		REP(i,n)REP(j,n){
			ll d1=dis[s1][i]+dis[i][j]+dis[j][t1];
			ll d2=dis[s2][i]+dis[i][j]+dis[j][t2];
			debug(d1,d2,dis[i][j],i,j);
			if(d1<=l1&&d2<=l2) ans=max(ans,m-(d1+d2)+dis[i][j]);
			debug(ans);
		}
	}
	debug(dis[s1][t1],dis[s2][t2]);
	if(dis[s1][t1]<=l1&&dis[s2][t2]<=l2){
		debug(ans);
		ll tmp=m-dis[s1][t1]-dis[s2][t2];
		debug(tmp,dis[s1][t1],dis[s2][t2],m);
		ans=max(ans,tmp);
		debug("TEST");
	}
	debug(ans);
	if(ans<0) cout<<-1<<endl;
	else cout<<ans<<endl;
}

