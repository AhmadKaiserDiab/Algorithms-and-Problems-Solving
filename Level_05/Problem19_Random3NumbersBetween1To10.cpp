#include <iostream>
using namespace std;

int RandomNumberGenerator(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From;

    return RandomNumber;
}

int main()
{
    // Used To Generate Different Random Number On Each Run
    srand((unsigned)time(NULL));

    for (int i = 1; i <= 3; i++)
        cout << RandomNumberGenerator(1, 10) << endl;

    return 0;
}
