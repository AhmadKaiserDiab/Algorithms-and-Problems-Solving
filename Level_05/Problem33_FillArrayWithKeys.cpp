#include <iostream>
using namespace std;

int ReadPoisitveNumbers(string Message)
{
    int x;
    do
    {
        cout << Message << endl;
        cin >> x;
    } while (x < 0);
    return x;
}

int RandomsGenerator(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

string KeyPieces()
{
    string KeyPiece = "";
    for (int i = 1; i <= 4; i++)
        KeyPiece = KeyPiece + char(RandomsGenerator(65, 90));
    return KeyPiece;
}

string GenerateKeys()
{
    string FullKey = "";

    // for (int i = 1; i <= 4; i++)
    FullKey = FullKey + KeyPieces() + "-" + KeyPieces()
        + "-" + KeyPieces() + "-" + KeyPieces();
    return FullKey  ;
}

void FillArrayWithKeys(string Array[] , int & Size)
{
    Size = ReadPoisitveNumbers("Enter Number Of Keys Do You Need: ");

    for(int i = 0;  i < Size ; i++ )
        Array[i]= GenerateKeys();
}

void PrintArrayElements(string Array[], int Size)
{
    for(int i = 0;  i < Size ; i++ )
        cout<<"Array["<<i<<"]: "<<Array[i]<<endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Size;
    string KeysArray[Size];

    FillArrayWithKeys(KeysArray,Size);

    cout<<"\nArray Elements:\n\n";
    PrintArrayElements(KeysArray,Size);


    return 0;
}
