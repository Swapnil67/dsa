/*
 * Fibonacci Number
 *
 * https://www.naukri.com/code360/problems/nth-fibonacci-number_74156
 * https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
 * https://www.naukri.com/code360/problems/print-fibonacci-series_7421617 
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

int get_fib(int x, vector<int> &dp) {
  if (x <= 1)
    return x;
  
  if (dp[x] != -1)
    return dp[x];
    
  return dp[x] = get_fib(x - 1, dp) + get_fib(x - 2, dp);
}

// * Bottom Up approach
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int get_fib(int x) {
  if (x <= 1)
    return x;

  vector<int> dp(x);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i < x + 1; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[x];
}

// * Bottom Up approach (Space Optimization)
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int get_fib2(int x) {
  if (x <= 1)
    return x;

  int prev1 = 1;
  int prev2 = 0;
  for (int i = 2; i < x + 1; ++i) {
    int cur = prev1 + prev2;
    prev2 = prev1;
    prev1 = cur;
  }
  return prev1;
}

// * Generates first 'n' fibonacci numbers
void gen_fib(int x, int n, vector<int> &ans) {
  if (x > n)
    return;
  // cout << x << " -> " << ans[x - 1] << " + " << ans[x - 2] << endl;

  ans[x] = ans[x - 1] + ans[x - 2];
  gen_fib(x + 1, n, ans);
}

int main(void) {
  int n = 10;
  vector<int> ans(n, 0);
  ans[0] = 0;
  ans[1] = 1;
  
  gen_fib(2, n, ans);
  cout << "First N fib numbers: " << endl;
  printArr(ans);

  vector<int> dp(n + 1, -1);
  // int fib_no = get_fib(8, dp);
  // int fib_no = get_fib(9);
  int fib_no = get_fib2(9);
  
  cout << "Nth Fibonacci Number: " << fib_no << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 00-fibonacci-no.cpp -o output && ./output

