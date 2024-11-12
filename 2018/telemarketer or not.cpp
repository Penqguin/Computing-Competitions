#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    if ((a == 8 || a == 9) && (d == 8 || d == 9) && b == c){
        cout << "ignore";
    }
    else {
        cout << "answer";
    }

    return 0;
}