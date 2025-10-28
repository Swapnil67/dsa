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

// ! Meta

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

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Binary Search
// * bloom_idx = upper_bound (flowers bloomed before arrival)
// * die_idx = lower_boundi (flowers died before arrival)

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
    int time = people[i];
    // * flowers which are bloom before `time`
    int bloom_idx = std::upper_bound(begin(start), end(start), time) - begin(start);
    // * flowers which died before `time`
    int die_idx = std::lower_bound(begin(die), end(die), time) - begin(die);
    // std::cout << "Person: " << time << std::endl;
    // std::cout << bloom_idx << " - " << die_idx << " = " << bloom_idx - die_idx << std::endl;
    ans[i] = bloom_idx - die_idx;
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------
// * Two Min Heaps
// * TIME COMPLEXITY O(nlogn + mlogn)
// * SPACE COMPLEXITY O(m + n)
std::vector<int> fullBloomFlowers2(std::vector<std::vector<int>> &flowers, std::vector<int> &people) {
  int n = flowers.size();
  int m = people.size();

  // * 1. Sort the people
  std::vector<std::pair<int, int>> sorted_people;
  for (int i = 0; i < m; i++) {
    sorted_people.push_back({people[i], i});
  }
  sort(sorted_people.begin(), sorted_people.end());

  // * 2. save the start and end days into two min_heaps
  std::priority_queue<int, std::vector<int>, std::greater<>> start_heap, end_heap;
  for (int i = 0; i < n; ++i) {
    start_heap.push(flowers[i][0]);
    end_heap.push(flowers[i][1]);
  }

  int count = 0;
  std::vector<int> ans(m);
  for (auto &person : sorted_people) {
    int pos = person.first, index = person.second;

    // * Flower has bloomed before the person came
    while (!start_heap.empty() && start_heap.top() <= pos) {
      start_heap.pop();
      count++;
    }

    // * Flower has died before the person came
    while (!end_heap.empty() && end_heap.top() < pos) {
      end_heap.pop();
      count--;
    }

    // std::cout << "Person: " << pos << ", Flowers: " << count << std::endl;
    // std::cout << bloom_idx << " - " << die_idx << " = " << bloom_idx - die_idx << std::endl;
    ans[index] = count;
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // std::vector<int> people = {2, 3, 7, 11};
  // std::vector<std::vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};

  // * testcase 2
  std::vector<int> people = {3, 3, 2};
  std::vector<std::vector<int>> flowers = {{1, 10}, {3, 3}};

  std::cout << "people: ";
  printArr(people);
  std::cout << "Flowers: " << std::endl;
  for (auto &vec : flowers)
    printArr(vec);

  // std::vector<int> ans = bruteForce(flowers, people);
  // std::vector<int> ans = fullBloomFlowers(flowers, people);
  std::vector<int> ans = fullBloomFlowers2(flowers, people);
  std::cout << "Number of Flowers in Full Bloom: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 06-no-of-flowers-in-full-bloom.cpp -o output && ./output