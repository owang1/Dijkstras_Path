// Challenge 10: Minimum Spanning Tree

#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int, int> prim(int[26][26], int);

struct Entry{
    public:
        int from;
        int dist;
        int to;

        bool operator<(const Entry &e) const{
            if(dist > e.dist){ return true;}
                return false;
    }
};

map<int, int>  prim(int graph[26][26], int num){
    priority_queue<Entry> frontier;
    map<int, int> marked;
    Entry e = {0,0,0};
    frontier.push(e);

    while(!frontier.empty()){
        Entry curr = frontier.top();
        frontier.pop();
        if(marked.count(curr.to) > 0){
            continue;
        }
        marked[curr.to] = curr.from;
        for(int i = 0; i < num; i++){
            if(graph[curr.to][i] != -1){
                frontier.push({curr.to, graph[curr.to][i], i});
            }        
        }
    }
    return marked;
}

// Main Execution
int main(int argc, char *argv[]) {
    int num;
    int input;
    int i = 0;
    while(cin >> num){                      // num for rows/columns
        if(i > 0){
            cout << "\n";
        }
    int matrix[26][26];
    // Read in adjacency matrix
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> input;
            matrix[i][j] = input;
        }
    }
    // Find the total weight
    map<int, int> marked = prim(matrix, num);
    int totalWeight = 1;
    for(map<int,int>::iterator it =marked.begin(); it!= marked.end(); ++it){
        totalWeight += matrix[it->first][it->second];
    }
    cout << totalWeight << "\n";
    set<string> myset;
    // Output edges in alphabetical order by inserting to set
    for(map<int,int>::iterator it = marked.begin(); it!=marked.end(); ++it){
        string c = "";
        if(it->first == it->second){
            continue;
        }
        if(it->first < it->second){
            c.push_back(it->first + 'A');
            c.push_back(it->second + 'A');
        }else{
            c.push_back(it->second + 'A');
            c.push_back(it->first + 'A');
        }
        myset.insert(c);
    }
    // Print out results
    for(set<string>::iterator it = myset.begin(); it!= myset.end(); it++){
        cout << *it << '\n';
    }
    i++;
    }
    return EXIT_SUCCESS;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
