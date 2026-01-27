/*
 * Leetcode - 2064
 * Minimized Maximum of Products Distributed to Any Store
 * 
 * You are given an integer n indicating there are 'n' specialty retail stores. 
 * There are 'm' product types of varying amounts, which are given as a 0-indexed integer array `quantities`, 
 * where `quantities[i]` represents the number of products of the ith product type.

 * You need to distribute all products to the retail stores following these rules:
 * - A store can only be given at most one product type but can be given any amount of it.
 * - After distribution, each store will have been given some number of products (possibly 0).
 * Let x represent the maximum number of products given to any store. You want x to be as small as possible, 
 * i.e., you want to minimize the maximum number of products that are given to any store.

 * Example 1:
 * Input       : n = 6, quantities = [11,6]
 * Output      : 3
 * Explanation : max(2, 3, 3, 3, 3, 3) = 3

 * Example 2:
 * Input       : n = 7, quantities = [15,10,10]
 * Output      : 5
 * Explanation : max(5, 5, 5, 5, 5, 5, 5) = 5
 
 * https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/
 */

#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * If we can distribute products in more stores than given the return false 
bool isValidQuantities(std::vector<int> quantities, int stores, int maxQuantity) {
  for (int &products : quantities) {
    // stores -= std::ceil((float)quantities[i] / (float)maxQuantity);
    stores -= ((products + maxQuantity - 1) / maxQuantity); // * alternative for ceil (faster than ceil)
    // std::cout << " --> " << (products + maxQuantity - 1) / maxQuantity << std::endl;
    // * products were distributed in more than necessary stores
    if (stores < 0)
      return false;
  }
  return true;
}

// * ------------------------- APPROACH : Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int minimizedMaximum(std::vector<int> quantities, int stores) {
  int n = quantities.size();
  int l = 1, r = *std::max_element(begin(quantities), end(quantities));
  int ans = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (isValidQuantities(quantities, stores, m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main(void) {
  int stores = 6;
  std::vector<int> quantities = {11, 6};

  // int stores = 7;
  // std::vector<int> quantities = {15, 10, 10};

  std::cout << "Stores: " << stores << std::endl;
  std::cout << "Product Quantities" << std::endl;
  printArr(quantities);

  int ans = minimizedMaximum(quantities, stores);
  std::cout << "Maximum of Products Distributed to Any Store " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++17 16-min-max-products-distributed.cpp -o output && ./output

// * DRY RUN
// * Quantities = [15, 10, 10], stores = 7

// * l = 0, r = 15, m = 7
// * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
// * [l                    m                            r]

// * 7 => 3 + 2 + 2 = 7  
// * (7 - 7) == 0           --- Valid quantity (r = m - 1)

// * l = 0, r = 6, m = 3
// * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
// * [l        m        r]

// * 3 => 5 + 3 + 3 = 11
// * (7 - 11) == -4           --- More quantity distributed (l = m + 1)

// * l = 4, r = 6, m = 5
// * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
// *              [l m r]

// * 5 => 3 + 2 + 2 = 7
// * (7 - 7) == 0           --- Valid quantity (r = m - 1)

// * l = 4, r = 4, m = 4
// * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
// *            [lmr]

// * 5 => 4 + 3 + 3 = 10
// * (7 - 10) == -3           --- More quantity distributed (l = m + 1)

// * Break the loop

