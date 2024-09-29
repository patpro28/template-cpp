#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
  vector<vector<int>> st;
  vector<int> log2;
  int n;

  SparseTable(const vector<int>& a) {
    n = a.size();
    log2.resize(n + 1);
    log2[1] = 0;
    for (int i = 2; i <= n; i++) {
      log2[i] = log2[i / 2] + 1;
    }
    st.assign(log2[n] + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
      st[0][i] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  int query(int l, int r) {
    int j = log2[r - l + 1];
    return min(st[j][l], st[j][r - (1 << j) + 1]);
  }
};

int main() {
  vector<int> a = {1, 3, 2, 4, 5, 3, 1, 2, 4, 5};
  SparseTable st(a);
  cout << st.query(0, 9) << '\n'; // 1
  cout << st.query(2, 5) << '\n'; // 2
  cout << st.query(3, 7) << '\n'; // 1
  cout << st.query(8, 9) << '\n'; // 4

  return 0;
}