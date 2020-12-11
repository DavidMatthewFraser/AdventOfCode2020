#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int smaller(int x, int y) {
    if(x<y) 
        return x;
    return y;
}

void printBoard(vector<vector<pair<char, char>>> tiles) {
    for(vector<pair<char, char>> v : tiles) {
        for(pair<char, char> c : v) {
            cout << c.first;
        } cout << endl;
    }
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
    int prev = 0;
    int finalocc = 1;
   // printBoard(tiles);
    while (prev != finalocc) {
        prev = finalocc;
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                int occurances = 0;
                int up = row;
                int right = cols-col-1;
                int left = col;
                int down = rows-row-1;
                int upright = smaller(up,right);
                int downright = smaller(down,right);
                int downleft = smaller(down, left);
                int upleft = smaller(up, left);
                // Epic Chess Logic
                if (tiles.at(row).at(col).first == '.')
                    continue;
                // North
                for(int i=0; i<up; i++) {
                    int r = (i*(-1)) - 1;
                    if (tiles.at(row+r).at(col).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col).first == 'L') {
                        break;
                    }

                }

                // North East
                for(int i=0; i<upright; i++) {
                    int r = (i*(-1)) - 1;
                    int c = (i*(1)) + 1;
                    if (tiles.at(row+r).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col+c).first == 'L') {
                        break;
                    }

                }

                // East
                for(int i=0; i<right; i++) {
                    int c = (i*(1)) + 1;
                    if (tiles.at(row).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row).at(col+c).first == 'L') {
                        break;
                    }

                 }

                // South East
                for(int i=0; i<downright; i++) {
                    int r = (i*(1)) + 1;
                    int c = (i*(1)) + 1;
                    if (tiles.at(row+r).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col+c).first == 'L') {
                        break;
                    }

                 }

                // South 
                for(int i=0; i<down; i++) {
                    int r = (i*(1)) + 1;
                    if (tiles.at(row+r).at(col).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col).first == 'L') {
                        break;
                    }

                 }

                // South West
                for(int i=0; i<downleft; i++) {
                    int r = (i*(1)) + 1;
                    int c = (i*(-1)) - 1;
                    if (tiles.at(row+r).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col+c).first == 'L') {
                        break;
                    }

                 }

                // West
                for(int i=0; i<left; i++) {
                    int c = (i*(-1)) - 1;
                    if (tiles.at(row).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row).at(col+c).first == 'L') {
                        break;
                    }

                 } 

                // North West
                for(int i=0; i<upleft; i++) {
                    int r = (i*(-1)) - 1;
                    int c = (i*(-1)) - 1;
                    if (tiles.at(row+r).at(col+c).first == '#') {
                        occurances++;
                        break;
                    }
                    if (tiles.at(row+r).at(col+c).first == 'L') {
                        break;
                    }
                 } 

                if(occurances >= 5) {
                    tiles.at(row).at(col).second = 'L';
                } else if(occurances == 0) {
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
