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
        for (short j = 0; j < Cols; j++) {
            cout <<setw(3) << Matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    int Matrix[3][3];
    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(Matrix, 3, 3);
    system("pause>0");
}



/*
#include <iostream>
#include <iomanip>
using namespace std;

int RandomNumberGenerator(int From, int To);
void FillMatrixWithRandomNumbers(int MyMatrix[3][3], int Rows, int Cols);
void PrintMatrixElements(int MyMatrix[3][3], int Rows, int Cols);

int main() {
    srand((unsigned)time(NULL));

    int Size1 = 3 , Size2 = 3, Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, Size1, Size2);

    cout << "The Following is 3x3 Random Matrix:" << endl;
    PrintMatrixElements(Matrix, Size1, Size2);

    return 0;
}

int RandomNumberGenerator(int From, int To) {
    return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int MyMatrix[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            MyMatrix[i][j] = RandomNumberGenerator(1, 100);
        }
    }
}

void PrintMatrixElements(int MyMatrix[3][3], int Rows, int Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << setw(5) << MyMatrix[i][j] << "  ";
        }
        cout << endl;
    }
}
*/