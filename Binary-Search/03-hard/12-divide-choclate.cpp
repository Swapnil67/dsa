/*
 * Leetcode - ?
 * Divide Chocolate
 * 
 * You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.
 * 
 * You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 
 * pieces using k cuts, each piece consists of some consecutive chunks.
 * 
 * Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.
 * 
 * Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.
 * 
 * 
 * Example 1    :
 * Input        : nums = [5 6 7 8 9 10 11 12 13], k = 3
 * Output       : 17
 * Explanation  : 
 * 
 * Example 2    :
 * Input        : nums = [1,2,3,4,5,6,7,8,9], k = 5
 * Output       : 6
 * Explanation  : 
 * 
 * https://neetcode.io/problems/divide-chocolate/question
 * https://www.naukri.com/code360/problems/divide-chocolates_1466966
*/

// ! Google

// ! Binary Search on Min/Max

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)

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

/*
 * Helper function to check if it's possible to divide the chocolate
 * into at least (k + 1) pieces such that every piece has a sweetness
 * of AT LEAST 'minSweetness'.
*/
bool isValid(vector<int> &arr, int &k, long long &minSweetness)
{
  long long curSweetness = 0;
  int pieces = 0;

  for (auto sweet : arr) {
    curSweetness += sweet;

    // * As soon as the current chunk reaches or exceeds the target sweetness,
    // * we make a cut and start a new piece.
    if (curSweetness >= minSweetness) {
      pieces += 1;
      curSweetness = 0; // * Reset sweetness accumulator for the next piece
    }
  }

  // * To share with k friends, we need a total of (k + 1) pieces.
  // * If we can make 'k + 1' or more pieces, this 'minSweetness' threshold is valid.
  return pieces >= (k + 1);
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * S = total sum of sweetness
// * TIME COMPLEXITY O(NlogS)
// * SPACE COMPLEXITY O(m + n)
int maximizeSweetness(vector<int> &sweetness, int k) {
  // * Lower bound: The absolute minimum possible sweetness of a piece 
  // * is the smallest single element in the array.
  long long l = *min_element(begin(sweetness), end(sweetness));
  
  // * Upper bound: The absolute maximum possible sweetness is the sum of 
  // * all elements (if k = 0 and you get the entire chocolate).
  long long r = accumulate(begin(sweetness), end(sweetness), 0LL);  // * Used '0LL' to prevent 32-bit signed integer overflow.
  
  long long ans = l;
  
  // * Perform Binary Search on the Answer space
  while (l <= r) {
    // * Calculate the mid-point (target minimum sweetness we want to test)
    long long m = l + (r - l) / 2;

    if (isValid(sweetness, k, m)) {
      ans = m;   // * 'm' is achievable! Record it as a potential answer.
      l = m + 1; // * Since we want to MAXIMIZE the sweetness, try a larger target.
    }
    else {
      r = m - 1; // * 'm' is too large (cannot form k+1 pieces), try a smaller target.
    }
  }
  
  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 5;
  // vector<int> sweetness = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  // * testcase 2
  // int k = 8;
  // vector<int> sweetness = {5, 6, 7, 8, 9, 1, 2, 3, 4};
  
  // * testcase 3
  int k = 2;
  vector<int> sweetness = {1, 2, 2, 1, 2, 2, 1, 2, 2};

  cout << "sweetness: " << endl;
  printArr(sweetness);

  int ans = maximizeSweetness(sweetness, k);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 12-divide-choclate.cpp -o output && ./output
