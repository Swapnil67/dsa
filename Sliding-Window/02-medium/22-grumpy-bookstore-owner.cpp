/**
 * * Grumpy Bookstore Owner
 * 
 * * Example 1
 * * Input  : customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
 * * Output : 16
 * * Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
 * * The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 * 
 * * Example 2
 * * Input  : customers = [1], grumpy = [0], minutes = 1
 * * Output : 1
 * 
 * * https://leetcode.com/problems/grumpy-bookstore-owner/description/
*/

#include <vector>
#include <climits>
#include <iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------`
// * Classic Sliding Window
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int minutes) {
  int n = customers.size();
  int max_unsatisfied_customers = INT_MIN;
  int cur_unsatisfied_customers = 0;
  int already_satisfied_customers = 0;
  int i = 0, j = 0;
  while (j < n) {
    if(j - i + 1 > minutes) {
      // * if owner was grumpy then remove those customers from cur_unsatisfied_customers
      if(grumpy[i]) {
        cur_unsatisfied_customers -= customers[i];
      }
      i += 1;
    }
    
    // * if owner was grumpy then add those customers to cur_unsatisfied_customers
    if (grumpy[j]) {
      cur_unsatisfied_customers += customers[j];
    }
    else {
      // * add these customers to already_satisfied_customers
      already_satisfied_customers += customers[j];
    }

    // * Max unsatisfied customer in window 
    if(j - i + 1 == minutes) {
      max_unsatisfied_customers = std::max(max_unsatisfied_customers, cur_unsatisfied_customers);
    }

    j += 1;
  }
  return max_unsatisfied_customers + already_satisfied_customers;
}

int main() {
  // * testcase 1
  // int minutes = 3;
  // std::vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  // std::vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};

  // * testcase 2
  int minutes = 1;
  std::vector<int> customers = {1};
  std::vector<int> grumpy = {0};

  std::cout << "Grumpy " << std::endl;
  printArr(grumpy);
  std::cout << "customers " << std::endl;
  printArr(customers);
  // int ans = bruteForce(customers, grumpy, minutes);
  int ans = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Number of customers satisfied are " << ans << std::endl;
  return 0;
}

// * run the code
// * g++ --std=c++20 22-grumpy-bookstore-owner.cpp -o output && ./output