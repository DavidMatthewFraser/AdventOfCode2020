#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<iomanip>
#include<math.h>

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

    // store each set of numbers that are 1 apart in a vector
    vector<set<int>> groupings;
    set<int> group;
    int diff;
    int previous;
    bool newgroup = true;

    for (int n : adapters) {
       if (newgroup) {
           group.insert(n);
           previous = n;
           newgroup = false;
           continue;
       }
       if (group.size() == 0) {
           group.insert(n);
       } else if ((n - previous) == 1)
           group.insert(n);
       else {
           groupings.push_back(group);
           group.clear();
           group.insert(n);
       }
       previous = n;
    } groupings.push_back(group);

// remove the first and last item of the series (they must be used)
// count the size of the remaining groupings
// the following arrangements are possilbe:

// size 1: |, * (3 arrangements)
// size 2: ||, *|, |*, ** (4 arrangements) 
// size 3: |||, *||, |*|, ||*, |**, **|, *|* ( 7 arrangements)


// multiply total # of arrangments by # of arrangements of each group
    
    long arrangements = 1;
    for(set<int> g : groupings) {
      // erase
      g.erase(*g.begin()); 
      g.erase(*(--g.end()));
      if(g.size() == 1) 
          arrangements *= 2;
      if(g.size() == 2)
          arrangements *= 4;
      if(g.size() == 3)
          arrangements *= 7;
    }
        
    cout << std::fixed << arrangements << endl;

    return 0;
}
