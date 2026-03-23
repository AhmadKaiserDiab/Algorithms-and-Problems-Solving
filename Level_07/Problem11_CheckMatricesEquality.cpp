#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
int SumOfMatrix(int Matrix[3][3] , int Rows , int Cols);
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
bool CheckMatricesEquality(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols);

int main() {
    //!Equailty Of 2 Matrices IS When They Have The Same Sum
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

    if(CheckMatricesEquality(FirstMatrix,SecondMatrix,3,3))
        cout<<"\nYes: Matrices Are Equal"<<endl;
    else
        cout<<"\nNO: Matrices Are Not Equal"<<endl;
}

int RandomNumber(int From, int To) {
    //Function to generate a random number
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

int SumOfMatrix(int Matrix[3][3] , int Rows , int Cols){
    int Sum = 0;
    for(short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            Sum+= Matrix[i][j];
    return Sum;
}

bool CheckMatricesEquality(int FirstMatrix[3][3], int SecondMatrix[3][3], short Rows, short Cols){
    return SumOfMatrix(FirstMatrix,3,3) == SumOfMatrix(SecondMatrix,3,3);
}