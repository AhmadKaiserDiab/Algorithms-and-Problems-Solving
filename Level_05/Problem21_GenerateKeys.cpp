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

void PrintKeys(int NumberOfKeys)
{
    for (int i = 1; i <= NumberOfKeys; i++)
        cout<<"Key["<<i<<"]:"<< GenerateKeys()<<endl;
}

int main()
{
    srand((unsigned)time(NULL));

    PrintKeys(
        ReadPoisitveNumbers(
            "Enter How Many Keys Do You Need: "));
    return 0;
}
