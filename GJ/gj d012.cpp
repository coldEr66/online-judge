#include<iostream>  
#include<iomanip>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<set>  
#include<map>  
#include<vector>  
#include<algorithm>  
#include<sstream>  
#include<cmath>  
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

map<char,pair<db,db> > pos;
vector<char> v;
ll ans[MaxN];
char cans[MaxN];

int main(){
	ll n;
	cin>>n;
	REP(i,n){
		db x,y;
		char c;
		cin>>c>>x>>y;
		pair<db,db> j=make_pair(x,y);
		pos[c]=j;
		v.pb(c);
		cans[i]=c;
	}
	REP(i,n){
		pair<db,db> cur=pos[v[i]];
		for(int j=0;j<n;j++){
			if(j==i) continue;
			pair<db,db> tmp=pos[v[j]];
			if(cur.F>tmp.F&&cur.S>tmp.S){
				ans[i]++;
			}
		}
	}
	REP(i,n){
		cout<<cans[i]<<' '<<ans[i]<<endl;
	}
}
