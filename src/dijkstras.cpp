// Project 5: Path Finding

#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int, int> path(int[50][50], int);

struct Tile{
    public:
        Tile *prev;
        pair<int, int> from;
        pair<int, int> to;
        int dist;
        int tracker;

        bool operator<(const Tile &t) const{
            if(dist > t.dist) { return true;}
                return false;
        }
};



// Main Execution

int main(int argc, char *argv[]) {

    // DECLARE VARIABLES
    int num, cost;
    char name;
    
    // READ IN COSTS
    cin >> num;
    map<char, int> costs; 
    for (int i = 0; i < num; i++) {
        cin >> name;
        cin >> cost;
        costs.insert(pair<char, int>(name, cost));
    }

    /*// TEST MAP OUTPUT
    for (map<char, int>::iterator it = costs.begin(); it!= costs.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }*/
    
    // READ IN MATRIX
    int row, col;
    cin >> row >> col;
    
    char matrix[row][col];

    for (int j = 0; j < row; j++) {
        for (int k = 0; k < col; k++) {
            char value;
            cin >> value;
            matrix[j][k] = value;
        }
    }

    /*// TEST MATRIX OUTPUT
    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            cout << matrix[a][b] << " ";
        }
        cout << endl;
    }*/

    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol >> endRow >> endCol;

    return 0;
}

// Function that returns adjacent neighbors


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
