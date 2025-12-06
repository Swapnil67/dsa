## Complete Graph
#### Vertices = v, & Edges = e
```
actual_edges = v * (v - 1) / 2

(actual_edges == e) => The graph is complete graph
```

```
1 ---- 2 
| \ /  |
| / \  |
3 ---- 4
```

## Bipartite graph
### What is a `bipartite graph`?
#### If you can color all the nodes in graph with only two colors such that two adjacent nodes must not have same color.
#### Odd length cycle = Not Bipartite graph
```
   1     4 
 /   \  /
2 --- 3
```

#### Even length cycle = Bipartite graph
```
   1     5 
 /   \  /
2     3
 \   /  
   4
```

### How to identify bipartite question ? 
#### When the question states that its dividing the graph into two parts

## Disjoint Set Union Or Union Find

### DSU has two main operations
#### 1. Combine two given sets
#### 2. Tell if two members (b, g) belongs to same set or not
