/*
 * Leetcode - 1209
 * Remove All Adjacent Duplicates in String II
 * 
 * You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters 
 * from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
 * We repeatedly make k duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
 * 
 * * Example 1
 * * Input  : s = "abcd", k = 2
 * * Output : "abcd"
 * 
 * * Example 2
 * * Input  : s = "deeedbbcccbdaa", k = 3
 * * Output : "aa"
 * 
 * * Example 2
 * * Input  : s = "pbbcggttciiippooaais", k = 2
 * * Output : "ps"
 * 
 * * Example 2
 * * Input  : s = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy", k = 4
 * * Output : "ybth"

* https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
*/

#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// * Using Plain Stack + Unordered Map
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
string removeDuplicates(string s, int k) {
  int n = s.size();
  stack<char> st;
  unordered_map<char, int> freqHash;
  for (char &ch : s) {
    freqHash[ch]++;
    if (!st.empty() && st.top() == ch) {
      freqHash[ch]++;
    } else {
      freqHash[ch] = 1;
    }
    st.push(ch);

    // cout << ch << " => " << freqHash[ch] << endl;
    // * If frequency becomes 'k'
    if (freqHash[ch] == k) {
      while (!st.empty() && freqHash[ch] != 0) {
        freqHash[ch]--;
        st.pop();
      }
    }
  }
  // cout << st.size() << endl;

  // * Create the answer
  string ans = "";
  while(!st.empty()) {
    ans = st.top() + ans;
    st.pop();
  }

  return ans;
}

// * Using Vector as stack
// ! This will pass all testcases 
// * TIME COMPLEXITY O(N) 
// * SPACE COMPLEXITY O(N)
string removeDuplicates2(string s, int k) {
  int n = s.size();
  vector<pair<char, int>> st;
  for(char ch: s) {
    if (st.empty() || st.back().first != ch) {
      // * New character
      st.push_back({ch, 1});
    }
    else {
      // * found duplicate, i.e. st[-1][0] == ch
      st.back().second++;
    }

    // * if ch count gets equal to 'k'
    if (st.back().second == k) {
      st.pop_back();
    }
  }
  // cout << st.size() << endl;

  string ans = "";
  for (auto &it : st) {
    ans.append(it.second, it.first);
  }

  return ans;
}

int main() {
  // * testcase 1
  // int k = 2;
  // string s = "abcd";

  // * testcase 2
  // int k = 3;
  // string s = "deeedbbcccbdaa";

  // * testcase 3
  // int k = 2;
  // string s = "pbbcggttciiippooaais";

  // * testcase 4
  int k = 4;
  string s = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy";

  cout << "Input String: " << s << endl;
  string ans = removeDuplicates2(s, k);
  cout << "Ans: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-remove-duplicate-strings.cpp -o output && ./output