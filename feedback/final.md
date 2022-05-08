# Final Project Grade

Awesome work, everyone! I hope it was a rewarding experience for you all :D

Here are some parts of the final project grade (apart from contract, proposal, and midproject checkin).

If you would like to showcase your work, feel free to clone this repository and host it on your personal git account (github-dev.cs.illinois.edu is being retired soon).

## Development Log

### Grade 

Sophisticated (100%)

Development Log (5 pts)
- [x] >= 4 development logs

### Comments

______________________________________________________________

## Presentation
### Content Grade

Sophisticated (100%)

Final Presentation Content (10 pts)
- [x] A short summary of the goals set for the project and a statement of whether the goals were met.
- [x] Some highlights of the development process (dataset, major design choices, and testing)
- [x] Results of each method
- [x] Concluding thoughts (what was learned and what you would do next)

### Skills Grade

Sophisticated (100%)

Final Presentation Skills (5 pts)
- [x] Roughly equal responsibilities
- [x] Appropriate and understandable visual aids

### Comments

I'm curious why the vocabulary book is the most "critical" node from the CS book? Is it simply because many people bought the vocab book so it becomes a large-degree node hub?

______________________________________________________________

## Written Report
### Grade

Sophisticated (100%)

Written Report (5 pts)
- [x] There are clear descriptions, figures, or tables of each method's output on the full target dataset.
- [x] Projects findings

### Comments

The report has a lot of details. More discussions about the findings would be interesting to see. For example, what items do those large green circles represent? What do you observe in relationship between items and their centrality?

By the way, you can break different paragraphs in Markdown (.md) by leaving an empty line in between.

## README

### Grade

Sophisticated (100%)

Readme (5 pts)
- [x] The linkage and location of all major code, data, results, and deliverable files
- [x] The necessary commands to run the assignment, include instructions for selecting the input dataset and output location
- [x] Instructions on how to reproduce the tests

### Comments

On top of the required components, great job on including development workflow and citations.

Typically we write the instruction using code blocks to emphasize the steps. For example, to build the test:

```
make test
```

Then, we can run the test.

```
./test
```

We can also select only specific test cases.

```
./test [graph][insert]
```

______________________________________________________________

## Code

### Goals Grade

Sophisticated (100%)

Code Goals (30 pts)
- [x] All methods listed in goals were successfully developed
- [x] All algorithms can be run on the full target dataset
- [x] All algorithms are thoroughly tested

### Execution Grade

Sophisticated (100%)

Code Execution (5 pts)
- [x] All methods and tests can be run
- [x] Ability to alter or adjust the input data and output location

### Efficiency Grade

Sophisticated (100%)

Code Efficiency (5 pts)
- [x] Code adheres to the expected Big O
- [x] There is no obvious inefficiency
- [x] Complete on target datasets

### Organization Grade

Partly Competent (80%)

Code Organization (5 pts)
- [x] Code is human-readable (only `*.h`)
- [ ] Unnecessary or obsolete code is completely absent

### Comments

Nice and concise CLI with "help" option for guideline. Maybe we can improve the output spacing a bit better, e.g. tabular format (aligning columns) for Betweeness Centrality and new lines with indentation for each node on BFS Path.

The suggested primary command runs in \~2 minutes on my vm.

The only issue is the code organization. Although comments in `*.h` explains lots of user-facing details, the code in `*.cpp` lacks comments for future developers. There are also some unnecessary code like `lodepng`,`.DS_Store`, `.vscode`, `.devcontainer`.
