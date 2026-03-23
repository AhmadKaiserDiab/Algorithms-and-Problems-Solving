#include <iostream>
using namespace std;

enum QuestionsLevel { Easy = 1 , Mediuem = 2 , Hard = 3 , MixedLevels = 4 };

enum OperationType { Add  = 1 , Sub = 2 , Multipli = 3 , Divide = 4 , MixedOperations = 5 };

int ReadPoisitveNumbers(string Message) {
    int x;
    do
    {
        cout << Message << endl;
        cin >> x;
    } while (x < 0);
    return x;
}

int RandomsGenerator(int From, int To) {
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

QuestionsLevel GetQuestionsLevel() {
    int Choice = ReadPoisitveNumbers("Enter Question Level:\n[1]Easy\n[2]Mediuem\n[3]Hard\n[4]mix");
    return (QuestionsLevel)Choice;
}

OperationType GetOperationType() {
    int Choice = ReadPoisitveNumbers(
        "Choose The Operation:\n[1]Add + \n[2]Sub - \n[3]Multipli * \n[4]Divide / \n[5]Mix");
    return (OperationType)Choice;
}

void GenerateNumbers(int &Number1 , int &Number2 , QuestionsLevel Level){
    switch(Level){
        case 1:
            Number1 = RandomsGenerator(1,10);
            Number2 = RandomsGenerator(1,10);
            break;
        case 2:
            Number1 = RandomsGenerator(11,50);
            Number2 = RandomsGenerator(11,50);
            break;
        case 3:
            Number1 = RandomsGenerator(51,100);
            Number2 = RandomsGenerator(51,100);
        case 4:
            Number1 = RandomsGenerator(1,100);
            Number2 = RandomsGenerator(1,100);
            break;
    }
}

void Formula(int Number1 , int Number2 , OperationType Operation , int & Result){
    cout<<Number1<<endl;
    cout<<Number2<<"\t";
    switch (Operation) {
    
    case OperationType::Add :
        cout<<"  +"<<endl;
        Result = Number1 + Number2;
        break;

    case OperationType::Sub :
        cout<<"  -"<<endl;
        Result = Number1 - Number2;
        break;
    
    case OperationType::Multipli :
        cout<<"  *"<<endl;
        Result = Number1 * Number2;
        break;

    case OperationType::Divide :
        cout<<"  /"<<endl;
        Result = Number1 / Number2;
        break;
    }
}

void GenerateQuestions(QuestionsLevel Level , OperationType Operation , int Points[2]){
    int Number1 , Number2 , Result , Answer;
    if(Level == QuestionsLevel::MixedLevels)
            Level = (QuestionsLevel)RandomsGenerator(1,4);
    if(Operation == OperationType::MixedOperations)
        Operation = (OperationType)RandomsGenerator(1,4);

    GenerateNumbers(Number1,Number2,Level);
    Formula(Number1 , Number2 , Operation , Result);
    cout<<"___________________"<<endl;
    cin>>Answer;
    if(Answer == Result) {
        system("color 2f");    
        Points[0]++;
    }
    else {
        system("color 4f");
        Points[1]++;
    }
}

void PrintLevel(QuestionsLevel Level){
    switch(Level){
        case 1:
            cout<<"Easy \n";
            break;
        case 2:
            cout<<"Mediuem \n";
            break;
        case 3:
            cout<<"Hard \n";
            break;
        case 4:
            cout<<"Mix \n";
            break;
    }
}

void PrintOperation(OperationType Operation){
    switch(Operation){
        case 1:
            cout<<"Add + \n";
            break;
        case 2:
            cout<<"Subtract - \n";
            break;
        case 3:
            cout<<"Multipli * \n";
            break;
        case 4:
            cout<<"Divide / \n";
            break;
        case 5:
            cout<<"Mix + - * / \n";
            break;
    }
}

void PrintGameResult( QuestionsLevel Level , OperationType Operation , int Points[]) {
    cout << "\t____________________________________________________" << endl;
    cout << "\t\t\tF I N A L   R E S U L T   I S :   ";
    if (Points[0] >= Points[1]) {
        cout << "P A S S" << endl;
        system("color 2f");
    }
    else {
        cout << "F A I L E D" << endl;
        system("color 4f");
        }
    cout << "\t____________________________________________________" << endl;
    cout << "\tQuestions Number:\t" << Points[0] + Points[1]<< endl;
    cout << "\tQuestions Level:\t"; 
    PrintLevel(Level);
    cout << "\tOperatin Type:\t";
    PrintOperation(Operation);
    cout << "\tNumber of Right Answers:" << Points[0] << endl;
    cout << "\tNumber of Wrong Answers: " << Points[1] << endl;
    cout << "\t____________________________________________________" << endl;
}

void ClearScreen() {
    system("cls");
    system("Color 0f");
}

bool StartGame() {
    int Questions, Continue, Points[2] = {0};
    Questions = ReadPoisitveNumbers("Enter How Many Questions Do You Want To Answer: ");
    QuestionsLevel Level = GetQuestionsLevel();
    OperationType Operation = GetOperationType();
    bool Result;
    for (int i = 1; i <= Questions; i++)
    {
        cout << "Question[" << i << "/"<<Questions<<"]"<< endl;
        GenerateQuestions(Level , Operation , Points);
    }
    PrintGameResult(Level , Operation , Points);
    Continue = ReadPoisitveNumbers("Do You Want To Play Again?\n[0]No\n[1]Yes");
    if (Continue == 1)
        return true;
    return false;
}

void Game() {
    bool Continue = true;
    while (Continue)
    {
        cout << "Welcome To The Game" << endl;
        Continue = StartGame();
        if (Continue)
            ClearScreen();
    }
}

int main() {
    srand((unsigned)time(NULL));
    Game();
    return 0;
}