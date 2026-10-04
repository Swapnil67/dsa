/*
 * Leetcode
 * Largest Subarray with sum atmost k
 *
 * Given a string s and an integer k, return the length of the longest contiguous substring such that the
 * abs difference b/w the ASCII values of any pair of characters in the substring is less than or equal to k.
 *
 * Example 1    :
 * Input        : s = "abacaba", k = 2
 * Output       : 7
 * Explanation  : "abacaba" is valid string
 *
 * Example 2    :
 * Input        : s = "azbzc", k = 2
 * Output       : 1
 * Explanation  : only single char satisfies the condition
 *
 * Example 3    :
 * Input        : s = "abaxzaba", k = 1
 * Output       : 3
 * Explanation  : "aba" is valid because max('b') - min('a') = 1.
 *
 * Example 4    :
 * Input        : s = "aaaaaa", k = 0
 * Output       : 6
 * Explanation  : Since k = 0, all characters in the substring must be identical. The entire string "aaaaaa" satisfies this.
 *
 * https://docs.google.com/document/d/1go_h1BaUdOBMSDcMPbwwnQfsXbzZaKh7R9sc0qnKbQE/edit?tab=t.0
 * https://drive.google.com/file/d/1JCFrbteuAc3gzQ-CQlbtlg2i8_5FJIW4/view
 * https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
 */

// ! OA
// ! Google
// ! Two Pointer + Sliding Window

#include <set>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i)
  {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(string s, int k) {
  int n = s.length(), maxLen = 0;
  for (int i = 0; i < n; ++i) {
    char minChar = s[i], maxChar = s[i];
    for (int j = i; j < n; ++j) {
      // * Track the actual min and max inside the current substring window
      minChar = min(minChar, s[j]);
      maxChar = max(maxChar, s[j]);

      if (maxChar - minChar <= k) {
        // cout << maxChar << " " << minChar << endl;
        maxLen = max(maxLen, (j - i + 1));
      } else {
        break; // * early break
      }
    }
  }
  return maxLen;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// * Two Pointer Template
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(n)
int betterApproach(string s, int k) {
  int n = s.length();
  multiset<char> ms;
  int maxLen = 0;
  int i = 0, j = 0, diff = 0;
  while (i < n && j < n) {
    ms.insert(s[j]);
    int diff = *ms.rbegin() - *ms.begin();

    // * Shrink window if condition is violated
    while (diff > k) {
      ms.erase(ms.find(s[i]));
      i++;
      diff = *ms.rbegin() - *ms.begin();
    }

    maxLen = max(maxLen, (j - i + 1));
    j++;
  }
  return maxLen;
}

// * ------------------------- APPROACH 3: Most Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int validSubstringOptimal(string s, int k) {
  int n = s.length();
  vector<int> count(26, 0);
  int maxLen = 0;
  int i = 0;

  for (int j = 0; j < n; ++j) {
    count[s[j] - 'a']++;

    // Helper lambda to find min and max char in the current window
    auto getDiff = [&]() {
      int minChar = 26, maxChar = -1;
      for (int c = 0; c < 26; ++c) {
        if (count[c] > 0) {
          minChar = min(minChar, c);
          maxChar = max(maxChar, c);
        }
      }
      return maxChar - minChar;
    };

    // Shrink window if max - min > k
    while (getDiff() > k) {
      count[s[i] - 'a']--;
      i++;
    }

    maxLen = max(maxLen, j - i + 1);
  }
  return maxLen;
}

int main(void) {
  // * testcase 1 // * Answer = 7
  // int k = 2;
  // string s = "abacaba";

  // * testcase 2 // * Answer = 1
  // int k = 2;
  // string s = "azbzc";

  // * testcase 3 // * Answer = 3
  // int k = 1;
  // string s = "abaxzaba";

  // * testcase 4 // * Answer = 6
  int k = 0;
  string s = "aaaaaa";

  cout << "k: " << k << endl;
  cout << "s: " << s << endl;

  // int ans = bruteForce(s, k);
  // int ans = betterApproach(s, k);
  int ans = validSubstringOptimal(s, k);

  cout << "Subarray with sum atmost k: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-largest-valid-substring.cpp -o output && ./output
