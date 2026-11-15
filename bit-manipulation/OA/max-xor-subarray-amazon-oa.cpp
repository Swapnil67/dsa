/*
 * Maximum Subarray with same xor
 * 
 * You are given two arrays A & B, each of length N. You need to select two integers i & j
 * such that 1 <= i <= j <= N and they meet the following condition
 * 
 * A[i] ^ A[i + 1] ^ ..... ^ A[j - 1] ^ A[j] = B[i] ^ B[i + 1] ^ ..... ^ B[j - 1] ^ B[j]
 * 
 * let G = j - i + 1
 * Output the maximum value of G if there exists two integers i & j satisfying the conditions
 * else print 0 on a new line.
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
 * https://docs.google.com/document/d/1GQjmQtVAGzVzC8NkAgLn2MrSh0f7XjjKLVRg_onz_BU/edit?tab=t.0
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

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
// * SPACE COMPLEXITY O(1)
int bruteForce(vi a, vi b) {
  int n = a.size();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int z1 = 0; // * XOR a[i...j]
    int z2 = 0; // * XOR b[i...j]
    for (int j = i; j <= n; ++j) {
      z1 = z1 ^ a[j]; // * running xor for vector 'a'
      z2 = z2 ^ b[j]; // * running xor for vector 'b'
      if (z1 == z2) {
        ans = max(ans, (j - i + 1));
      }
    }
  }

  return ans;
}

/*
* A[i] ^ A[i + 1] ^ ..... ^ A[j - 1] ^ A[j] = B[i] ^ B[i + 1] ^ ..... ^ B[j - 1] ^ B[j]
*
* A[i] ^ A[i + 1] ^ ..... ^ A[j - 1] ^ A[j] - B[i] ^ B[i + 1] ^ ..... ^ B[j - 1] ^ B[j] = 0
* 
* (A[i] ^ B[i]) ^ (A[i+1] ^ B[i+1]) ^ (A[i+2] ^ B[i+2]) ^ ....  ^ (A[j] ^ B[j]) = 0
*
* So now the question turns into finding longest subarray with xor = 0
* since if both subarray have same xor then 
* xor_a ^ xor_b = 0 (this should be true since there value is same)
*
*/
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int optimal(vi a, vi b) {
  int n = a.size();
  vector<int> c(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    c[i] = a[i - 1] ^ b[i - 1];
  }
  // printArr(c);

  // * Prefix XOR of 'c' vector.
  vector<int> p(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] ^ c[i];
  }
  // printArr(p);

  // * Find subarray in 'c' whose xor is 0
  unordered_map<int, int> mp;
  mp[p[0]] = 0;

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = p[i];
    if (mp.count(cur)) // * check if same xor exists previously
      ans = max(ans, (i - mp[cur]));
  
    // * Only store first occurence to maximize subarray length
    if (!mp.count(cur)) 
      mp[cur] = i;
  }
  return ans;
}

int main(void) {
  // * testcase 1 // * ans = 5
  // vi a = {1, 2, 3, 4, 5};
  // vi b = {1, 2, 3, 4, 5};
  
  // * testcase 2 // * ans = 1
  // vi a = {5, 3, 9, 2};
  // vi b = {2, 3, 4, 1};

  // * testcase 3 // * ans = 0
  // vi a = {1, 2, 4, 8};
  // vi b = {0, 0, 0, 0};

  // * testcase 4 // * ans = 2
  vi a = {5, 1, 3, 2, 9, 4};
  vi b = {2, 1, 6, 2, 9, 3};

  cout << "a: ";
  printArr(a); 
  cout << "b: ";
  printArr(b); 
  
  // int ans = bruteForce(a, b);
  int ans = optimal(a, b);

  cout << "Longest subarray length with equal xor: " << ans << '\n';

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 max-xor-subarray-amazon-oa.cpp -o output && ./output
