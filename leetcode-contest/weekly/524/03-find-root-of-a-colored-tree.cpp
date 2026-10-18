/*
 * Find Root of a Colored Tree
 * 
 * Description:
 * Given an undirected tree of n nodes (0 to n - 1), an edges array, and a string colors ('R', 'B', 'W'), find a valid root index such that orienting the tree away from it satisfies:
 * - Binary-tree property: Every node has at most two children (degree at most 3 in the graph, 2 <= n <= 10^5).
 * - Layered color pattern: Nodes at the same depth share a color, following a repeating sequence starting at depth 0 (R->B->W, B->W->R, or W->R->B).
 * Return any valid root index, or -1 if none exists.
 * 
 * Example 1 Visualized:
 * Input: edges = [[3,1],[3,2],[1,4],[2,0]], colors = "BRRWB"
 * Output: 3
 * 
 * Structure:
 *               Depth 0:         [ Node 3 ]  (Color: B)
 *                                /        \
 *               Depth 1:   [ Node 1 ]      [ Node 2 ]  (Color: R)
 *                             /               /
 *               Depth 2: [ Node 4 ]      [ Node 0 ]  (Color: W)
 * 
 * Explanation: Node 3 chosen as root splits nodes uniformly into levels where each depth shares a uniform
 *              color cycle (B -> R -> W), satisfying the binary constraint.
 * 
 * https://leetcode.com/problems/find-root-of-a-colored-tree/description/
*/

// ! Binary Tree

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

typedef struct TreeNode TreeNode;

struct TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;
  
  TreeNode(int val) {
    data = val;
    left = right = nullptr;
  }
};

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

void printAdjList(unordered_map<int, vector<int>> &adj) {
  int n = adj.size();
  for (auto &[key, vec] : adj) {
    cout << key << " -> ";
    printArr(vec);
  }
}

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

// * all Edges are in outward/downward direction in directed tree from the root
int findColoredRoot(vector<vi>& edges, string colors) {
  int n = edges.size();
  cout << n << endl;

  // * Valid edges R -> B, B -> W, & W -> R
  // * First create a Adj list with given colors
  unordered_map<int, vector<int>> adj;
  for (auto &it: edges) {
    int u = it[0], v = it[1];
    char u_color = colors[u], v_color = colors[v];

    if (u_color == 'R' && v_color == 'B') {
      adj[u].push_back(v); // * u -> v
    } else if (u_color == 'B' && v_color == 'R') {
      adj[v].push_back(u); // * v -> u
    }
    
    if (u_color == 'B' && v_color == 'W') {
      adj[u].push_back(v); // * u -> v
    } else if (u_color == 'W' && v_color == 'B') {
      adj[v].push_back(u); // * v -> u
    }
    
    if (u_color == 'W' && v_color == 'R') {
      adj[u].push_back(v); // * u -> v
    } else if (u_color == 'R' && v_color == 'W') {
      adj[v].push_back(u); // * v -> u
    }
  }

  int answer = 0;
  // * create indegree & outdegree vectors
  vi indegree(n + 1, 0), outdegree(n + 1, 0);
  for (int u = 0; u <= n; u++) {
    for (auto v : adj[u]) {
      indegree[v]++;
      outdegree[u]++;
    }
  }
  // printAdjList(adj);
  // printArr(indegree);
  // printArr(outdegree);

  // * Count nodes who've indegree = 0 (i.e, possible root node of tree)
  int roots = 0;
  for (int i = 0; i <= n; ++i) {
    if (indegree[i] == 0) {
      answer = i;
      roots++;
    }
  }

  // * A Binary-tree cannot have more than 1 root.
  if (roots > 1)
    return -1;

  // * Now check each node has atmost 2 children.
  for (int i = 0; i < n; ++i) {
    if (outdegree[i] >= 3) {
      return -1;
    }
  }

  return answer;
}

int main(void) {
  // * testcase 1
  // string colors = "BRRWB";
  // vector<vi> edges = {{3, 1}, {3, 2}, {1, 4}, {2, 0}};

  // * testcase 2
  // string colors = "RBRB";
  // vector<vi> edges = {{0, 1}, {1, 2}, {2, 3}};

  // * testcase 3
  string colors = "BR";
  vector<vi> edges = {{1, 0}};

  int ans = findColoredRoot(edges, colors);
  cout << "Answer: " << ans << '\n';

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-find-root-of-a-colored-tree.cpp -o output && ./output
