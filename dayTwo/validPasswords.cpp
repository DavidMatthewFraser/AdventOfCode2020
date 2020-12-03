#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

bool calcValid(int min, int max, char target, string password) {
    int occurences = 0;
    for (char c : password) {
        if (c == target) {
            occurences++;
        }
    }
    return ((occurences >= min) && (occurences <= max));
}

bool calcInvalid(int min, int max, char target, string password) {
    int occurences = 0;
    for (char c : password) {
        if (c == target) {
            occurences++;
        }
    }
    return !((occurences >= min) && (occurences <= max));
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
