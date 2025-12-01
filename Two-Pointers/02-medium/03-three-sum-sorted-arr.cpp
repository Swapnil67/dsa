/**
 * * Leetcode - 15
 * * Three Sum
 * * You are given an array ‘ARR’ containing ‘N’ integers.
 * * Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i and their 
 * * sum is equal to zero i.e. nums[i] + nums[j] + nums[k] == 0.

 * * Example 1
 * * Input  : 'nums' = [-1,0,1,2,-1,-4]
 * * Output : [[-1,-1,2],[-1,0,1]]
 * 
 * * Example 2
 * * Input  : 'nums' = [0,1,1]
 * * Output : []

 * * https://leetcode.com/problems/3sum/description/
 * * https://www.naukri.com/code360/problems/three-sum_6922132
*/

// ! Google, Meta, Dell

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
// * TIME COMPLEXITY O(N^3) x log(no of tripletes) = O(N^3) x log(m)
/*
 * O(N^3) => Three for loop
 * log(no of tripletes) => Set insert
*/
// * SPACE COMPLEXITY 2 x O(no of tripletes)
std::vector<std::vector<int>> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        int sum = arr[i] + arr[j] + arr[k];
        // std::cout<<arr[i]<<" + "<<arr[j]<<" + "<<arr[k]<<" = "<<sum<<std::endl;
        if(sum == 0) {
          std::vector<int> temp = { arr[i], arr[j], arr[k] };
          std::sort(temp.begin(), temp.end());
          vectorSet.insert(temp);
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
//* arr[i] + arr[j] + arr[k] = 0 
// * Then we can also derive the following
// * arr[k] = -(arr[i] + arr[j]);
// * here we are not finding 0 rather we are finding kth element
// * TIME COMPLEXITY O(N^2) x log(size of set) = O(N^2) x log(m)
/*
 * O(N^2) => Two for loop
 * log(m) => hashset (st)
*/
// * SPACE COMPLEXITY O(N) x O(no of triplets) x 2
/*
 * O(N) => hashset   => O(N) (Worst Case)
 * O(no of triplets) => tripletSet
 * O(no of triplets) => ans
*/
std::vector<std::vector<int>> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> triplet_set;
  for (int i = 0; i < n; i++) {
    std::set<int> st;
    for (int j = i + 1; j < n; j++) {
      int k = -(arr[i] + arr[j]);
      if (st.count(k)) {
        // * found a triplet
        std::vector<int> temp = {arr[i], arr[j], k};
        sort(temp.begin(), temp.end());
        triplet_set.insert(temp);
      }
      st.insert(arr[j]);
    }
  }
  std::vector<std::vector<int>> ans(triplet_set.begin(), triplet_set.end());
  return ans;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH (TWO POINTERS) -------------------------
// * TIME COMPLEXITY O(nlogn) + O(N^2)
/*
 * O(nlogn) => Sort the initial array
 * O(N^2) => Nested loop
*/
// * SPACE COMPLEXITY O(no of triplets)
// * O(no of triplets) => ans
std::vector<std::vector<int>> threeSum(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end()); // * n(logn)
  int n = arr.size(); 
  std::vector<std::vector<int>> ans;

  // * O(N^2)
  for (int i = 0; i < n; i++) {
    // * Doing this to prevent taking duplicate triplet
    if (i > 0 && arr[i - 1] == arr[i])
      continue;
    int j = i + 1, k = n - 1;
    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if(sum == 0) {
        ans.push_back({arr[i], arr[j], arr[k]});
        j++;
        k--;
        // * Doing this to prevent taking duplicate triplet
        while (j < n && arr[j] == arr[j - 1])
          j++;
        while (k >= 0 && arr[k] == arr[k + 1])
          k--;
      }
      else if (sum < 0)
        j++;
      else
        k--;
    }
  }
  return ans;
}

int main() {
  // std::vector<int> arr = {-1, 0, 1, 2, -1, -4};
  std::vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
  std::cout << "Input Array" << std::endl;
  printArr(arr);
  // std::vector<std::vector<int>> ans = bruteForce(arr);
  // std::vector<std::vector<int>> ans = betterApproach(arr);
  std::vector<std::vector<int>> ans = threeSum(arr);
  std::cout << "Tripletes which gives 0 sum" << std::endl;
  printMatrix(ans);

  return 0;
}


// * Run the code
// * g++ --std=c++17 03-three-sum-sorted-arr.cpp -o output && ./output