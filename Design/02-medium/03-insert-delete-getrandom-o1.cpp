/*
 * Leetcode - 380 
 * Insert Delete GetRandom O(1)
 * 
 * Implement the RandomizedSet class:
 * - RandomizedSet() Initializes the RandomizedSet object.
 * 
 * - bool insert(int val) Inserts an item val into the set if not present. 
 *   Returns true if the item was not present, false otherwise.
 * 
 * - bool remove(int val) Removes an item val from the set if present. 
 *   Returns true if the item was present, false otherwise.
 * 
 * - int getRandom() Returns a random element from the current set of elements 
 *   (it's guaranteed that at least one element exists when this method is called). 
 *   Each element must have the same probability of being returned.

 * You must implement the functions of the class such that each function works in average O(1) time complexity.

 * https://leetcode.com/problems/design-circular-queue/description/
*/

// ! Google, Amazon, Meta, Microsoft, Uber

#include <vector>
#include <iostream>
#include <unordered_map>

class RandomizedSet {
  std::vector<int> nums;
  std::unordered_map<int, int> idx_mp;

public:
    RandomizedSet() {
      nums.clear();
      idx_mp.clear();
    }
    
    bool insert(int val) {
      if (idx_mp.count(val))
        return false;

      // * Insert in vector and map
      nums.push_back(val);
      idx_mp[val] = nums.size();
      return true;
    }

    bool remove(int val) {
      if (!idx_mp.count(val))
        return false;

      // * Swap last and removing elements
      int remove_ele_idx = idx_mp[val];
      int last_ele = nums.back();
      nums[remove_ele_idx] = last_ele;
      nums[nums.size() - 1] = val;

      // * Update index of last ele
      idx_mp[last_ele] = remove_ele_idx;

      // * Remove from map & nums
      idx_mp.erase(val);
      nums.pop_back();
      return true;
    }

    int getRandom() {
      int idx = rand() % nums.size();
      return nums[idx];
    }
};

int main(void) {

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-design-circular-queue.cpp -o output && ./output
