#include <iostream>
using namespace std;

enum Posibilities { Paper = 1 , Scissor = 2 , Stone = 3 };

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

Posibilities GetPlayerChoice() {
    int Choice = ReadPoisitveNumbers("Enter Your Choice:\n[1]Paper\n[2]Scissor\n[3]Stone");

    switch (Choice)
    {
    case 1:
        cout << "Player  Choice:  Paper" << endl;
        break;
    case 2:
        cout << "Player  Choice:  Scissor" << endl;
        break;
    case 3:
        cout << "Player  Choice:  Stone" << endl;
        break;
    }

    return (Posibilities)Choice;
}

Posibilities GetComputerChoice() {
    int Choice = RandomsGenerator(1, 3);
    switch (Choice)
    {
    case 1:
        cout << "Computer Choice:  Paper" << endl;
        break;
    case 2:
        cout << "Computer Choice:  Scissor" << endl;
        break;
    case 3:
        cout << "Computer Choice:  Stone" << endl;
        break;
    }
    return (Posibilities)Choice;
}

void CheckWinner(Posibilities Player, Posibilities Computer, int Points[3]) {
    if (Player == Computer)
    {
        cout << "Round Winner:     [No Winner]" << endl;
        system("Color 6f");
        Points[2]++;        // Draw
    }

    else if (Player == Posibilities::Paper) {
            if (Computer == Posibilities ::Scissor) {
            cout << "Round Winner:     [Computer]\a" << endl;
            system("Color 4f");
            Points[1]++;        // Computer Wins
        }
        else {
            cout << "Round Winner:     [You]" << endl;
            system("Color 2f");
            Points[0]++; // Player Wins
        }
    }
    
    else if (Player == Posibilities :: Scissor) {
        if (Computer == Posibilities :: Stone) {
            cout << "Round Winner:     [Computer]\a" << endl;
            system("Color 4f");
            Points[1]++; // Computer Wins
        }
        else {
            cout << "Round Winner:     [You]" << endl;
            system("Color 2f");
            Points[0]++; // player Wins
        }
    }
    else { 
        if (Computer == Posibilities :: Paper) {
            cout << "Round Winner:     [Computer]\a" << endl;
            system("Color 4f");
            Points[1]++;        // Computer Wins
        }
        else {
            cout << "Round Winner:     [You]" << endl;
            system("Color 2f");
            Points[0]++; // Player Wins
        }
}

}

void PrintGameResult(int Points[]) {
    cout << "\t____________________________________________________" << endl;
    cout << "\t\t\t ***   G A M E O V E R   ***" << endl;
    cout << "\t____________________________________________________" << endl;
    cout << "\t______________[ Game Results ]_______________________" << endl;
    cout << "\tGame Numbers:\t" << Points[0] + Points[1] + Points[2] << endl;
    cout << "\tPlayer Win Times:   " << Points[0] << endl;
    cout << "\tComputer Win Times: " << Points[1] << endl;
    cout << "\tDraw Times:\t" << Points[2] << endl;
    cout << "\tFinal Winner:    ";
    if (Points[0] > Points[1])
        cout << "Player" << endl;
    else if (Points[0] < Points[1])
        cout << "Computer" << endl;
    else
        cout << "NoBody Wins, It's A Draw" << endl;
    cout << "\t____________________________________________________" << endl;
}

void ClearScreen() {
    system("cls");
    system("Color 0f");
}

void Round(int Points[3]) {
    Posibilities PlayerChoice, ComputerChoice;
    PlayerChoice = GetPlayerChoice();
    ComputerChoice = GetComputerChoice();
    CheckWinner(PlayerChoice, ComputerChoice, Points);
}

bool StartGame() {
    int Rounds, Continue, Points[3] = {0};
    Rounds = ReadPoisitveNumbers("Enter How Many Round Do You Want To Play: ");
    for (int i = 1; i <= Rounds; i++)
    {
        cout << "__________Round[" << i << "] Begins:__________" << endl;
        Round(Points);
        cout << "____________________________________" << endl;
    }
    PrintGameResult(Points);
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