/*
 * Leetcode - 2251
 * Number of Flowers in Full Bloom
 * 
 * You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will
 * be in full bloom from starti to endi (inclusive). 
 * You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person 
 * will arrive to see the flowers.

 * Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom 
 * when the ith person arrives.

 * Example 1
 * input       : flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}}, people = {2, 3, 7, 11}
 * output      : [1,2,2,2]

 * https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// ! TLE
// * ------------------------- APPROACH 1: Brute Force Approach -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(m * n)
// * SPACE COMPLEXITY O(1)
std::vector<int> bruteForce(std::vector<std::vector<int>> &flowers, std::vector<int> &people) {
  int n = flowers.size();
  int m = people.size();

  std::vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int pos = people[i];
    int flowers_seen = 0;
    for (int j = 0; j < n; ++j) {
      if (pos >= flowers[j][0] && pos <= flowers[j][1]) {
        flowers_seen++;
      }
    }
    ans[i] = flowers_seen;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Binary Search
// * bloom_idx = upper_bound
// * die_idx = lower_bound

// * TIME COMPLEXITY O(nlogn + mlogn)
// * SPACE COMPLEXITY O(m + n)
std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers, std::vector<int> &people) {
  int n = flowers.size();
  int m = people.size();

  std::vector<int> start;
  std::vector<int> die;
  for (int i = 0; i < n; ++i) {
    start.push_back(flowers[i][0]);
    die.push_back(flowers[i][1]);
  }
  std::sort(begin(start), end(start));
  std::sort(begin(die), end(die));

  std::vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int pos = people[i];
    int bloom_idx = std::upper_bound(begin(start), end(start), pos) - begin(start);
    int die_idx = std::lower_bound(begin(die), end(die), pos) - begin(die);
    ans[i] = bloom_idx - die_idx;
    
    // std::cout << "Person: " << pos << std::endl;
    // std::cout << bloom_idx << " - " << die_idx << " = " << bloom_idx - die_idx << std::endl;
    // std::cout << "------------------------------------" << pos << std::endl;
  }

  return ans;
}


// * 0 1 2 3    => index
// * 1 2 4 9    => start
// * 6 7 12 14  => die

// * Person = 2nd day
// * bloom_idx = 1, die_idx = 0 
// * Ans = bloom_idx - die_idx = 1 flowers

// * Person = 3rd day
// * bloom_idx = 2, die_idx = 0 
// * Ans = bloom_idx - die_idx = 2 flowers

// * Person = 7th day
// * bloom_idx = 3, die_idx = 1 
// * Ans = bloom_idx - die_idx = 2 flowers

// * Person = 11th day
// * bloom_idx = 4, die_idx = 2 
// * Ans = bloom_idx - die_idx = 2 flowers


int main(void) {
  // * testcase 1
  std::vector<int> people = {2, 3, 7, 11};
  std::vector<std::vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};

  // * testcase 2
  // std::vector<int> people = {3, 3, 2};
  // std::vector<std::vector<int>> flowers = {{1, 10}, {3, 3}};

  std::cout << "people: ";
  printArr(people);
  std::cout << "Flowers: " << std::endl;
  for (auto &vec : flowers)
    printArr(vec);

  
  // std::vector<int> ans = bruteForce(flowers, people);
  std::vector<int> ans = fullBloomFlowers(flowers, people);
  std::cout << "Number of Flowers in Full Bloom: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-no-of-flowers-in-full-bloom.cpp -o output && ./output