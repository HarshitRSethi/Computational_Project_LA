/*
Q.2 Write a code for Laplace expansion (cofactor expansion) of the determinant of a square matrix
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> minor(vector<vector<double>> A, int j)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
        A[i].erase(A[i].begin() + j);
    A.erase(A.begin());
    return A;
}

double determinant(const vector<vector<double>> &A)
{
    int n = A[0].size();

    if (n == 1)
        return A[0][0];

    if (n == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0;
    for (int i = 0; i < n; i++)
    {
        auto B = minor(A, i);
        if (i % 2 == 0)
            det += A[0][i] * determinant(B);
        else
            det -= A[0][i] * determinant(B);
    }
    return det;
}

int main()
{
    cout << "Number of rows / columns: " << endl;
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Number of rows / columns must be positive" << endl;
        return 0;
    }

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Elements of matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Determinant of given matrix is " << determinant(A) << endl;
    return 0;
}