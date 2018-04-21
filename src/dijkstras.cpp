// Project 5: Path Finding

#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct Tile{
    public:

        pair<int, int> curr;
        pair<int, int> prev;
        int cost;
        

        bool operator<(const Tile &t) const{
            if(cost > t.cost) { return true;}
                return false;
        }
};

map<pair<int, int>, pair<int, int>> dijkstras(vector<vector<int>> matrix, int row, int col, pair<int, int> start, pair<int, int>end){

    priority_queue<Tile> frontier;
    map<pair<int, int>, pair<int, int>> marked;
    Tile tile = {start, start, 0};
    frontier.push(tile);
    int totalCost = 0;

    while(!frontier.empty()){
        Tile t = frontier.top();
        frontier.pop();
        
        if(marked.count(t.curr)){
            continue;
        }
        // Check for existence of neighbors, and push back into a vector of pairs   
        vector<pair<int,int>> neighbors;   
        if (t.curr.first - 1 >= 0 && marked.count(pair<int, int>(t.curr.first - 1, t.curr.second)) == 0) {      // Upper neighbor
            pair<int,int> upper(t.curr.first - 1, t.curr.second);
            neighbors.push_back(upper);
        }
      
         if (t.curr.first + 1 < row && marked.count(pair<int, int>(t.curr.first + 1, t.curr.second)) == 0) { // Lower neighbor
            pair<int,int> lower(t.curr.first + 1, t.curr.second);
            neighbors.push_back(lower);
         }

         if (t.curr.second - 1 >= 0 && marked.count(pair<int, int>(t.curr.first, t.curr.second - 1)) == 0) {        // Left neighbor
            pair<int,int> left(t.curr.first, t.curr.second -1);
            neighbors.push_back(left);
        }
     
         if (t.curr.second + 1 < col && marked.count(pair<int, int>(t.curr.first, t.curr.second + 1)) == 0) {   // Right neighbor
            pair<int,int> right(t.curr.first, t.curr.second + 1);
            neighbors.push_back(right);
        }
        if(neighbors.empty()){
           continue;
        }

        marked[t.curr] = t.prev;

        if(t.curr.first == end.first && t.curr.second == end.second){
            totalCost = t.cost;
            break;
        }
        
        // Loop over the neighbors
        for(size_t i = 0; i <neighbors.size(); i++){
            auto it = neighbors[i];
            Tile newTile = {it, t.curr, matrix[it.first][it.second] + t.cost};   
            frontier.push(newTile);
        }

    }

    totalCost = totalCost + matrix[start.first][start.second] - matrix[end.first][end.second];
    cout << totalCost << endl;
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
    
    vector<vector<int>> matrix;

    for (int j = 0; j < row; j++) {
        vector<int> temp;
        for (int k = 0; k < col; k++) {
            char value;
            cin >> value;
            temp.push_back(costs[value]);
        }
        matrix.push_back(temp);
    }

    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol >> endRow >> endCol;

    pair<int, int> start (startRow, startCol);
    pair<int, int> end (endRow, endCol);
    map<pair<int, int>, pair<int, int>> marked = dijkstras(matrix, row, col, start, end);

    // Output marked pairs
    vector<pair<int, int>> path;
    while (end != start) {
        path.push_back(end);
        end = marked.find(end)->second;
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

// Function that returns adjacent neighbors


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
