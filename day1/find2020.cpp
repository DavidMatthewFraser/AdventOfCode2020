#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ifstream infile("numbersFile.txt");
    int a;
    vector<int> numbers;

    while (infile >> a ) {
        numbers.push_back(a);
    }

    for(int i : numbers) {
        for(int j : numbers) {
            int need = 2020 - i - j;
            if (find(numbers.begin(), numbers.end(), need) != numbers.end()) {
                cout << i << "*" << j << "*" << need << "=" << i*j*need << endl;
            }
        }
    }

    cout << "Hello World" << endl;
    return 0;
}
