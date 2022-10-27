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
#include <iomanip>

using namespace std;


string getDigitCode(char digit){
//returns barcode for single digits
    switch(digit) {
        case '1': 
            return ":::||";
        case '2': 
            return "::|:|";
        case '3': 
            return "::||:";
        case '4': 
            return ":|::|";
        case '5': 
            return ":|:|:";
        case '6': 
            return ":||::";
        case '7': 
            return "|:::|";
        case '8': 
            return "|::|:";
        case '9': 
            return "|:|::";
        case '0': 
            return "||:::";
    }
    return "";
}

//Calculates check digit and returns after completion
int calcCheckDigit(int sum){
    //checks if sum is divisible by 10
if(sum%10 == 0);
return 0; //returns 0 after completion
    //calculates the check digit, then returns the result
    return 10-sum%10;
}

//this function calculates and arranges the barcode based on the inputs.
string barCode(string code)
{
string barcode = "|";
int sum = 0;
    for(unsigned i=0; i<code.size(); i++) {
        barcode = barcode + getDigitCode(code[i]);
        sum = sum + (code[i]-'0');
    }
    //calculate check digit
    char check = calcCheckDigit(sum) + '0';
    barcode = barcode + getDigitCode(check) + "|";
return barcode;
}

bool isValid(string code)
{
    for(int i = 0; i< code.length(); i++){
    //check if the input contains any non integers
        if(code[i] < '0' || code[i]> '9')
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
    cout << "Enter the input file name: ";
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
        cout << "The file " << outputFile << " has been saved." << endl;
    }
while(1)
{
    //read a zipcode from the given input File.
    fin>> code;
    //check for the end of file
    if(fin.eof()) {
    break;
    }
    //check code for integrity
    if(code.length()<5){
        fout << left << setw(10) << code << "Zip code is not 5 digits" << endl;
    }
    else if(code.length()>5 || !isValid(code)){
        fout << left << setw(10) << code << "Illegal Characters in ZipCode!" << endl;
    }
    //if the code is valid, this function will write the barcode to the output file
    else
        fout << left << setw(10) << code << barCode(code) << endl;
}
//close the files and remove from memory
fout.close();
fin.close();

//return 0 and end the program
return 0;
}