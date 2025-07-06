## Tree
```
                      1
                /          \  
               2             3
            /    \         /    \
           4      5       6      7
          / \     / \    / \    / \
        8    9   10 11  12  13 14  15
```
              

1. Non linear Data Structure
2. Collection of n nodes & (n-1) incoming edges where one of the node is root node.
3. Degree of a node - No. of children it has.
3. Degree of a tree - Max degree a node can have.

#### Note
#### length of path == No. of edges

#### Depth of a Node
- It is the length of the path from the root node to itself

#### Height of a node
- It is the length of the path from itself to the longest leaf node
- Height of a leaf node will always be zero

#### Height of a tree
- Height of a root node

# -----------------------------------------------------------------------------

#### Complete binary tree
- A BT is a complete BT if all the levels are completely filled except
possibly the last level and the last level should have all the keys as left as possible.
## Complete Binary Tree
```
                      1
                /          \  
               2             3
            /    \         /   \
           4      5       6     NULL
```

## Not Complete Binary Tree
```
                      1
                /          \  
               2             3
            /    \         /    \
           4      5       NULL   7
```

#### Perfect Binary Tree
- A BT with all internal nodes having 2 children and all leaf nodes lying at the same level
is called perfect BT.
- Every Perfect BT is a complete binary tree.
## Perfect & Complete Binary Tree
```
                      1
                /          \  
               2             3
            /    \         /   \
           4      5       6     7
```

## Not Perfect but Complete Binary Tree
```
                      1
                /          \  
               2             3
            /    \         /   \
           4      5       6     NULL
```

#### Full Binary Tree
- A binary tree with either 0 or 2 children
- L = No. of Leaf Nodes
- I = No. of Internal Nodes
- N = Total no of nodes in tree
$$
L = I + 1   
$$
$$
N = I + L   
$$

- Space complexity of internal nodes
- Say there are x internal nodes
$$
N = x + x + 1
$$
$$
N = 2x + 1
$$
$$
N - 1 = 2x
$$
$$
x = (N - 1) / 2
$$

- Therefore we can say that x = O(n)

# -----------------------------------------------------------------------------

#### Min no of nodes possible in a binary tree of height 'h' ?
- h + 1  (left or right skewed binary tree)
- h = 2, nodes = h + 1 = 3
```
        1
      /
    2 
  /    
4     
```

#### Max no of nodes possible in a binary tree of height 'h' ?
## Binary Tree
                      1                           L-1 = 2^0 nodes
                /          \  
               2             3                    L-2 = 2^0 + 2^1 nodes
            /    \         /   \ 
           4      5       6     7                 L-3 = 2^0 + 2^1 + 2^2 nodes

                                                  L-(h+1) = 2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h nodes

```
L-(h+1) = 2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h                    - Total nodes of tree with 'h' height
```

- Geometric Progression
$$
        = a*r^0 + a*r^1 + a*r^2 + a*r^3 + ..... + a*r^n          
$$
$$
        = a(r^n - 1)/(r - 1)
$$

- Using GP we can say
```
        = 1 [2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h]
        = 2^(h+1) - 1
        = (2^(h+1) - 1) / (2 - 1)
        = 2^(h+1) - 1 Nodes

```

# -----------------------------------------------------------------------------

#### Max height possible with 'n' nodes in a binary tree ?
- height = n - 1  (left or right skewed binary tree)

#### Min height possible with 'n' nodes in a binary tree ?
## Binary Tree
                      1                           H-0 = 2^0 nodes
                /          \  
               2             3                    H-1 = 2^0 + 2^1 nodes
            /    \         /   \ 
           4      5       6     7                 H-2 = 2^0 + 2^1 + 2^2 nodes

                                                  H-h = 2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h nodes

```
L-(h+1) = 2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h                    - Total nodes of tree with 'h' height
        = a*r^0 + a*r^1 + a*r^2 + a*r^3 + ..... + a*r^n          - Geometric Progression
        = a(r^n - 1)/(r - 1)

        = 1 [2^0 + 2^1 + 2^2 + 2^3 + ..... + 2^h]
        = 2^(h+1) - 1
        = (2^(h+1) - 1) / (2 - 1)
        = 2^(h+1) - 1 
        = 2^(h+1) - 1 = n
        = 2^(h+1) = n + 1
        = log2(2^(h+1)) = log2(n + 1)
        = h + 1 = log2(n + 1)
        = h = log2(n + 1) - 1
```
- Height of BT = O(n)           - (Sparse Tree)
- Height of BT = Omega(logn)    - (Dense Tree)
- Min height      <= Height       <= Max Height
- log2(n + 1) - 1 <= Height of BT <= (n - 1)

# -----------------------------------------------------------------------------

### Traversal Techniques

```
                      1
                /          \  
               2             3
            /    \         /   \
           4      5       6     7
```

### Inorder Traversal  (Left | Root | Right)
-  4 2 5 1 6 3 7

### Pre-order Traversal  (Root | Left | Right)
-  1 2 4 5 3 6 7

### Post-order Traversal  (Left | Right | Root)
-  4 5 2 6 7 3 1

### Breadth First Traversal  
-  1 2 3 4 5 6 7

# -----------------------------------------------------------------------------

#### Space Complexity
- Number of Activation Records = No of levels in tree or Height of Tree
- Number of Activation Records = O(height of tree)
