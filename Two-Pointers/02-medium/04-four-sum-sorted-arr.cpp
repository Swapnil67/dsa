/*
 * Leetcode - 18
 * Four Sum
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 0 <= a, b, c, d < ‘N’ and a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target

 * Example 1
 * Input  : 'nums' = [1,0,-1,0,-2,2], target = 0
 * Output : [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * Example 2
 * Input  : 'nums' = [2,2,2,2,2], target = 8
 * Output : [[2,2,2,2]]

 * https://leetcode.com/problems/4sum/
 * https://www.naukri.com/code360/problems/4sum_5713771
 * https://www.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
*/

#include <set>
#include <vector>
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// ****** Intuition ******
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
vector<vector<int>> bruteForce(vector<int>arr) {
  int n = arr.size();
  set<vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          int sum = arr[i] + arr[j] + arr[k] + arr[l];
          // cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << endl;
          if (sum == 0) {
            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            sort(temp.begin(), temp.end());
            vectorSet.insert(temp);
          }
        }
      }
    }
  }

  vector<vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// ****** Intuition ******
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
vector<vector<int>> betterApproach(vector<int> arr, int target) {
  int n = arr.size();
  set<vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      set<int> st;
      for (int k = j + 1; k < n; k++) {
        int l = target - (arr[i] + arr[j] + arr[k]);
        if (st.count(l)) {
          // * found a quadraplet
          vector<int> temp = {arr[i], arr[j], arr[k], l};
          sort(temp.begin(), temp.end());
          vectorSet.insert(temp);
        }
        st.insert(arr[k]);
      }
    }
  }

  vector<vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH (TWO POINTERS) -------------------------
// ****** Intuition ******
// * Two Pointer

// * TIME COMPLEXITY O(N^3) 
// * Space Complexity O(no of quads) => ans

vector<vector<int>> fourSum(vector<int> arr, int target) {
  int n = arr.size();
  vector<vector<int>> ans;

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
        long sum = arr[i] + arr[j] + arr[k] + arr[l];
        if (sum == target) {
          ans.push_back({arr[i], arr[j], arr[k], arr[l]});
          k++, l--;
          
          while (k < l && arr[k] == arr[k - 1])
            k++;

          // * Redundant
          // while (k < l && arr[l] == arr[l + 1])
          //   l--;
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
  vector<int> arr = {1, 0, -1, 0, -2, 2};
  
  // * testcase 2
  // int target = 8;
  // vector<int> arr = {2, 2, 2, 2, 2};

  // vector<vector<int>> ans = bruteForce(arr);
  // vector<vector<int>> ans = betterApproach(arr);
  vector<vector<int>> ans = fourSum(arr, target);

  for (auto &vec : ans)
    printArr(vec);
  return 0;
}

// * Run the code
// * g++ --std=c++17 04-four-sum-sorted-arr.cpp -o output && ./output

