#include<iostream>
#include<set>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

double checksum(set<double> &preamble) {
    double sum = 0;
    for (double d : preamble) {
        sum += d;
    }
    return sum;
}

int main() {
    ifstream infile("input.txt");
    vector<double> nums;
    set<double> block;
    int num;
    int startindex = 0;
    const double invalid = 542529149; // for pII
    
    while (infile >> num) {
        nums.push_back(num);
    }

    int itr = 0;

    while(true) {
        block.insert(nums.at(startindex + itr));
        if (checksum(block) == invalid)
            break;
        if (checksum(block) > invalid) {
            block.clear();
            itr = 0;
            startindex++;
        } else {
            itr++;
        }
    }

    double first = *block.begin();
    double second = *(--block.end());
    cout << std::fixed << first + second << endl;

    return 0;
}
