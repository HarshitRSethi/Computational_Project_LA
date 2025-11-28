/*
Q.1 Write an algorithm and C/C++/MATLAB program to compute the row-reduced echelon (RRE) form of a matrix.
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int returnNonZeroRow(vector<vector<double>> &A, int &sortedColumn, int &sortedRow)
{
    if (sortedColumn >= A[0].size())
        return -1;

    sortedColumn++;
    for (int i = sortedRow; i < A.size(); i++)
        if (A[i][sortedColumn - 1] != 0)
            return i;

    return returnNonZeroRow(A, sortedColumn, sortedRow);
}

void exchange(vector<vector<double>> &A, int currentRow, int sortedRow)
{
    vector<double> tmp = A[currentRow];
    A[currentRow] = A[sortedRow];
    A[sortedRow] = tmp;
}

void makePivotOne(vector<vector<double>> &A, int &sortedColumn, int &sortedRow)
{
    double tmp = A[sortedRow][sortedColumn - 1];
    for (int i = sortedColumn - 1; i < A[0].size(); i++)
        A[sortedRow][i] /= tmp;
}

void eliminateOtherRows(vector<vector<double>> &A, int &sortedColumn, int &sortedRow)
{
    double tmp;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == sortedRow)
            continue;

        tmp = A[i][sortedColumn - 1];
        for (int j = 0; j < A[0].size(); j++)
            A[i][j] = A[i][j] - tmp * A[sortedRow][j];
    }
}

int main()
{
    cout << "Dimensions of matrix" << endl;
    // m x n matrix
    int m, n;
    int sortedColumn = 0, sortedRow = 0;
    cin >> m >> n;
    vector<vector<double>> A(m, vector<double>(n));
    cout << "Elements of matrix" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int currentRow;
    while (true)
    {
        currentRow = returnNonZeroRow(A, sortedColumn, sortedRow);
        if (currentRow == -1)
            break;

        if (currentRow != sortedRow)
            exchange(A, currentRow, sortedRow);

        makePivotOne(A, sortedColumn, sortedRow);
        eliminateOtherRows(A, sortedColumn, sortedRow);
        sortedRow++;
    }

    cout << "Row-Reduced Echelon Form:" << endl
         << fixed << setprecision(3);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(8) << A[i][j];

        cout << endl;
    }
    return 0;
}