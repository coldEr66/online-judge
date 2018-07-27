#include <bits/stdc++.h>
using namespace std;
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);

int d[100005];
map<int,int> mp;
int main(){
  IOS();
  int n;
  cin>>n;
  int ans = 0;
  for(int i=0;i<n;i++){
    cin>>d[i];
    if(d[i]==0) continue;
    if(!mp.count(d[i])){
      ans++;
      mp[d[i]]++;
    }
  }
  cout<<ans<<'\n';
}
