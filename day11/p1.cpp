#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void printBoard(vector<vector<pair<char, char>>> tiles) {
    for(vector<pair<char, char>> v : tiles) {
        for(pair<char, char> c : v) {
            cout << c.first;
        } cout << endl;
    }
}

void calcAction() {
    int x = 0;
}

void doAction() {
    int x = 0;
}

int main() {
    ifstream infile("input.txt");
    char tile;
    vector<vector<pair<char, char>>> tiles;
    int rows, cols;
    string line;

    while(getline(infile, line)) {
        vector<pair<char,char>> row;
        for(char c : line) {
            row.push_back(pair<char, char>(c, c));
        }
        tiles.push_back(row);
    }

    rows = tiles.size();
    cols = tiles.at(0).size();
    int finalocc = 0;
   // printBoard(tiles);
    for(int i=0; i<5001; i++) {
        //cout << "====== NEW BOARD =======" << endl << endl;
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if (tiles.at(row).at(col).first == '.')
                    continue;
                bool upper = !(row == 0);
                bool right = !(col == cols-1);
                bool lower = !(row == rows-1);
                bool left = !(col == 0);
                int occupied = 0;
                // north 
                if(upper) {
                    if (tiles.at(row-1).at(col).first == '#') {
                        occupied++;
                    }
                }

                // north east
                if(upper && right) {
                    if (tiles.at(row-1).at(col+1).first == '#') {
                        occupied++;
                    }
                }

                // east
                if(right) {
                    if (tiles.at(row).at(col+1).first == '#') {
                        occupied++;
                    }
                }

                // south east
                if(lower && right) {
                    if (tiles.at(row+1).at(col+1).first == '#') {
                        occupied++;
                    }
                }

                // south
                if(lower) {
                    if (tiles.at(row+1).at(col).first == '#') {
                        occupied++;
                    }
                }

                // south west
                if(lower && left) {
                    if (tiles.at(row+1).at(col-1).first == '#') {
                        occupied++;
                    }
                }

                // west
                if(left) {
                     if (tiles.at(row).at(col-1).first == '#') {
                        occupied++;
                    }
                }

                // north west
                if(upper && left) {
                    if (tiles.at(row-1).at(col-1).first == '#') {
                        occupied++;
                    }
                }

                if(occupied >= 4) {
                    tiles.at(row).at(col).second = 'L';
                } else if(occupied == 0) {
                    tiles.at(row).at(col).second = '#';
                }

            }
        }
        finalocc = 0;
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(tiles.at(row).at(col).second == '#')
                    finalocc++;
                tiles.at(row).at(col).first = tiles.at(row).at(col).second;
            }
        }
        //printBoard(tiles);
    }
    cout << "final occ " << finalocc << endl;
    return 0;
}
