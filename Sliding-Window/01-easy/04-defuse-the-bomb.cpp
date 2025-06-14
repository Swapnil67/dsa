/**
 * * Leetcode - 1652
 * * Defuse the Bomb
 * 
 * * You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular
 * * array code of length of n and a key k.
 * * To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

 * * If k > 0, replace the ith number with the sum of the next k numbers.
 * * If k < 0, replace the ith number with the sum of the previous k numbers.
 * * If k == 0, replace the ith number with 0.
 * 
 * * As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].
 * * Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
 * 
 * * Example 1
 * * Input  : code = [5,7,1,4], k = 3
 * * Output : [12,10,16,13]
 * 
 * * Example 2
 * * Input  : code = [1,2,3,4], k = 0
 * * Output : [0,0,0,0]
 * 
 * * Example 3
 * * Input  : code = [2,4,9,3], k = -2
 * * Output : [12,5,6,13]

 * * https://leetcode.com/problems/defuse-the-bomb/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * TIME COMPLEXITY O(N * k)
// * SPACE COMPLEXITY O(N)    // * For Answer only
std::vector<int> bruteForce(std::vector<int>& code, int k) {
  int n = code.size();
  std::vector<int> ans(n, 0);

  if (k == 0)
    return ans;
  
  int i = 0;
  while (i != n) {
    if (k < 0) {
      // * start from curr element till 'k' prev elements
      for(int j = i - std::abs(k); j < i; ++j) {
        ans[i] += code[(j + n) % n];
      }
    }
    else {
      // * start from next element till 'k' next elements
      for(int j = i + 1; j <= i + k; ++j) {
        ans[i] += code[j % n];
      }
    }
    i++;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`

std::vector<int> decrypt(std::vector<int>& code, int k) {
  int n = code.size();
  std::vector<int> ans(n, 0);

  if (k == 0)
    return ans;

  // * Get the window pointers
  int i = -1, j = -1;
  if (k < 0) {
    i = n - std::abs(k);
    j = n - 1;
  } else {
    i = 1;
    j = k;
  }
  // std::cout << i << " " << j << std::endl;
  
  // * calculate the initial window value
  int windowSum = 0;
  for (int k = i; k <= j; ++k) {
    windowSum += code[k];
  }

  for (int x = 0; x < n; ++x) {
    // * Update the ans index 
    ans[x] = windowSum;

    // * remove the ele from the start of window
    windowSum -= code[i];
    i = (i + 1) % n;

    // * Add the ele from the start of window
    j = (j + 1) % n;
    windowSum += code[j];
  }
  return ans;
}

int main() {  
  // int k = 3;
  // std::vector<int> code = {5, 7, 1, 4};

  int k = -2;
  std::vector<int> code = {2, 4, 9, 3};

  std::cout << "code: " << std::endl;
  printArr(code);
  std::cout << "Decrypted Code: " << std::endl;

  // std::vector<int> ans = bruteForce(code, k);
  std::vector<int> ans = decrypt(code, k);
  printArr(ans);

  return 0;
}

// * g++ --std=c++17 04-defuse-the-bomb.cpp -o output && ./output