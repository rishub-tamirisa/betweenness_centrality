# raunakb2-aparik31-pr16-rishubt2
# Amazon Product Analysis 
*309fc45c-e3d6-4289-9f69-65753fd6980c*

## Core Project File Structure
├── docs <br>
├── test_output<br>
│   ├── GraphDrawn_SizeK.svg<br>
│   ├── GraphDrawn_SizeK+1.svg<br>
│   └── etc.<br>
├── 225FPDataset<br>
│   ├── amazon-meta-reduced.txt<br>
│   ├── com-amazon-reduced.ungraph.txt<br>
│   └── test.txt<br>
├── catch.hpp<br>
├── catchmain.cpp<br>
├── clean.py<br>
├── graph.cpp<br>
├── graph.h<br>
├── NodeReader.cpp<br>
├── NodeReader.h<br>
├── Makefile<br>
└── README.md<br>



## Run Tests with `tests.cpp` <br>
First make the `test` executable by running `make test` in the command line. <br>
Run the default test suite by executing `./test` in the command line. <br>
- To filter test cases by tags, insert either `[graph]` and `[full]` tags when executing.
- Note: tests on the full dataset are not run by default, use `[full]` to run them.

## Run `main`
First make the `graph` executable by running `make` in the command line. <br>
Run the contents of `main.cpp` by executing `./graph` in the command line

### Workflow

On local branch: <br>
`git add` changes <br>
`git commit -m` message <br>
`git push` <br>
Create and merge pull request via github.com UI

