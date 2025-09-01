#include <queue>
#include <math.h>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// TODO
// * BRUTE FORCE

long long pickGifts(std::vector<int>& gifts, int k) {
  // * 1. push all the gift piles to max_heap
  std::priority_queue<int> max_heap;
  for (auto &n : gifts) {
    max_heap.push(n);
  }
  
  while (k > 0) {
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
  // int k = 4;
  // std::vector<int> gifts = {25, 64, 9, 4, 100};

  // * testcase 2
  int k = 4;
  std::vector<int> gifts = {1, 1, 1, 1};

  std::cout << "Gifts: " << std::endl;
  printArr(gifts);

  long long ans = pickGifts(gifts, k);

  std::cout << "Last Stone Weight " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-take-gift-from-richest-pile.cpp -o output && ./output

