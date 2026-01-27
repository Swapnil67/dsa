
/*
 * Leetcode - 1711
 * Count Good Meals
 * 
 * A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a
 * power of two.
 * 
 * You can pick any two different foods to make a good meal.
 * 
 * Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ 
 * item of food, return the number of different good meals you can make from this list modulo 109 + 7.
 * 
 * Note that items with different indices are considered different even if they have the 
 * same deliciousness value.

 * Example 1:
 * Input:  deliciousness = [1,3,5,7,9]
 * Output: 4
 * Explanation: The good meals are (1,3), (1,7), (3,5) and, (7,9).
 *              Their respective sums are 4, 8, 8, and 16, all of which are powers of 2.
 * 
 * Example 1:
 * Input:  deliciousness = [1,1,1,3,3,3,7]
 * Output: 15
 * Explanation: The good meals are (1,1) with 3 ways, (1,3) with 9 ways, and (1,7) with 3 ways.

 * https://leetcode.com/problems/count-good-meals/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

int countPairs(std::vector<int>& deliciousness) {
  int ans = 0;
  int mod = 1e9 + 7;

  sort(begin(deliciousness), end(deliciousness));

  std::unordered_map<int, int> mp;
  for (auto& x : deliciousness) {
    // * Power of 2 from 0 to 21
    for (int i = 0; i <= 21; ++i) { 
      int z = 1 << i;
      int y = z - x;
      if (y > x)
          break;

      ans += mp[y]; // * check if seen
      ans %= mod;
    }
    mp[x]++;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<int> deliciousness = {1, 3, 5, 7, 9};

  // * testcase 2
  // std::vector<int> deliciousness = {1, 1, 1, 3, 3, 3, 7};

  int ans = countPairs(deliciousness);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}