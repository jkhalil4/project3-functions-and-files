/*
// Josh Khalil
// Project 3
// Reads barcodes and gives information on zip codes after reading in/out files.
// October 20, 2022
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;


string getDigitCode(char digit){

    switch(digit) {
        case 1:
            return ":::||";
            break;
        case 2:
            return " :::|:|";
            break;
        case 3:
            return "::||:";
            break;
         case 4:
            return ":|::|";
            break;
         case 5:
            return ":|:|:";
            break;
         case 6:
            return ":||::";
            break;
         case 7:
            return "|:::|";
            break;
         case 8:
            return "|::|:";
            break;
         case 9:
            return "|:|::";
            break;
         case 0:
            return "||:::";
            break;
        default:
            cout<<"Invalid digit entered.";
    }
}

int calcCheckDigit (int sum){
    if(sum%10 == 0);
    return 0;

return10-sum%10;
}
int main()
{
    int n=0
    while(n==0){
        char zipCode[100];
        int sum=0;
        int flag=0;
            cout << "Enter a Zip code: ";
    if(strlen(zipCode) !=5){
        cout << "Error: Code must be of 5 digits. " << endl;
        flag == 0;
            break;
    }
    else
    {
        sum+=zipCode[i] - '0';
        flag++;
    }
    continue;
    }
if(flag!=0){
    cout << "Code: " << "|  ";
    for (int i=0;i<5;i++){
        cout << getDigitCode(zipCode[i]) << " ";
    }
    char c = calcCheckDigit(sum);
        cout << getDigitCode(c + 0);
        cout << "  |" << endl;
}
char pnt;
    cout << "More Codes? y/n"
}