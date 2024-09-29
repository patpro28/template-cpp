#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// Check if X is in the increasing array a
bool binary_search(int a[], int dau, int cuoi, int x)
{
  while (dau <= cuoi)
  {
    int giua = (dau + cuoi) / 2;
    if (x == a[giua])
      return true;
    if (x > a[giua])
      dau = giua + 1;
    else
      cuoi = giua - 1;
  }
  return false;
}

// Find the first element that is greater than or equal to X in the increasing array a
int binary_search2(int a[], int dau, int cuoi, int x)
{
  int res = cuoi + 1;
  while (dau <= cuoi)
  {
    int giua = (dau + cuoi) / 2;
    if (a[giua] >= x)
    {
      res = giua;
      cuoi = giua - 1;
    }
    else
      dau = giua + 1;
  }
  return res;
}

// Find the last element that is less than or equal to X in the increasing array a
int binary_search3(int a[], int dau, int cuoi, int x)
{
  int res = dau - 1;
  while (dau <= cuoi)
  {
    int giua = (dau + cuoi) / 2;
    if (a[giua] <= x)
    {
      res = giua;
      dau = giua + 1;
    }
    else
      cuoi = giua - 1;
  }
  return res;
}

int main() {
  int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int n = 10;
  cout << binary_search(a, 0, n - 1, 5) << endl; // 1
  cout << binary_search(a, 0, n - 1, 6) << endl; // 0
  cout << binary_search2(a, 0, n - 1, 6) << endl; // 3 => a[3] = 7 >= 6
  cout << binary_search2(a, 0, n - 1, 20) << endl; // 10 => All elements are less than 20
  cout << binary_search3(a, 0, n - 1, 6) << endl; // 2 => a[2] = 5 <= 6
  cout << binary_search3(a, 0, n - 1, 0) << endl; // -1 => All elements are greater than 0
  return 0;
}