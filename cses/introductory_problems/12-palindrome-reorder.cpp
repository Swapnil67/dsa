/*
 * Palindrome Reorder
 * 
 * https://cses.fi/problemset/task/1755
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

void palindromeReorder() {
  string s;
  cin >> s;
  vector<int> freq(26, 0);
  for (auto &c : s)
    freq[c - 'A']++;

  ll n = s.length();
  int taken = 0;
  bool already_mid = false;
  for (char c = 0; c < 26; ++c) {
    if (freq[c] & 1) {
      if (n % 2 == 0 || already_mid) {
        cout << "NO SOLUTION" << "\n";
        return;
      }
      else {
        s[n / 2] = 'A' + c;
        already_mid = true;
      }
      freq[c]--;
    }
    int half = freq[c] / 2;
    for (int i = 0; i < half; ++i) {
      s[taken + i] = s[n - 1 - taken - i] = 'A' + c;
    }
    taken += half;
  }

  cout << s << "\n";
}

void palindromeReorder2() {
  string s;
  cin >> s;
  vector<int> freq(26, 0);
  for (auto &c : s)
    freq[c - 'A']++;

  ll n = s.length();
  string half = "";
  char mid = '?';
  for (char c = 0; c < 26; ++c) {
    if (freq[c] & 1) {
      if (n % 2 == 0 || mid != '?') {
        cout << "NO SOLUTION" << "\n";
        return;
      }
      else {
        mid = 'A' + c;
      }
      freq[c]--;
    }
    half += string(freq[c] / 2, 'A' + c);
  }

  cout << half;
  if (mid != '?')
    cout << mid;
  reverse(begin(half), end(half));
  cout << half << "\n"; 
}

// * TIME COMPLEXITY O(logn)
// * SPACE COMPLEXITY O(1)
int main() {
  // palindromeReorder();
  palindromeReorder2();
  return 0;
}

// * Run the code
// * g++ --std=c++20 12-palindrome-reorder.cpp -o output && ./output

/*
Input:
AAAACACBA
ABZ

Output:
AACABACAA
NO SOLUTION
*/

/*
* A: 6
* C: 2
* B: 1

* AAACBCAAA
*/