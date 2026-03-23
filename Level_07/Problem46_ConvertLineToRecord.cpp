#include <iostream>
#include <vector>
using namespace std;

struct stClientData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

vector<string> SplitString(string S1, string Seperator = "#//#");
stClientData ConvertLineToRecord(string record , string Seperator = "#//#");
void PrintClientData(stClientData Data);

int main() {
    string AhmadRecord = 
    "ADK0#//#1234#//#Ahmad Kaiser Diab#//#0000#//#100000";

    stClientData Ahmad = ConvertLineToRecord(AhmadRecord);

    cout<<"Line Record Is: \n"
        <<AhmadRecord<<endl;

    PrintClientData(Ahmad);
}

vector<string> SplitString(string S1, string Seperator) {
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ( (pos = S1.find(Seperator)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word

        if (sWord != "")
            vString.push_back(sWord);

        // erase() until positon and move to next word.
        S1.erase(0, pos + Seperator.length()); 
        }
        if (S1 != "")
            vString.push_back(S1); // it adds last word of the string.
    return vString;
}

stClientData ConvertLineToRecord(string record , string Seperator = "#//#"){
    vector<string> vData = SplitString(record , Seperator);

    stClientData TempData ;
    TempData.AccountNumber = vData[0];
    TempData.PinCode = vData[1];
    TempData.Name = vData[2];
    TempData.Phone = vData[3];
    TempData.AccountBalance = stod(vData[4]);

    return TempData;
}

void PrintClientData(stClientData Data){
    cout<<"\nThe Following Is The Extracted Client's Record:\n\n";

    cout<<"Account Number  : "
        <<Data.AccountNumber<<endl;

    cout<<"Pin Code        : "
        <<Data.PinCode<<endl;

    cout<<"Name            : "
        <<Data.Name<<endl;
    
    cout<<"Phone           : "
        <<Data.Phone<<endl;

    cout<<"Account Balance : "
        <<Data.AccountBalance<<endl;
}