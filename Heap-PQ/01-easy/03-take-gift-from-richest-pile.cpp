/*
 * Leetcode - 2558
 * Take Gifts From the Richest Pile
 * 
 * You are given an integer array gifts denoting the number of gifts in various piles. 
 * Every second, you do the following:
 * 
 * - Choose the pile with the maximum number of gifts.
 * - If there is more than one pile with the maximum number of gifts, choose any.
 * - Reduce the number of gifts in the pile to the floor of the square root of the original number of
 *   gifts in the pile.
 * 
 * Return the number of gifts remaining after k seconds.

 * Example 1
 * input  : gifts = [25,64,9,4,100], k = 4
 * output : 29
 * Explanation: 
 * The gifts are taken in the following way:
 * - In the first second, the last pile is chosen and 10 gifts are left behind.
 * - Then the second pile is chosen and 8 gifts are left behind.
 * - After that the first pile is chosen and 5 gifts are left behind.
 * - Finally, the last pile is chosen again and 3 gifts are left behind.
 * The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
 * 
 * https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
*/

#include <queue>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop + Sorting
// * TIME COMPLEXITY O(k * nlogn)
// * SPACE COMPLEXITY O(1)
long long bruteForce(std::vector<int>& gifts, int k) {
  int n = gifts.size();
  if (n == 0)
    return 0;
    
  while (k > 0) {
    // * to get the largest pile of gift
    std::sort(gifts.begin(), gifts.end());
    int cur_gift_pile = gifts[n - 1];

    int new_gift_pile = std::floor(std::sqrt(cur_gift_pile));
    gifts[n - 1] = new_gift_pile;
    k--;

    // printArr(gifts); // * for debugging
  }

  long long ans = 0;
  for (auto &n : gifts)
    ans += n;

  return ans;
}

// * ------------------------- APPROACH 2: Optimal Approach -------------------------`
// * Using max_heap
// * TIME COMPLEXITY O(nlogn + klogn)
// * SPACE COMPLEXITY O(n)
long long pickGifts(std::vector<int>& gifts, int k) {
  // * 1. push all the gift piles to max_heap
  std::priority_queue<int> max_heap; // * O(nlogn)
  for (auto &n : gifts) {
    max_heap.push(n);
  }
  
  while (k > 0) { // * O(klogn)
    // * take the largest gift pile
    int cur_gift_pile = max_heap.top();
    max_heap.pop();
    
    // * find the new gift pile
    int new_gift_pile = std::floor(std::sqrt(cur_gift_pile));
    max_heap.push(new_gift_pile);

    k--;
  }

  // * find sum of all the gifts
  long long ans = 0;
  while (!max_heap.empty()) {
    ans += max_heap.top();
    max_heap.pop();
  }

  return ans;
}

int main() {
  // * testcase 1
  int k = 4;
  std::vector<int> gifts = {25, 64, 9, 4, 100};

  // * testcase 2
  // int k = 4;
  // std::vector<int> gifts = {1, 1, 1, 1};

  std::cout << "Gifts: ";
  printArr(gifts);

  long long ans = bruteForce(gifts, k);
  // long long ans = pickGifts(gifts, k);

  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-take-gift-from-richest-pile.cpp -o output && ./output

