#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RI(X) cin>>X
#define RII(X,Y) cin>>X>>Y
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define MP make_pair
#define VI vector<int>
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

const ll MaxN=1e3+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);
const ll dx[]={-1,0,1,0};
const ll dy[]={0,1,0,-1};

struct room{
	ll x,y,w;
};
ll g[MaxN][MaxN][4];
ll dis[MaxN][MaxN][4];
ll n,m;

bool out(ll x,ll y){
	if(x<0||x>=n||y<0||y>=m) return false;
	return true;
}

ll turn(ll x){
	return x%4<0 ?x%4+4:x%4;
}

int main(){
	IOS();
	RII(n,m);
	RST(dis,-1);
	REP(i,n)REP(j,m){
		char c;
		cin>>c;
		if(c=='+'||c=='^'||c=='|'||c=='R'||c=='L'||c=='D') g[i][j][0]=1;
		if(c=='+'||c=='>'||c=='-'||c=='U'||c=='L'||c=='D') g[i][j][1]=1;
		if(c=='+'||c=='v'||c=='|'||c=='R'||c=='U'||c=='L') g[i][j][2]=1;
		if(c=='+'||c=='<'||c=='-'||c=='R'||c=='D'||c=='U') g[i][j][3]=1;
	}
	debug("hi");
	ll x1,y1,x2,y2;
	RII(x1,y1);
	RII(x2,y2);
	x1--,y1--;
	x2--,y2--;
	queue<room> q;
	q.push({x1,y1,0});
	debug("T",x1,y1);
	dis[x1][y1][0]=0;
	debug("TEST");
	while(SZ(q)){
		room cur=q.front();
		q.pop();
		ll x=cur.x;
		ll y=cur.y;
		ll w=cur.w;
		if(dis[x][y][(w+1)%4]==-1){
			dis[x][y][(w+1)%4]=dis[x][y][w]+1;
			q.push({x,y,(w+1)%4});
			debug(dis[x][y][(w+1)%4],x,y,(w+1)%4);
		}
		REP(i,4){
			ll xx=x+dx[i],yy=y+dy[i];
			if(out(xx,yy)){
				if(g[x][y][turn(i-w)]==1&&g[xx][yy][turn(i-w+2)]==1){
					if(dis[xx][yy][w]==-1){
						dis[xx][yy][w]=dis[x][y][w]+1;
						q.push({xx,yy,w});
						debug(dis[xx][yy][w],xx,yy,w,dis[x][y][w],x,y);
					}
				}
			}
		}
	}
	ll mn=INF;
	REP(i,4)if(dis[x2][y2][i]!=-1){
		mn=min(mn,dis[x2][y2][i]);
		debug(mn);
	}
	if(mn==INF) cout<<"-1"<<endl;
	else cout<<mn<<endl;
}

