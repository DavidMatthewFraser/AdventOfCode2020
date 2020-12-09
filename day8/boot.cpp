#include<iostream>
#include<vector>
#include<set>
#include<fstream>

using namespace std;

static vector<pair<string, int>> instructions;

int determineSign(int value, char sign) {
    if(sign == '+')
        return value;
    return -1*value;
}

bool inVisited(int i, set<int> visited) {
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
        cout << instruction << " " << sign << " " << value << endl;
    }

    set<int> visited;
    int accumulator = 0;

    for(int i=0; i<instructions.size(); i++) {
        pair<int, int> cpuResult = cpu(instructions.at(i));
        accumulator += cpuResult.first;
        i += cpuResult.second;
        if(inVisited(i, visited))
            break;
        visited.insert(i);
    }

    cout << accumulator << endl;

    return 0;
}
