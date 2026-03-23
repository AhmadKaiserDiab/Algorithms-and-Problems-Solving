#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
bool CheckIdentityMatrices(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols);

int main() {
    //! Typical Matrices Is When Both Have The Same Number In Each Cell
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int FirstMatrix[3][3] , SecondMatrix[3][3];

    FillMatrixWithRandomNumbers(FirstMatrix, 3, 3);
    FillMatrixWithRandomNumbers(SecondMatrix, 3, 3);

    cout <<"\nMatrix1:\n";
    PrintMatrix(FirstMatrix, 3, 3);
    cout<<endl;

    cout <<"\nMatrix2:\n";
    PrintMatrix(SecondMatrix, 3, 3);

    if(CheckIdentityMatrices(FirstMatrix,SecondMatrix,3,3))
        cout<<"\nYes: Matrices Are Typical"<<endl;
    else
        cout<<"\nNO: Matrices Are Not Typical"<<endl;
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
            printf("%0*d   ",2,Matrix[i][j]);
        cout << "\n";
    }
}

bool CheckIdentityMatrices(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols){
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; i < Cols ; i++)
            if(FirstMatrix[i][j] != SecondMatrix[i][j])
                return false;
    return true;
}