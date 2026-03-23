#include <iostream>
#include <iomanip>
using namespace std;


int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols , short Number);

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3] , Number;

    FillMatrixWithRandomNumbers(Matrix,3,3);
    cout <<"\nMatrix:\n";
    PrintMatrix(Matrix, 3, 3);
    cout<<endl;

    cout <<" Enter a Number To Count in The Matrix:\n";
    cin>>Number;
    printf("\nNumber %d Count In The Matrix Is: %d \n",Number ,
                        CountNumberInMatrix(Matrix,3,3,Number));
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            Matrix[i][j] = RandomNumber(1, 10);
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) 
            printf(" %0*d   ",2,Matrix[i][j]);
        cout << "\n";
    }
}

int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols , short Number)
{
    int Counter = 0;
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; j < Cols ; j++)
            if( Number == Matrix[i][j])
                Counter++;
    return Counter;
}