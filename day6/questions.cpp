#include<iostream>
#include<fstream>
#include<vector>
#include<set>

using namespace std;

static vector<int> counts;

int addGroup(vector<string> questions) {
    set<char> unique;
    set<char> toErase;
    int i = 0;
    for(string s : questions) {
        if(i == 0) {
            i++;
            for(char c : s) 
                unique.insert(c);
            continue;
        }
        for(char c : unique) {
           if(s.find(c) > s.length()) 
               toErase.insert(c);
        }
    }
    for(char c : toErase) {
        unique.erase(c);
    }
    return unique.size();
}

int main() {
    ifstream infile("input.txt");
    string line;
    vector<string> group;
    int sum = 0;
    while(getline(infile, line)) {
        if(line == "") {
            sum += addGroup(group);
            group.clear();
        } else {
            group.push_back(line);
        }
    }
   cout << sum << endl;
   return 0;
}
