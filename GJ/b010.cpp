#include <iostream>
using namespace std;

int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A') s[i]='Y';
    else if(s[i]=='B') s[i]='Z';
    else s[i]-=2;
  }
  cout<<s<<endl;
}
