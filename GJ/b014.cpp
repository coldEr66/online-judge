#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int d[3],ans[3]={0,1,2};
bool cmp(int a,int b){
  return d[a]>d[b];
}

int main(){
  string a;
  stringstream ss;
  for(int i=0;i<3;i++){
    d[i]=0;
    int tmp;
    getline(cin,a);
    ss.clear();
    ss.str(a);
    while(ss>>tmp) d[i]+=tmp;
  }
  sort(ans,ans+3,cmp);
  sort(d,d+3,greater<int>());
  cout<<ans[0]+1<<' '<<d[0]<<endl;
}
