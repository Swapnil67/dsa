#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

// * Print adjacency list
template <typename T>
void printAdjList(std::vector<T> &adj) {
  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    std::cout << i << " -> ";
    printArr(adj[i]);
  }
}

int main(void) {
  // * testcase 1
  int n = 3;
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
  
  // * testcase 2
  // int n = 7;
  // std::vector<std::vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  
  // * testcase 3
  // int n = 6;
  // std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};

  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output