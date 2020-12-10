#include<iostream>
#include<fstream>
#include<set>
#include<vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    set<int> adapters;

    int outlet;
    while (fin >> outlet) {
        adapters.insert(outlet);
    }
    
    // add source outlet and your device adapter
    adapters.insert(0);
    adapters.insert(*(--adapters.end()) + 3);

    int previous = 0;
    int diff1 = 0;
    int diff3 = 0;
    for (int adapter : adapters) {
        if (adapter == 0)
            continue;
        if ((adapter - previous) == 1)
            diff1++;
        else 
            diff3++;
        previous = adapter;
    }
    cout << diff1 * diff3 << endl;
    return 0;
}
