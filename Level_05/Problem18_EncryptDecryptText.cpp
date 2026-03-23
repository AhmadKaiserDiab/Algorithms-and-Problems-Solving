#include <iostream>
using namespace std;

string ReadString()
{   
    string Text;
    cout<<"Enter Your Name: ";
    getline(cin,Text);
    return Text;
}

string Encryption(string Text)
{
    for(int i = 0 ; i< Text.size();i++)
        Text[i] = char(Text[i] + 2);
    return Text;
}

string Decryption(string EncryptedText)
{
    for(int i = 0 ; i< EncryptedText.length();i++)
        EncryptedText[i] = char(EncryptedText[i] - 2);
    return EncryptedText;
}

int main()
{
    string Text = ReadString();

    cout<<"Your Text: "<<Text<<endl;
    cout<<"Your Text After Encryption: "<<Encryption(Text)<<endl;
    cout<<"Your Text After Decryption: "<<Decryption(Encryption(Text))<<endl;

    return 0;
}
