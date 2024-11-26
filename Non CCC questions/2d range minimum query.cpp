#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int MAX_N = 1000;
const int LOG_MAX = 11;

int sparseTable[LOG_MAX][LOG_MAX][MAX_N][MAX_N];
int n;

// Preprocess the array into a 2D sparse table
void init(std::vector<std::vector<int>> arr) {
    n = arr.size();
    int logN = std::log2(n) + 1;

    // Base case: subgrids of size 1x1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sparseTable[0][0][i][j] = arr[i][j];
        }
    }

    // Fill sparse table for subgrids of size 1x(2^k)
    for (int k = 1; k < logN; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j + (1 << k) <= n; ++j) {
                sparseTable[0][k][i][j] = std::min(sparseTable[0][k - 1][i][j],
                                                   sparseTable[0][k - 1][i][j + (1 << (k - 1))]);
            }
        }
    }

    // Fill sparse table for subgrids of size (2^k)x(2^l)
    for (int k1 = 1; k1 < logN; ++k1) {
        for (int k2 = 0; k2 < logN; ++k2) {
            for (int i = 0; i + (1 << k1) <= n; ++i) {
                for (int j = 0; j + (1 << k2) <= n; ++j) {
                    sparseTable[k1][k2][i][j] = std::min(sparseTable[k1 - 1][k2][i][j],
                                                         sparseTable[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
                }
            }
        }
    }
}

// Query the sparse table for the minimum value in the subgrid
int query(int a, int b, int c, int d) {
    int k1 = std::log2(c - a + 1);
    int k2 = std::log2(d - b + 1);

    int min1 = sparseTable[k1][k2][a][b];
    int min2 = sparseTable[k1][k2][c - (1 << k1) + 1][b];
    int min3 = sparseTable[k1][k2][a][d - (1 << k2) + 1];
    int min4 = sparseTable[k1][k2][c - (1 << k1) + 1][d - (1 << k2) + 1];

    return std::min({min1, min2, min3, min4});
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> input(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> input[i][j];
        }
    }

    init(input);

    int xorResult = 0;
    for (int i = 0; i < Q; ++i) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        // Convert 1-based to 0-based indexing
        a--; b--; c--; d--;

        int result = query(a, b, c, d);
        xorResult ^= result;
    }

    std::cout << xorResult << std::endl;

    return 0;
}
