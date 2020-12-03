#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool calcValid(int min, int max, char target, string password) {
   if(max > password.length() || min > password.length())
       return false;
   bool minMatch = (target == password.at(min-1)); 
   bool maxMatch = (target == password.at(max-1)); 
   bool bothMatch = minMatch && maxMatch; 
   return((minMatch || maxMatch) && (!bothMatch));
}

bool calcInvalid(int min, int max, char target, string password) {
   if(max > password.length() || min > password.length())
       return false;
   bool minMatch = (target == password.at(min-1)); 
   bool maxMatch = (target == password.at(max-1)); 
   bool bothMatch = minMatch && maxMatch; 
   return !((minMatch || maxMatch) && (!bothMatch));   
}

int main() {
    ifstream infile("passwords.txt");
    int numberValid = 0;
    int numberInvalid = 0;
    int numberPasswords = 0;

    int min;
    char separator;
    int max;
    char target;
    char semicolon;
    string password;

    while (infile >> min ) {
        infile >> separator;
        infile >> max;
        infile >> target;
        infile >> semicolon;
        infile >> password;
        numberValid += calcValid(min, max, target, password);
        numberInvalid += calcInvalid(min, max, target, password);
        numberPasswords++;
        //cout << "min: " << min << " max: " << max << " target: " << target << "password: " << password << endl; 
    }

    cout << "Passwords" << numberPasswords << endl;
    cout << "Valid" << numberValid << endl;
    cout << "Valid + Invalid" << numberValid + numberInvalid << endl;

    return 0;
}
