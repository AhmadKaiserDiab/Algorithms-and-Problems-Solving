#pragma once
#include <iostream>
#include <stack>
using namespace std;

class clsMyString
{
    private:
        string _Value = "";
        stack <string> V1;
        stack <string> V2;

    public:
        void SetValue(string Value )
        {
            _Value = Value;
            V1.push(_Value);
        }

        string GetValue()
        {
            return _Value;
        }

        void Undo()
        {
            V2.push(_Value);
            V1.pop();
            _Value = (!V1.empty()) ? V1.top() : "";

            // if(!V1.empty())
            // {
            //     _Value = V1.top();
            // }
            // else
            // {
            //     _Value = "";
            // }
        }

        void Redo()
        {
            _Value = (!V2.empty()) ? V2.top() : "";
            V2.pop();
            V1.push(_Value);
        }

};
