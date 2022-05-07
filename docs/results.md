# Written Report




## Betweenness Centrality (Brandes Algorithm) <br>
This algorithm measures the centrality of a node in a graph based on the unweighted shortest path options. It is run in O(VE) time and uses O(V+E) space complexity, which is better than our anticipated O(V^2) space complexity. <br>

Our main algorithm `betweenness_centrality(int k)` employs `Brandes_BFS_helper(int s, std::unordered_map<int,std::vector<int>>& pred, std::unordered_map<int, int>& sigma, std::stack<int>& stack)` to find shortest paths for all the nodes and stores it. This is an implementation of BFS apart from the main standalone algorithm. We needed this to be done in order to significantly clean up the code for Brandes, and act as an effective re-implementation of the BFS at the same time <br>
 
We followed the Brandes algorithm from the original paper from its pseudocode to generate our own implementation of it. <br>

We utilized a series of test cases starting at different nodes of different sizes to ensure this algorithm worked properly. When run with the full file, this returns the top 10 list of most common product nodes, their titles, and centralities within the subgraph of the chosen starting and ending nodes. Here is an example using starting node 1 and ending node 404753: ![Betweenness Centrality Example](BC.png) <br>

## Force Directed Graph Drawing (Fruchterman - Reingold Representation) <br>
This algorithm utilizes the inverse square law of forces to connect edges between nodes and represents it in a neat visual format. It is run in O(V^2) time and uses O(V+E) space complexity. We create an output image formatted in an SVG file. <br>
Highlighting our function, we have several key pieces of the algorithm broken up into helper functions that organize the functionality of our code very well. We have: <br>
`calc_forces(float x, float y)`: Gives the edge list the weight it needs to space itself apart from other vertices <br>
`normalize_bc()`: Normalizes the betweenness - Centrality output values within a range, as centrality value cannot be directly used <br>
`init_pos(int width, int height)`:  Initializes the position of vertex positions randomly within frame <br>
`set_dims(int& width, int& height)`: Scales the SVG output to fit the max height and width from the Fruchterman-Reingold algorithm and readjusts vertexes to stay inbounds <br>
`draw_graph(std::string loc, int width, int height, bool ID)`: Creates the SVG file with the location, and draws the output with corresponding betweenness-centrality based output color-coding <br>

In terms of the full scale project, it is run as the graph visualizer in our `main.cpp` file. To ensure this function properly worked, multiple edge test cases were run to ensure it could create the full graph with different starting nodes, sizes, and dimensions. <br>
The example with starting node at 100000, a size of 500, betweenness centrality of 10, dimensions 1000 x 1000, and BFS starting node/ending node of 1 and 404753 can be seen here: ![Final Graph](Final1.png) <br>
The larger green circles represent the most frequently visited product nodes, which are also listed in the Betweenness Centrality section. The node values can also be toggled on and off in the input statement (toggled off here for visualization). <br>

## BFS Traversal <br>

We have a standalone implementation of the BFS that we use in the shortest path between 2 given nodes. Its a simple traversal algorithm that provides the output node ID values. <br> 

We have much more interesting implementations of our BFS algorithms within our `Brandes_BFS_helper(int s, std::unordered_map<int,std::vector<int>>& pred, std::unordered_map<int, int>& sigma, std::stack<int>& stack)` function and `connected_subgraph(int root, int size)` algorithms. <br>

The Brandes BFS Helper function is very useful for the Brandes Implementation in that finds the shortest paths for a node to every other node in list of paths. <br>

The Connected Subgraph algorithm takes into account that it is a completely connected graph and outputs a connected subgraph of the main graph given a node and the size of the nodes we want in the subgraph. This runs in O(V + E) and runs BFS to find the shortest paths to go from the given node to all the other nodes within the size that we ask of it. 


## Answer to Leading Question <br>
To reiterate, our leading question was “What Amazon products are ‘critical’ in how customers will purchase different products?” We can figure this out by finding out which node is traveled to the most via BFS. To answer this question, we attempted to run our program on the entire data set, but given it consists of 300,000+ nodes, the time it would take for it to fully execute would be days, considering our algorithms run in O(V^2) time. Instead, we decided to take smaller subsets of the data and opposing connected graph components to figure out which list of product nodes were the most visited within a size of 1000 nodes. Of course, this differed with the central node because different subgraphs with different connected components are being compared. But after a handful of test cases, we noticed a pattern: given an input central node, there was a predictable category of which node was visited the most. For example, given the central node 219526, a book titled “The Algorithm Design Manual”, the most visited node via BFS was another book at node 245137 titled “Introduction to Algorithms, Second Edition”. This logically makes sense, as they both fall into the category of books and algorithms. So if a producer wanted to implement this product for one of their products, they could set the central node as the product they are trying to sell and find out the critical products via BFS. If we took the time to run our entire dataset, which could take days, there would be a singular most critical product that related everything in this dataset.
