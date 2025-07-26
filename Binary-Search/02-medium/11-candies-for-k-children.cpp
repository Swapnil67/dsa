/*
 * Leetcode - 2226 
 * Maximum Candies Allocated to K Children
 * You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i].
 * You can divide each pile into any number of sub piles, but you cannot merge two piles together.
 * 
 * You are also given an integer k. You should allocate piles of candies to k children such that each child gets 
 * the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of 
 * candies may go unused.
 * 
 * Return the maximum number of candies each child can get.
 * 
 * Example 1
 * Input     : candies = [5, 8, 6], k = 3
 * Output    : 5
 
 * Example 2
 * Input     : candies = [2, 5], k = 11
 * Output    : 0
 
 * Example 3
 * Input     : candies = [4, 7, 5], k = 4
 * Output    : 3

 * https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool checkIsChildrenSatisfied(std::vector<int> candies, long long k, int curCandies) {
  if (curCandies == 0)
    return true;
    
  long long satisfiedChildren = 0;
  int n = candies.size();
  for (int i = 0; i < n; ++i) {
    if (satisfiedChildren >= k)
      break;
    std::cout << candies[i] << " / " << curCandies << " = " << (candies[i] / curCandies) << std::endl;
    // * check how many children current pile can satisfy
    satisfiedChildren += (candies[i] / curCandies);
  }

  return satisfiedChildren >= k;;
}

int maximumCandies(std::vector<int> &candies, long long k) {
  int n = candies.size();
  int maxCandies = *std::max_element(candies.begin(), candies.end());
  long long totalCandies = accumulate(candies.begin(), candies.end(), 0);

  // * There are more children than available candies
  if (totalCandies < k)
    return 0;

  int ans = 0;
  int l = 0, r = maxCandies;

  while (l <= r) {
    int curCandies = l + (r - l) / 2;
    bool areChildrenSatisfied = checkIsChildrenSatisfied(candies, k, curCandies);
    // std::cout << curCandies << " -> " << areChildrenSatisfied << std::endl;
    if (areChildrenSatisfied) {
      ans = curCandies;
      l = curCandies + 1;
    }
    else {
      r = curCandies - 1;
    }
  }
  return ans;
}

int main(void) {
  // * testcase 1
  // long long k = 3;
  // std::vector<int> candies = {5, 8, 6};

  // * testcase 2
  // long long k = 11;
  // std::vector<int> candies = {2, 5};

  // * testcase 3
  // long long k = 4;
  // std::vector<int> candies = {4, 7, 5};

  // * testcase 4
  long long k = 1;
  std::vector<int> candies = {1};

  std::cout << "Pile of candies" << std::endl;
  printArr(candies);
  int ans = maximumCandies(candies, k);
  std::cout << "Maximum Candies Allocated to K Children " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 11-candies-for-k-children.cpp -o output && ./output