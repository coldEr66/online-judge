#include<bits/stdc++.h>
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

char graph[105][105];
ll dis[105][105];
ll dx[]={1,0,0,-1};
ll dy[]={0,1,-1,0};

int main(){
	IOS();
	ll t;
	while(cin>>t&&t!=0){
		string s;
		ll a,b,l,r;
		REP(i,t){
			cin>>s;
			REP(j,SZ(s)){
				if(s[j]=='K'){
					a=i;
					b=j;
				}
				graph[i][j]=s[j];
			}
		}
		REP(i,t) pary(graph[i],graph[i]+SZ(s));
		REP(i,105) REP(j,105) dis[i][j]=INF;
		REP(i,t) pary(dis[i],dis[i]+SZ(s));
		queue<ii> q;
		q.push(make_pair(a,b));
		dis[a][b]=0;
		bool ok=false;
		while(!q.empty()){
			REP(i,4){
				ll x=q.front().F+dx[i];
				ll y=q.front().S+dy[i];
				if(graph[x][y]=='.'&&dis[x][y]>dis[q.front().F][q.front().S]+1){
					dis[x][y]=dis[q.front().F][q.front().S]+1;
					q.push(make_pair(a,b));
				}
				if(graph[x][y]=='@'){
					ok=true;
					l=x;
					r=y;
					dis[l][r]=dis[q.front().F][q.front().S]+1;
					break;
				}
			}
			if(ok) break;
			q.pop();
		}
		if(ok) cout<<dis[l][r]<<endl;
		else cout<<"= =\""<<endl;
	}
}
