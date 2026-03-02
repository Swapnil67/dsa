/*
 * Leetcode - 11
 * Container With Most Water
 * 
 * You are given an integer array height of length n. There are n vertical lines drawn such that the
 * two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * 
 * Example 1
 * Input  : height = [1,8,6,2,5,4,8,3,7]
 * Output : 49
 * 
 * https://leetcode.com/problems/container-with-most-water/description/
 * https://www.naukri.com/code360/problems/container-with-most-water_873860
*/

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> height) {
  int n = height.size();
  int maxArea = INT_MIN;
  for (int i = 0; i < n; ++i)  {
    for (int j = i + 1; j < n; ++j) {
      int curArea = ((j - i) * min(height[i], height[j]));
      // cout << curArea << " ";
      maxArea = max(curArea, maxArea);
    }
    // cout << endl;
  }
  return maxArea;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Two pointer at start & end
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxArea(vector<int> height) {
  int n = height.size();
  int i = 0, j = n - 1;
  int max_area = INT_MIN;
  while (j > i) {
    int cur_area = (j - i) * min(height[i], height[j]);
    max_area = max(max_area, cur_area);

    // * keep the more height for finding 'greater area'
    if (height[i] > height[j])
      j--;
    else
      i++;
  }
  return max_area;
}

int main() {
  vector<int> nums = {3, 1, 2, 3};
  // vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // vector<int> nums = {1, 1};
  printArr(nums);

  // int ans = bruteForce(nums);
  int ans = maxArea(nums);
  cout << "maximum amount of water a container can store : " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++17 05-container-with-most-water.cpp -o output && ./output
