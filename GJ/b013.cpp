#include <iostream>
#include <cstring>
using namespace std;

int main(){
  string a[3];
  for(int i=0;i<3;i++) getline(cin,a[i]);
  cout<<a[2]<<endl;
  cout<<a[0]<<endl;
  cout<<a[1]<<endl;
}
