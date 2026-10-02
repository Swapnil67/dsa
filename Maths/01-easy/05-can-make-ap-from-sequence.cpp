/*
 * Leetcode - 1502
 * Can Make Arithmetic Progression From Sequence
 * 
 * A sequence of numbers is called an arithmetic progression if the difference 
 * between any two consecutive elements is the same. Given an array of numbers arr, 
 * return true if the array can be rearranged to form an arithmetic progression. 
 * Otherwise, return false.
 * 
 * Constraints  : 
 *                - 2 <= arr.length <= 1000
 *                - -10^6 <= arr[i] <= 10^6
 * 
 * Example 1    :
 * Input        : arr = [3,5,1]
 * Output       : true
 * Explanation  : We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 
 *                respectively, which are both arithmetic progressions.
 * 
 * Example 2    :
 * Input        : arr = [1,2,4]
 * Output       : false
 * Explanation  : There is no way to reorder the elements to form an arithmetic progression 
 *                because the differences between elements cannot be made equal.
 *
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
*/

// ! Arithmetic Progression
// ! Google

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// ! Intuition
/*
* AP = a, a+d, a+2d, a+3d, a+4d, ........., a+(n-1)d
* General formula = a + i*d
*
* min = a               ------ eq1
* max = a + (n-1)*d      ------ eq2
* 
* If we subtract above eq1 and eq2
* diff = (n - 1)*d
* d = diff / (n - 1)
* 
*/

// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
bool bruteForce(vector<int> nums) {
  int n = nums.size();
  sort(all(nums));
  int d = nums[1] - nums[0];
  for (int i = 0; i < n - 1; ++i) {
    if (d != (nums[i + 1] - nums[i]))
      return false;
  }
  return true;
}

// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
bool betterApproach(vector<int> &nums) {
  int n = nums.size();

  unordered_set<int> st(all(nums));

  int min_ele = *min_element(all(nums)); // * a
  int max_ele = *max_element(all(nums)); // * a + (n - 1)*d

  // * max - min / (n - 1) = d
  if ((max_ele - min_ele) % (n - 1) != 0)
    return false;

  // * Common difference required for AP
  int d = (max_ele - min_ele) / (n - 1);

  int i = 0;
  while (i < n) {
    // * ap[i] = a + i*d
    int num = min_ele + (i * d);
    if (!st.count(num))
      return false;
    i++;
  }
  return true;
}


// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(1)
bool canMakeArithmeticProgression(vector<int> &nums) {
  int n = nums.size();

  int min_ele = *min_element(all(nums)); // * a
  int max_ele = *max_element(all(nums)); // * a + (n - 1)*d

  // * (max - min / (n - 1)) = d
  if (((max_ele - min_ele) % (n - 1)) != 0)
    return false;

  // * Common difference required for AP
  int d = (max_ele - min_ele) / (n - 1);
  int i = 0;
  while (i < n) {
    int val = nums[i];
    // * Check if already at correct position in AP
    if (val == min_ele + (i * d)) {
      i++;
    } else {
      // * Check if valid integer
      if ((val - min_ele) % d != 0)
        return false;

      // * Find valid index for val
      int j = (val - min_ele) / d;
      if (val == nums[j]) // * If both are same then AP not psbl.
        return false;

      swap(nums[i], nums[j]);
    }
  }
  return true;
}
int main(void) {
  // * testcase 1
  // vector<int> nums = {3, 5, 1};
  
  // * testcase 2
  // vector<int> nums = {1, 2, 4};
  
  // * testcase 3
  vector<int> nums = {1, 6, 7, 2, 3, 4, 4};

  cout << "nums: ";
  printArr(nums);

  // bool ans = bruteForce(nums);
  // bool ans = betterApproach(nums);
  bool ans = canMakeArithmeticProgression(nums);

  cout << "Can make AP: " << ans << "\n";
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 05-can-make-ap-from-sequence.cpp -o output && ./output

