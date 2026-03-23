#include <iostream>
using namespace std;

struct stClientData {
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountBalance = 0;
};

stClientData ReadNewClient();
string ConvertRecordToLine(stClientData Client, string Separator = "#//#");
void PrintClientData(stClientData Data);

int main() {
    stClientData Ahmad;

    cout << "\nPlease Enter Client Data : \n\n";
    Ahmad = ReadNewClient();

    cout<<"\nClient Record For Saving Is: \n"
        <<ConvertRecordToLine(Ahmad)
        <<endl;
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
