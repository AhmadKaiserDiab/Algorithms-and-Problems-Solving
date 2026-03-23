#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
bool CheckNumberExistsInMatrix(int Matrix[3][3], short Rows, short Cols , short Number);

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3] , Number;

    FillMatrixWithRandomNumbers(Matrix,3,3);

    cout <<"\nMatrix:\n";
    PrintMatrix(Matrix, 3, 3);
    cout<<endl;

    cout <<" Enter a Number To look For in The Matrix:  ";
    cin>>Number;

    if(CheckNumberExistsInMatrix(Matrix,3,3 , Number))
        cout<<"\n Yes: It's There"<<endl;
    else
        cout<<"\n No: Number Not is Not Found"<<endl;

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
