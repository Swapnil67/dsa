/*
* Leetcode - 1993
* Operations on Tree

* https://leetcode.com/problems/operations-on-tree/ 
*/

// ! Design
// ! Meta, Google, Amazon

// * Do this in leetcode

#include <vector>
#include <iostream>

class LockingTree
{
  std::vector<int> locked;
  std::vector<int> parent;
  std::vector<std::vector<int>> child;

  int dfs(int node) {
    int locked_count = 0;
    if (locked[node]) {
      locked_count++;
      locked[node] = 0;
    }
    for (int &nei : child[node]) {
      locked_count += dfs(nei);
    }
    return locked_count;
  }

public:
  LockingTree(std::vector<int> &parent) : parent(parent), locked(parent.size()) {
    int n = parent.size();
    child.resize(n);
    // * {0: {1, 2}, 1: {3, 4}, 2: {5, 6}}
    for (int node = 1; node < n; ++node) {
      child[parent[node]].push_back(node);
    }
  }

  bool lock(int num, int user) { // * O(1)
    if (locked[num])
      return false;
    locked[num] = user;
    return true;
  }

  bool unlock(int num, int user) { // * O(1)
    if (locked[num] != user)
      return false;
    locked[num] = 0;
    return true;
  }

  bool upgrade(int num, int user) { // * O(N)
    // * Go to its ancestors and check if any node is locked
    int node = num;
    while (node != -1) {
      if (locked[node])
        return false;
      node = parent[node];
    }

    // * Go to its descendants & unlocks all the nodes
    int locked_count = dfs(num);
    if (locked_count > 0) {
      locked[num] = user; // * lock the given node with given user
      return true;
    }
    return false;
  }
};

int main(void) {
  // * testcase 1
  // std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  // LockingTree *obj = new LockingTree(parent);
  // std::cout << obj->lock(2, 2) << std::endl;
  // std::cout << obj->unlock(2, 3) << std::endl; 
  // std::cout << obj->unlock(2, 2) << std::endl; 
  // std::cout << obj->lock(4, 5) << std::endl;
  // std::cout << obj->upgrade(0, 1) << std::endl;
  // std::cout << obj->lock(0, 1) << std::endl;

  // * testcase 2
  std::vector<int> parent = {-1,0,1,1,0};
  LockingTree *obj = new LockingTree(parent);
  std::cout << obj->unlock(2, 1) << std::endl;
  std::cout << obj->unlock(3, 10) << std::endl;
  std::cout << obj->upgrade(2, 9) << std::endl;
  std::cout << obj->upgrade(4, 1) << std::endl;
  std::cout << obj->upgrade(1, 5) << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++20 38-operations-on-tree.cpp -o output && ./output

