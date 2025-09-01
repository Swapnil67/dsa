#include <queue>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int lastStoneWeight(std::vector<int> &stones) {
  std::priority_queue<int> max_heap;
  for (int &n : stones)
    max_heap.push(n);

  while (max_heap.size() != 1) {
    int s1 = max_heap.top();
    max_heap.pop();
    int s2 = max_heap.top();
    max_heap.pop();

    if (s1 != s2) {
      max_heap.push(std::abs(s2 - s1));
    }
  }

  return max_heap.size() ? max_heap.top() : 0;
}

int main() {
  std::vector<int> stones = {2, 7, 4, 1, 8, 1};
  std::cout << "Stones: " << std::endl;
  printArr(stones);

  int ans = lastStoneWeight(stones);
  std::cout << "Last Stone Weight " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-last-stone-weight.cpp -o output && ./output