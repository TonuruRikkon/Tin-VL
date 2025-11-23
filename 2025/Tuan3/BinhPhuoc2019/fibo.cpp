#include <bits/stdc++.h>
using namespace std;

// Function to multiply two 2x2 matrices
void multiply(vector<vector<int>>& mat1,vector<vector<int>>& mat2) {
    // Perform matrix multiplication
    int x = mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0];
    int y = mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1];
    int z = mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0];
    int w = mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1];

    // Update matrix mat1 with the result
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}

// Function to perform matrix exponentiation
void matrixPower(vector<vector<int>>& mat1, int n) {
    // Base case for recursion
    if (n == 0 || n == 1) return;

    // Initialize a helper matrix
    vector<vector<int>> mat2 = {{1, 1}, {1, 0}};

    // Recursively calculate mat1^(n/2)
    matrixPower(mat1, n / 2);

    // Square the matrix mat1
    multiply(mat1, mat1);

    // If n is odd, multiply by the helper matrix mat2
    if (n % 2 != 0) {
        multiply(mat1, mat2);
    }
}

// Function to calculate the nth Fibonacci number
// using matrix exponentiation
int nthFibonacci(int n) {
    if (n <= 1) return n;

    // Initialize the transformation matrix
    vector<vector<int>> mat1 = {{1, 1}, {1, 0}};

    // Raise the matrix mat1 to the power of (n - 1)
    matrixPower(mat1, n - 1);

    // The result is in the top-left cell of the matrix
    return mat1[0][0];
}

int main() {
    int n;
    cin>>n;
    int result = nthFibonacci(n+1);
    cout << result;

    return 0;
}