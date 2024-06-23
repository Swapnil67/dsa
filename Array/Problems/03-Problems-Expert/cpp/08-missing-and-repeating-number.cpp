/**
 * * Merge overlapping intervals
 * * Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.
 * * You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space.
 * * Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' 
 * * should have the last 'M' elements. 
 * 
 * * Note
 * * You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
 *
 * * Example 1
 * * Input  :  arr = {4, 3, 6, 2, 1, 1}
 * * Output : [1, 5]
 * * Explanation : 1 is Repeating & 5 is missing number

 * * https://www.naukri.com/code360/problems/missing-and-repeating-numbers_6828164
*/


#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> arr) {
  int n = arr.size();
  int repeating = -1, missing = -1;
  for (int i = 1; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[j] == i) cnt++;
    }
    if(cnt == 2) repeating = i;
    else if(cnt == 0) missing = i;

    if (repeating != -1 && missing != -1)
      break;
  }
  return { repeating, missing };
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Hashed Array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
std::vector<int> betterApproach(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> hashArr(n+1, 0);
  // * O(N)
  int missing = -1, repeating = -1;
  for (int i = 0; i < n; i++) {
    hashArr[arr[i]]++;
  }
  // * O(N)
  for (int i = 1; i <= n; i++) {
    if(hashArr[i] > 1) repeating = i;
    else if(hashArr[i] == 0) missing = i;
    if (repeating != -1 && missing != -1)
      break;
  }
  return {repeating, missing};
}

// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Maths & Equations 
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> findMissingRepeatingNumbers(std::vector<int> arr) {
  long long n = arr.size();
  // * S - SN | x - y
  // * S2 - S2N

  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

  long long S = 0, S2 = 0;
  for (int i = 0; i < n; i++) {
    S += arr[i];
    S2 += (long long)arr[i] * (long long)arr[i];
  }

  long long val1 = S - SN; // * x - y
  long long val2 = S2 - S2N; // * (x^2 - y^2) = (x - y)(x + y)
  val2 = val2 / val1; // * x + y
  // std::cout << val1 << " " << val2 << std::endl;

  long long x = (val1 + val2) / 2;
  long long y = x - val1;

  return {(int)x, (int)y};
}

int main() {
  std::vector<int> arr = {4, 3, 6, 2, 1, 1};
  printArr(arr);
  // std::vector<int> ans = bruteForce(arr);
  // std::vector<int> ans = betterApproach(arr);
  std::vector<int> ans = findMissingRepeatingNumbers(arr);
  printArr(ans);
  return 0;
}

// * Run the code.
// * g++ --std=c++17 08-missing-and-repeating-number.cpp -o 08-missing-and-repeating-number && ./08-missing-and-repeating-number