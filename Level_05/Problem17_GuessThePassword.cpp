#include <iostream>
#include <string>
using namespace std;

bool PrintLetters(string Input)
{
    int Trial = 1;
    string Word = "";
    for (int i = 65; i <= 90; i++)
        for (int j = 65; j <= 90; j++)
            for (int k = 65; k <= 90; k++) {
                Word = Word + char(i) + char(j)+ char(k);
                
                cout<<"Trial["<<Trial<<"]: "
                << Word<< endl;
                
                if(Input == Word){
                    cout<<"\nAPassWord Is: "<<Word
                    <<"\nFound After "<<Trial
                    <<" Times"<<endl;
                    return true;
                }
                Trial++;
                Word = "";
            }
    return false;
}

int main()
{
    string Input;
    cin>>Input;
    PrintLetters(Input);
    return 0;
}
