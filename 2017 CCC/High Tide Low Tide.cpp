#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a;
    cin >> a;

    int n = a / 2 + (a % 2 > 0);
    int d = 0;
    int c = -1;
    vector<int> arr;
    vector<int> tides(a);

    // Reading tides input
    for (int i = 0; i < a; i++) {
        cin >> tides[i];
    }

    // Sorting the tides
    sort(tides.begin(), tides.end());

    // Split into low and high tides
    vector<int> low(tides.begin(), tides.begin() + n);
    vector<int> high(tides.begin() + n, tides.end());

    // Alternating appending of low and high tides
    for (int i = 0; i < n; i++) {
        arr.push_back(low[c + low.size()]);
        c -= 1;
        if (d < high.size()) {
            arr.push_back(high[d]);
            d++;
        }
    }

    // Print the result
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}