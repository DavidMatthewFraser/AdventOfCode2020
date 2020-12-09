#include<iostream>
#include<set>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

void next(set<double> &preamble, double &add, double &remove) {
    preamble.erase(remove);
    preamble.insert(add);
}

bool checkpattern(set<double> &preamble, double &num) {
    for(double db1 : preamble) {
       for(double db2 : preamble) { 
           if(db1 == db2) continue;
           if(db1 + db2 == num) return true;
       }
    }
    return false;
}

int main() {
    ifstream infile("input.txt");
    set<double> preamble;
    vector<double> nums;
    double num;
    double checknum;
    int x = 1;
    const double invalid = 542529149; // for pII
    
    while (infile >> num) {
        if (x <= 25) {
            preamble.insert(num);
        } 
        nums.push_back(num);
        x++;
    }

    for (int i=0; i<nums.size()-25; i++) {
        checknum = nums.at(i+25);
        if (!checkpattern(preamble, checknum)) {
            cout << std::fixed << checknum << " was not in the pattern" << endl;
            break;
        }
        next(preamble, checknum, nums.at(i));
    }

    return 0;
}
