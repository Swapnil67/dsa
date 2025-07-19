#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

bool searchRange(std::vector<int> &arr, int n1, int n2) {
  for (int k = 0; k < arr.size() - 1; ++k) {
    if (n1 <= arr[k] && n2 <= arr[k])
      return true;
  }
  return false;
}

std::vector<int> bruteForce(vector<vector<int>> nums) {
  
  // * Merge All the vectors into One
  std::vector<int> temp;
  for (auto &vec : nums) {
    temp.insert(temp.end(), vec.begin(), vec.end());
  }
  printArr(temp);
  // std::sort(temp.begin(), temp.end());

  std::vector<int> ans;
  for (int i = 0; i < temp.size() - 1; ++i) {
    int n1 = temp[i];
    for (int j = i + 1; j < temp.size() - 1; ++j) {
      bool isValidRange = true;
      int n2 = temp[j];

      // * check if range from n1-n2 exists in nums
      for (auto &vec : nums) {
        isValidRange = searchRange(vec, n1, n2);
        if (!isValidRange)
          break;
      }

      if(isValidRange) {
        if (!ans.size()) {
          ans = {n1, n2};
        } else {
          if (ans[1] - ans[2] > n2 - n1) {
            ans = {n1, n2};
          }
        }
      }

      std::cout << n1 << " " << n2 << " => " << isValidRange << std::endl;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * sliding window
// * TIME COMPLEXITY O(N * K)
// * SPACE COMPLEXITY O(K)
std::vector<int> betterApproach(vector<vector<int>> nums) {
  int k = nums.size();

  // * This will contain current index of element of nums vec
  std::vector<int> temp(k, 0); // * {0, 0, 0, ...}

  // * Range => (a, b)
  std::vector<int> ans = {-1000000, 1000000};

  
  while (true) {
    int minEleListIdx = 0;    // * Index of list which has min element
    int maxEle = INT_MIN, minEle = INT_MAX;

    for (int listIdx = 0; listIdx < k; ++listIdx) {
      int eleIdx = temp[listIdx];
      int ele = nums[listIdx][eleIdx];
  
      if (ele < minEle) {
        minEle = ele;
        minEleListIdx = listIdx;
      }
  
      maxEle = std::max(maxEle, ele);
    }
  
    // std::cout << minEle << " " << maxEle << " -> " << minEleListIdx << std::endl;

    // * Did we found a better range
    if (maxEle - minEle < ans[1] - ans[0]) {
      ans[0] = minEle;
      ans[1] = maxEle;
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
std::vector<int> smallestRange(vector<vector<int>> nums) {
  int n = nums.size();

  // * This will contain current index of element of nums vec
  std::vector<int> temp(n, 0); // * {0, 0, 0, ...}
  
  // * min heap => {minEle, listIdx, eleIdx}
  int maxEle = INT_MIN;
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  // * Poplulate min heap with first elements of all vector
  for(int i = 0; i < n; ++i) {
    pq.push({nums[i][0], i, 0}); // * {minEle, listIdx, eleIdx} 
    maxEle = std::max(nums[i][0], maxEle);
  }

  // * Range => (a, b)
  std::vector<int> ans = {-1000000, 1000000};

  while (!pq.empty()) {
    vector<int> cur = pq.top();
    pq.pop();
    // int [ minEle, listIdx, eleIdx ] = cur;
    int minEle = cur[0];    
    int listIdx = cur[1];
    int eleIdx  = cur[2];

    if (maxEle - minEle < ans[1] - ans[0]) {
      ans[1] = maxEle;
      ans[0] = minEle;
    }

    // * Decrease the range from min side
    if (eleIdx + 1 >= nums[listIdx].size()) {
      break;
    }

    int nextIdx = eleIdx + 1;
    int nextElement = nums[listIdx][nextIdx];
    pq.push({nextElement, listIdx, nextIdx});
    maxEle = std::max(maxEle, nextElement);
  }

  return ans;
}

int main(void) {
  vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};

  std::cout << "Input Ranges" << std::endl;
  for (auto &vec : nums) {
    printArr(vec);
  }

  // std::vector<int> ans = bruteForce(nums);
  // std::vector<int> ans = betterApproach(nums);
  std::vector<int> ans = smallestRange(nums);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-smallest-range-covering-elements-from-k-lists.cpp -o output && ./output 
