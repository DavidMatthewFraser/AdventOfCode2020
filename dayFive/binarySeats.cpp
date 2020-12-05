#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;

void printVector(vector<int> vec) {
    for(int i : vec)
        cout << i << ", ";
     cout << endl;
     cout << "======" << endl;
}

string convertDirections(string toConvert) {
    string newString;
    for(char c : toConvert) {
        if (c == 'L')
            newString += 'F';
        else
            newString += 'B';
    }
    return newString;
}

int binarySearch(vector<int> row, string directions) {
    int length = row.size();
    if(length == 2) {
        if(directions.at(0) == 'F')
            return row.at(0);
        return row.at(1);
    } else {
        vector<int> newRow(length/2);
        int begin;
        int end;
        if (directions.at(0) == 'F') {
           begin = 0; 
           end = length/2;
        } else {
           begin = length/2; 
           end = length;
        }
        newRow = vector<int>(row.begin() + begin, row.begin() + end);    
        string newDirections = directions.substr(1, directions.length()-1);
        return binarySearch(newRow, newDirections);
    }
}

int getID(int row, int col) {
    return 8*row+col;
}

void initVector(vector<int> &vec, int size) {
    for(int i=0; i<=size; i++)
        vec.at(i) = i;
}

static set<int> permutations;
static vector<int> row(128);
static vector<int> col(8);

void generatePermutations(string perm) {
    if(perm.length() == 10) {
        string rowdirections = perm.substr(0,7);
        string coldirections = perm.substr(7,3);
        int numRow = binarySearch(row,rowdirections);
        int numCol = binarySearch(col, coldirections);
        int id = getID(numRow, numCol);
        permutations.insert(id);
    } else {
        generatePermutations(perm + 'F');
        generatePermutations(perm + 'B');
    }
}

void printPermutations(set<int>& s) {
    for(int i: s)
        cout << i << endl;
}

int main() {
    initVector(row, 127);
    initVector(col, 7);

    int highestID = 0;
    ifstream infile("input.txt");

    string line;
    int numRow, numCol, id;

    generatePermutations("");

    while(infile >> line) {
        string rowdirections = line.substr(0,7);
        string coldirections = convertDirections(line.substr(7,3));
        numRow = binarySearch(row, rowdirections);
        numCol = binarySearch(col, coldirections);
        id = getID(numRow, numCol);
        permutations.erase(id);
    }

    printPermutations(permutations);

    return 0;
}
