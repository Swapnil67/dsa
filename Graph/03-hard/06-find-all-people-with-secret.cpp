/*
 * Leetcode - 2092
 * Find All People With Secret
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

 * You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in
 * this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there 
 * is a directed edge from node aj to node bj.

 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge
 * from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the 
 * most frequently occurring color along that path.

 * Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

 * * Example 1  :
 * * Input      : n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
 * * Output     : [0,1,2,3,5]
 * 
 * * Example 2  :
 * * Input      : n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
 * * Output     : [0,1,3]
 * 
 * * Example 3  :
 * * Input      : n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
 * * Output     : [0,1,2,3,4]
 * 
 * https://leetcode.com/problems/find-all-people-with-secret/description/
 * 
 */

// ! Google

#include <map>
#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

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

typedef std::pair<int, int> P;

void printMap(std::map<int, std::vector<P>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    for (auto &it: vec) {
      std::cout << "(" << it.first << " " << it.second << "), ";
    }
    std::cout << std::endl;
  }
}

void printAdjList2(std::unordered_map<int, std::vector<int>> &adj) {
  for (auto &[key, vec] : adj) {
    std::cout << key << " -> ";
    printArr(vec);
  }
}

void printAdjList(std::unordered_map<int, std::vector<P>> &adj) {
  for (auto &[u, vec]: adj) {
    std::cout << u << " -> ";
    for (auto &it : vec) {
      std::cout << "(" << it.first << " " << it.second << "), ";
    }
    std::cout << std::endl;
  }
}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * TIME COMPLEXITY  O(V + E) * 26
// * SPACE COMPLEXITY O(V + E)
std::vector<int> findAllPeople(int n, int first_person, std::vector<std::vector<int>> &meetings) {

  // * Create the map of meetings with respective persons in sorder ascending order
  // * {time: {p1, p2}, {p1, p3}}
  std::map<int, std::vector<P>> time_meetings_mp;
  for (auto &data: meetings) { // * O(M)
    int person1 = data[0];
    int person2 = data[1];
    int time = data[2];
    time_meetings_mp[time].push_back({person1, person2});
  }
  std::cout << "Time Meetings map" << std::endl;
  printMap(time_meetings_mp); // * For debugging

  std::vector<bool> knows_secret(n, false);
  knows_secret[0] = true;
  knows_secret[first_person] = true;

  for (auto &it : time_meetings_mp) { // * O(M)
    int t = it.first;
    std::vector<P> meets = it.second; 

    std::unordered_map<int, std::vector<int>> adj; // * a -> {b, c, d}
    std::queue<int> q; 
    std::unordered_set<int> already_added;
    std::cout << "-----------------" << std::endl;

    for (auto &[person1, person2] : meets) {
      adj[person1].push_back(person2);
      adj[person2].push_back(person1);

      if (knows_secret[person1] && !already_added.count(person1)) {
        q.push(person1);
        already_added.insert(person1);
      }

      if (knows_secret[person2] && !already_added.count(person2)) {
        q.push(person2);
        already_added.insert(person2);
      }
    }
    printAdjList2(adj);
    std::cout << "Queue size: " << q.size() << std::endl;

    // * Spread the secret
    while (!q.empty()) {
      int person = q.front();
      q.pop();
      for (auto &ngbr : adj[person]) {
        if (knows_secret[ngbr] == false) {
          knows_secret[ngbr] = true;
          q.push(ngbr);
        }
      }
    }
  }

  // * People who know the secret
  std::vector<int> res;
  for (int i = 0; i < n; i++) {
    if (knows_secret[i])
      res.push_back(i);
  }
  
  return res;
}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * Easy to understand
// * TIME COMPLEXITY  O(V + E) * 26
// * SPACE COMPLEXITY O(V + E)
std::vector<int> findAllPeople2(int n, int first_person, std::vector<std::vector<int>> &meetings) {
  // * 1. Create a Adj list {person1: {person2, time}}
  std::unordered_map<int, std::vector<P>> adj;
  for (auto &it : meetings) {
    int u = it[0], v = it[1], time = it[2];
    adj[u].push_back({v, time});
    adj[v].push_back({u, time});
  }
  printAdjList(adj); // * For Debugging

  // * People who already know the secret
  std::vector<int> secret_time(n, INT_MAX);
  secret_time[0] = 0;
  secret_time[first_person] = 0;

  // * BFS
  std::queue<P> q;
  q.push({0, 0});             // * People who already know the secret
  q.push({first_person, 0});  // * People who already know the secret

  while (!q.empty()) {
    int N = q.size();
    while (N--) {
      auto [person1, time] = q.front();
      q.pop();

      for (auto &[person2, time2] : adj[person1]) {
        // * Person2 doesn't knows the secret and there meeting is in future time
        // * So person1 will share the secret with person2 in that meeting
        if (time2 >= time && secret_time[person2] > time2) {
          secret_time[person2] = time2;
          q.push({person2, time2});
        }
      }
    }  
  }
  
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (secret_time[i] != INT_MAX)
      ans.push_back(i);
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // int n = 6, firstPerson = 1;
  // std::vector<std::vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
  
  // * testcase 2
  // int n = 4, firstPerson = 3;
  // std::vector<std::vector<int>> meetings = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};

  // * testcase 3
  // int n = 5, firstPerson = 1;
  // std::vector<std::vector<int>> meetings = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};

  // * testcase 3 (Dry Run)
  int n = 4, firstPerson = 2;
  std::vector<std::vector<int>> meetings = {{0, 1, 4}, {1, 3, 3}, {2, 1, 2}};

  std::cout << "First Person " << firstPerson << std::endl;
  std::cout << "-------- Meetings -------- " << std::endl;
  for (auto &vec : meetings)
    printArr(vec);

  // std::vector<int> ans = findAllPeople(n, firstPerson, meetings);
  std::vector<int> ans = findAllPeople2(n, firstPerson, meetings);
  std::cout << "People who know secret: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-find-all-people-with-secret.cpp -o output && ./output

// * DRY Run (Testcase 4)
/*
* Adj Matrix
* Person1 -> (Person2, Time)
* 0 -> (1 4)  
* 1 -> (0 4), (3 3), (2 2) 
* 2 -> (1 2) 
* 3 -> (1 3) 
* 
*
*/