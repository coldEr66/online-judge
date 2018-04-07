#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
  string a;
  int ans1,ans2;
  stringstream ss;
  bool fg=false;
  for(int i=0;i<3;i++){
    int cnt=0;
    getline(cin,a);
    string tmp;
    ss.clear();
    ss.str(a);
    while(ss>>tmp){
      cnt++;
      if(tmp=="BILL"){
        fg=true;
        ans1=i+1;
        ans2=cnt;
      }
    }
  }
  if(fg) cout<<ans1<<' '<<ans2<<endl;
  else cout<<"NO"<<endl;
}
