#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) ;
void PrintMatrix(int Matrix[3][3], short Rows, short Cols) ;
bool CheckPalindromeMatrix(int FirstMatrix[3][3], short Rows, short Cols);

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3] , TestMatrix[3][3]={{5,1,5},{0,1,0},{2,0,2}};

    cout <<"\nMatrix:\n";
    PrintMatrix(TestMatrix, 3, 3);
    cout<<endl;

    if(CheckPalindromeMatrix(TestMatrix,3,3))
        cout<<"\n Yes: The Matrix Is Palindrome"<<endl;
    else
        cout<<"\n No: Matrix Is Not Palindrome"<<endl;
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

bool CheckPalindromeMatrix(int Matrix[3][3], short Rows, short Cols){
    for (short  i = 0; i < Rows; i++)
        for (short  j = 0; j < Cols/2 ; j++)
            if( Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
    return true;
}
