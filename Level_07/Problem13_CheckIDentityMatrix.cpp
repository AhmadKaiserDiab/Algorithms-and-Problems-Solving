#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
bool CheckIdentityMatrix(int FirstMatrix[3][3], short Rows, short Cols);

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int FirstMatrix[3][3] , TestMatrix[3][3]={{1,0,0},{0,1,0},{0,0,1}};

    cout <<"\nMatrix:\n";
    PrintMatrix(TestMatrix, 3, 3);
    cout<<endl;

    if(CheckIdentityMatrix(TestMatrix,3,3))
        cout<<"\n Yes: Matrix Is Identity"<<endl;
    else
        cout<<"\n No: Matrix Is Not Identity"<<endl;
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

bool CheckIdentityMatrix(int Matrix[3][3], short Rows, short Cols){
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; i < Cols ; i++)
            if( i != j && Matrix[i][j] != 0)
                    return false;
            else if( i==j && Matrix[i][j] != 1)
                    return false;
    return true;
}