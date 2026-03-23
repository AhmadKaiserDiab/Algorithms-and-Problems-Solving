#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
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

void SumMatrixRows(int Matrix[3][3] , int Rows , int Cols){
    for (short j = 0; j < Cols; j++){ 
        int Sum = 0;
        for(short i = 0; i < Rows; i++) 
            Sum+= Matrix[i][j];
        printf("Column: %d  , Sum: %0.3d \n" , j + 1 , Sum );
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);

    cout <<"\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(Matrix, 3, 3);

    cout <<"\nThe Sum Of Each Column In The Matrix:\n";
    SumMatrixRows(Matrix, 3, 3);

}
