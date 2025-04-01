#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int bruteForce(std::vector<int> scores, int k) {
  int n = scores.size();
  int ans = 0;
  std::sort(scores.begin(), scores.end());
  for (int i = 0; i < n; ++i) {
    for(int j = i; j - i < k - 1; ++j) {
      printf("%d ", scores[j]);
    }
    printf("\n");
  }
  return ans;
}

int minimumDifference(std::vector<int> scores, int k) {
  int n = scores.size();
  int ans = INT_MAX;
  std::sort(scores.begin(), scores.end());
  int l = 0, r = k - 1;
  while(r < n) {
    printf("%d %d\n", scores[l], scores[r]);
    ans = std::min(ans, scores[r] - scores[l]);
    l += 1;
    r += 1;
  }
  return ans;
}

int main() {
  printf("Two Pointer Practice.\n");
  // int k = 3;
  int k = 2;
  std::vector<int> nums = {9, 4, 1, 7};
  printArr(nums);
  int ans = minimumDifference(nums, k);
  std::cout << ans << std::endl;
  return 0;
}

// * i
// * 9, 4, 1, 7
// * j

// * i
// * 7, 9, 4, 1
// * j

// * Run the code
// * $CXX --std=c++20 practice.cpp -o output && ./output