#include <iostream>
using namespace std;

enum enCharType {SpecialCharacter, Digit,
                CapitalLetters, SmallLetters};

int RandomsGenerator(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

char SelectRandomCharacter(enCharType CharType)
{

    switch(CharType) {
        case enCharType::SpecialCharacter :
            return char(RandomsGenerator(43,47));
        case enCharType::Digit:
            return char(RandomsGenerator(48,57));
        case enCharType::CapitalLetters:
            return char(RandomsGenerator(65,90));
        case enCharType::SmallLetters :
            return char(RandomsGenerator(97,122));
    }
    return ' ';
}

int main()
{
    srand((unsigned)time(NULL));
    
    cout<<SelectRandomCharacter(enCharType::SpecialCharacter)<<endl;
    cout<<SelectRandomCharacter(enCharType::Digit)<<endl;
    cout<<SelectRandomCharacter(enCharType::CapitalLetters)<<endl;
    cout<<SelectRandomCharacter(enCharType::SmallLetters)<<endl;
    
    return 0;
}
