#include <iostream>
using namespace std;

int RandomNumber(int From, int To) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
bool CheckNumberExistsInMatrix(int Matrix[3][3], short Rows, short Cols , short Number);
void CheckIntersectedNumbersInMatrices(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols);

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int FirstMatrix[3][3] , SecondMatrix[3][3];

    FillMatrixWithRandomNumbers(FirstMatrix,3,3);
    FillMatrixWithRandomNumbers(SecondMatrix,3,3);

    cout <<"\nMatrix1:\n";
    PrintMatrix(FirstMatrix, 3, 3);
    cout<<endl;

    cout <<"\nMatrix2:\n";
    PrintMatrix(SecondMatrix, 3, 3);
    cout<<endl;

    CheckIntersectedNumbersInMatrices(FirstMatrix,SecondMatrix,3,3);
}

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            Matrix[i][j] = RandomNumber(1, 10);
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) 
            printf(" %0*d   ",2,Matrix[i][j]);
        cout << "\n";
    }
}

bool CheckNumberExistsInMatrix(int Matrix[3][3], short Rows, short Cols , short Number){
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; j < Cols ; j++)
            if( Number == Matrix[i][j])
                return true;
    return false;
}

void CheckIntersectedNumbersInMatrices(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols){
    cout<<"Intersected Numbers In The Two Matrices are: ";
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; j < Cols ; j++)
            if( CheckNumberExistsInMatrix(SecondMatrix,3,3,FirstMatrix[i][j]))
                cout<<FirstMatrix[i][j]<<"   ";
    cout<<endl;
}