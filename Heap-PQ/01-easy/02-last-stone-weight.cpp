#include <queue>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

int lastStoneWeight(vector<int> &stones) {
  priority_queue<int> max_heap;
  for (int &n : stones)
    max_heap.push(n);

  while (max_heap.size() != 1) {
    int s1 = max_heap.top();
    max_heap.pop();
    int s2 = max_heap.top();
    max_heap.pop();

    if (s1 != s2) {
      max_heap.push(abs(s2 - s1));
    }
  }

  return max_heap.size() ? max_heap.top() : 0;
}

int main() {
  vector<int> stones = {2, 7, 4, 1, 8, 1};
  cout << "Stones: " << endl;
  printArr(stones);

  int ans = lastStoneWeight(stones);
  cout << "Last Stone Weight " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 02-last-stone-weight.cpp -o output && ./output