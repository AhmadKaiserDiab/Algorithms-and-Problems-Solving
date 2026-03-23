#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
bool CheckScalarMatrix(int FirstMatrix[3][3], short Rows, short Cols);

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int TestMatrix[3][3]={{5,0,0},{0,5,0},{0,0,5}};

    cout <<"\nMatrix:\n";
    PrintMatrix(TestMatrix, 3, 3);
    cout<<endl;

    if(CheckScalarMatrix(TestMatrix,3,3))
        cout<<"\n Yes: Matrix Is Scalar"<<endl;
    else
        cout<<"\n No: Matrix Is Not Scalar"<<endl;
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

bool CheckScalarMatrix(int Matrix[3][3], short Rows, short Cols){
    int x = Matrix[0][0];

    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; i < Cols ; i++)
            if( i == j && x != Matrix[i][j])
                return false;
            else if( i != j && Matrix[i][j] != 0)
                    return false;
    return true;
}