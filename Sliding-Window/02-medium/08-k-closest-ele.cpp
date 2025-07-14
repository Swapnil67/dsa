/**
 * * Leetcode - 658
 * * Find K Closest Elements
 * * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
 * * The result should also be sorted in ascending order.
 * 
 * * An integer a is closer to x than an integer b if:
 * * |a - x| < |b - x|, or
 * * |a - x| == |b - x| and a < b

 * * Example 1
 * * Input: arr = [1, 2, 3, 4, 5], k = 4, x = 3
 * * Output : [1, 2, 3, 4]
 * 
 * * Example 2
 * * Input  :  arr = [1, 1, 2, 3, 4, 5], k = 4, x = -1
 * * Output : [1, 1, 2, 3]
 * 
 * * https://leetcode.com/problems/find-k-closest-elements/description/
*/

#include <deque>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Push the difference of first k elements to deque
// * TIME COMPLEXITY O(N * k)
// * SPACE COMPLEXITY O(N)
std::vector<int> bruteForce(std::vector<int> arr, int k, int x) {
  std::deque<std::pair<int, int>> dq;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    if(dq.size() < k) {
      dq.push_back({arr[i] - x, arr[i]});
    }
  }
  
  std::vector<int> ans;
  for(int i = 0; i < dq.size(); i++) {
    // printf("arr[i] - x: %d \t arr[i]: %d\n", dq[i].first, dq[i].second);
    ans.push_back(dq[i].second);
  }
  return ans;
}

// * f(m) = abs(arr[m] - x)
// * 1st number in window will always be closer to x than the last+1 element
// * g(m) = f(m) <= f(m+k)

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Sliding Window + Binary Search
// * x - arr[m] > arr[m+k] - x
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
  int n = arr.size();
  // * 'r' is little restricted becoz m + k should not become greater than n
  int l = 0, r = n - k;
  // * binary search
  while(l < r) {
    int m = (l + r) / 2; // * m is the starting point of window of size k

    // printf("arr[%d] = %d & arr[%d + k] = %d\n", m, arr[m], m, arr[m + k]);
    // * start of window is not smaller than one outside of window
    if (x - arr[m] > arr[m + k] - x) {
      l = m + 1;
    }
    else {
      // * f(m) <= f(m+k) (True)
      r = m;
    }
  }
  return std::vector(arr.begin() + l, arr.begin() + l + k);
}

int main() {

  // * testcase 1
  // int k = 4, x = 3;
  // std::vector<int> arr = {1, 2, 3, 4, 5};

  // * testcase 2
  // int k = 4, x = -1;
  // std::vector<int> arr = {1, 1, 2, 3, 4, 5};

  // * testcase 2
  int k = 1, x = 9;
  std::vector<int> arr = {1, 1, 1, 10, 10, 10};

  printf("Input Array: ");
  printArr(arr);

  // std::vector<int> ans = bruteForce(arr, k, x);
  std::vector<int> ans = findClosestElements(arr, k, x);
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-k-closest-ele.cpp -o output && ./output


// * ============ DRY RUN ============
// * arr = [1, 1, 2, 3, 4, 5], n = 6, k = 4, x = -1
// * l = 0, r = (n - k) = 2

// * --------------------------------------

// * [1, 1, 2, 3, 4, 5]
// *  l  m  r 

// * x - arr[m]     = -1 - 1    = -2
// * arr[m + k] - x = 5 - (- 1) = 6
// * r = m (left side is more closer)

// * --------------------------------------

// * [1, 1, 2, 3, 4, 5]
// *  l  r  
// *  m  

// * x - arr[m]     = -1 - 1    = -2
// * arr[m + k] - x =  4 - (-1) = 5
// * r = m (left side is more closer)

// * --------------------------------------

// * [1, 1, 2, 3, 4, 5]
// *  l 
// *  r

// * Ans = { arr.begin() + l, arr.begin() + l + k }

// * Break the loop