#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++)
            Matrix[i][j] = RandomNumber(1, 100);
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) 
            cout <<setw(3) << Matrix[i][j] << " ";
        cout << "\n";
    }
}

void SumMatrixColumnsInArray(int Matrix[3][3] , int Sum[3], int Rows , int Cols){
    for (short j = 0; j < Cols; j++) 
        for(short i = 0; i < Rows; i++)
            Sum[j]+= Matrix[i][j];
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        printf("Column: %d  , Sum: %0.3d \n" , i + 1  , Array[i] );
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3] , SumArray[3] = {0};

    FillMatrixWithRandomNumbers(Matrix, 3, 3);

    cout <<"\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(Matrix, 3, 3);

    SumMatrixColumnsInArray(Matrix, SumArray, 3, 3);

    cout <<"\nThe Sum Of Each Column In The Matrix Using Array:\n";
    PrintArrayElements(SumArray,3);
}
