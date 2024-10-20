/*
 * Minimum Penalty for a Shop
 * You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only
 * of characters 'N' and 'Y':
 * If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:
 * For every hour when the shop is open and no customers come, the penalty increases by 1.
 * For every hour when the shop is closed and customers come, the penalty increases by 1.

 * Example 1:
 * Input: customers = "YYNY"
 * Output: 2
 * 
 * Example 2:
 * Input: customers = "YYYY"
 * Output: 4
 * 
 * Example 3:
 * Input: customers = "NNNNN"
 * Output: 0
 * 
 * https://leetcode.com/problems/minimum-penalty-for-a-shop/description/ 
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(nlogn) +  O(N^2)
// * SPACE COMPLEXITY O(2)
int bruteForce(std::string customers) {
  int n = customers.size();
  int min_penalty = INT_MAX, min_hr = INT_MAX;

  for (int i = 0; i <= n; ++i) {
    int close_hr = i, penalty = 0;
    for (int j = 0; j <= n; ++j) {
      // * if shop is already closed and customer comes then add penalty
      if(j >= close_hr && customers[j] == 'Y') {
        penalty += 1;
      }
      // * If shop is open and no customer comes then add penalty
      if(close_hr > j && customers[j] == 'N') {
        penalty += 1;
      }
    }
    std::cout << close_hr << " => " << penalty << std::endl;
    if(penalty < min_penalty) {
      min_penalty = penalty;
      // min_hr = std::min(min_hr, close_hr);
      min_hr = close_hr;
    }
  }
  return min_hr;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Prefix & Suffix sum
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1) [For Answer]
int bestClosingTime(std::string customers) {
  int n = customers.size();

  // * Penalty for "N" when shop is open
  std::vector<int> prefix_n(n + 1);
  int prefix_cnt = 0;
  for (int i = 0; i <= n; ++i) {
    prefix_n[i] = prefix_cnt;
    if(customers[i] == 'N') {
      prefix_cnt += 1;
    }
  }
  // printArr(prefix_n);

  // * Penalty for "Y" when shop is closed
  std::vector<int> suffix_y(n + 1);
  int suffix_cnt = 0;
  for (int i = n; i >= 0; --i) {
    if(customers[i] == 'Y') {
      suffix_cnt += 1;
    }
    suffix_y[i] = suffix_cnt;
  }
  // printArr(suffix_y);

  int min_penalty = INT_MAX, hr = INT_MAX;
  for (int i = 0; i <= n; ++i) {
    int penalty = prefix_n[i] + suffix_y[i];
    if(penalty < min_penalty) {
      min_penalty = penalty;
      hr = i;
    }
  }

  return hr;
}


int main() {
  // * testcase 1
  // std::string customers = "YYYY";
  // * testcase 2
  // std::string customers = "NNNN";
  // * testcase 3
  // std::string customers = "YYNY";
  // * testcase 4
  // std::string customers = "YYNYN";
  // * testcase 5
  std::string customers = "YYYNYNY";
  std::cout << "customers: " << customers << std::endl;
  // int hour = bruteForce(customers);
  int hour = bestClosingTime(customers);
  std::cout << "Earliest hour to close shop is " << hour << std::endl;
  // bruteForce(customers);
}

// * run the code
// * g++ --std=c++17 13-min-penalty-for-shop.cpp -o output && ./output