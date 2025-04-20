#include<vector>
#include<deque>
#include<iostream>
#include <numeric>
#include <climits>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool bruteForce(std::vector<int> arr, int k) {
  int n = arr.size();
  std::unordered_map<int, int> hash;
  for (int i = 0; i < n; ++i) {
    if(hash.count(arr[i])) {
      if (std::abs(i - arr[i]) <= k)
        return true;
    }
    hash[arr[i]] = i;
  }
  return false;
}

bool containsNearbyDuplicate(std::vector<int> arr, int k) {
  int n = arr.size();
  int i = 0, j = 0;
  std::unordered_set<int> st;
  while (j < n) {
    if (std::abs(i - j) > k) {
      st.erase(arr[i]);
      i += 1;
    }
    if (st.find(arr[j]) != st.end()) {
      return true;
    }
    st.insert(arr[j]);
    j += 1;
  }

  return false;
}

int maxSumOfKSubarray(std::vector<int> arr, int k) {
  int n = arr.size();
  int max_sum = 0, cur_sum = 0;
  int i = 0, j = 0;
  while(j < n) {
    if(j - i + 1 > k) {
      cur_sum -= arr[i];
      i += 1;
    }
    cur_sum += arr[j];
    if (j - i + 1 == k) {
      max_sum = std::max(max_sum, cur_sum);
    }
    j += 1;
  }
  return max_sum;
}

int minimumRecolors(std::string blocks, int k) {
  int n = blocks.size();
  int i = 0, j = 0;
  int min_ops = INT_MAX;
  int cur_ops = 0;
  while (j < n) {
    // * window exceeded
    if(j - i + 1 > 7) {
      if(blocks[i] == 'W') {
        cur_ops -= 1;
      }
      i += 1;
    }
    if(blocks[j] == 'W') {
      cur_ops += 1;
    }
    if (j - i + 1 == k) {
      min_ops = std::min(min_ops, cur_ops);
    }
    j += 1;
  }
}

int main() {
  std::string blocks = "WBBWWBBWBW";
  int k = 7;
  int ans = minimumRecolors(blocks, k);
  std::cout << "Minimum recolors " << k << " is " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output