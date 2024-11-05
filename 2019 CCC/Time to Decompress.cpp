#include <iostream>

using namespace std;

int main() {
    int l;
    int n;
    char x;
    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> n >> x;
        cout << string(n, x) << endl;
    }

    return 0;
}