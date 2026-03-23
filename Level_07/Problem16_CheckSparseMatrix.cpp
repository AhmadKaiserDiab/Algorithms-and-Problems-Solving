#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
bool CheckSparseMatrix(int FirstMatrix[3][3], short Rows, short Cols);
bool CheckSparseMatrix2(int FirstMatrix[3][3], short Rows, short Cols);
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols , short Number);

int main() {
    //! Sparse Matrix is When The Zeroe's Count is Larger than Other Numbers Count
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3] , TestMatrix[3][3]={{1,0,0},{0,1,0},{0,0,1}};

    FillMatrixWithRandomNumbers(Matrix,3,3);

    cout <<"\nMatrix1:\n";
    PrintMatrix(Matrix, 3, 3);
    cout<<endl;

    if(CheckSparseMatrix(Matrix,3,3))
        cout<<"\n Yes: Matrix Is Sparse"<<endl;
    else
        cout<<"\n No: Matrix Is Not Sparse"<<endl;

    cout <<"\n\n\nMatrix2:\n";
    PrintMatrix(TestMatrix, 3, 3);
    cout<<endl;

    if(CheckSparseMatrix2(TestMatrix,3,3))
        cout<<"\n Yes: Matrix Is Sparse"<<endl;
    else
        cout<<"\n No: Matrix Is Not Sparse"<<endl;
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

bool CheckSparseMatrix(int Matrix[3][3], short Rows, short Cols){
    short ZeroesCount = 0 , OtherNumbersCount = 0;
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; i < Cols ; i++)
            if( Matrix[i][j] == 0)
                    ZeroesCount++;
            else
                    OtherNumbersCount++;

    return ZeroesCount > OtherNumbersCount;
}

int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols , short Number){
    int Counter = 0;
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; j < Cols ; j++)
            if( Number == Matrix[i][j])
                Counter++;
    return Counter;
}

bool CheckSparseMatrix2(int Matrix[3][3], short Rows, short Cols){
    short MatrixSize = Rows * Cols ;

    return CountNumberInMatrix(Matrix,3,3,0) > int(MatrixSize/2);
}