/*
 * Leetcode - 2570
 * Merge Two 2D Arrays by Summing Values
 * Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:
 * - Only ids that appear in at least one of the two arrays should be included in the resulting array.
 * - Each id should be included only once and its value should be the sum of the values of this id in the two arrays. 
 *   If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
 * 
 * Example 2
 * Input  : nums1 = {{1, 2}, {2, 3}, {4, 5}}, nums2 = {{1, 4}, {3, 2}, {4, 1}}
 * Output : {{1, 6}, {2, 3}, {3, 2}, {4, 6}} 

 * https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
*/

// * Similar Question - https://leetcode.com/problems/merge-similar-items/

#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>> matrix) {
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

std::vector<std::vector<int>> mergeArrays(
    std::vector<std::vector<int>> &nums1,
    std::vector<std::vector<int>> &nums2) {
  std::vector<std::vector<int>> ans;
  int i = 0, j = 0;
  while (i < nums1.size() && j < nums2.size()) {
    int a = nums1[i][0];
    int b = nums2[j][0];
    if (a == b) {
      ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
      i++, j++;
    } else if(a > b) {
      ans.push_back({nums2[j]});
      j++;
    } else {
      ans.push_back({nums1[i]});
      i++;
    }
  }

  while (i < nums1.size()) {
    ans.push_back(nums1[i]);
    i++;
  }
  
  while (j < nums2.size()) {
    ans.push_back(nums2[j]);
    j++;
  }

  return ans;
}

int main() {
  std::vector<std::vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
  std::vector<std::vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
  printMatrix(nums1);
  printMatrix(nums2);
  
  std::vector<std::vector<int>> ans = mergeArrays(nums1, nums2);
  printMatrix(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++20 08-merge-2D-arrays -o output && ./output