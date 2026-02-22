#include <iostream>
using namespace std;

int main() {
    int row, col;
    cout << "Enter the row and column numbers: ";
    cin >> row >> col;
    int matrx[row][col];
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrx[i][j];
        }
    }

    cout << "your entered matrix is: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrx[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int x = row * col;
    int minrow = 0, mincol = 0, maxrow = row - 1, maxcol = col - 1, count = 0;

    while (count < x) {
        for (int i = mincol; i <= maxcol; i++) {
            cout << matrx[minrow][i] << " ";
            count++;
            if (count >= x) break;
        }
        minrow++;


        for (int i = minrow; i <= maxrow; i++) {
            cout << matrx[i][maxcol] << " ";
            count++;
            if (count >= x)break;
        }
        maxcol--;


        for (int i = maxcol; i >= mincol; i--) {
            cout << matrx[maxrow][i] << " ";
            count++;
            if (count >= x)break;
        }
        maxrow--;


        for (int i = maxrow; i >= minrow; i--) {
            cout << matrx[i][mincol] << " ";
            count++;
            if (count >= x)break;
        }
        mincol++;
    }
    return 0;
}
