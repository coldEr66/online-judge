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

const ll MAXn=1e7;
const ll MOD=1000000007;
const ll INF=(ll)1e18;

int team[MAXn],kase,f[MAXn],t[1000];

int main(){
	IOS();
	int n;
	while(cin>>n){
		kase++;
		int fr=-1,ba=-1;
		RST(team,0);
		cout<<"Line #"<<kase<<endl;
		REP1(i,n){
			int k;
			cin>>k;
			REP(j,k){
				int x;
				cin>>x;
				team[x]=i;
			}
		}
		RST(f,-1);
		RST(t,-1);
		string s;
		while(cin>>s){
			if(s[0]=='E'){
				int tmp;
				cin>>tmp;
				if(fr==-1){
					fr=ba=tmp;
					if(team[tmp]) t[team[tmp]]=tmp;
					f[tmp]=-1;
				}
				else if(t[team[tmp]]!=ba && t[team[tmp]]!=-1){
					f[tmp]=f[t[team[tmp]]];
					t[team[tmp]]=f[t[team[tmp]]]=tmp;
				}
				else{
					if(team[tmp]) t[team[tmp]]=tmp;
					ba=f[ba]=tmp;
					f[tmp]=-1;
				}
			}
			else if(s[0]=='D'){
				cout<<fr<<endl;
				if(fr==t[team[fr]]) t[team[fr]]=-1;
				fr=f[fr];
			}
			else break;
		}
	}
}

