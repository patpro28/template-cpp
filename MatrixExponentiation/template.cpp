#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
* Matrix class for matrix multiplication and exponentiation
*   - mat: 2D vector to store the matrix
*   - row: number of rows
*   - col: number of columns
*   - operator*: matrix multiplication
*   - operator^: matrix exponentiation
* usage:
*   - Matrix a(row, col): create a matrix with row and col
*   - a.mat: access the 2D vector
*   - Matrix res = a * b: multiply matrix a and b
*   - Matrix res = a ^ n: exponentiate matrix a to the power of n
*   - a.mat = {{1, 2}, {3, 4}}: assign a 2x2 matrix to a
*/
struct Matrix {
    vector<vector<long long>> mat;
    int row, col;
    Matrix(int row, int col) : row(row), col(col) {
        mat.resize(row, vector<long long>(col, 0));
    }

    Matrix operator*(const Matrix &other) {
        Matrix res(row, other.col);
        for (int k = 0; k < col; k++) 
            for (int i = 0; i < row; i++) 
                for (int j = 0; j < other.col; j++) 
                    (res.mat[i][j] += mat[i][k] * other.mat[k][j]) %= MOD;
        return res;
    }

    Matrix operator^(long long n) {
        Matrix res(row, col);
        for (int i = 0; i < row; i++) res.mat[i][i] = 1;
        Matrix a = *this;
        while (n) {
            if (n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    // Calculate the nth Fibonacci number
    // [F(0), F(1)] * [[0, 1], [1, 1]] ^ n = [F(n), F(n + 1)]
    int n = 1e6;
    Matrix a(1, 2);
    a.mat[0] = {0, 1};
    Matrix b(2, 2);
    b.mat = {
        {0, 1}, 
        {1, 1}
    };
    Matrix res = a * (b ^ n);  // [F(n), F(n + 1)]
    cout << res.mat[0][0] << endl;  // F(n)
    return 0;
}