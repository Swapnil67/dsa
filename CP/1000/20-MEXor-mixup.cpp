/*
 * MEXor Mixup
 *
 * You are given two integers a and b. Your task is to find the shortest possible 
 * length of an array consisting of non-negative integers such that:
 * 1. The MEX (Minimum EXcluded) of the array is exactly equal to a. 
 *    (i.e., the smallest non-negative integer missing from the array is a).
 * 2. The bitwise XOR sum of all elements in the array is exactly equal to b.
 * 
 * Constraints:
 * 1 <= a <= 3 * 10^5
 * 0 <= b <= 3 * 10^5
 * The number of independent test cases t does not exceed 5 * 10^4.
 * 
 * Example 1    :
 * Input        : a = 1, b = 1
 * Output       : 3
 * Explanation  : The MEX must be 1, meaning 0 must be in the array, but 1 must not.
 *                If we take [0], its XOR sum is 0 (which is != 1).
 *                To make the XOR sum equal to 1, we can add elements. 
 *                The array [0, 2, 3] has a MEX of 1 and its XOR sum is 0 ^ 2 ^ 3 = 1.
 *                The shortest length possible satisfying both conditions is 3.
 * 
 * Example 2    :
 * Input        : a = 2, b = 1
 * Output       : 2
 * Explanation  : The MEX must be 2, meaning 0 and 1 must be present, but 2 must not.
 *                The base array containing all required elements is [0, 1].
 *                Its XOR sum is 0 ^ 1 = 1, which perfectly matches b = 1.
 *                Thus, no extra elements are needed, and the minimum length is 2.
 *
 * https://codeforces.com/problemset/problem/1567/B
*/

// ! Bit Manipulation

// ! Observation
/*
* For MEX 'a' we'll use 0,1,2,3,.....,a-1 elements
* Let the XOR of all the elements from 0,1,2,3,.....,a-1 be 'x'
*
* Case 1:
* x == b then we return answer as a - 1

* Case 2:
* x != b && x^b != a (if it becomes a then our MeX condition will become false)
* then we'll if x^b = b if yes the we'll add x^b with 'x', so it will become
* x ^ (x ^ b) = b
* Here our answer will be a + 1.      ((x ^ b) this is one extra element we added to our answer)
* 
* Case 3:
* x != b also x^b != b
* then we'll do following
* x ^ (x ^ b ^ (a + 1)) ^ (a + 1) = b
* Here our answer will be a + 2.     ((x ^ b ^ (a + 1)) & (a + 1) two extra elements we added to our answer)
*/

#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;

ll xor_till(ll n) {
  ll a = n % 4;
  
  // * Depending on the remainder, return the appropriate XOR value
  if (a == 0) {
    return n;
  } else if (a == 1) {
    return 1LL;
  } else if (a == 2) {
    return n + 1LL;
  } 
  return 0LL;
}

ll solve(void) {
  ll a, b;
  cin >> a >> b;
  
  ll arr_xor = xor_till(a - 1);
  
  // * Check if the calculated XOR matches the required XOR
  if (arr_xor == b) {
    // * If it matches, the length of the array is a
    return a;
  }
  else if ((arr_xor ^ b) != a) { // * not MeX
    // * If XOR of arr_xor and b is not equal to a, the length is a + 1
    return a + 1LL;
  }
  else {
    // * Otherwise, the length is a + 2
    return a + 2LL;
  }
} 

// ! Greedy with Bitwise XOR
// * Time Complexity (TC): O(1)
// * Space Complexity (SC): O(1)
int main(void) {
  ll t;
  cin >> t;

  while (t--) {
    ll ans = solve();
    cout << ans << "\n";
  }
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 20-MEXor-mixup.cpp -o output && ./output

// * testcases
/*
5
1 1
2 1
2 0
1 10000
2 10000

*/

// * Output
/*
RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR
*/
