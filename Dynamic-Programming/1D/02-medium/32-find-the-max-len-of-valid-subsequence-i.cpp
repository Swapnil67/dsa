/*
 * Leetcode -  
 * NAME
 * 
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
 * https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/
*/

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

int maximumLength(vector<int> &nums) {
    int evens = 0, odds = 0;
    int altEvenStart = 0, altOddStart = 0;
    bool expectEven = true, expectOdd = false;

    for (int x : nums) {
        // * Case 1: Subsequence where all adjacent pairs sum to 0 (all Evens
        // * or all Odds)
        if (x % 2 == 0) evens++;
        else odds++;

        // * Case 2: Subsequence where all adjacent pairs sum to 1
        // * (Alternating Parities) Sequence type A: Starts with an Even
        // * number
        if (x % 2 == 0 && expectEven) {
            altEvenStart++;
            expectEven = false; // * Next one must be Odd
        }
        else if (x % 2 != 0 && !expectEven) {
            altEvenStart++;
            expectEven = true; // * Next one must be Even
        }

        // * Sequence type B: Starts with an Odd number
        if (x % 2 != 0 && !expectOdd) {
            altOddStart++;
            expectOdd = true; // * Next one must be Even
        }
        else if (x % 2 == 0 && expectOdd) {
            altOddStart++;
            expectOdd = false; // * Next one must be Odd
        }
    }

    // The answer is the maximum of all valid configurations
    return max({evens, odds, altEvenStart, altOddStart});
}

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
