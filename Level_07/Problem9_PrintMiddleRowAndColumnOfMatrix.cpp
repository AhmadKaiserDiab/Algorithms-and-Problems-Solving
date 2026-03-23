#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) 
        for (short j = 0; j < Cols; j++)
            Matrix[i][j] = RandomNumber(1, 100);
}

void PrintMiddleRowAndColumnOfMatrix(int Matrix[3][3], short Rows, short Cols) {
    short MiddleRow = Rows/2 , MiddleColumn = Cols/2;

    cout<<"Middle Column:"<<endl;
    for (short i = 0; i < Rows; i++)
        cout <<setw(3) << Matrix[i][MiddleColumn] << endl;

    cout<<"\nMiddle Row:"<<endl;
    for (short j = 0; j < Cols; j++)
        cout <<setw(3)<< Matrix[MiddleRow][j] << "   ";
    cout<<endl;
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    short MiddleRow = Rows/3 , MiddleCo = Rows/3;
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) 
            cout <<setw(5) << Matrix[i][j] << " ";
        cout << "\n";
    }
}

int main() {

    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int FirstMatrix[3][3];

    FillMatrixWithRandomNumbers(FirstMatrix, 3, 3);

    cout <<"\nMatrix1:\n";
    PrintMatrix(FirstMatrix, 3, 3);
    cout<<endl;

    PrintMiddleRowAndColumnOfMatrix(FirstMatrix, 3, 3);
}
