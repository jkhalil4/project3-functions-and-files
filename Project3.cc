/*
// Josh Khalil
// Project 3
// Reads barcodes and gives information on zip codes after reading in/out files.
// October 20, 2022
*/


//iostream for basic io; fstream for file input/output; string and string.h for characters, pass by ref values; iomanip for setprecision.
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>

using namespace std;


string getDigitCode(char digit){
//returns barcode for single digits
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

//Calculates check digit and returns after completion
int calcCheckDigit (int sum){
    //checks if sum is divisible by 10
    if(sum%10 == 0);
    return 0; //returns 0 after completion
    //calculates the check digit, then returns the result
    return10-sum%10;
}

//this function calculates and arranges the barcode based on the inputs.
string barcode(string code)
{
string barcode = "|";
    for(unsigned i=0; i<code.size(); i++ )
    {
        barcode = barcode + getDigitCode(code[i]) + " ";
        sum = sum + (code[i] - 0);
    }
//this function gets the check digit.
char checkDigit = calcCheckDigit(sum) + 0;
barcode = barcode + calcCheckDigit(checkDigit) + "|";

return barcode;
}

bool isValid(string code)
{
    for(int i = 0; i< code.length(); i++){
    //check if the input contains any non integers
        if(code[i] < 0 || code[i]> 9)
            return false;
    }
    return true;
}
//main function for reading input files in and output files out.
int main()
{
//Variables
string inputFile;
string outputFile;
string code;
ifstream fin;
ofstream fout;

//Enter input file name
    cout << "Enter the input file name: "
    //read input file into the program
    cin >> inputFile;
    //open the input file
    fin.open(inputFile.c_str());
    //check for integrity
    if(!fin.is_open())
    {
        cout << "Invalid input file. Try checking the name of the input file and the location.\n";
            return 1;
    }
//Enter output file name
    cout << "Enter the output file name: ";
    //read the output file
    cin >> outputFile;
    //open the output file into the program
    fout.open(outputFile.c_str());
    //check for integrity
    if(fout.is_open())
    {
        cout << "The file" << outputFile << " has been saved." << endl;
    }
}
