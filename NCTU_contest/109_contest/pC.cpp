#include <bits/stdc++.h>
using namespace std;


const ll MAXn=1e5+5;
const ll MOD = 998244353;
ll d[MAXn];
vector<pair<ll,ll> > qr[MAXn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    for (int i=0;i<n;++i) {
        cin >> d[i];
    }
    ll q;
    cin >> q;
    for (int i=0;i<q;++i) {
        int id,w;
        cin >> id >> w;
        qr[d[id]].emplace_back(w,i);
    }
    
}
