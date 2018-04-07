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

vector<ll> graph[MaxN],final[MaxN];
bool visited[MaxN];
ll d[MaxN];
ll dp[MaxN];
ll in[MaxN];

ll DFS(ll n){
	visited[n]=true;
	ll sum=1;
	REP(i,SZ(final[n]))if(visited[final[n][i]]!=true) sum+=DFS(final[n][i]);
	return sum;
}

int main(){
	IOS();
	ll n,m;
	cin>>n>>m;
	REP1(i,n) cin>>d[i];
	REP(i,m){
		ll a,b;
		cin>>a>>b;
		graph[a].pb(b);
		in[b]++;
	}
	REP1(i,n) dp[i]=d[i];
	dp[0]=0;
	queue<ll> q;
	REP1(i,n)if(in[i]==0) q.push(i);
	while(SZ(q)){
		ll cur=q.front();
		q.pop();
		if(!SZ(graph[cur])){
			if(dp[cur]>dp[0]){
				final[0].clear();
				final[0].pb(cur);
				dp[0]=dp[cur];
			}
			else if(dp[cur]==dp[0]){
				final[0].pb(cur);
			}
			continue;
		}
		REP(i,SZ(graph[cur])){
			if(dp[cur]+d[graph[cur][i]]>dp[graph[cur][i]]){
				dp[graph[cur][i]]=dp[cur]+d[graph[cur][i]];
				final[graph[cur][i]].clear();
				final[graph[cur][i]].pb(cur);
			}
			else if(dp[cur]+d[graph[cur][i]]==dp[graph[cur][i]]){
				final[graph[cur][i]].pb(cur);
			}
			in[graph[cur][i]]--;
			if(in[graph[cur][i]]==0) q.push(graph[cur][i]);
		}
	}
	cout<<DFS(0)-1<<endl;
}

