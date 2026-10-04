/*
 * Repetitions
 * 
 * https://cses.fi/problemset/task/1069
*/

#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) (Input string)
int main(void) {
  string s;
  cin >> s;

  ll n = s.length();
  ll max_len = 1, count = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      max_len = max(max_len, count);
      count = 1;
    }
  }
  max_len = max(max_len, count);
  cout << max_len << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 03-repetitions.cpp -o output && ./output

/*
Input:
ATTCGGGA

Output:
3
*/