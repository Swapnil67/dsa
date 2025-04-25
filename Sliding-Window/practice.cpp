#include <vector>
#include <deque>
#include <iostream>
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

int subarraySum(std::vector<int> arr, int k) {    
  int n = arr.size();
  int max_sum = 0, cur_sum = 0; 
  int i = 0, j = 0;
  std::unordered_set<int> st;
  while(j < n) {
    while (i < j && (j - i + 1 > k || st.count(arr[j])))
    {
      cur_sum -= arr[i];
      st.erase(arr[i]);
      i += 1;
    }

    st.insert(arr[j]);
    cur_sum += arr[j];

    if(st.size() == k) {
      max_sum = std::max(max_sum, cur_sum);
    }

    j += 1;
  }

  return max_sum;
}

// std::vector<int> firstNegative(std::vector<int> arr, int k) {
//   // TODO
// }


// int longestOnes(std::vector<int> arr, int k) {
//   // TODO
// }

int main() {
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output