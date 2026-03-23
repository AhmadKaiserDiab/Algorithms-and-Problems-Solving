#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols , short Number) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++)
            Matrix[i][j] = Number++;
}

void TrasposeMatrix(int Matrix[3][3], int TransposeMatrix[3][3],short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            TransposeMatrix[j][i]=Matrix[i][j];
    
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
    int Matrix[3][3] , TransposeMatrix[3][3];

    FillMatrixWithOrderedNumbers(Matrix, 3, 3 , 1);

    cout <<"\nThe following is a 3x3 Ordered Matrix From 1 To 9:\n";
    PrintMatrix(Matrix, 3, 3);

    TrasposeMatrix(Matrix, TransposeMatrix ,3, 3);

    cout <<"\nThe following The Transpose Matrix:\n";
    PrintMatrix(TransposeMatrix, 3, 3);

}

