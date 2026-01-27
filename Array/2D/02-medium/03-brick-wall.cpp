/*
 * Spiral Matrix

 * Example 

 * Input
 * * 1 2 2 1 
 * * 3 1 2 
 * * 1 3 2 
 * * 2 4 
 * * 3 1 2 
 * * 1 3 1 1 

 * Output
 * 2
 * 
 * https://leetcode.com/problems/brick-wall/description/
 * https://www.naukri.com/code360/problems/spiral-matrix_840698
*/

#include<map>
#include<iostream>

void printMatrix(std::vector<std::vector<int>> matrix) {
  int r = matrix.size();
  for (int i = 0; i < r; ++i) {
    int c = matrix[i].size();
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


// * Prefix Sum + Hashmap
// * Space Complexity O(r * c)
// * Time Complexity O(1)
int leastBricks(std::vector<std::vector<int>> wall) {
  std::map<int, int> gapMap; // * pos -> gap;
  gapMap[0] = 0;

  int r = wall.size();
  for (int i = 0; i < r; ++i) {
    int c = wall[i].size(), gapPrefix = 0;
    for (int j = 0; j < c - 1; ++j) {
      gapPrefix += wall[i][j];
      if(gapMap.find(gapPrefix) != gapMap.end()) {
        gapMap[gapPrefix] = 1 + gapMap[gapPrefix];
      }
      else {
        gapMap[gapPrefix] = 1;
      }
    }
  }

  int max_gap = INT_MIN;
  for(auto it : gapMap) {
    // std::cout << it.first << " -> " << it.second << std::endl;
    max_gap = std::max(max_gap, it.second);
  }

  return r - max_gap;
}

int main() {
  // std::vector<std::vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
  // std::vector<std::vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
  // std::vector<std::vector<int>> wall = {{1, 1}, {2}, {1, 1}};
  // std::vector<std::vector<int>> wall = {{1}, {1}, {1}};
  
  std::cout << "--------------- Wall ---------------" << std::endl;
  printMatrix(wall);
  int ans = leastBricks(wall);
  std::cout << "Least colliding bricks are " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 03-brick-wall.cpp -o output && ./output