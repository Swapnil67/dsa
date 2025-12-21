/*
* Leetcode - 1334
* Find the City With the Smallest Number of Neighbors at a Threshold Distance
*
* There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
* represents a bidirectional and weighted edge between cities from[i] and to[i], 
* and given the integer distanceThreshold.

* Return the city with the smallest number of cities that are reachable through some path and whose distance 
* is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

* Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' 
* weights along that path.

* Example 1:
* Input         : n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
* Output        : 3
* Explanation   : The figure above describes the graph. 
*                 The neighboring cities at a distanceThreshold = 4 for each city are:
*                 The city 0 & 3 have can reach smallest no. of neighbouring cities but the ans is '3' since its greater
*                 - City 0 -> [City 1, City 2] 
*                 - City 1 -> [City 0, City 2, City 3] 
*                 - City 2 -> [City 0, City 1, City 3] 
*                 - City 3 -> [City 1, City 2] 

* Example 2:
* Input         : n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
* Output        : 0
* Explanation   : The figure above describes the graph. 
*                 The neighboring cities at a distanceThreshold = 2 for each city are:
*                 The city 0 have can reach smallest no. of neighbouring cities within threshold
*                 - City 0 -> [City 1] 
*                 - City 1 -> [City 0, City 4] 
*                 - City 2 -> [City 3, City 4] 
*                 - City 3 -> [City 2, City 4]
*                 - City 4 -> [City 1, City 2, City 3] 
*
* https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description
* https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0
* https://www.naukri.com/code360/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance_1264289
*/

// ! uber

#include <queue>
#include <vector>
#include <climits>
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

// * ------------------------- Approach 1: Optimal -------------------------
// * Floyd Warshall
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(N^2)
int findTheCity(int n, int &distanceThreshold, std::vector<std::vector<int>> &edges) {
  std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));
  for (auto &it : edges) {
    int u = it[0], v = it[1], w = it[2];
    dist[u][v] = w;
    dist[v][u] = w;
  }

  // * Count the min dist from every 'V' to every other 'V'
  // * Distance to itself will be 0
  for (int i = 0; i < n; ++i)
    dist[i][i] = 0;
  
  for (int via = 0; via < n; ++via) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
          continue;

        // * dist[1][0] = dist[1][0] + dist[0][0] (eg: going via 0)
        dist[i][j] = std::min(dist[i][j], (dist[i][via] + dist[via][j]));
      }
    }
  }

  // * Find the city which can reach to smallest no of adj cities within distanceThreshold
  int city_max_cnt = n, city_no = 0;
  for (int city = 0; city < n; ++city) {
    int city_cur_cnt = 0;
    for (int adjcity = 0; adjcity < n; ++adjcity) {
      if (dist[city][adjcity] <= distanceThreshold) {
        city_cur_cnt++;
      }
    }
    // * if it can reach less cities then updated max count
    if (city_cur_cnt <= city_max_cnt) {
      city_max_cnt = city_cur_cnt;
      city_no = city;
    }
  }

  return city_no;
}

int main(void) {
  // * testcase 1
  int n = 4, distanceThreshold = 4;
  std::vector<std::vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

  // * testcase 1
  // int n = 5, distanceThreshold = 2;
  // std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};

  std::cout << "n: " << n << ", distanceThreshold: " << distanceThreshold << std::endl;
  std::cout << "edges: " << std::endl;
  for (auto &vec : edges)
    printArr(vec);

  int ans = findTheCity(n, distanceThreshold, edges);
  std::cout << "City With the Smallest Number of Neighbors at a Threshold Distance: " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 09-find-the-city-with-the-smallest-no-of-neighbors-at-a-threshold-distance.cpp -o output && ./output