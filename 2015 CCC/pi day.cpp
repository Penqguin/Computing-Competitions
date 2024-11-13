#include <iostream>
#include <vector>

using namespace std;

int countWays(int n, int k);

int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);

  int result = countWays(n, k);
  printf("%d\n", result);
  return 0;
}

int countWays(int n, int k) {
  vector<vector<int>> slices(n + 1, vector<int>(k + 1, 0));

  // Base cases:
  for (int i = 1; i <= n; i++) {
    slices[i][1] = 1; // Only one way to give i pieces to 1 person
  }
  for (int i = 1; i <= k; i++) {
    slices[i][i] = 1; // Only one way to distribute i pieces to i people (each gets one piece)
  }
  for (int j = 2; j <= k; j++) { // Number of people
    for (int i = j; i <= n; i++) { // Number of pieces
      slices[i][j] = slices[i - 1][j - 1] + slices[i - j][j];
    }
  }

  return slices[n][k];
}
