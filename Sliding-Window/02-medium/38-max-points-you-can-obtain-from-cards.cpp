/*
 * Leetcode - 1423
 * Maximum Points You Can Obtain from Cards
 * 
 * There are several cards arranged in a row, and each card has an associated number of points. 
 * The points are given in the integer array cardPoints.
 * 
 * In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
 * 
 * Your score is the sum of the points of the cards you have taken.
 * 
 * Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
 * 
 * Example 1
 * Input        : cardPoints = [1,2,3,4,5,6,1], k = 3
 * Output       : 12
 * Explanation  : Sum from = [1, 6, 5]
 * 
 * Example 2
 * Input        : cardPoints = [2,2,2], k = 2
 * Output       : 4
 * Explanation  : Sum from = [2, 2]
 * 
 * Example 3
 * Input        : cardPoints = [9,7,7,9,7,7,9], k = 7
 * Output       : 55
 * Explanation  : You have to take all the cards. Your score is the sum of points of all cards.
 * 
 * Example 4
 * Input        : cardPoints = [100,40,17,9,73,75], k = 3
 * Output       : 248
 * Explanation  : Sum from = [100, 73, 75]

 * https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
*/

// ! Amazon

#include <climits>
#include <vector>
#include <iostream>

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

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * Classic Sliding Window
// * Find the smallest subarray with (n-k) size then we'll get the max sum circular subarray
// * Keep frequency map of character occurences
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numKLenSubstrNoRepeats(std::vector<int> &cardPoints, int k) {
  int n = cardPoints.size();
  int total_sum = 0, cur_sum = 0, max_sum = INT_MAX;
  int i = 0, j = 0;

  int k2 = n - k; // * smallest subarray size
  while (j < n) {
    total_sum += cardPoints[j];

    cur_sum += cardPoints[j];
    if ((j - i + 1) > k2) {
      cur_sum -= cardPoints[i];
      i++;
    }

    if ((j - i + 1) == k2) {
      max_sum = std::min(max_sum, cur_sum);
    }
    j++;
  }

  if (k2 == 0)
    return total_sum;

  return total_sum - max_sum;
}

int main(void) {
  // * testcase 1
  int k = 3;
  std::vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  
  // * testcase 2
  // int k = 2;
  // std::vector<int> cardPoints = {2, 2, 2};
  
  // * testcase 3
  // int k = 7;
  // std::vector<int> cardPoints = {9, 7, 7, 9, 7, 7, 9};
  
  // * testcase 4
  // int k = 3;
  // std::vector<int> cardPoints = {100, 40, 17, 9, 73, 75};

  std::cout << "K: " << k << std::endl;
  std::cout << "Card Poinst: ";
  printArr(cardPoints);

  int ans = numKLenSubstrNoRepeats(cardPoints, k);
  std::cout << "Answer: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 38-max-points-you-can-obtain-from-cards.cpp -o output && ./output