#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 1000; // Maximum size of the 2D array
const int LOG = 10;    // log2(1000) ≈ 10

int st[MAXN][MAXN][LOG][LOG]; // Sparse Table

// Function to build the Sparse Table
void init(std::vector<std::vector<int>> arr); 

// Function to query the minimum in the submatrix from (a, b) to (c, d)
int query(int a, int b, int c, int d);

// Example usage
int main() {
  int N;
  cin >> N;
  vector<vector<int>> arr(N, vector<int>(N));

// Input the 2D array
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  // Initialize the Sparse Table
  init(arr);

  // Example query
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << query(a, b, c, d) << endl;

  return 0;
}

void init(std::vector<std::vector<int>> arr) {
  int N = arr.size();

  // Step 1: Initialize the Sparse Table for submatrices of size 1x1
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      st[i][j][0][0] = arr[i][j];
    }
  }

  // Step 2: Build the Sparse Table for larger submatrices
  for (int x = 0; (1 << x) <= N; ++x) {         // Row dimension
    for (int y = 0; (1 << y) <= N; ++y) {     // Column dimension
      if (x == 0 && y == 0) continue;       // Already initialized
        
      for (int i = 0; i + (1 << x) - 1 < N; i++) {
        for (int j = 0; j + (1 << y) - 1 < N; j++) {
          if (x == 0) {
            // Only expanding in the column direction
            st[i][j][x][y] = min(st[i][j][x][y-1], st[i][j + (1 << (y-1))][x][y-1]);
          } else if (y == 0) {
            // Only expanding in the row direction
            st[i][j][x][y] = min(st[i][j][x-1][y], st[i + (1 << (x-1))][j][x-1][y]);
          } else {
            // Expanding in both row and column directions
            st[i][j][x][y] = min({st[i][j][x-1][y-1], 
                                  st[i + (1 << (x-1))][j][x-1][y-1],
                                  st[i][j + (1 << (y-1))][x-1][y-1],
                                  st[i + (1 << (x-1))][j + (1 << (y-1))][x-1][y-1]});
          }
        }
      }
    }
  }
}

int query(int a, int b, int c, int d) {
  int kx = log2(c - a + 1);
  int ky = log2(d - b + 1);

  // Use precomputed values from the Sparse Table
  int min1 = st[a][b][kx][ky];
  int min2 = st[c - (1 << kx) + 1][b][kx][ky];
  int min3 = st[a][d - (1 << ky) + 1][kx][ky];
  int min4 = st[c - (1 << kx) + 1][d - (1 << ky) + 1][kx][ky];

  return min({min1, min2, min3, min4});
}