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

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(n x m)
// * SPACE COMPLEXITY O(1)
vector<int> bruteForce(vector<int> &spells, vector<int> &potions, int success) {
  int n = spells.size();
  int m = potions.size();

  vector<int> pairs;
  
  for (auto &s: spells) {
    int cur = 0;
    for (auto &p: potions) {
      if ((s * p) >= success) {
        cur++;
      }
    }
    pairs.push_back(cur);
  }

  return pairs;
}

// * TIME COMPLEXITY O(logn) 
// * Lower Bound
int lower_bound(vector<int> &potions, long long min_potion) {
  int n = potions.size();
  int l = 0, r = n - 1;
  int ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    // * find more smaller index
    if (potions[m] >= min_potion) {
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
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, int success) {
  int n = spells.size(), m = potions.size();
  vector<int> pairs;

  sort(potions.begin(), potions.end());
  int max_potion_val = potions[m - 1];

  for (auto &cur_spell : spells) {
    // * Small but important optimization
    // * spell = '1' cannot multiply with any potions[j] to give atleast 'success' 
    // * min_potion * cur_spell >= success
    // * min_potion >= (success / cur_spell)

    int min_potion = ceil((double)success / (double)cur_spell);
    if (min_potion > max_potion_val) {
      pairs.push_back(0);
      continue;
    }
    int lb = lower_bound(potions, min_potion);
    // std::cout << min_potion << ", lb: " << lb << std::endl;
    pairs.push_back(m - lb);
  }

  return pairs;
}

int main(void) {
  // * testcase 1
  int success = 7;
  vector<int> spells = {5, 1, 3};
  vector<int> potions = {1, 2, 3, 4, 5};

  // * testcase 2
  // int success = 16;
  // vector<int> spells = {3, 1, 2};
  // vector<int> potions = {8, 5, 8};

  cout << "Success:    " << success << endl;
  cout << "Spell:      ";
  printArr(spells);
  cout << "Potions:    ";
  printArr(potions);
  
  cout << "Successful Pairs" << endl;
  // vector<int> pairs = bruteForce(spells, potions, success);
  vector<int> pairs = successfulPairs(spells, potions, success);
  printArr(pairs);

  return 0;
}

// * Run the code
// * g++ --std=c++20 07-spells-and-potions.cpp -o output && ./output


