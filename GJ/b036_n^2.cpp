#include <iostream>
using namespace std;

int d[1005];
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,ans=0;
  cin>>n;
  for(int i=0;i<n;i++) cin>>d[i];
  for(int i=0;i<n-1;i++){
    pair<int,int> tp,idx;
    idx = make_pair(-1,-1);
    tp=make_pair(100000000,100000000);
    for(int j=0;j<n+i;j++){
      if(d[j]<0) continue;
      if(d[j]<tp.first){
        tp.second = tp.first;
        tp.first = d[j];
        idx = make_pair(j,idx.first);
      }
      else if(d[j]<tp.second){
        tp.second = d[j];
        idx = make_pair(idx.first,j);
      }
    }
    ans+=(tp.first + tp.second);
    d[n + i] = tp.first + tp.second;
    d[idx.first] = -d[idx.first];
    d[idx.second] = -d[idx.second];
  }
  cout<<ans<<endl;
}
