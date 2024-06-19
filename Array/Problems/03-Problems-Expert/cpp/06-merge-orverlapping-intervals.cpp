/**
 * * Merge overlapping intervals
 *
 * * Example 1
 * * Input  : [[1,3], [2,6], [8,9], [9,11], [8,10], [2,4], [15,18], [16,17]]
 * * Output : [[1,6], [8,11], [15,18]]

 * * https://www.naukri.com/code360/problems/merge-all-overlapping-intervals_6783452
 * * https://leetcode.com/problems/merge-intervals/description/
*/

#include<iostream>

void printMatrix(std::vector<std::vector<int>> matrix) {
  int n = matrix.size(), m = matrix[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(nlogn) +  O(2N)
/*
 * O(nlogn) => sorting the md array
 * O(2N) => Nested loop (the jth loop only runs for 2 elements)
*/
// * SPACE COMPLEXITY O(N) [For Answer])
std::vector<std::vector<int>> bruteForce(std::vector<std::vector<int>> arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;

  // * Sort the array O(nlogn)
  std::sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {
    int start = arr[i][0];
    int end = arr[i][1];
    // * Checks if interval already a part of previous interval
    if(!ans.empty() && end <= ans.back()[1]) {
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      if(arr[j][0] <= end) {
        end = std::max(end, arr[j][1]);
      }
      else {
        break;
      }
    }
    ans.push_back({start, end});
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(NlogN) + O(N)
// * SPACE COMPLEXITY O(N) [For Answer]
std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;
  std::sort(arr.begin(), arr.end());
  std::vector<int> interval = arr[0];
  for (int i = 0; i < n; i++) {
    if(arr[i][0] <= interval[1]) {
      interval[1] = std::max(interval[1], arr[i][1]);
    }
    else {
      ans.push_back(interval);
      interval = arr[i];
    }
  }
  ans.push_back(interval);
  return ans;
}

int main() {
  std::vector<std::vector<int>> arr = {{1, 4}, {0, 4}};
  // std::vector<std::vector<int>> arr = {{1, 3}, {1, 5}, {6, 7}};
  // std::vector<std::vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
  // printMatrix(arr);
  // std::vector<std::vector<int>> ans = bruteForce(arr);
  std::vector<std::vector<int>> ans = mergeOverlappingIntervals(arr);
  printMatrix(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++17 06-merge-orverlapping-intervals.cpp -o 06-merge-orverlapping-intervals && ./06-merge-orverlapping-intervals