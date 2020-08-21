#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RST(i,n) memset(i,n,sizeof i)
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define X first
#define Y second
#define eb emplace_back

const int MAXn = 19;
double lfrandom(double rmin,double rmax) {
    double ret = (double)rand() / RAND_MAX;
    return rmin + ret * (rmax - rmin);
}
ii cmp[MAXn][MAXn];
/*
{cmp[a][b].X == true ?a > b:a < b, cmp[a][b].Y is the id of the command}
*/
int ansid[MAXn];
pair<double,int> data[MAXn],ans[MAXn];
map<double,bool> chk;
int cnt[MAXn];
int main(){
    srand(clock());
    cout << "input the number of player" << endl;
    int n;
    cin >> n;

    cout << fixed << setprecision(2) << endl;
    REP1 (i,n) {
        double l = rand()%30000, r = rand()%30000;
        if (l > r) swap(l,r);
        double cur = lfrandom(l,r);
        while (chk[cur]) cur = lfrandom(l,r);
        data[i] = {cur,i};
        ans[i] = {cur,i};
        chk[cur] = true;
        cout << i << " " << cur << endl;
    }
    sort(ans+1,ans+n+1);

    cout << "GAME START!" << endl;
    int score = 0;
    while (1) {
        cout << "input the id of the current player, input 0 to get ot the second stage" << endl;
        int id; // 1-indexed
        cin >> id;
        while (id > n) {
            cout << "the id is out of bound, please input again" << endl;
            cin >> id;
        }
        if (id == 0) break; // input 0 to get to second stage
        cout << "input the command id" << endl;
        int cmd;
        /*
        1 a: ask relation between id and a
        2 a: publish the relation between id and a
        3: publish the id_th player's number
        */
        cin >> cmd;
        if (cmd == 1) {
            int a;
            cin >> a;
            if (a == 100) continue;
            while (a <= 0 || a > n || cmp[id][a].Y != 0) {
                cout << "This command was already processed, please input again" << endl;
                cin >> a;
                if (a == 100) continue;
            }
            cnt[id]++;
            if (data[id] > data[a]) cmp[id][a] = {1,cnt[id]};
            else cmp[id][a] = {0,cnt[id]};
            score += cnt[id];
            cout << id << ' ' << (cmp[id][a].X ?'>':'<') << ' ' << a << endl;
        }
        else if (cmd == 2) {
            int a;
            cin >> a;
            if (a == 100) continue;
            while (a <= 0 || a > n || cmp[id][a].Y == 0) {
                cout << "This command not processed yet, please input again" << endl;
                cin >> a;
                if (a == 100) continue;
            }
            cout << id << ' ' << (cmp[id][a].X ?'>':'<') << ' ' << a << endl;
            score += cmp[id][a].Y;
        }
        else if (cmd == 3) {
            cout << data[id].X << endl;
            score += n * id;
        }
        else {
            continue;
        }
    }

    cout << "Start to sort the card!" << endl;
    REP1 (i,n) {
        cout << ans[i].Y << " \n"[i==n];
        ansid[ans[i].Y] = i;
    }
    int score1 = score;
    REP1 (i,n) {
        int x;
        cin >> x;
        score += (abs(i - ansid[x]) * abs(i - ansid[x]));
    }
    int score2 = score - score1;

    cout << "Congratulation!" << endl;
    cout << "The first stage's score is " << score1 << endl;
    cout << "The second stage's score is " << score2 << endl;
    cout << "Yout team's total score is " << score << endl;
}
