/*
 * Leetcode - 1865 
 * Finding Pairs With a Certain Sum
 * 
 * https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

class FindSumPairs {
public:
  std::vector<int> vec1, vec2;
  std::unordered_map<int, int> freq_mp;

  FindSumPairs(std::vector<int> &nums1, std::vector<int> &nums2) {
    vec1 = nums1;
    vec2 = nums2;
    // * Save the freq of vec2 elements
    for(auto &x: vec2) {
      freq_mp[x]++;
    }
  }

  void add(int index, int val) {
    freq_mp[vec2[index]]--; // * Remove the old val freq
    vec2[index] += val;    
    freq_mp[vec2[index]]++; // * Add the new val freq
  }

  int count(int tot) {
    int pairs = 0;
    for (auto &x: vec1) {
      // * vec1[i] + vec2[j] = tot
      // * vec1[i] = tot - vec2[j]
      pairs += freq_mp[tot - x]; // * Like Two Sum
    }
    return pairs;
  }
};

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 04-finding-pairs-with-a-certain-sum.cpp -o output && ./output
