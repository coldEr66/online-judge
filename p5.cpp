//final_5.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Rectangular() {
    double l,w;
    cout << "Please enter the Length and Width respectively." << endl;
    cin >> l >> w;
    cout << "The perimeter of a rectangular with (Length,Width) = (" << l << ", " <<  w << ") is " << 2.0 * (l + w) << endl;
}

void Square(){
    double l;
    cout << "Please enter the Length." << endl;
    cin >> l;
    cout << "The perimeter of a square with (Length) = (" << l << ") is " << l * 4.0 << endl;
}

void Circle(){
    double r;
    double PI = acos(-1);
    cout << "Please enter the radius of the circle." << endl;
    cin >> r;
    cout << "The perimeter of a circle with (Radius) = (" << r << ") is " << 2.0 * PI * r << endl;
}

int main()
{
    int selection;
    cout << "====================\n"
        <<  "1.Rectangular 2.Square 3.Circle 4.Exit\n"
        << "Choose the type of perimeter you want to calculate:\n";
    cout << fixed << setprecision(3);
    while(cin >> selection){
        if(selection==1){
            //call function which caculate the perimeter of a rectangular
            Rectangular();
        }
        else if(selection==2){
            //call function which caculate the perimeter of a square
            Square();
        }
        else if(selection==3){
            //call function that caculate the perimeter of a circle
            Circle();
        }
        else if(selection==4){
            cout << "Good bye!\n";
            break;
        }
        else{
            cout << "Please follow the instruction carefully.\n";
        }
        cout << "====================\n"
            <<  "1.Rectangular 2.Square 3.Circle 4.Exit\n"
            << "Choose the type of perimeter you want to calculate:\n";
    }

    return 0;
}


