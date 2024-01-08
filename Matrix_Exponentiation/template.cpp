#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
  int r, c;
  vector<vector<int>> a;

  Matrix(int r, int c) : r(r), c(c) {
    a.assign(r, vector<int>(c, 0));
  }

  // Multiply two matrices
  Matrix operator*(const Matrix& other) const {
    Matrix res(r, other.c);
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < other.c; ++j)
        for (int k = 0; k < c; ++k)
          res.a[i][j] = (res.a[i][j] + a[i][k] * 1LL * other.a[k][j]) % MOD;
    return res;
  }
  
  // Calculate matrix power
  Matrix operator^(long long k) const {
    Matrix res(r, c), base = *this;
    for (int i = 0; i < r; ++i) res.a[i][i] = 1;
    while (k) {
      if (k & 1) res = res * base;
      base = base * base;
      k >>= 1;
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  return 0;
}