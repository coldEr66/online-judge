#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define REP(i,n) for(int i=0;i<(n);i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)

const int maxn=205;
const ll INF=1e17;

int n;
string s,t;
string l[maxn];
string r[maxn];
unordered_map<string,int> mp;

vector<string> pro;
int pt[25];
ll dp[25][205][205];
string v[25][205];
void solve(int kase){
    mp.clear();
    pro.pb(s);
    pro.pb(t);
    REP(i,n) pro.pb(l[i]),pro.pb(r[i]);
    {
        memset(pt,0,sizeof pt);
        for(string cur:pro){
            REP(i,SZ(cur)){
                string tmp=string(cur,i,SZ(cur)-i);
                if(!mp.count(tmp)){
                    mp[tmp]=pt[SZ(tmp)];
                    v[SZ(tmp)][pt[SZ(tmp)]]=tmp;
                    pt[SZ(tmp)]++;
                }
            }
        }
    }
    for(int len=1;len<=SZ(s);len++){
        REP(i,pt[len]) REP(j,pt[len]){
            if(i==j) dp[len][i][j]=0;
            else dp[len][i][j]=INF;
        }
    }
    REP(i,n){
        if(SZ(l[i])>SZ(s)) continue;
        dp[SZ(l[i])][mp[l[i]]][mp[r[i]]]=1;
        cout<<l[i]<<mp[l[i]]<<' '<<mp[r[i]]<<'\n';
    }
    // for(int len=1;len<=SZ(s);len++){
    //     REP(i,pt[len]) cout<<v[len][i]<<' ';
    //     cout<<'\n';
    // }
    for(int len=1;len<=SZ(s);len++){
        if(len!=1){
            for(int i=0;i<pt[len];i++) for(int j=0;j<pt[len];j++)if(i!=j){
                if(v[len][i][0]!=v[len][j][0]) continue;
                string A=string(v[len][i],1,len-1);
                string B=string(v[len][j],1,len-1);
                if(mp.count(A)&&mp.count(B)){
                    dp[len][i][j]=min(dp[len][i][j],dp[len-1][mp[A]][mp[B]]);
                }
            }
        }
        // REP(i,pt[len]) REP(j,pt[len]){
            // cout<<((dp[len][i][j]>=INF)?123:dp[len][i][j])<<" \n"[j==pt[len]-1];
        // }
        REP(j,pt[len]) REP(i,pt[len]) REP(k,pt[len]){
            dp[len][i][k]=min(dp[len][i][k],dp[len][i][j]+dp[len][j][k]);
        }
        // REP(i,pt[len]) REP(j,pt[len]){
        //     cout<<((dp[len][i][j]>=INF)?123:dp[len][i][j])<<" \n"[j==pt[len]-1];
        // }
    }
    cout<<"Case "<<kase<<": ";
    if(dp[SZ(s)][mp[s]][mp[t]]>=INF) cout<<"No solution\n";
    else cout<<dp[SZ(s)][mp[s]][mp[t]]<<'\n';
}

int main(){
    IOS;
    int kase=0;
    while(cin>>s&&s[0]!='.'){
        cin>>t;
        cin>>n;
        REP(i,n) cin>>l[i]>>r[i];
        solve(++kase);
    }
}
