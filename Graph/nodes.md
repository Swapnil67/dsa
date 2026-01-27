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

## Dijkstra Algorithm
- Finds the shortest path from a single starting node to all other nodes in a graph with non-negative edge weights.

### Disadvantages
- Can't work with -ve edges
- Won't detect cycle if we have -ve edges

## Bellman-Ford Algorithm
- Rinds the shortest path from a single starting node to all other nodes in a graph with non-negative edge weights.
- Here we need to relax V vertices only V - 1 times
- Works in directed edges and if undirected then there should not be a -ve edge
- If we are given undirected edge we need to convert it to directed edge.
- Helps detect -ve cycle.

## Floyd Warshall Algorithm
- Multi source shortest path detection algorithm.
- helps us detect negative cycle as well.

### Disadvantages
- Can't work with -ve edges
- Won't detect cycle if we have -ve edges

## Spanning Tree
- It has all vertices of graph 'G'
- It has (V - 1) no of edges

#### Take the following graph G(V, E) 
#### V - No. of vertices
#### E - No. of Edges
```
A ---- B
|      |
|      |
C ---- D
```
#### Some possible spanning trees
```
A ---- B               A ---- B
|                             |
|                             | 
C ---- D               C ---- D
```

## Minimum Spanning Tree (Min Weight)
```
      5
  A ---- B
2 |      | 3
  |      |
  C ---- D
      8
```

#### Some possible min spanning trees
```
      5          |                      |       5          |          5  
   A ---- B      |       A      B       |    A ---- B      |       A ---- B        
 2 |             |     2 |      | 3     |           | 3    |     2 |      | 3  
   |             |       |      |       |           |      |       |      |  
   C ---- D      |       C ---- D       |    C ---- D      |       C      D      
      8          |          8           |       8          |        

      (15)                 (13)                (16)                (10) (MST)
``` 
