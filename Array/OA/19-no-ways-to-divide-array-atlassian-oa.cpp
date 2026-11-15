/*
 * NAME
 * 
 * Description:
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://drive.google.com/file/d/1hcDwOvmGr9ZYIfRBPfReYHIaxhwXz5xn/view
 * https://docs.google.com/document/d/1fceytryhHdMXhbazAY8Vg8OzSmPUvCE-OBxX7Fc-QLg/edit?tab=t.0
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)
int bruteForce(vi nums, int max_allowed) {
  int cur = 0;

  auto isValidPages = [&](const int max_pages) {
    int cur = 0;
    for (auto &p: nums) {
      // cur += ceil((double)p / (double)max_pages);
      cur += ((p + max_pages - 1) / max_pages);
    }
    // cout << "max_pages: " << max_pages << ", cur: " << cur << '\n';
    return cur <= max_allowed;
  };

  int ans = 0;
  for (int i = max_allowed; i >= 1; --i) {
    bool valid = isValidPages(i);
    // cout << i << " " << valid << '\n';
    if (valid == true) {
      ans = i;
    }
  }

  return ans;
}

// * TIME COMPLEXITY O(N * max_allowed)
// * SPACE COMPLEXITY O(1)
int optimalApproach(vi nums, int max_allowed) {
  int cur = 0;

  auto isValidPages = [&](const int max_pages) {
    int cur = 0;
    for (auto &p: nums) {
      // cur += ceil((double)p / (double)max_pages);
      cur += ((p + max_pages - 1) / max_pages);
    }
    // cout << "max_pages: " << max_pages << ", cur: " << cur << '\n';
    return cur <= max_allowed;
  };

  int ans = 0;
  for (int i = max_allowed; i >= 1; --i) {
    bool valid = isValidPages(i);
    // cout << i << " " << valid << '\n';
    if (valid == true) {
      ans = i;
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  int d = 16;
  vi nums = {5, 8, 3};
  
  // * testcase 2
  // int d = 8;
  // vi nums = {5, 8, 3};

  cout << "d: " << d << '\n';
  cout << "Nums: ";
  printArr(nums);

  int ans = bruteForce(nums, d);
  cout << "Answer: " << ans << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 19-no-ways-to-divide-array-atlassian-oa.cpp -o output && ./output
