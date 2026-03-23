#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct stClientData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

vector<string> SplitString(string S1, string Delim);
stClientData ConvertLineToRecord(string record , string Seperator = "#//#");
vector <stClientData> LoadClientsDataFromFile(string FileName);
void PrintClientCard(stClientData Record);
void PrintAllClientsData(vector<stClientData> vRecords);

int main() {
    const string FileName= "ClientsData.txt";
    vector<stClientData> vRecords = LoadClientsDataFromFile(FileName);
    PrintAllClientsData(vRecords);
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

stClientData ConvertLineToRecord(string record , string Seperator) {
    vector<string> vData = SplitString(record , Seperator);
    stClientData Temp ;
    Temp.AccountNumber = vData[0];
    Temp.PinCode = vData[1];
    Temp.Name = vData[2];
    Temp.Phone = vData[3];
    Temp.AccountBalance = stod(vData[4]);
    return Temp;
}

vector <stClientData> LoadClientsDataFromFile(string FileName){
    fstream MyFile;
    MyFile.open(FileName , ios::in);
    vector <stClientData> vRecords;
    if(MyFile.is_open()){
        string Record;
        while(getline(MyFile,Record))
            vRecords.push_back(ConvertLineToRecord(Record));
        MyFile.close();
    }
    return vRecords;
}

void PrintClientCard(stClientData Record) {
    cout<<"| "<<setw(15)<<left<<Record.AccountNumber
        <<"| "<<setw(10)<<left<<Record.PinCode
        <<"| "<<setw(40)<<left<<Record.Name
        <<"| "<<setw(12)<<left<<Record.Phone
        <<"| "<<setw(12)<<left<<Record.AccountBalance
        <<endl;
}

void PrintAllClientsData(vector<stClientData> vRecords) {
    cout<<"\n"<<setw(40)<<"Client List("<<vRecords.size()<<") Client(s)."<<endl;
    cout<<"________________________________________________"
        <<"________________________________________________\n"<<endl;
    cout<<"| "<<left<<setw(15)<<"Account Number"
        <<"| "<<left<<setw(10)<<"Pin Code"
        <<"| "<<left<<setw(40)<<"Client Name"
        <<"| "<<left<<setw(12)<<"Phone"
        <<"| "<<left<<setw(12)<<"Balance"
        <<endl;
    cout<<"________________________________________________"
        <<"________________________________________________\n"<<endl;
    for(stClientData & Record : vRecords)
        PrintClientCard(Record);
    cout<<"________________________________________________"
        <<"________________________________________________\n"<<endl;
}