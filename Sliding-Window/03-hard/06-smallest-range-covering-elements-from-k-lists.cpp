/*
 * Leetcode - 632
 * Smallest Range Covering Elements from K Lists
 * 
 * You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one
 * number from each of the k lists.
 * 
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
 * 
 * Example 1    :
 * Input        : nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
 * Output       : [20,24]
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : nums = [[1,2,3],[1,2,3],[1,2,3]]
 * Output       : [1,1]
 * Explanation  : 
 * 
 * 
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 * https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356
 * https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
*/

#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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

bool checkInRange(vector<int> &nums, int &n1, int &n2) {
  for (auto &x : nums) {
    if (x >= n1 && x <= n2) // * In x in range of [n1...n2]
      return true;
  }
  return false;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * Nexted Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
vector<int> bruteForce(vector<vector<int>> nums) {
  // * Merge All the vectors into One
  vector<int> temp;
  for (auto &vec : nums) {
    temp.insert(temp.end(), vec.begin(), vec.end());
  }
  // printArr(temp); // * debug
  sort(temp.begin(), temp.end());

  vector<int> ans;
  int N = temp.size();
  for (int i = 0; i < N; ++i) {
    int n1 = temp[i];
    for (int j = i; j < N; ++j) {
      int n2 = temp[j];
      
      // * check if current range from n1 to n2 exists in all the k-list
      bool inRange = true;
      for (auto &vec : nums) {
        if (!checkInRange(vec, n1, n2)) {
          inRange = false;
          break;
        }
      }

      if (inRange) {
        // * check if current range is smaller than the answer
        if (ans.empty() || (ans[1] - ans[0]) > (n2 - n1)) {
          ans = {n1, n2};
        }
      }

      cout << n1 << " " << n2 << " => " << inRange << endl;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * sliding window
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(K)
vector<int> betterApproach(vector<vector<int>> nums) {
  int k = nums.size();

  // * This will contain current index of element of nums vec
  vector<int> temp(k, 0); // * {0, 0, 0, ...}

  // * Range => (a, b)
  vector<int> ans = {-1000000, 1000000};
  
  while (true) {
    int minEleListIdx = 0;    // * Index of list which has min element
    int maxEle = INT_MIN, minEle = INT_MAX;

    // * Find current min and max element and also the min element list index
    for (int listIdx = 0; listIdx < k; ++listIdx) {
      int eleIdx = temp[listIdx];
      int ele = nums[listIdx][eleIdx];
  
      if (ele < minEle) {
        minEle = ele;
        minEleListIdx = listIdx;
      }
      maxEle = max(maxEle, ele);
    }
  
    // cout << minEle << " " << maxEle << " -> " << minEleListIdx << endl;

    // * Did we found a better range
    if (ans[1] - ans[0] > maxEle - minEle) {
      ans[0] = minEle, ans[1] = maxEle;
    }

    int nextSmallestIdx = temp[minEleListIdx] + 1;
    if (nextSmallestIdx >= nums[minEleListIdx].size()) {
      break;
    }
    temp[minEleListIdx] = nextSmallestIdx;
  }

  return ans;
}


// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Same as above just for finding minEle we are using min Heap
// * sliding window + Heap
// * TIME COMPLEXITY O(N * logK)
// * SPACE COMPLEXITY O(K)
vector<int> smallestRange(vector<vector<int>> nums) {
  int n = nums.size();

  // * This will contain current index of element of nums vec
  vector<int> temp(n, 0); // * {0, 0, 0, ...}
  
  // * min heap => {minEle, listIdx, eleIdx}
  int maxEle = INT_MIN;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  // * Poplulate min heap with first elements of all vector
  for(int i = 0; i < n; ++i) {
    pq.push({nums[i][0], i, 0}); // * {minEle, listIdx, eleIdx} 
    maxEle = max(nums[i][0], maxEle);
  }

  // * Range => (a, b)
  vector<int> ans = {-1000000, 1000000};

  while (!pq.empty()) {
    vector<int> cur = pq.top();
    pq.pop();
    // int [ minEle, listIdx, eleIdx ] = cur;
    int minEle = cur[0];    
    int listIdx = cur[1];
    int eleIdx  = cur[2];

    if (maxEle - minEle < ans[1] - ans[0]) {
      ans[1] = maxEle, ans[0] = minEle;
    }

    // * Decrease the range from min side
    if (eleIdx + 1 >= nums[listIdx].size())
      break;

    int nextIdx = eleIdx + 1;
    int nextElement = nums[listIdx][nextIdx];
    pq.push({nextElement, listIdx, nextIdx});
    maxEle = max(maxEle, nextElement);
  }

  return ans;
}

int main(void) {
  vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};

  cout << "Input Ranges" << endl;
  for (auto &vec : nums) {
    printArr(vec);
  }

  vector<int> ans = bruteForce(nums);
  // vector<int> ans = betterApproach(nums);
  // vector<int> ans = smallestRange(nums);

  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-smallest-range-covering-elements-from-k-lists.cpp -o output && ./output 
