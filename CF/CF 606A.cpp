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

const ll MaxN=1e5+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int main(){
	IOS();
	ll a,b,c;
	cin>>a>>b>>c;
	ll x,y,z;
	cin>>x>>y>>z;
	ll has=0;
	bool na=false,nb=false,nc=false;
	if(a-x>=0) has+=(a-x)/2;
	else na=true;
	if(b-y>=0) has+=(b-y)/2;
	else nb=true;
	if(c-z>=0) has+=(c-z)/2;
	else nc=true;
	if(na){
		has-=(x-a);
		if(has<0){
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(nb){
		has-=(y-b);
		if(has<0){
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(nc){
		has-=(z-c);
		if(has<0){
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(has<0){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}

