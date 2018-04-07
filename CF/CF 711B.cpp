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
#define MP make_pair
#define VI vector<int>
#ifdef cold66
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.F<<","<<_p.S<<")";}
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

const ll MAXn=505;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

ll n;
ll d[MAXn][MAXn];
ll x,y;
void init(){
	cin>>n;
	REP(i,n)REP(j,n){
		cin>>d[i][j];
		if(d[i][j]==0){
			x=i;
			y=j;
		}
	}
}

void build(){

}
ll sum,tmp,ans;
void sol(){
	if(n==1 && d[0][0]==0){
		cout<<1<<endl;
		return;
	}
	REP(i,n){
		if(i==x) continue;
		sum=0;
		REP(j,n) sum+=d[i][j];
		debug(sum);
		if(tmp==0) tmp=sum;
		if(sum!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	debug(tmp);
	REP(i,n){
		if(i==y) continue;
		sum=0;
		REP(j,n) sum+=d[j][i];
		if(sum!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	sum=0;
	if(x!=y){
		REP(i,n) sum+=d[i][i];
		if(sum!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	sum=0;
	if(n-x-1!=y){
		REP(i,n) sum+=d[n-i-1][i];
			if(sum!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	sum=0;
	REP(i,n) sum+=d[x][i];
	ans=tmp-sum;
	sum=0;
	REP(i,n) sum+=d[i][y];
	if(sum+ans!=tmp){
		cout<<-1<<endl;
		return;
	}
	debug(ans);
	sum=0;
	if(x==y){
		REP(i,n) sum+=d[i][i];
		if(sum+ans!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	debug(ans);
	sum=0;
	if(n-x-1==y){
		REP(i,n) sum+=d[n-i-1][i];
		if(sum+ans!=tmp){
			cout<<-1<<endl;
			return;
		}
	}
	debug(ans);
	if(ans<=0) cout<<-1<<endl;
	else cout<<ans<<endl;
}

int main(){
	IOS();
	init();
	build();
	sol();
	return 0;
}

