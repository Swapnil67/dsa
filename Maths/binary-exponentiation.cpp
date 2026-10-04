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
 * 
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()
const ll M = 1e9+7;

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

// ! a, b < 10^9
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(ll a, ll b) {
  ll ans = 1;
  for (int i = 1; i <= b; ++i) {
    ans *= a;
    ans %= M;
  }
  return ans;
}

// ! Recursive
// ! a, b < 10^9
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int binExpRecr(ll a, ll b) {
  if (b == 0)
    return 1;
  int res = binExpRecr(a, b / 2);
  if (b & 1) {
    return (a * (res * 1LL * res) % M) % M;
  } else {
    return (res * 1LL * res) % M;
  }
}

/*
* a = 2, b = 13
* 
* --- b ---    a      ans
* 1 1 0 1      2       2^1
*   1 1 0      2^2     2^1   
*     1 1      2^4     2^5    
*       1      2^8     2^13
* 
*/

// ! iterative
// ! a, b < 10^9
// * TIME COMPLEXITY O(logN)
// * SPACE COMPLEXITY O(1)
int binExprIter(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) { // * check if 0th bit is set
      ans = (ans * a) % M; // * add that to answer
    }
    a = (a * a) % M;
    b >>= 1; // * right shift
  }
  return ans;
}

int main(void) {
  ll a = 2LL, b = 10LL;

  // int ans = bruteForce(a, b);
  // int ans = binExpRecr(a, b);
  int ans = binExprIter(a, b);

  cout << "ans: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 binary-exponentiation.cpp -o output && ./output
