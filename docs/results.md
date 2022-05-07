# Written Report

## BFS Traversal <br>


## Betweenness Centrality (Brandes Algorithm) <br>
### This algorithm measures the centrality of a node in a graph based on the unweighted shortest path options. It is run in O(VE) time and uses O(V+E) space complexity, which is better than our anticipated O(V^2) space complexity. <br>
We utilized a series of test cases starting at different nodes of different sizes to ensure this algorithm worked properly. When run with the full file, this returns the top 10 list of most common product nodes, their titles, and centralities within the subgraph of the chosen starting and ending nodes. Here is an example using starting node 1 and ending node 404753: ![Betweenness Centrality Example](/BC.png) <br>

## Force Directed Graph Drawing (Fruchterman - Reingold Representation) <br>
### This algorithm utilizes the inverse square law of forces to connect edges between nodes and represents it in a neat visual format. It is run in O(V^2) time and uses O(V+E) space complexity. We create an output image formatted in an SVG file. <br>
Highlighting our function, we have several key pieces of the algorithm broken up into helper functions that organize the functionality of our code very well. We have: <br>
- `calc_forces(float x, float y)`: Gives the edge list the weight it needs to space itself apart from other vertices
- `normalize_bc()`: Normalizes the betweenness - Centrality output values within a range, as centrality value cannot be directly used 
- `init_pos(int width, int height)`:  Initializes the position of vertex positions randomly within frame
- `set_dims(int& width, int& height)`: Scales the SVG output to fit the max height and width from the Fruchterman-Reingold algorithm and readjusts vertexes to stay inbounds
- `draw_graph(std::string loc, int width, int height, bool ID)`: Creates the SVG file with the location, and draws the output with corresponding betweenness-centrality based output color-coding 

In terms of the full scale project, it is run as the graph visualizer in our `main.cpp` file. To ensure this function properly worked, multiple edge test cases were run to ensure it could create the full graph with different starting nodes, sizes, and dimensions. <br>
The example with starting node at 100000, a size of 500, betweenness centrality of 10, dimensions 1000 x 1000, and BFS starting node/ending node of 1 and 404753 can be seen here: ![Final Graph](/Final1.png) <br>
The larger green circles represent the most frequently visited product nodes, which are also listed in the Betweenness Centrality section. The node values can also be toggled on and off in the input statement (toggled off here for visualization). <br>

## Answer to Leading Question <br>
To reiterate, our leading question was “What Amazon products are ‘critical’ in how customers will purchase different products?”