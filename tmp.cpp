#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream file;
    string filename = "input.txt";
    file.open(filename, ios::in);
    if (!file) {
        cerr << "error!\n";
        system("pause");
        return 0;
    }

    int tmp;
    file >> tmp;
    cout << tmp << endl;
}
