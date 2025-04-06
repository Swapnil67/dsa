#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printMatrix(std::vector<std::vector<T>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

std::string mergeAlternately(std::string word1, std::string word2) {
  int i = 0, j = 0, k = 0;
  std::string ans = "";
  while(i < word1.size() && j < word2.size()) {
    ans += word1[i++];
    ans += word2[j++];
  }
  while (i < word1.size()) {
    ans += word1[i++];
  }

  while (j < word2.size()) {
    ans += word2[j++];
  }
  return ans;
}

std::vector<int> mergeBrute(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int i = 0, j = 0;
  std::vector<int> ans;
  while (i < n && j < m) {
    if(nums1[i] > nums2[j]) {
      ans.push_back(nums2[j]);
      j += 1;
    }
    else {
      ans.push_back(nums1[i]);
      i += 1;
    }
  }

  while (i < n) {
    ans.push_back(nums1[i]);
    i += 1;
  }

  while (j < m) {
    ans.push_back(nums2[j]);
    j += 1;
  }

  return ans;
}

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int k = m + n - 1;
  printf("k = %d\n", k);
  while (m > 0 && n > 0) {
    if(nums1[m - 1] > nums2[n - 1]) {
      nums1[k] = nums1[m - 1];
      m -= 1;
    }
    else {
      nums1[k] = nums2[n - 1];
      n -= 1;
    }
    k -= 1;
  }

  while (m > 0)
  {
    nums1[k] = nums1[m - 1];
    m -= 1;
    k -= 1;
  }

  while (n > 0)
  {
    nums1[k] = nums2[n - 1];
    n -= 1;
    k -= 1;
  }
}

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
  vector<vector<int>> ans;
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    if(nums1[i][0] <= nums2[j][0]) {
      if(nums1[i][0] == nums2[j][0]) {
        ans.push_back({{nums1[i][0], nums1[i][1] + nums2[j][1]}});
        i += 1;
        j += 1;
      } else {
        ans.push_back(nums1[i]);
        i += 1;
      }
    } else {
      ans.push_back(nums2[j]);
      j += 1;
    }
  }

  while (i < nums1.size()) {
    ans.push_back(nums1[i]);
    i += 1; 
  }

  while (j < nums2.size()) {
    ans.push_back(nums2[j]);
    j += 1;
  }

  return ans;
}

int main() {
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output