/**
 * * leetcode - 3208
 * * Alternating Groups II
 * * There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. 
 * * The color of tile i is represented by colors[i]:
 * * An alternating group is every k contiguous tiles in the circle with alternating colors
 * * (each tile in the group except the first and last one has a different color from its left and right tiles).
 * * Return the number of alternating groups.
 * * Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
 * 
 * * Example 1
 * * Input  : colors = [0, 1, 0, 1, 0], k = 3
 * * Output : 3
 * 
 * * Example 2
 * * Input  : colors = [0, 1, 0, 0, 1, 0, 1], k = 6
 * * Output : 2
 * 
 * * Example 3
 * * Input  : colors = [1, 1, 0, 1], k = 4
 * * Output : 0
 * 
 * * https://leetcode.com/problems/alternating-groups-ii/description/
*/

#include<vector>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> &arr, int k) {
  // * Append k - 1 elements to the end of array (to make circular)
  int temp = k - 1;
  for (int i = 0; i < temp; ++i) {
    arr.push_back(arr[i]);
  }
  // printArr(arr);
  
  int n = arr.size();
  int ans = 0;
  for (int i = 0; i <= n - k; ++i) {
    bool isAlt = true;
    int j = i;
    for (; j < i + k; ++j) {
      std::cout << arr[j] << " ";
      if ((j - i) == k - 1)
        break;
      if (j < n && arr[j] == arr[j + 1]) {
        isAlt = false;
        break;
      }
    }
    // std::cout << std::endl;
    if ((j - i) == k - 1 && isAlt)
      ans++;
  }

  return ans;
}


// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Add k - 1 elements to the input array for making it circular
// * Classic Sliding Window
// * TIME COMPLEXITY O(N + K)
// * SPACE COMPLEXITY O(1)
int numberOfAlternatingGroups(std::vector<int> &arr, int k) {
  // * Append k - 1 elements to the end of array (to make circular)
  for(int i = 0; i < k - 1; ++i) {
    arr.push_back(arr[i]);
  }
  // printArr(arr);

  int result = 0;
  int i = 0 , j = 1;
  int n = arr.size();
  while (j < n) {
    // * If j same as previous one then bring i to j
    if(arr[j] == arr[j - 1]) {
      i = j;
      j += 1;
      continue;
    }

    // * k window found
    if (j - i + 1 == k) {
      i += 1;
      result += 1;
    }

    j += 1;
  }

  return result;
}


int main() {
  int k = 3;
  std::vector<int> arr = {0, 1, 0, 1, 0};
  // int k = 6;
  // std::vector<int> arr = {0, 1, 0, 0, 1, 0, 1};
  // int k = 4;
  // std::vector<int> arr = {1, 1, 0, 1};
  printArr(arr);

  // int ans = bruteForce(arr, k);
  int ans = numberOfAlternatingGroups(arr, k);
  printf("Alternating consecutive tiles: %d\n", ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 23-alternating-groups-ii.cpp -o output && ./output