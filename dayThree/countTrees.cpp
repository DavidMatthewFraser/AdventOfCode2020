#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int countTrees(vector<string> trees, int right) {
    int numTrees = 0;
    int locationX = 0;
    for (string t : trees) {
        if (t.at(locationX % t.length()) == '#') {
            numTrees++;
        }
        locationX += right;
    }
    cout << numTrees << endl;
    return numTrees;
}
int everyOther(vector<string> trees) {
    vector<string> EOOTree;
    int x = 1;
    for(string t : trees) {
        if(++x % 2 != 0)
            continue;
        EOOTree.push_back(t);
    }
    return countTrees(EOOTree, 1);

}

int main() {
    ifstream infile("tree.txt");
    string lineOfTrees;
    vector<string> trees;

    while (infile >> lineOfTrees ) {
        trees.push_back(lineOfTrees);
    }
    long answer = 1;
    answer *= countTrees(trees, 1);
    answer *= countTrees(trees, 3);
    answer *= countTrees(trees, 5);
    answer *= countTrees(trees, 7);
    answer *= everyOther(trees);
    cout << answer << endl;
    return 0;
}
