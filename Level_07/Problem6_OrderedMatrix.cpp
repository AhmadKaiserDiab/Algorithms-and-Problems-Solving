#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols , short Number) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++)
            Matrix[i][j] = Number++;
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) 
            cout <<setw(3) << Matrix[i][j] << " ";
        cout << "\n";
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3];

    FillMatrixWithOrderedNumbers(Matrix, 3, 3 , 1);

    cout <<"\nThe following is a 3x3 Ordered Matrix From 1 To 9:\n";
    PrintMatrix(Matrix, 3, 3);
}
