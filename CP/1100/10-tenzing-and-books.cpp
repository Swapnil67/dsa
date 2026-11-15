/*
 * Tenzing and Books
 * 
 * Description  : Tenzing has 3 stacks of books, with each stack containing n books. 
 *                Each book has a non-negative integer difficulty rating. Tenzing's 
 *                initial knowledge is 0. He can repeatedly pick any non-empty stack, 
 *                read the book on top, and update his knowledge from u to (u | v), 
 *                where v is the book's difficulty rating and '|' represents the bitwise 
 *                OR operation. Determine if he can achieve a final knowledge rating of 
 *                exactly x by reading any number of books.
 * 
 * Constraints  : 1 <= t <= 10^4 (number of test cases)
 *                1 <= n <= 10^5
 *                0 <= x <= 10^9
 *                0 <= difficulty_i <= 10^9
 *                The sum of n over all test cases does not exceed 10^5.
 * 
 * Example 1    :
 * Input        : n = 3, x = 7
 *                stack_a = [1, 2, 3]
 *                stack_b = [4, 5, 6]
 *                stack_c = [7, 8, 9]
 * Output       : Yes
 * Explanation  : Tenzing can read the top book of stack A (difficulty 1), his knowledge becomes 0|1 = 1.
 *                Then he reads the next book of stack A (difficulty 2), knowledge becomes 1|2 = 3.
 *                Then he reads the top book of stack B (difficulty 4), knowledge becomes 3|4 = 7.
 *                His knowledge is now exactly x = 7, so he can stop.
 * 
 * https://codeforces.com/problemset/problem/1842/B
*/

// ! Observation
/*
* If a book has difficulty rating  and 𝑥|𝑦 != 𝑥, Tenzing will never read this book because it will
* change a 0 bit in 𝑥 to 1.
*
* We called a number 𝑦 valid if 𝑥|𝑦 = 𝑥. For each sequence, we can find a longest prefix of it such 
* that all numbers in this prefix are valid. 
* Find the bitwise OR of the three prefix and check whether it equals to 𝑥.
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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

// * Time Complexity (TC): O(3 * N^2)
// * Space Complexity (SC): O(N)
void solve() {
  ll n, x;
  cin >> n >> x;

  ll s = 0;
  VEC(a, n, ll);
  for (size_t i = 0; i < 3; ++i) {

    // * Take the input for stack.
    for (size_t j = 0; j < n; ++j) cin >> a[j];
    
    for (size_t j = 0; j < n; ++j) {
      if ((x | a[j]) != x) // * Some unwanted but bit got set.
        break;
      s |= a[j];
    }
  }

  cout << (s == x ? "YES\n" : "NO\n");
}


// * Here we precompute the prefix ORs of all 3 stack each array can have max 31 values
// * since there are 31 individual bits which can be set to '1'.
// * Time Complexity (TC): O(max(3*n, (31^3)))
// * Space Complexity (SC): O(3*31)
void solve2() {
  ll n, x;
  cin >> n >> x;
 
  // * Precomputed OR results for each stack
  vector<ll> pre[3];
  
  ll s = 0;
  for (size_t i = 0; i < 3; ++i) {
    ll s = 0;
    pre[i].push_back(s);

    // * Read each book's difficulty in the stack
    for (size_t j = 0; j < n; ++j) {
      ll a;
      cin >> a;

      // * If adding this book changes the OR result, update it
      if ((s | a) != s) {
        s |= a;
        pre[i].push_back(s);
      }
    }
  }
  
  bool ans = false; // * Flag to check if x can be achieved
	// * Check all combinations of OR results from the three stacks
  for (auto A: pre[0]) {
    for (auto B: pre[1]) {
      for (auto C: pre[2]) {
        // * Check if the combined OR result equals x
        if ((A | B | C) == x) {
          ans = true;
          break;
        }
      }
      if (ans) break;
    }
    if (ans) break;
  }
 
  
  cout << (ans ? "YES\n" : "NO\n");
}

int main(void) {
  // Optimize standard I/O operations for competitive programming
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  solve();
  solve2();

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output

// * testcases
/*
5
2
1 2
6
10 2 3 6 1 3
4
1000000000 1000000000 1000000000 1000000000
15
60978 82265 78961 56708 39846 31071 4913 4769 29092 91348 64119 72421 98405 222 14294
8
19957 69913 37531 96991 57838 21008 14207 19198
*/

// * Output
/*
1
9
0
189114
112141
*/