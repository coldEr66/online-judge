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

struct node{
	ll cont;
	node *L,*R,*P;
};
node *root;

void ins(ll n,node *k){
	if(k){
		if(n>k->cont){
			if(k->R) ins(n,k->R);
			else{
				node *tmp=new node;
				tmp->cont=n;
				tmp->L=NULL;
				tmp->R=NULL;
				tmp->P=k;
				k->R=tmp;
			}
		}
		else{
			if(k->L) ins(n,k->L);
			else{
				node *tmp=new node;
				tmp->cont=n;
				tmp->L=NULL;
				tmp->R=NULL;
				tmp->P=k;
				k->L=tmp;
			}
		}
	}
	else{
		root=new node;
		root->cont=n;
		root->L=NULL;
		root->R=NULL;
		root->P=NULL;
	}
}

void del(ll n){
	node *tmp=root;
	while(tmp!=NULL){
		if(n>tmp->cont) tmp=tmp->R;
		else if(n==tmp->cont) break;
		else tmp=tmp->L;
	}
	debug(tmp->cont);
	node *leaf;
	if(tmp->R){
		leaf=tmp->R;
		while(leaf->L) leaf=leaf->L;
		tmp->cont=leaf->cont;
		if(leaf->R){
			leaf->cont=leaf->R->cont;
			delete leaf->R;
			leaf->R=NULL;
		}
		else{
			if(leaf->P->L==leaf) leaf->P->L=NULL;
			else leaf->P->R=NULL;
		}
	}
	else{
		if(tmp->P){
			if(tmp->P->L==tmp){
				tmp->P->L=tmp->L;
				delete tmp;
				debug("FF");
			}
			else{
				tmp->P->R=tmp->L;
				delete tmp;
			}
			if(tmp->L){
				tmp->L->P=tmp->P;
				debug("LEFT");
			}
			if(tmp->R){
				tmp->R->P=tmp->P;
				debug("RIGHT");
			} 
		}
		else{
			root=root->R;
			if(root) root->P=NULL;
			debug("NO");
		}
	}
}

void q(ll n){
	node *tmp=root;
	ii ret;
	ret.F=ret.S=root->cont;
	while(tmp!=NULL){
		if(abs(n-tmp->cont)<abs(n-ret.F)) ret.F=ret.S=tmp->cont;
		else if(abs(n-tmp->cont)==abs(n-ret.F)) ret.S=tmp->cont;
		if(n>tmp->cont) tmp=tmp->R;
		else tmp=tmp->L;
	}
	if(ret.F==ret.S) cout<<ret.F<<endl;
	else cout<<min(ret.F,ret.S)<<' '<<max(ret.F,ret.S)<<endl;
}

int main(){
	IOS();
	ll n;
	cin>>n;
	while(n--){
		string s;
		ll x;
		cin>>s>>x;
		if(s[0]=='i') ins(x,root);
		else if(s[0]=='d') del(x);
		else q(x);
	}
}

