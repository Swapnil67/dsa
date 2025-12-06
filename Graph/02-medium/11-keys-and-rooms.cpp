/**
 * * Leetcode - 841
 * * Keys and Rooms
 *
 * * There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
 * * Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
 
 * * When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
 * * denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

 * * Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
 * * return true if you can visit all the rooms, or false otherwise.

 * * Example 1  :
 * * Input      : grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * * Output     : 2

 * * Example 2  :
 * * Input      : grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * * Output     : 1
 * 
 * * https://leetcode.com/problems/keys-and-rooms/description/
 * * https://www.naukri.com/code360/problems/rooms_1214959
*/

#include <vector>
#include <iostream>

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

void dfs(int room, std::vector<bool> &visited, std::vector<std::vector<int>> &rooms) {
  visited[room] = true;
  
  for (auto &key : rooms[room]) {
    if (!visited[key]) {
      dfs(key, visited, rooms);
    }
  }
}

// * Note: rooms is similar to adjacency list of graph
bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
  int n = rooms.size();
  std::vector<bool> visited(n, false);
  dfs(0, visited, rooms);
  // printArr(visited); // * For debugging

  for (bool v : visited) {
    if (!v)
      return false;
  }
  return true;
}

int main(void) {
  // * testcase 1
  // std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
  
  // * testcase 2
  std::vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};

  bool ans = canVisitAllRooms(rooms);
  std::cout << "rooms: " << std::endl;
  for (auto &vec : rooms)
    printArr(vec);

  std::cout << "Can visit all rooms: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-keys-and-rooms.cpp -o output && ./output