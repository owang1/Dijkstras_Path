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

map<pair<int, int>, pair<int, int>> dijkstras(int *matrix, int row, int col, pair<int, int> start, pair<int, int>end){

    priority_queue<Tile> frontier;
    map<pair<int, int>, pair<int, int>> marked;
    Tile t = {NULL, pair<int, int>(0,0), pair<int,int>(0,0), 0, 0};
    frontier.push(t);

    while(!frontier.empty()){
        Tile curr = frontier.top();
        frontier.pop();
            
    if (t.from.first - 1 >= 0 && marked.count(pair<int, int>(t.from.first - 1, t.from.second)) > 0) {      // Upper neighbor
         continue;
     }
  
     if (t.from.first + 1 < row && marked.count(pair<int, int>(t.from.first + 1, t.from.second)) > 0) { // Lower neighbor
         continue;
    }

     if (t.from.second - 1 >= 0 && marked.count(pair<int, int>(t.from.first, t.from.second - 1)) > 0) {        // Left neighbor
         continue;
    }
 
     if (t.from.second + 1 < col && marked.count(pair<int, int>(t.from.first, t.from.second + 1)) > 0) {   // Right neighbor
          continue;
     }
    

     }
    return marked;
}


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
