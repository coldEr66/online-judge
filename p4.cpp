#include <iostream>
using namespace std;

int decision_to_int(char c){ // 剪刀: 2, 石頭: 1, 布: 0, 如果數字加一除以三的餘數等於對方, 我方勝利
    // example: 布 vs 石頭 -> 0 vs 1 -> (0 + 1) % 3 = 1 -> 布贏
    if (c == 'p') return 0;
    if (c == 'r') return 1;
    return 2;
}

int main(){
    cout << "Enter s, r, p for player 1: ";
    char p1;
    cin >> p1;
    int p1_decision = decision_to_int(p1);

    cout << "Enter s, r, p for player 2: ";
    char p2;
    cin >> p2;
    int p2_decision = decision_to_int(p2);

    if (p1_decision == p2_decision) cout << "Two players tie!" << endl;
    else {
        if ((p1 + 1) % 3 == p2) cout << "Player 1 win!" << endl;
        else cout << "Player 2 win!" << endl;
    }
}
