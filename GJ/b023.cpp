#include <iostream>
using namespace std;

void hanoi(int n,char a,char b,char c){
  if(n==1) cout<<"Ring "<<1<<" from "<<a<<" to "<<c<<endl;
  else{
    hanoi(n-1,a,c,b);
    cout<<"Ring "<<n<<" from "<<a<<" to "<<c<<endl;
    hanoi(n-1,b,a,c);
  }
}

int main(){
  int n;
  cin>>n;
  hanoi(n,'1','2','3');
}
