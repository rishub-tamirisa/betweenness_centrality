### Grade

Not Yet Competent (70%)

Must resubmit with leading question justification!

### Checklist

Leading question
- [x] Interesting question or expected result
- [ ] How the dataset and algorithms will answer this

Dataset
- [x] Data format (both neighbor and attribute dataset)
- [x] Acquire (SNAP)
- [x] Process (parse)
- [x] Store (adjacency matrix + hash table)
- [x] Data correction for potential errors (irrelevant columns, invalid IDs)

Algorithm
- [x] One graph traversal (BFS)
  - [x] Input and output
  - [x] Run-time efficiency
- [x] One algorithm not in class (graphic output)
  - [x] Input and output
  - [x] Run-time efficiency
- [x] One algorithm not in class (betweenness centrality)
  - [x] Input and output
  - [x] Run-time efficiency

Timeline
- [x] Reasonable date on every major benchmark.

### Comments

Great job on dataset, algorithms, and timeline sections! A couple of comments I have:
- Suggestion on data storage: how dense is your graph? Would it be more time/space efficient to store it with adjacency list instead of adjacency matrix?
- Your timeline plan makes sense overall; I'd make sure that everyone in the team can work without blocking each other in the week. 

Prof. Solomon and I both agree on missing details on the leading question section, unfortunately.
- The proposal states the leading question but lack a further explanation/interpretation. For example, how would you measure the frequency or frequentness (count, probability, or else)?
- We'd like to see an explicit connection between leading question and dataset + algorithms. How would your solution answer the question?
- Definition of a "successful solution" would be very helpful in evaluating the final result.

Please feel free to contact me if you have any further question or need clarification. Keep up the great work!

### Prof. Solomon's Comments

Overall this is a good proposal but you neglected to give sufficient details for your leading question.

**Leading Question**
I would have liked to see a much more detailed leading question, especially since the question as listed doesn't seem to match up to any of your algorithms. I suspect you are using betweenness centrality to answer the question but since your graph is unweighted and undirected, its really just measuring the objects which have been purchased with a *variety* of other objects, rather than the highest frequency items. 

Remember that the leading question should include an explicit description of how you plan to answer it! (Another way to think about it is what defines a 'success' for your project?)