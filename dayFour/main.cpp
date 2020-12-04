#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

static vector<int> fields_valid;
static string fields[7] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

bool birth(string str) {
    stringstream s(str);
    int year;
    s >> year;
    return (1920 <= year && year <= 2002); 
}
bool issue(string str) {
    stringstream s(str);
    int year;
    s >> year;
    return (2010 <= year && year <= 2020);
}
bool expire(string str) {
    stringstream s(str);
    int year;
    s >> year;
    return (2020 <= year && year <= 2030);
}
bool height(string str) {
    stringstream s(str);
    int height;
    string units;
    s >> height;
    s >> units; 
    if(units == "cm") {
        return (150 <= height && height <= 193);
    } else if (units == "in") {
        return (59 <= height && height <= 76);
    } else {
        return false;
    }
}
bool hcolor(string str) {
    if(str.at(0) != '#')
        return false;
    for(int i=1; i<str.length(); i++) {
        if (!((str.at(i) >= 97 && str.at(i) <= 102) || (str.at(i) >= 48 || str.at(i) <= 57)))
            return false;
    }
    return str.length() == 7;
}
bool ecolor(string s) {
    return (s == "amb" || s == "blu" || s == "brn" || s == "gry" || s == "grn" || s == "hzl" || s ==
    "oth");
}
bool id(string str) {
    for(char c : str) {
        if (c < 48 || c > 57)
            return false;
    }
    return str.length() == 9;
}

bool handleData(string key, string value) {
//    cout << key << ":" << value << endl;

    if(key == fields[0])
        return birth(value); 

    if(key == fields[1])
        return issue(value);

    if(key == fields[2])
        return expire(value); 

    if(key == fields[3])
        return height(value); 

    if(key == fields[4])
        return hcolor(value);

    if(key == fields[5])
        return ecolor(value);

    if(key == fields[6])
        return id(value);

    return 0;
}    

void countFields(int index, string line)
{
    stringstream stream(line);
    string word;
    string key;
    string value;

    while(stream >> word) {
        key = word.substr(0,3);
        value = word.substr(4, word.length() - 4);
        for(string s: fields) {
            if (key == s) {
                fields_valid.at(index) += handleData(key, value);
            }
        }
//        cout << code << endl;
    }
}

int main() {
    ifstream infile("c.txt");
    string line;
    int index = 0;
    int valid = 0;

    fields_valid.push_back(0);
    while (getline(infile, line)) {
      if(line == "") {
          fields_valid.push_back(0);
          index++;
      } else {
          countFields(index, line);
      }
    }
    for(int i : fields_valid) {
          cout << i << endl;
          if (i >= 7)
              valid++;
    }
    cout << fields_valid.size() << endl;
    cout << valid << endl;
    return 0;
}
