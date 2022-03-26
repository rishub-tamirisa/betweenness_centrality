# Final Project Proposal
## Leading Question:
### How frequently are Amazon products purchased with other products?

## Dataset Acquisition and Processing:

**Data Format:**
We are planning to get the Amazon product co-purchasing network and ground-truth communities dataset from SNAP. We are getting 2 sets of data, one with the nodes and the neighboring nodes in one set and the other set contains the attributes of each of the nodes (category, review, title), but we will be mostly using the title/category from this dataset. The input format of the first dataset is the node followed by the neighbor of that node. It is given like # FromNodeId	  #ToNodeId. The input format of the second dataset is Id, ASIN, title, group, salesrank, similar, categories, reviews (time, user id, rating, total number of votes on the review, total number of helpfulness votes(how many people found the review to be helpful). For the first dataset, we will be using all of the information given while we plan to use a subset for the second dataset because the title and group is what we need the most out of the dataset.

**Data Correction:**
We will parse our input data by just reading the data and filtering out the values we don’t need, like the sales rank, product categorization, and product reviews. The check that we will do to ensure the input data is error-free would be to make sure none of the neighbors are node ID’s that don’t exist. 

**Data Storage:**
We plan on representing the graph with an O(V2) adjacency matrix storage system in order to completely represent the graph with direct pointer accessibility to every node/edge. We planned on this over an adjacency list as to save time in accessing every node over the course of implementing our algorithms. We also would store the metadata list of information about the products in a hash table in addition to the adjacency matrix. This would be O(V).

## Graph Algorithms

**Graphic Output of the Graph:**
We will use a force-directed graphic output algorithm to determine the shortest distance between nodes for products. The expected input for this algorithm are the nodes and edges of the graph. The output of this algorithm will be an image of the graph that best minimizes the spacing between nodes given that the edges are all weighted as 1. We may consider weighting the edges in our representation by the number of neighbors for a non-equidistant representation. Our target time complexity is O(N^2) and the space complexity is O(V^2)
 
**Betweenness Centrality:**
We will be using Brandes’ Algorithm for calculating betweenness centrality for undirected and unweighted graphs. The expected input for this algorithm is the graph itself. As mentioned earlier in the proposal, we will convert the input data to an adjacency matrix so that it can be used with our algorithm. The output of this algorithm will be the centrality values for nodes in the graph. Brande’s Algorithm would give us almost a guaranteed O(V*E) due to the nature of the algorithm working on the unweighted nature of the graph. Our target time efficiency is O(V*E) and space complexity is O(V^2).

**BFS Traversal:**
We will also implement a BFS traversal for our graph data structure. BFS takes the adjacency matrix representation of the graph and a source node as inputs. The output of our BFS algorithm will be a printed output of the nodes in order of the traversal. The theoretical / worst-case time complexity for our algorithm is O(V+E), where V is the number of vertices and E is the number of edges in the graph. The worst case space complexity is O(V^2) due to storing an adjacency matrix. Our targets for time / space complexity are O(V+E) and O(V^2), respectively.
 
## Timeline

Week 1: Create template classes
Breaking down of our project codebase into classes 
Creation of main classes
Skeleton functions

Week 2: Data storage and access algorithms
Storage access between classes
Creation of storage classes
Correction/Checking of our data structures of holding and accessing our data

Week 3: B-C algorithm creation 
Creation of a B-C algorithm that would take in the context of our data unweighted graph data structure of Amazon Products

Week 4: Implementation of B-C algorithm with data access
Connecting the B-C algorithm with our storage classes
Testing the output of the B-C algorithm
Week 5: Creation of graphical representation method and algorithm

Creation of graphic output/representation of graph
Method to iterate through dataset and output BC algorithm details
Creation of justification of placement of data structures onto the graphical representation

Week 6: Test and Finalize project 
Creation of user interface/input for product input
Testing and debugging of any part of any of previous work
