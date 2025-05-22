/*
 * Leetcode - 2161
 * Partition Array According to Given Pivot

 * Example 1:
 * Input: nums = [9,12,5,10,14,3,10], pivot = 10
 * Output: [9,5,3,10,10,12,14]
 * [ less than pivot   Eq to pivot     Greater than pivot ]
 * [  9 5 3             10 10           12 14  ]

 * Example 1:
 * Input: nums = [-3,4,3,2], pivot = 2
 * Output: [-3,2,4,3]

 * https://leetcode.com/problems/partition-array-according-to-given-pivot/
*/

#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Keep vectors of less_than_pivot, equal_to_pivot, greater_than_pivot 
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> &arr, int pivot) {
  int n = arr.size();
  std::vector<int> less_than_pivot;
  std::vector<int> equal_to_pivot;
  std::vector<int> greater_than_pivot;
  for(int i = 0; i < n; ++i) {
    if (arr[i] < pivot) {
      less_than_pivot.push_back(arr[i]);
    }
    else if (arr[i] > pivot) {
      greater_than_pivot.push_back(arr[i]);
    }
    else {
      equal_to_pivot.push_back(arr[i]);
    }
  }

  // * here we use less_than_pivot for answer 
  for(int i = 0; i < equal_to_pivot.size(); i++) {
    less_than_pivot.push_back(equal_to_pivot[i]);
  }
  for(int i = 0; i < greater_than_pivot.size(); i++) {
    less_than_pivot.push_back(greater_than_pivot[i]);
  }

  return less_than_pivot;
}

// * ------------------------- APPROACH 2A: Optimal APPROACH -------------------------`
// * Get the starting positions of less than & greater than elements
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)

// *  less than pivot   Eq to pivot     Greater than pivot
// *  ----------        ----------      -------------
// *  ^ = i            ^ = j            ^ = k
std::vector<int> pivotArray(std::vector<int> &arr, int pivot) {
  int n = arr.size();
  int less_than_pivot_cnt = 0, equal_to_pivot_cnt = 0;
  for(int i = 0; i < n; ++i) {
    if (arr[i] < pivot) {
      less_than_pivot_cnt++;
    }
    else if (arr[i] == pivot) {
      equal_to_pivot_cnt++;
    }
  }

  // std::cout << less_than_pivot_cnt << " " << equal_to_pivot_cnt << std::endl;

  std::vector<int> ans(n);
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
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> pivotArray2(std::vector<int> &arr, int pivot) {
  int n = arr.size();
  int i = 0, j = n - 1;
  int lessIdx = 0, moreIdx = n - 1; // * For ans index
  std::vector<int> ans(n);

  while (i < n && j >= 0) {
    if (arr[i] < pivot) {
      ans[lessIdx] = arr[i];
      lessIdx++;
    }

    if (arr[j] > pivot) {
      ans[moreIdx] = arr[j];
      moreIdx--;
    }

    // * Keep incr/decr the i & j pointers
    i++, j--;
  }

  // * Put pivot in indexes from l -> r
  while(lessIdx <= moreIdx) {
    ans[lessIdx] = pivot;
    lessIdx++;
  }

  return ans;
}

int main() {
  int pivot = 10;
  std::vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  printArr(nums);

  // std::vector<int> ans = bruteForce(nums, pivot);
  // std::vector<int> ans = pivotArray(nums, pivot);
  std::vector<int> ans = pivotArray2(nums, pivot);
  printArr(ans);
  return 0;
}


// * Run the code
// * g++ --std=c++20 12-partition-arr-to-given-pivot.cpp -o output && ./output