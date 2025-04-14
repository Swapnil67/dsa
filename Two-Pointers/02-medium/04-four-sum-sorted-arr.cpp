/**
 * * Four Sum
 * * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * * 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.
 * * nums[a] + nums[b] + nums[c] + nums[d] == target

 * * Example 1
 * * Input  : 'nums' = [1,0,-1,0,-2,2], target = 0
 * * Output : [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * * Example 2
 * * Input  : 'nums' = [2,2,2,2,2], target = 8
 * * Output : [[2,2,2,2]]

 * * https://www.naukri.com/code360/problems/4sum_5713771
 * * https://leetcode.com/problems/4sum/
*/

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Time Complexity O(N^2)
void printMatrix(std::vector<std::vector<int>>&mat) {
  int n = mat.size();
  if(n == 0) return;
  int m = mat[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * ****** Intuition ******
// * Nested loops

// * TIME COMPLEXITY O(N^4) x log(size of set) = O(N^4) x log(m)
/*
 * O(N^4) => Four for loop
 * log(m) => hashset (st)
*/
// * SPACE COMPLEXITY O(no of quads) x 2
/*
 * O(no of quads) => vectorSet
 * O(no of quads) => ans
*/
std::vector<std::vector<int>> bruteForce(std::vector<int>arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          int sum = arr[i] + arr[j] + arr[k] + arr[l];
          // std::cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << std::endl;
          if (sum == 0) {
            std::vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            sort(temp.begin(), temp.end());
            vectorSet.insert(temp);
          }
        }
      }
    }
  }

  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * ****** Intuition ******
// * If the following is true
// * arr[i] + arr[j] + arr[k] + arr[l] = target
// * Then we can also derive the following
// * arr[l] = target - (arr[i] + arr[j] + arr[k]);

// * TIME COMPLEXITY O(N^3) x log(size of set) = O(N^3) x log(m)
/*
 * O(N^3) => Three for loop
 * log(m) => hashset (st)
*/
// * SPACE COMPLEXITY O(N) x O(no of quads) x 2
/*
 * O(N) => hashset   => O(N) (Worst Case)
 * O(no of quads) => tripletSet
 * O(no of quads) => ans
*/
std::vector<std::vector<int>> betterApproach(std::vector<int> arr, int target) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      std::set<int> st;
      for (int k = j + 1; k < n; k++) {
        int l = target - (arr[i] + arr[j] + arr[k]);
        if (st.count(l)) {
          // * found a quadraplet
          std::vector<int> temp = {arr[i], arr[j], arr[k], l};
          sort(temp.begin(), temp.end());
          vectorSet.insert(temp);
        }
        st.insert(arr[k]);
      }
    }
  }

  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH (TWO POINTERS) -------------------------
// * ****** Intuition ******
// * Two Pointer

// * TIME COMPLEXITY O(N^3) 
// * Space Complexity O(no of quads) => ans

std::vector<std::vector<int>> fourSum(std::vector<int> arr, int target) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;

  // * Sort the input arr
  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) {
    // * avoid the duplicates while moving i:
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    for (int j = i + 1; j < n; j++) {
      // * avoid the duplicates while moving j:
      if (j != i + 1 && arr[j] == arr[j - 1])
        continue;
      int k = j + 1, l = n - 1;
      // * 2 pointers:
      while (k < l) {
        long sum = arr[i];
        sum += arr[j];
        sum += arr[k];
        sum += arr[l];
        if(sum == target) {
          std::vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp);
          k++, l--;
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l--;
        } 
        else if(sum > target) l--;
        else k++;
      }
    }
  }
  return ans;
}

int main() {
  // * testcase 1
  int target = 0;
  // * testcase 2
  std::vector<int> arr = {1, 0, -1, 0, -2, 2};
  // int target = 8;
  // std::vector<int> arr = {2, 2, 2, 2, 2};

  // std::vector<std::vector<int>> ans = bruteForce(arr);
  // std::vector<std::vector<int>> ans = betterApproach(arr);
  std::vector<std::vector<int>> ans = fourSum(arr, target);

  printMatrix(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-four-sum-sorted-arr.cpp -o output && ./output

