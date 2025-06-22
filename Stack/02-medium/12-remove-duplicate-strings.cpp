/*
 * Leetcode - 1209
 * Remove All Adjacent Duplicates in String II
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

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

// * Using Plain Stack + Unordered Map
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
std::string removeDuplicates(std::string s, int k) {
  int n = s.size();
  std::stack<char> st;
  std::unordered_map<char, int> freqHash;
  for (char &ch : s) {
    freqHash[ch]++;
    if (!st.empty() && st.top() == ch) {
      freqHash[ch]++;
    } else {
      freqHash[ch] = 1;
    }
    st.push(ch);

    // std::cout << ch << " => " << freqHash[ch] << std::endl;
    // * If frequency becomes 'k'
    if (freqHash[ch] == k) {
      while (!st.empty() && freqHash[ch] != 0) {
        freqHash[ch]--;
        st.pop();
      }
    }
  }
  // std::cout << st.size() << std::endl;

  // * Create the answer
  std::string ans = "";
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
std::string removeDuplicates2(std::string s, int k) {
  int n = s.size();
  std::vector<std::pair<char, int>> st;
  for(char ch: s) {
    if(!st.size() || st.back().first != ch) {
      // * New character
      st.push_back({ch, 1});
    }
    else {
      // * found duplicate, i.e. st[-1][0] == ch
      st.back().second++;
    }

    // * if ch count gets equal to 'k'
    if(st.back().second == k) {
      st.pop_back();
    }
  }
  // std::cout << st.size() << std::endl;

  std::string ans = "";
  for (auto x : st) {
    ans.append(x.second, x.first);
  }

  return ans;
}

// * My Solution
// ! this fails on testcase 4 but the answer is right it's just that order is different
// ! since here we are using unordered_map this changes the order of o/p
std::string removeDuplicates3(std::string s, int k) {
  int n = s.size();
  std::unordered_map<char, int> freqHash;
  for(char &ch: s) {
    freqHash[ch]++;
    if (freqHash[ch] >= k) {
      while (freqHash[ch] == 0)
        freqHash[ch]--;
      freqHash.erase(ch);
    }
  }

  for(auto it: freqHash) {
    std::cout << it.first << " -> " << it.second << std::endl;
  }

  std::string ans = "";
  for(auto it: freqHash) {
    while(it.second > 0) {
      ans = it.first + ans;
      it.second--;
    }
  }

  return ans;
}

int main() {
  // * testcase 1
  // int k = 2;
  // std::string s = "abcd";

  // * testcase 2
  // int k = 3;
  // std::string s = "deeedbbcccbdaa";

  // * testcase 3
  // int k = 2;
  // std::string s = "pbbcggttciiippooaais";

  // * testcase 4
  int k = 4;
  std::string s = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy";

  std::cout << "Input String: " << s << std::endl;
  std::string ans = removeDuplicates3(s, k);
  std::cout << "Ans: " << ans << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 12-remove-duplicate-strings.cpp -o output && ./output