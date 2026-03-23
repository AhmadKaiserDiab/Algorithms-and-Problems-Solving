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
    bool MarkForDelete = false;
};

stClientData ReadNewClient();
vector<string> SplitString(string S1, string Sepertor = "#//#");
stClientData ConvertLineToRecord(string Line , string Sepertor = "#//#");
string ConvertRecordToLine(stClientData Client, string Separator = "#//#");
vector <stClientData> LoadClientsDataFromFile(string FileName);
void PrintClientData(stClientData Client);
string ReadAccountNumber();
bool FindClientByAccountNumber(string AccountNumber , vector <stClientData> & vClientsData ,stClientData & Client);
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClientData> & vClients); 
vector <stClientData> SaveCleintsDataToFile(string FileName, vector <stClientData> vClients);
bool UpdateClientByAccountNumber(string AccountNumber , vector <stClientData> & vClients);

int main() {
    vector <stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    UpdateClientByAccountNumber(AccountNumber , vClients);
}

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) 
    {
        sWord = S1.substr(0, pos); // store the word

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        // erase() until positon and move to next word.
        S1.erase(0, pos + Delim.length()); 
        
    }
        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }
    return vString;
}

stClientData ReadNewClient() {
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

string ReadAccountNumber() {
    string AccountNumber;
    cout<<"Please Enter Account Number: ";
    cin>>AccountNumber;
    return AccountNumber;
};

vector <stClientData> LoadClientsDataFromFile(string FileName) {
    fstream MyFile;
    MyFile.open(FileName , ios::in);
    vector <stClientData> vRecords;
    if(MyFile.is_open())
    {
        string Record;
        while(getline(MyFile,Record))
        {
            vRecords.push_back(ConvertLineToRecord(Record , "#//#"));
        }
        MyFile.close();
    }
    return vRecords;
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

string ConvertRecordToLine(stClientData Client, string Separator) {
    string strClientRecord = "";
    strClientRecord += Client.AccountNumber + Separator;
    strClientRecord += Client.PinCode + Separator;
    strClientRecord += Client.Name + Separator;
    strClientRecord += Client.Phone + Separator;
    strClientRecord += to_string(Client.AccountBalance);
    return strClientRecord;
}

bool FindClientByAccountNumber(string AccountNumber , vector <stClientData> & vClientsData ,stClientData & Client ){
    for(stClientData & C : vClientsData)
    {
        if(AccountNumber == C.AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void PrintClientData(stClientData Client){
    cout<<"\nThe Following Are The Clients Data:\n "<<endl;
    cout<<"Account Number  : "<<Client.AccountNumber<<endl
        <<"Pin Code        : "<<Client.PinCode<<endl
        <<"Client Name     : "<<Client.Name<<endl
        <<"Phone           : "<<Client.Phone<<endl
        <<"Account Balance : "<<Client.AccountBalance<<endl
        <<endl;
}

vector <stClientData> SaveCleintsDataToFile(string FileName, vector <stClientData> vClients) { 
    fstream MyFile; 
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine; 
    if (MyFile.is_open()) 
    { 
        for (stClientData C : vClients) 
        { 
            if (C.MarkForDelete == false) 
            { 
                //we only write records that are not marked for delete. 
                DataLine = ConvertRecordToLine(C); 
                MyFile << DataLine << endl; 
            } 
        } 
        MyFile.close(); 
        } 
    return vClients; 
}

void UpdateClient(string AccountNumber, vector <stClientData>& vClients)  { 
    
    for (stClientData & C : vClients) 
    { 
        if (C.AccountNumber == AccountNumber) 
        { 
            C = ReadNewClient();
            break; 
        }
    }
} 

bool UpdateClientByAccountNumber(string AccountNumber , vector <stClientData> & vClients){
    stClientData Client;
    char Answer = 'n';
    if(FindClientByAccountNumber(AccountNumber , vClients , Client))
    {
        PrintClientData(Client);
        cout<<"\n\nDo You Want To Update This Client? Y/N     ";
        cin>>Answer;
        if(Answer == 'Y' || Answer == 'y')
        {   
            UpdateClient(AccountNumber,vClients);
            SaveCleintsDataToFile(ClientsFileName , vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout<<"\n\n Client Updated Successfully."<<endl;
            return true;
        }
    }
    else
    {
        cout<<"\nClient With Account Number ("<<AccountNumber<<") Not Found!!!"<<endl;
        return false;
    }
}
