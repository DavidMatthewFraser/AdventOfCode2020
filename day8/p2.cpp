#include<iostream>
#include<vector>
#include<set>
#include<fstream>

using namespace std;

static vector<pair<string, int>> instructions;
int accumulator = 0;

int determineSign(int value, char sign) {
    if(sign == '+')
        return value;
    return -1*value;
}

bool inSet(int i, set<int> visited) {
    for(int num : visited) {
        if(num == i)
            return true;
    } return false;
}

pair<int, int> cpu(pair<string, int> instr) {
    string instruction = instr.first;
    int value = instr.second;
    if(instruction == "nop") 
        return pair<int, int>(0, 0);
    
    if(instruction == "acc") 
        return pair<int, int>(value, 0);
    else  
        return pair<int, int>(0, --value);
}

pair<int, int> index_timesSwapped(0,0);
set<int> triedIndexes;

int findNewIndex() {
//  cout << "inside find new index ... size of tried:" << triedIndexes.size() << endl;
    for(int i=0; i<instructions.size(); i++) {
        if(inSet(i, triedIndexes))
            continue;
        if(instructions.at(i).first == "jmp" || instructions.at(i).first == "nop")
            return i;
    }
    //cout << accumulator << endl;
    cout << "ERROR" << endl;
    exit(-1);
}

void revertIndex() {
    //cout << "Inside revert, index" << index_timesSwapped.first << " swapped from " <<
    instructions.at(index_timesSwapped.first).first;
    triedIndexes.insert(index_timesSwapped.first);
    if(instructions.at(index_timesSwapped.first).first == "jmp")
       instructions.at(index_timesSwapped.first).first = "nop";
   else
       instructions.at(index_timesSwapped.first).first = "jmp";
    //cout << " to " << instructions.at(index_timesSwapped.first).first << endl;

}

void changeInstruction() {
   //cout << index_timesSwapped.first << " " <<  index_timesSwapped.second << " " << endl;
   if(triedIndexes.size() != 0)
       revertIndex();
   index_timesSwapped.first = findNewIndex(); 
   index_timesSwapped.second = 0; 
   revertIndex();
   if(triedIndexes.size() == 0)
       triedIndexes.insert(index_timesSwapped.first);
}

int main() {
    ifstream inFile("input.txt");
    string instruction;
    char sign;
    int value;

// parsing

    while(inFile >> instruction) {
        inFile >> sign;
        inFile >> value;
        value = determineSign(value, sign);
        instructions.push_back(pair<string, int>(instruction, value));
    }


// looping

    set<int> visited;
    vector<int> tried;

    for(int i=0; i<instructions.size(); i++) {
        pair<int, int> cpuResult = cpu(instructions.at(i));
        accumulator += cpuResult.first;
        i += cpuResult.second;
        //cout << "inside cpu" << endl;
        //cout << "accumulator " << cpuResult.first << " index " << cpuResult.second << endl; 
        if(inSet(i, visited)) {
            changeInstruction();
            accumulator = 0;
            i = -1;
            visited.clear();
        }
        visited.insert(i);
    }

    cout << accumulator << endl;

    return 0;
}
