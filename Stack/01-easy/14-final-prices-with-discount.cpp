/*
 * Leetcode - 1475
 * Final Prices With a Special Discount in a Shop
 * You are given an integer array prices where prices[i] is the price of the ith item in a shop.
 * There is a special discount for items in the shop. If you buy the ith item, 
 * then you will receive a discount equivalent to prices[j] where j is the minimum index such that 
 * j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.
 * 
 * Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, 
 * considering the special discount.
 * 
 * Example 1
 * input : prices = [8,4,6,2,3]
 * output : [4,2,4,2,3]
 * 
 * Example 2
 * input : prices = [1,2,3,4,5]
 * output : [1,2,3,4,5]
 * 
 * https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
*/

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N) (ans vector)
std::vector<int> bruteForce(std::vector<int> prices) {
  int n = prices.size();
  std::vector<int> ans = prices;
  for (int i = 0; i < n; ++i) {
    int cur_discount = prices[i];
    for (int j = i + 1; j < n; ++j) {
      if(prices[j] <= prices[i]) {
        ans[i] = prices[i] - prices[j];
        break;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Monotonic Stack
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) (stack)
std::vector<int> finalPrices(std::vector<int> prices) {
  int n = prices.size();
  std::vector<int> ans = prices;
  std::stack<int> monotonic_stack;

  for (int i = 0; i < n; ++i) {
    while (!monotonic_stack.empty() && prices[i] <= prices[monotonic_stack.top()]) {
      ans[monotonic_stack.top()] = prices[monotonic_stack.top()] - prices[i];
      monotonic_stack.pop();
    }
    monotonic_stack.push(i);
  }

  return ans;
}

int main() {
  std::cout << "Prices before discount" << std::endl;
  std::vector<int> prices = {8, 4, 6, 2, 3};
  printArr(prices);

  std::cout << "Prices after discount" << std::endl;
  // std::vector<int> discounts = bruteForce(prices);
  std::vector<int> discounts = finalPrices(prices);
  printArr(discounts);
  return 0;
}

// * Run the code
// * g++ -std=c++17 14-final-prices-with-discount.cpp -o output && ./output