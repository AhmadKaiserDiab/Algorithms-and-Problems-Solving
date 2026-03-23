#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string ClientsFileName= "ClientsData.txt";
struct stClientData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

vector<string> SplitString(string S1, string Sepertor = "#//#");
stClientData ConvertLineToRecord(string Line , string Sepertor = "#//#");
vector <stClientData> LoadClientsDataFromFile(string FileName);
string ReadAccountNumber();
bool FindClientByAccountNumber(string AccountNumber , vector <stClientData> & vClientsData ,stClientData & Client);
void PrintClientData(stClientData Record);

int main() {
    stClientData Client;
    string AccountNumber = ReadAccountNumber();
    vector <stClientData> vClientsData = LoadClientsDataFromFile(ClientsFileName);
    if (FindClientByAccountNumber(AccountNumber , vClientsData , Client))
        PrintClientData(Client);
    else
        cout<<"\nClient With Account Number ("<<AccountNumber<<") Not Found!!!"<<endl;
}

string ReadAccountNumber(){
    string AccountNumber;
    cout<<"Please Enter Account Number: ";
    cin>>AccountNumber;
    return AccountNumber;
};

vector <stClientData> LoadClientsDataFromFile(string FileName){
    fstream MyFile;
    MyFile.open(FileName , ios::in);
    vector <stClientData> vRecords;
    if(MyFile.is_open()){
        string Record;
        while(getline(MyFile,Record))
            vRecords.push_back(ConvertLineToRecord(Record , "#//#"));
        MyFile.close();
    }
    return vRecords;
}

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word

        if (sWord != "")
            vString.push_back(sWord);

        // erase() until positon and move to next word.
        S1.erase(0, pos + Delim.length()); 
        }
        if (S1 != "")
            vString.push_back(S1); // it adds last word of the string.
    return vString;
}

stClientData ConvertLineToRecord(string record , string Seperator){
    vector<string> vData = SplitString(record , Seperator);
    stClientData Temp ;
    Temp.AccountNumber = vData[0];
    Temp.PinCode = vData[1];
    Temp.Name = vData[2];
    Temp.Phone = vData[3];
    Temp.AccountBalance = stod(vData[4]);
    return Temp;
}

bool FindClientByAccountNumber(string AccountNumber , vector <stClientData> & vClientsData ,stClientData & Client ){
    for(stClientData & C : vClientsData)
        if(AccountNumber == C.AccountNumber){
            Client = C;
            return true;
        }
    return false;
}

void PrintClientData(stClientData Record){
    cout<<"\nThe Following Are The Clients Data:\n "<<endl;
    cout<<"Account Number  : "<<Record.AccountNumber<<endl
        <<"Pin Code        : "<<Record.PinCode<<endl
        <<"Client Name     : "<<Record.Name<<endl
        <<"Phone           : "<<Record.Phone<<endl
        <<"Account Balance : "<<Record.AccountBalance<<endl
        <<endl;
}
