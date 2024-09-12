/*
Problem of the Day: Maximum balanced strings
Problem Description: https://medium.com/@pradeepsooryavanshee1210/maximum-balanced-strings-unstop-solution-d0c49cadbf0a
*/

#include <iostream>
#include <string>
using namespace std;

string encapsulateBalancedStrings(string S)
{
    int balance = 0;
    string result = "";
    string temp = "";

    for (char c : S)
    {
        temp += c;

        if (c == 'L')
        {
            balance--;
        }
        else
        {
            balance++;
        }

        if (balance == 0)
        {
            result += "(" + temp + ")";
            temp = "";
        }
    }

    return result;
}

int main()
{
    string S;
    cin >> S;

    cout << encapsulateBalancedStrings(S) << endl;

    return 0;
}