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

const ll MaxN=1e2+5;
const ll MOD=1000000007;
const ll INF=ll(1e15);

string d[MaxN];
bool cmp[30][30];
bool ok[30];

ll ID(char alph){
	if(alph==' ') return 0;
	return alph-'a'+1;
}

int main(){
	IOS();
	ll n;
	cin>>n;
	REP(i,n){
		cin>>d[i];
		d[i]+=' ';
	}
	REP1(i,26) cmp[0][i]=true;
	REP(i,n-1){
		ll pos=0;
		while(d[i][pos]==d[i+1][pos]) pos++;
		cmp[ID(d[i][pos])][ID(d[i+1][pos])]=true;
		debug(ID(d[i][pos]),ID(d[i+1][pos]));
	}
	debug("OK");
	REP(i,27)REP(j,27)REP(k,27) cmp[i][j]|=cmp[i][k]&cmp[k][j];
	REP(i,27){
		if(cmp[i][i]){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	debug("TEST");
	REP(i,27){
		ll cur=0;
		REP(j,27){
			bool fg=(!ok[j]);
			REP(k,27)if(!ok[k]&&cmp[k][j]) fg=false;
			if(fg){
				cur=j;
				break;
			}			
		}
		if(i>0) cout<<char('a'+cur-1);
		ok[cur]=true; 
	}
}

