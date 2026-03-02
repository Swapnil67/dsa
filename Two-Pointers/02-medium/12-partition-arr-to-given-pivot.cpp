/*
 * Leetcode - 2161
 * Partition Array According to Given Pivot
 *
 * Example 1:
 * Input: nums = [9,12,5,10,14,3,10], pivot = 10
 * Output: [9,5,3,10,10,12,14]
 * 
 * [ less than pivot   Eq to pivot     Greater than pivot ]
 * [  9 5 3             10 10           12 14  ]
 *
 * Example 1:
 * Input: nums = [-3,4,3,2], pivot = 2
 * Output: [-3,2,4,3]
 *
 * https://leetcode.com/problems/partition-array-according-to-given-pivot/
*/

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
// * Keep vectors of less_than_pivot, equal_to_pivot, greater_than_pivot 
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
vector<int> bruteForce(vector<int> &arr, int pivot) {
  int n = arr.size();
  vector<int> less_than_pivot;
  vector<int> equal_to_pivot;
  vector<int> greater_than_pivot;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < pivot) {
      less_than_pivot.push_back(arr[i]);
    } else if (arr[i] > pivot) {
      greater_than_pivot.push_back(arr[i]);
    } else {
      equal_to_pivot.push_back(arr[i]);
    }
  }

  less_than_pivot.insert(less_than_pivot.end(), begin(equal_to_pivot), end(equal_to_pivot));
  less_than_pivot.insert(less_than_pivot.end(), begin(greater_than_pivot), end(greater_than_pivot));

  return less_than_pivot;
}

// * ------------------------- APPROACH 2A: Optimal APPROACH -------------------------
// * Get the starting positions of less than & greater than elements
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)

// *  less than pivot   Eq to pivot     Greater than pivot
// *  ----------        ----------      -------------
// *  ^ = i            ^ = j            ^ = k
vector<int> pivotArray(vector<int> &arr, int pivot) {
  int n = arr.size();
  int less_than_pivot_cnt = 0, equal_to_pivot_cnt = 0;
  for (auto& x : arr) {
    if (x < pivot) {
      less_than_pivot_cnt++;
    }
    else if (x == pivot) {
      equal_to_pivot_cnt++;
    }
  }

  vector<int> ans(n);
  int i = 0;     // * Less than pivot
  int j = less_than_pivot_cnt;
  int k = less_than_pivot_cnt + equal_to_pivot_cnt;
  for(int &num : arr) {
    if(num < pivot) {        // * Elements lesser than pivot
      ans[i] = num;
      i++;
    } else if(num > pivot) { // * Elements greater than pivot
      ans[k] = num;
      k++;
    } else {                 // * Elements equal to pivot  
      ans[j] = num;
      j++;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2B: Optimal APPROACH -------------------------`
// * Classic Two Pointer Approach
// * The key here is to incr 'i' till n & decr 'j' till 0
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
vector<int> pivotArray2(vector<int> &arr, int pivot) {
  int n = arr.size();
  
  vector<int> ans(n);
  int i = 0, j = n - 1;
  int start_idx = 0, end_idx = n - 1; // * For ans index

  while (i < n && j >= 0) {
    // * Put the smaller than pivot from front
    if (arr[i] < pivot) {
      ans[start_idx] = arr[i];
      start_idx++;
    }

    // * Put the greater than pivot from back
    if (arr[j] > pivot) {
      ans[end_idx] = arr[j];
      end_idx--;
    }

    // * Keep incr/decr the i & j pointers
    i++, j--;
  }

  // * Put pivot in indexes from l -> r
  while (start_idx <= end_idx) {
    ans[start_idx] = pivot;
    start_idx++;
  }

  return ans;
}

int main() {
  // * testcase 1
  int pivot = 10;
  vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  
  // * testcase 2
  // int pivot = 2;
  // vector<int> nums = {-3, 4, 3, 2};

  std::cout << "pivot: " << pivot << std::endl;
  std::cout << "Input nums: ";
  printArr(nums);

  // vector<int> ans = bruteForce(nums, pivot);
  // vector<int> ans = pivotArray(nums, pivot);
  vector<int> ans = pivotArray2(nums, pivot);

  std::cout << "Answer: ";
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-partition-arr-to-given-pivot.cpp -o output && ./output
