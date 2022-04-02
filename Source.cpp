// TuteReadFile.cpp : This file contains the 'main' function. Program execution beginsand ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TaxPayer.hpp"
using namespace std;
vector <TaxPayer*> rsult;
TaxPayer* parseLine(std::string str)
{
    vector<string> store; // dont need to delete it because its local and not a pointer
    string tok = "";
    TaxPayer* retv = nullptr;
    for (int i = 0; i < (int)str.size(); i++)
    {
        char c = str[i];
        if (c != ',')
        {
            tok = tok + c;
        }
        else
        {
            store.push_back(tok);
            tok = "";
        }
    }
    if (tok != "") { store.push_back(tok); }
    for (string s : store)
    {
        cout << "DEBUG " << s << " | " << endl;
    }
    retv = new
        TaxPayer(store[0], store[1], store[2], store[3], stoi(store[4]), stoi(store[5])); 
    // dont delete it because we need it
        //taxpayerId=store[0];
            //name=store[1];
            //address=store[2];
            //postcode=store[3];
            //salary = store[4];
            //deductions = store[5];
            //taxDue = store[6]; // not used
     return retv;
}
bool readFile()
{
    
    std::ifstream myFile("C:\\Users\\chuboi\\Documents\\ST2TaxExample\\Taxpayerdata.txt");
    if (!myFile.is_open())
    {
        cout << "It failed to open the file" << endl;
        return false;
    }
    std::string str;
    int i = 0;
    while (std::getline(myFile, str))
    {
        cout << "DEBUG -- line " << ++i << " is:" << str << endl;
        if (str[0] != '/')
        {
            TaxPayer* taxpayer = parseLine(str);
            rsult.push_back(taxpayer);
        }
    }
    for (TaxPayer* t : rsult)
    {
        t->showFull();
    }
    return true;
}
int main()
{
    std::cout << "Read file!\n";
    bool rc = readFile();
    for (TaxPayer* t : rsult) delete t; // tidy up
    if (rc)
    {
        std::cout << "All good!\n";

        
    }
}