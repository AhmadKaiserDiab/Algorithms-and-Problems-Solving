#include<iostream>
using namespace std;

int RandomNumbersGenerator(int From , int To);
void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
void GetMinNumberInMatrix(int Matrix[3][3], short Rows , short Cols);
void GetMaxNumberInMatrix(int Matrix[3][3], short Rows , short Cols);


int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix,3,3);

    cout <<"\nMatrix1:\n";
    PrintMatrix(Matrix, 3, 3);
    cout<<endl;

    GetMinNumberInMatrix(Matrix,3,3);
    GetMaxNumberInMatrix(Matrix,3,3);
}

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
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

void GetMinNumberInMatrix(int Matrix[3][3], short Rows , short Cols) {
    short Min = Matrix[0][0];
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            if(Matrix[i][j]< Min)
                Min = Matrix[i][j];
    cout<<"The Minimum Number In The Matrix Is: "<<Min<<endl;
}

void GetMaxNumberInMatrix(int Matrix[3][3], short Rows , short Cols){
    short Max = Matrix[0][0];
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++) 
            if(Matrix[i][j] > Max)
                Max = Matrix[i][j];
    cout<<"The Max Number In The Matrix Is:     "<<Max<<endl; 
}