#include <bits/stdc++.h>
using namespace std;

int main(){
  srand(time(NULL));
  int n = rand()%2000;
  int m = rand()%1000;
  cout<<n<<" "<<m*(rand()%100)+rand()%m<<endl;
  for(int i=0;i<m;i++){
    int a = rand()%n,b=rand()%n;
    while(a==b) b = rand()%n;
    cout<<a<<" "<<b<<endl;
  }
}
