/*
 * Leetcode - 2149
 * Rearrange Array Elements by Sign
 * 
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of
 * positive and negative integers.
 * 
 * Example 1:
 * Input: nums = [3, 1, -2, -5, 2, -4]
 * Output: [3, -2, 1, -5, 2, -4]
 * Explanation: The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].

 * Example 2:
 * Input: nums = [-1,1]
 * Output: [1,-1]
 * Explanation: 1 is the only positive integer and -1 the only negative integer in nums.
 * 
 * https://www.naukri.com/code360/problems/alternate-numbers_6783445
 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
*/

// ! Here number of -ve & +ve integers are equal

#include <vector>
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
// * Create different arrays for +ve & -ve elements
// * TIME COMPLEXITY O(N) + O(N/2)
// * SPACE COMPLEXITY O(N)
vector<int> bruteForce(vector<int> &arr) {
  vector<int> n_pos;
  vector<int> n_neg;
  int n = arr.size();

  // * O(N)
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) 
      n_pos.push_back(arr[i]);
    else
      n_neg.push_back(arr[i]);
  }

  // * O(N/2)
  for (int i = 0; i < n / 2; i++) {
    arr[2 * i] = n_pos[i];
    arr[2 * i + 1] = n_neg[i];
  }
  return arr;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Take +ve and -ve indexes in variable 
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
vector<int> rearrangeArray(vector<int> arr) {
  int n = arr.size();

  // * initialize the ans array
  vector<int> ans(n);

  // * Intialize the positive & negative indexes
  int p_index = 0; // * even index
  int n_index = 1; // * odd index
  for (int i = 0; i < n; i++) {
    if(arr[i] < 0) {
      ans[n_index] = arr[i];
      n_index += 2; // * next negative index
    } else {
      ans[p_index] = arr[i];
      p_index += 2; // * next positive index
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Variant 1 - number of -ve & +ve integers are not equal
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
vector<int> rearrangeArrayVariant(vector<int> arr) {
  int n = arr.size();

  vector<int> pos_vec, neg_vec;
  for (auto &x: arr) {
    if (x > 0)
      pos_vec.push_back(x);
    else
      neg_vec.push_back(x);
  }

  // printArr(pos_vec);
  // printArr(neg_vec);

  // * initialize the ans array
  vector<int> ans(n);

  int pos_idx = 0, neg_idx = 1;
  if (pos_vec.size() > neg_vec.size()) {
    for (int i = 0; i < neg_vec.size(); ++i) {
      ans[2 * i] = pos_vec[i];
      ans[2 * i + 1] = neg_vec[i];
    }
    int idx = (neg_vec.size() * 2);
    for (int i = neg_vec.size(); i < n; ++i) {
      ans[idx] = pos_vec[i];
      idx++;
    }
  }
  else {
    for (int i = 0; i < pos_vec.size(); ++i) {
      ans[2 * i] = pos_vec[i];
      ans[2 * i + 1] = neg_vec[i];
    }
    int idx = pos_vec.size() * 2;
    for (int i = pos_vec.size(); i < n; ++i) {
      ans[idx] = neg_vec[i];
      idx++;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // vector<int> arr = {1, 2, -4, -5};
  
  // * testcase 2
  // vector<int> arr = {3, 1, -2, -5, 2, -4, 7, 8};

  // * testcase 3
  vector<int> arr = {3, 1, -2, -5, 2, -4, -7, -8, 3, -9};

  cout << "Before Rearranging" << endl;
  printArr(arr);

  // vector<int> ans = bruteForce(arr);
  // vector<int> ans = rearrangeArray(arr);
  // cout << "After Rearranging" << endl;
  // printArr(ans);
  
  vector<int> ans2 = rearrangeArrayVariant(arr);
  cout << "After Rearranging" << endl;
  printArr(ans2);

  return 0;
}

// * Run the code
// * g++ --std=c++17 10-rearrange-array-elements-by-sign-a.cpp -o output && ./output