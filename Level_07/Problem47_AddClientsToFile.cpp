#include <iostream>
#include <fstream>
using namespace std;

struct stClientData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

stClientData ReadNewClientData();
string ConvertRecordToLine(stClientData Client, string Separator = "#//#");
void AddDataLineToFile(string FileName, string Record);
void AddNewClient(string file);
void AddClients(string file);

int main() {
    const string MyFile = "ClientsData.txt";
    AddClients(MyFile);
}

stClientData ReadNewClient(){
    stClientData TempData;
    
    cout << "Enter Account Number ? ";
    getline(cin >> ws, TempData.AccountNumber);

    cout << "Enter PinCode ? ";
    getline(cin, TempData.PinCode);

    cout << "Enter Name ? ";
    getline(cin, TempData.Name);

    cout << "Enter Phone ? ";
    getline(cin, TempData.Phone);

    cout << "Enter Account Balance ? ";
    cin >> TempData.AccountBalance;

    return TempData;
}

string ConvertRecordToLine(stClientData Client, string Separator) {
    string strClientRecord = "";
    strClientRecord += Client.AccountNumber + Separator;
    strClientRecord += Client.PinCode + Separator;
    strClientRecord += Client.Name + Separator;
    strClientRecord += Client.Phone + Separator;
    strClientRecord += to_string(Client.AccountBalance);
    return strClientRecord;
}

void AddDataLineToFile(string FileName, string Record){
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << Record << endl;
        MyFile.close();
    }
}

void AddNewClient(string FileName){
    stClientData TempData = ReadNewClientData();
    string Record = ConvertRecordToLine(TempData , "#//#");
    AddDataLineToFile(FileName, Record);
}

void AddClients(string MyFile){
    bool confirm;
    do{
        system("cls");
        cout<<"\nAdding New Client: \n\n";
        AddNewClient(MyFile);
        cout<<"\n\nClient Added Succesfully Do You Want To Add More Clients:"
            <<"\n 0 - No \n 1 - Yes "<<endl;
        cin>>confirm;
    } while (confirm); 
}