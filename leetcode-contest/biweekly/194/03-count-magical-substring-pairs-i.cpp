/*
 * Leetcode - 4090
 * Count Magical Substring Pairs I
 *
 * https://leetcode.com/problems/count-magical-substring-pairs-i/description/
*/

#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

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

// ! TLE
// * TIME COMPLEXITY O(N^3)
// * SPACE COMPLEXITY O(N)
int bruteForce(string s) {
  int n = s.length();
  int ans = 0;
  unordered_map<char, int> freq_s1, freq_s2;
  for (int i = 0; i < n; ++i) {
    freq_s1.clear();
    for (int j = i; j < n; ++j) {
      freq_s1[s[j]]++;
      freq_s2.clear();
      for (int k = j + 1; k < n; ++k) {
        freq_s2[s[k]]++;
        if (freq_s1.size() == freq_s2.size())
          ans++;
      }
    }
  }
  return ans;
}

// ! Intuition
/*
*
* 0 1 2 3 4 5 6 7
* a b a a b a b c
*       j
* 
* substring: distinct characters
*
*   j...0                 j+1...n
* Left Strings           Right Strings
*       a: 1             b: 1
*     a a: 1             b a: 2
*   b a a: 2             b a b: 2 
* a b a a: 2             b a b c: 3
*
*
* For j = 3
* For 1 distinct characters
* 1 substring on left of 1 distinct char & 1 substring on right of 1 distinct char.
* => 1 * 1 = 1
*
* For 2 distinct characters 
* 3 substrings on left of 2 distinct char & 3 substrings on right of 2 distinct char.
* => 3 * 3 = 8
*
* For 3 distinct characters => 0 * 1 = 0
* 0 substrings on left of 3 distinct char & 1 substrings on right of 3 distinct char.
* => 0 * 1 = 0
*
* Answer for 'j' = 1 + 8 + 0 => 9
*/

// * Fix the middle point 'j' and look for left and right substrings
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int countMagicalPairs(string s) {
  int n = s.length();
  int ans = 0;
  for (int j = 0; j < n; ++j) {
    vector<int> dis1(27, 0), dis2(27, 0);

    // * Find all count of distinct lenght substrings on left
    // * j...0
    int cur_distinct = 0;
    map<char, bool> freq;
    for (int i = j; i >= 0; --i) {
      if (freq[s[i]] == false) {
        cur_distinct++;
        freq[s[i]] = true;
      }
      dis1[cur_distinct]++;
    }

    // * Find all count of distinct lenght substrings on right
    // * j+1...k
    cur_distinct = 0;
    freq.clear();
    for (int k = j + 1; k < n; ++k) {
      if (freq[s[k]] == false) {
        cur_distinct++;
        freq[s[k]] = true;
      }
      dis2[cur_distinct]++;
    }

    // * For the given middle idx 'j' count all the substrings from len 1-26
    // * on left & right. (1 len on left * 1 len on right) + (2 len on left * 3 len on right) ... so on
    for (int i = 1; i <= 26;
         ++i) // * we can at max have 26 distinct characters
      ans += (dis1[i] * dis2[i]);

    // printArr(dis1);
    // printArr(dis2);
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // string s = "aba";

  // * testcase 2
  // string s = "kkk";

  // * testcase 3
  string s = "abcac";

  cout << "s: " << s << endl;

  // int ans = bruteForce(s);
  int ans = countMagicalPairs(s);
  cout << "ans: " << ans << '\n';


  return 0;
}
 
// * Run the code
// * g++ --std=c++20 03-count-magical-substring-pairs-i.cpp -o output && ./output
