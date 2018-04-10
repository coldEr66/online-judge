#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  ll ans=-1,tmp=0;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    tmp+=x;
    if(tmp<0) tmp=0;
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
}
