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

const ll MaxN=105;
const ll MOD=1000000007;
const ll INF=ll(1e15);

ii d[MaxN];
ii x[1005];

int main(){
	IOS();
	ll n,k;
	cin>>n>>k;
	REP(i,n){
		cin>>d[i].F;
		d[i].S=i+1;
	}
	ll cnt=0;
	ll ans=-1;
	sort(d,d+n,greater<ii>());
	REP(i,k){
		ans=d[0].F-d[n-1].F;
		if(ans==0) break;
		d[0].F-=1;
		d[n-1].F+=1;
		x[i].F=d[0].S;
		x[i].S=d[n-1].S;
		sort(d,d+n,greater<ii>());
		ans=d[0].F-d[n-1].F;
		debug(ans);
		if(ans==0){
			cnt++;
			break;
		}
		cnt++;
	}
	cout<<ans<<' '<<cnt<<endl;
	REP(i,cnt){
		cout<<x[i].F<<' '<<x[i].S<<endl;
	}
}

