#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define F first
#define S second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
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

map<pair<char,char>,char> color;
string clrs="RYBWOPGD",bs="RYB";
ll dis[3][MaxN][MaxN];
ii start[5];
bool visited[MaxN][MaxN];
ll dx[]={1,1,1,0,0,-1,-1,-1};
ll dy[]={1,0,-1,1,-1,1,0,-1};
ll cnt[1005];

int main(){
	IOS();
	color[{'W','Y'}]='Y';
	color[{'Y','W'}]='Y';
	color[{'W','R'}]='R';
	color[{'R','W'}]='R';
	color[{'W','B'}]='B';
	color[{'B','W'}]='B';
	color[{'R','Y'}]='O';
	color[{'Y','R'}]='O';
	color[{'R','B'}]='P';
	color[{'B','R'}]='P';
	color[{'B','Y'}]='G';
	color[{'Y','B'}]='G';
	color[{'O','B'}]='D';
	color[{'B','O'}]='D';
	color[{'P','Y'}]='D';
	color[{'Y','P'}]='D';
	color[{'R','G'}]='D';
	color[{'G','R'}]='D';
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		REP(i,3){
			char c;
			ll a,b;
			cin>>c;
			cin>>a>>b;
			if(c=='R') start[0]={a,b};
			else if(c=='Y') start[1]={a,b};
			else start[2]={a,b}; 
		}
		//REP(i,n) cout<<start[i].F<<' '<<start[i].S<<endl;
		queue<ii> q;
		REP(i,3){
			REP(k,n)REP(j,n) visited[k][j]=false;
			q.push(start[i]);
			dis[i][start[i].F][start[i].S]=0;
			visited[start[i].F][start[i].S]=true;
			while(SZ(q)){
				ii cur=q.front();
				q.pop();
				ll x=cur.F,y=cur.S;
				REP(j,8){
					ll xx=x+dx[j],yy=y+dy[j];
					if(xx>=0&&xx<n&&yy>=0&&yy<n&&visited[xx][yy]==false){
						//debug(dis[i][xx][yy]);
						dis[i][xx][yy]=dis[i][x][y]+1;
						//debug(dis[i][xx][yy]);
						visited[xx][yy]=true;
						q.push({xx,yy});
					}
				}
			}
		}
		debug(dis[0][4][1],dis[1][4][1],dis[2][3][2]);
		RST(cnt,0);
		char qs;
		cin>>qs;
		REP(i,n)REP(j,n){
			ll ta[]={0,1,2};
			sort(ta,ta+3,[&](int a,int b){return dis[a][i][j]<dis[b][i][j];});
			char now='W';
			REP(k,3){
				//cout<<now<<endl;
				if(now==qs) cnt[dis[ta[k]][i][j]]--;
				//cout<<bs[ta[k]]<<endl;
				now=color[{now,bs[ta[k]]}];
				//cout<<color[f]<<endl;
				if(now==qs) cnt[dis[ta[k]][i][j]]++;
			}
		}
		pary(cnt,cnt+n+1);
		ll mx=0,tmp=0;
		REP(i,n+1){
			tmp+=cnt[i];
			mx=max(tmp,mx);
		}
		cout<<mx<<endl;
	}
}
