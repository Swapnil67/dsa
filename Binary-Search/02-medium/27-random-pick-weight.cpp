/*
 * Leetcode - 528
 * Random Pick with Weight
 * 
 * You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
 * You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] 
 * (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).
 * 
 * For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), 
 * and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 * 
 * 
 
 * https://leetcode.com/problems/random-pick-with-weight/description/
*/

#include <vector>
#include <iostream>

class Solution {
public:
  std::vector<int> prefix_vec;
  Solution(std::vector<int>& w) {
    int n = w.size();
    for (int& x : w) {
      if (prefix_vec.empty()) {
        prefix_vec.push_back(x);
      } else {
        prefix_vec.push_back(x + prefix_vec.back());
      }
    }
  }

  int pickIndex() {
    int x = prefix_vec.back();
    int index = rand() % x;
    int l = 0, r = prefix_vec.size() - 1;
    int ans = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (prefix_vec[m] > index) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return ans;
  }
};

// * Run the code
// * g++ --std=c++17 27-random-pick-weight.cpp -o output && ./output