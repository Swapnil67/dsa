/*
 * Missing Number
 * 
 * https://cses.fi/problemset/task/1083
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int main(void) {
  ll n;
  cin >> n;
  vector<ll> nums(n);
  ll cur_sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    cin >> nums[i];
    cur_sum += nums[i];
  }

  ll total_sum = n * (n + 1) / 2;
  cout << total_sum - cur_sum << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-missing-number.cpp -o output && ./output

/*
Input:
5
2 3 1 5

Output:
4
*/