/*
 * Ambitious Kid
 * 
 * Description:
 * Given an array of N integers, you can perform an operation where you choose 
 * any element and either increase or decrease its value by 1. This operation 
 * can be repeated multiple times on any elements. Find the minimum number of 
 * operations required to make the product of all elements in the array equal to 0.
 * 
 * Constraints:
 * - 1 <= N <= 10^5 (number of elements in the array).
 * - -10^5 <= A[i] <= 10^5 (value of each element).
 * 
 * Example 1    :
 * Input        : nums = [2, -6, 5, -2]
 * Output       : 2
 * Explanation  : We can choose the first element (2) and decrease it by 1 twice 
 *                to make it 0. The array becomes [0, -6, 5, -2], whose product is 0. 
 *                This takes 2 operations, which is the minimum possible.
 * 
 * Example 2    :
 * Input        : nums = [0]
 * Output       : 0
 * Explanation  : The array already contains a 0, so the product of its elements 
 *                is already 0. No operations are required.
 *
 * https://codeforces.com/problemset/problem/1866/A
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TC = O(n)
// * SC = O(n)
int main(void) {
  // Optimize standard I/O operations for competitive programming
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> a(n);
  
  int min_abs = 1e18;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    min_abs = min(min_abs, (int)abs(a[i]));
  }
  
  cout << min_abs << endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-ambitious-kid.cpp -o output && ./output


// * output 
// 3
// 2 -6 5

// * output 
// 2
