#include <iostream>

using namespace std;

int main() {
    int l;
    cin >> l;
    for(int i = 0; i < l; i++) {
        int n;
        char x;
        cin >> n >> x;
        cout << string(n, x) << endl;
    }
    
    return 0;
}