# raunakb2-aparik31-pr16-rishubt2
# Amazon Product Analysis 
*309fc45c-e3d6-4289-9f69-65753fd6980c*

## Core Project File Structure
* docs <br>
  * test_output<br>
  * GraphDrawn_SizeK.svg <br>
  * GraphDrawn_SizeK+1.svg <br>
  * etc.<br>
* 225FPDataset<br>
  * amazon-meta-reduced.txt<br>
  * com-amazon-reduced.ungraph.txt<br>
  * test.txt<br>
* tests.cpp <br>
* main.cpp <br>
* catch.hpp<br>
* catchmain.cpp<br>
* clean.py<br>
* graph.cpp<br>
* graph.h<br>
* NodeReader.cpp<br>
* NodeReader.h<br>
* Makefile<br>
* README.md<br>

## Description of File Interaction

The `Graph` class headers and definitions are stored in `graph.h` and `graph.cpp`. <br>
The `NodeReader` class headers and definitions are stored in `NodeReader.h` and `NodeReader.cpp`. <br>
`clean.py` is a python script that cleans the SNAP dataset accordinig to our specifications (no invalid Node IDs, no discontinued products).

`NodeReader` interacts with `Graph` by reading in the user-specified dataset with `readInEdgeList`, which takes a `Graph` as an argument. The test suite is located in `test.cpp` and the main output executable is located in `main.cpp`. Instruction on usage and output of these executables is described below.

The provided `Makefile` contains `make` targets for both the test suite and driver code. Header files, `cpp` files are all linked and compiled via the `Makefile`.


## How to Use the code and Test Suite

### Run Tests with `tests.cpp` <br>

First make the `test` executable by running `make test` in the command line. <br>
Run the default test suite by executing `./test` in the command line. <br>
* To filter test cases by tags, insert either `[graph]` and `[full]` tags when executing.
* The `[graph]` cases have further subdivisions of tags that test individual function correctness, these are all the tags:
  * `[insert]` which tests `insertVertex` 
  * `[incident]` which tests `incidentEdges`
  * `[reader]` which tests the `NodeReader` label read-in functionality
  * `[BFS]` which tests `BFS` shortest path correctness and connected subgraph algorithm
  * ***`[draw]` which tests the `draw_graph` function and outputs to the `test_output` directory***
* Note: tests on the full dataset are not run by default, use `[full]` to run them. Example usage is `./test [full]`. <br>
  * These tests test data cleaning, betweenness centrality, graph drawing, and BFS on the full dataset as well. 
  * Default compilation of the tests on the full dataset is ~1min 30s.

Example usage of the default test suite is `./test [graph][insert]`, which would inform the correctness of vertex insertion.

### Run driver code with `main.cpp`
First make the `graph` executable by running `make` in the command line. <br>
Run the contents of `main.cpp` by executing `./graph` in the command line followed by command line arguments. You must follow the format: <br>

`./graph [input loc] [input labels] [output loc] [starting node] [size] [# of BC vals] [img x dim] [img y dim] [BFS start ID] [BFS end ID]`

Example usage is `./graph "225FPDataset/com-amazon-reduced.ungraph.txt" "225FPDataset/amazon-meta-reduced.txt" "" 100000 500 10 500 500 1 40475`. <br>
This would run betweenness centrality and force directed graph drawing on a subgraph with `500` nodes starting at the node with ID `100000`. Betweenness centrality will return the top `10` central nodes. The size of the graph output frame will be `500` x `500` pixels. A shortest path will be printed from the node with ID `1` to the node with ID `40475`. The input file dataset is located at `225FPDataset/com-amazon-reduced.ungraph.txt` and the labels were provided at `225FPDataset/amazon-meta-reduced.txt`. Because no `output loc` was specified, the graph drawing `SVG` output will be in the general project directory.

## How to view the Graph Drawing Output:
To view the graph drawing output, an `SVG` renderer must be used. The easiest method is to open the `SVG` file in a standard internet browser.
* SVG was used because it is a human-readable image format that supports vector graphics, and requires no external libraries. The image can be viewed natively in Github or by opening the image from its file location in a default internet browser (Google Chrome, etc.)
### Workflow

On local branch: <br>
`git add` changes <br>
`git commit -m` message <br>
`git push` <br>
Create and merge pull request via github.com UI

## Dataset Citation
### Network Data
http://snap.stanford.edu/data/com-Amazon.html <br>
J. Yang and J. Leskovec. Defining and Evaluating Network Communities based on Ground-truth. ICDM, 2012. <br>

### Label Data
http://snap.stanford.edu/data/amazon-meta.html <br>
J. Leskovec, L. Adamic and B. Adamic. The Dynamics of Viral Marketing. ACM Transactions on the Web (ACM TWEB), 1(1), 2007.
