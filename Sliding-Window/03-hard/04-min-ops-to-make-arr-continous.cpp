
/**
 * * Frequency of the Most Frequent Element
 * * You are given an integer array nums and an integer k. In one operation, you can choose an index 
 * * of nums and increment the element at that index by 1.
 * * Return the maximum possible frequency of an element after performing at most k operations.

 * * Example 1
 * * Input  : nums = [1,2,4], k = 5
 * * Output : 3
 * * Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
 * 
 * * https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/
*/

#include<set>
#include<vector>
#include<climits>
#include<iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * Use [min_ele, max_ele] window for every 'i'
// * max_ele = min_ele + n - 1
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(std::vector<int> &arr) {
  int n = arr.size();
  int min_ops = INT_MAX;
  for(int i = 0; i < n; ++i) {
    // * cur range [L, R] => [min_ele, max_ele]
    int L = arr[i], R = L + n - 1; 
    int cur_operations = 0;
    std::set<int> st;
    for(int j = 0; j < n; ++j) {
      // * cur element exists b/w L & R & also not duplicate
      if ((arr[j] >= L && arr[j] <= R) && (!st.count(arr[j]))) {
        st.insert(arr[j]);
        continue;
      }
      else {
        // * cur element does not exists b/w L & R
        cur_operations += 1;
      }
    }
    min_ops = std::min(min_ops, cur_operations);
  }
  return min_ops;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Use [min_ele, max_ele] window of element that satifies condition
// * max_ele = min_ele + n - 1
// * TIME COMPLEXITY O(Nlogn)
// * SPACE COMPLEXITY O(N)
int minOperations(std::vector<int> &arr) {
  int n = arr.size();

  // * Sort the Arr & Eliminate Duplicates
  std::set<int> st(arr.begin(), arr.end());
  std::vector<int> temp(st.begin(), st.end());

  printArr(temp);

  int r = 0, min_operations = INT_MAX;
  for(int l = 0; l < n; ++l) {
    // * arr[l], arr[l] + n - 1       => [min_ele, max_ele]
    // * Incr 'r' till one past upper bound (that's why we did not include '-1')
    while(r < temp.size() && temp[r] < temp[l] + n) {
      r += 1; 
    }

    // * Current valid window
    int window = r - l;
    min_operations = std::min(min_operations, n - window);
  }
  return min_operations;
}

int main() {
  // * testcase 1
  // std::vector<int> arr = {1, 2, 3, 5, 6};

  // * testcase 2
  std::vector<int> arr = {1, 10, 100, 1000};

  // * testcase 3
  // std::vector<int> arr = {1, 3, 2, 3};


  printf("Input Array\n");
  printArr(arr);

  // int ans = bruteForce(arr);
  int ans = minOperations(arr);
  printf("Minimum Number of Operations to Make Array Continuous: %d\n", ans);
  // printArr(ans);

  return 0;
}

// * Run the code
// * $CXX --std=c++20 04-min-ops-to-make-arr-continous.cpp -o output && ./output