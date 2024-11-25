#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>


using namespace std;

void swipe(vector<int> A, vector<int> B, int N);

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> B(N);
  
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  swipe(A,B,N);
  
  return 0;
}

void swipe(vector<int> A, vector<int> B, int N) {
  // Compress B to get B'
  vector<int> B_prime;
  for (int i = 0; i < N; i++) {
    if (i == 0 || B[i] != B[i - 1]) {
      B_prime.push_back(B[i]);
    }
  }

  // Check if B' is a subsequence of A
  int i = 0, j = 0;
  while (i < N && j < B_prime.size()) {
    if (A[i] == B_prime[j]) {
      j++;
    }
    i++;
  }

  if (j != B_prime.size()) {
    cout << "NO\n";
    return;
  }

  // Track swipes
  vector<tuple<char, int, int>> swipes;
  i = 0, j = 0;
  while (j < B_prime.size()) {
    int l = i;
    while (i < N && A[i] == B_prime[j]) {
      i++;
    }
    int r = i - 1;
    if (l < r) {
      swipes.push_back({'L', l, r});
    }
    j++;
  }

  // Perform right swipes
  for (int i = N - 1; i >= 0; i--) {
    if (i < N - 1 && A[i] == A[i + 1]) {
      swipes.push_back({'R', i, i + 1});
    }
  }

  // Print result
  cout << "YES\n";
  cout << swipes.size() << '\n';
  for (auto& op : swipes) {
    char type;
    int l, r;
    tie(type, l, r) = op;
    cout << type << ' ' << l << ' ' << r << '\n';
  }
}