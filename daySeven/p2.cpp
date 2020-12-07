#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<unordered_map>

using namespace std;

static unordered_map<string, vector<string>> bagMap;

void insertMap(string key, vector<string> values) {
    bagMap.insert(pair<string, vector<string>>(key, values));
}

void parseLine(string line) {
    vector<string> values;
    stringstream ss(line);
    string adj, color, junk, key, value;
    char next;
    ss >> adj >> color >> junk >> junk;
    key = adj + "-" + color;
    while(true) {
        int numBags = 0;
        ss >> junk; 
        if(junk == "no") {
            numBags++;
            value = "none";
        } else { 
            stringstream number(junk);
            number >> numBags;
            ss >> adj >> color >> junk;
            value = adj + "-" + color;
        }
        for(int i=0; i< numBags; i++)
            values.push_back(value);
        if(junk.at(junk.length() - 1) != ',') 
            break;
    }
    insertMap(key, values);
}

bool inVisited(vector<string> v, string s) {
    if(v.size() == 0)
        return false;
    for(string str : v) {
        if(str == s)
            return true;
    }
    return false;
}

void checkContents(unordered_map<string, vector<string>>::iterator it, vector<string> &visited) {
    if(it != bagMap.end()) {
        string current = it->first;
        if(current != "none") {
            visited.push_back(current);
            for(string bag : it->second) {
                if(bag == "none")
                    it = bagMap.end();
                else
                    it = bagMap.find(bag);
                checkContents(it, visited);
            }
        }
    }
}

int main() {
    ifstream infile("input.txt");
    string line;   
    int bagCount = 0;

    while(getline(infile, line)) {
        parseLine(line);
    }

    unordered_map<string, vector<string>>::iterator it;
    /*for(it = bagMap.begin(); it != bagMap.end(); it++) {
        if(it->first == "shiny-gold")
            continue;
        vector<string> visited;
        checkContents(it, visited);
        bagCount += inVisited(visited, "shiny-gold"); 
    }*/

    // part two
    it = bagMap.find("shiny-gold");
    vector<string> visited;
    checkContents(it, visited);
    cout << visited.size() - 1  << endl;


    cout << "count " << bagCount << endl;

    return 0;
}
