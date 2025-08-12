/*
 * Leetcode - 2300
 * Successful Pairs of Spells and Potions
 
 * Example 1:
 * Input       : spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * Output      : [4,0,3]
 * Explanation : 
 * - 0th spells: 5 * [1,2,3,4,5] = [5, '10', '15', '20', '25']. 4 pairs are successful.
 * - 1st spells: 1 * [1,2,3,4,5] = [1, 2, 3, 4, 5]. 0 pairs are successful.
 * - 2nd spells: 3 * [1,2,3,4,5] = [3, 6, '9', '12', '15']. 3 pairs are successful.
 
 * Example 2:
 * Input       : spells = [3,1,2], potions = [8,5,8], success = 16
 * Output      : [2,0,2]
 * Explanation : 
 * - 0th spells: 3 * [8,5,8] = ['24', 15, '24']. 2 pairs are successful.
 * - 1st spells: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
 * - 2nd spells: 2 * [8,5,8] = ['16', 10, '16']. 2 pairs are successful. 

 * https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(n x m)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<int> &spells, std::vector<int> &potions, int success) {
  int n = spells.size();
  int m = potions.size();

  std::vector<int> pairs;
  
  for (int i = 0; i < n; ++i) {
    int curSpell = spells[i];
    int curPairs = 0;
    for (int j = 0; j < m; ++j) {
      if (curSpell * potions[j] >= success) {
        curPairs++;
      }
    }
    pairs.push_back(curPairs);
  }

  return pairs;
}

// * TIME COMPLEXITY O(logn) 
// * Lower Bound
int bSearch(std::vector<int> &potions, long long minPotion) {
  int n = potions.size();
  int l = 0, r = n - 1;
  int ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    // * find more smaller index
    if (potions[m] >= minPotion) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * spell * potion >= success
// * potion = success / spell
// * Find min potion index
// * TIME COMPLEXITY O(n * logn)
// * SPACE COMPLEXITY O(1)
std::vector<int> successfulPairs(std::vector<int> &spells, std::vector<int> &potions, int success) {
  int n = spells.size();
  int m = potions.size();
  std::vector<int> pairs;

  std::sort(potions.begin(), potions.end());
  int maxPotionVal = potions[m - 1];

  for (int i = 0; i < n; ++i) {
    int curSpell = spells[i];

    // * Small but important optimization
    // * spell = '1' cannot muliply with any potions[j] to give atleast 'success' 
    // * minPotion * curSpell >= success
    long long minPotion = std::ceil((1.0 * success) / curSpell);
    if (minPotion > maxPotionVal) {
      pairs.push_back(0);
      continue;
    }

    int index = bSearch(potions, minPotion);
    // std::cout << minPotion << " " << index << std::endl;
    pairs.push_back(m - index);
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  int success = 7;
  std::vector<int> spells = {5, 1, 3};
  std::vector<int> potions = {1, 2, 3, 4, 5};

  // * testcase 2
  // int success = 16;
  // std::vector<int> spells = {3, 1, 2};
  // std::vector<int> potions = {8, 5, 8};

  std::cout << "Spell: " << std::endl;
  printArr(spells);
  std::cout << "Potions: " << std::endl;
  printArr(potions);
  
  std::cout << "Successful Pairs" << std::endl;
  // std::vector<int> pairs = bruteForce(spells, potions, success);
  std::vector<int> pairs = successfulPairs(spells, potions, success);
  printArr(pairs);
  return 0;
}

// * Run the code
// * g++ --std=c++20 07-spells-and-potions.cpp -o practice && ./practice


