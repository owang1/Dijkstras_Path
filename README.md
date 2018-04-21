Project 05: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

-----------------------------------------------------------------------------

Please note: The output files output1.txt and output2.txt were changed to match the output from our dijkstras.cpp after confirmation with Nate Kremer-Herman. Our diff1.txt and diff2.txt show the differences from the original output files and the output files created by our dijkstras.cpp code. The differences are as summarized here:
    - For input2.txt, our dijkstras implementation chose to go to 6 4 instead of 5 5
    - For input2.txt, our dijkstras implementation chose to go to 3 1 instead of 2 2, and 3 2 instead of 2 3

Group contributions:
    Yejee Oh (yoh1)
        - Worked on dijkstras.cpp
        - Wrote generate_map.py
        - Ran tests (Question 3 in README.md)
        - 10/10 would work with again
    Olivia Wang (owang1)
        - Worked on dijkstras.cpp
        - Worked on README.md (Question 1, 2, 4)
        - 10/10 would work with again

-----------------------------------------------------------------------------
Questions:

1. We verified that the web application works by running ./src/python-server.py

2. Confirmed (use http://student01.cse.nd.edu:9777)
    The web application works on the student01 machine, at port 9777.
3. 

Trial 1:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023996--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450931--------|3.757812--------|
|500-------------|3.322494--------|17.402344-------|
|1000------------|14.930730-------|66.042969-------|

Trial 2:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450930--------|3.757812--------|
|500-------------|3.329493--------|17.398438-------|
|1000------------|14.984721-------|66.058594-------|

Trial 3:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002999--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.300781--------|
|100-------------|0.102983--------|1.800781--------|
|200-------------|0.450931--------|3.753906--------|
|500-------------|3.339492--------|17.402344-------|
|1000------------|14.951726-------|66.058594-------|

Trial 4:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.140625--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023995--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.446931--------|3.757812--------|
|500-------------|3.292498--------|17.406250-------|
|1000------------|14.965723-------|66.035156-------|

Trial 5:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.144531--------|
|20--------------|0.004998--------|1.164062--------|
|50--------------|0.023996--------|1.304688--------|
|100-------------|0.101983--------|1.800781--------|
|200-------------|0.450931--------|3.757812--------|
|500-------------|3.330493--------|17.402344-------|
|1000------------|14.875738-------|66.042969-------|

Average:
| N              | Elapsed Time   | Memory Usage   |
|----------------|----------------|----------------|
|10--------------|0.002998--------|1.143750--------|
|20--------------|1.143750--------|1.164062--------|
|50--------------|0.023995--------|1.303907--------|
|100-------------|0.102183--------|1.800781--------|
|200-------------|0.450131--------|3.757031--------|
|500-------------|3.322894--------|17.402344-------|
|1000------------|14.941728-------|66.047656-------|

4. 

- How did you represent the map as a graph?
    We represented the map as a graph using a 2D vector called vector<vector<int>> matrix.
    It is a vector of dimension row x col, constants read in from the input stream. The 
    integer values within this 2D vector give the cost to leave each vertex.

- Explain which graph representation you used and how you determined the relationship between vertices
 include the edges and their weights.
    To find the weights, we first created a map called map<char, int> costs, which mapped
    each char key to its corresponding cost value. This way, we could later convert the chars 
    from the raw input into the correct integer weights.
    
    We used a nested for loop to read in and push back the values of the graph into our 2D
    vector matrix. Using a 2D vector was effective because it contained information on the
    coordinates as well as the cost for each tile, as an int. We didn't to create an 
    adjacency list or matrix, because the adjacent neighbors of each tile could be easily 
    found by looking at the elements to the left, right, up, and down (when they exist). 

- What is the complexity of your implementation of Dijkstra's Algorithm?
    O(V^2) where V is the number of vertices in the graph (V = row * col).   
    
- Explain this by describing which data structures you used and how you used them to implement
  path finding.  

    This implementation uses a priority queue of Tile structs called frontier. The Tile struct
    is a 3 tuple that contains 3 pieces of information: curr (coordinates of that tile), prev,
    and cost (lowest known cost to get to that tile). The first tile pushed into the frontier 
    is located at the start position. In the proceeding while loop the minimum tile (by cost)
    is popped off each time. 

    To save the path, we had a marked map: map<pair<int, int>, pair<int, int>> marked.
    Lastly, we had a vector<pair<int,int>> called neighbors, which stores the coordinates of
    each of the neighbors of the current tile (maximum of 4). A series of if statements checks
    the existence of those neighbors, which are an O(N) operation where N is the number of 
    vertices. Since you have to check each tile until the target is reached, you would multiply
    this value by N, getting a final complexity of O(N^2).

- How well does your implementation scale?
    The time complexity of O(N^2) is not the best in terms of scalability. A source from stackoverflow.com
    https://stackoverflow.com/questions/9420014/what-does-it-mean-scalability mentions that 
    scalability is roughly defined as "a linear increase in output requested only demands
    a linear increase in resources," which is not the case in an O(N^2) implementation.

- Explain what effect N(size of the map) had on your dijkstras pathfinding component in terms of execution 
  time and memory usage? 
    As suggested by the time complexity as well as the hash tables, N had a nonlinear effect on the
    dijkstras pathfinding component.
    There is a substantial gap when comparing the average memory usage for smaller
    datasets to that of larger datasets like when N = 1000. The time and memory usages increased
    more than just linearly, which makes sense considering the theoritical time complexity of
    O(N^2). Memory usage stayed relatively small for N values <= 100, but increased by almost 
    4x going from N=500 to N=1000, even though that was a linear increase.