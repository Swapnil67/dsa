/*
 * Leetcode - 942
 * DI String Match
 * 
 * A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented 
 * as a string s of length n where:
 * 
 * - s[i] == 'I' if perm[i] < perm[i + 1], and
 * - s[i] == 'D' if perm[i] > perm[i + 1].
 * 
 * Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm,
 * return any of them.
 * 
 * Example 1
 * Input  : s = "IDID"
 * Output : [0,4,1,3,2]
 * 
 * Example 2
 * Input  : s = "III"
 * Output : [0,1,2,3]
 * 
 * Example 3
 * Input  : s = "DDI"
 * Output : [3,2,0,1]

 * https://leetcode.com/problems/di-string-match/description/
*/

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

bool matchesPattern(std::string num, std::string &pattern) {
  for (int i = 0; i < pattern.size(); ++i) {
    if ((pattern[i] == 'I' && num[i] > num[i + 1]) ||
        (pattern[i] == 'D' && num[i] < num[i + 1]))
    {
      return false;
    }
  }
  return true;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * CPP STL
// * TIME COMPLEXITY O(n * O(n+1)!)
// * SPACE COMPLEXITY O(n)
std::vector<int> bruteForce(std::string &s) {
  int n = s.size();
  std::string num = "";
  for (int i = 0; i <= n; ++i) {
    num.push_back(i + '0');
  }
  std::cout << num << std::endl;

  std::vector<int> ans;
  while (!matchesPattern(num, s)) { // * O(n)
    std::next_permutation(begin(num), end(num)); // * O(n+1)! [Permutation TC]
  }
  for (auto &c : num) {
    ans.push_back(c - '0');
  }
  return ans;
}


// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Stack Data structure
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n) [For answer only]
std::vector<int> diStringMatch(std::string s) {
  int n = s.size();
  std::vector<int> ans;
  std::stack<int> st;
  int count = 0;

  for (int i = 0; i <= n; ++i) {
    st.push(count);
    count += 1;
    if (i == n || s[i] == 'I') {
      while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
      }
    }
  }
  return ans;
}

int main() {
  // * testcase 1
  // std::string s = "IDID";

  // * testcase 2
  // std::string s = "III";

  // * testcase 3
  std::string s = "DDI";

  std::cout << "s: " << s << std::endl;
  // std::vector<int> ans = bruteForce(s);
  std::vector<int> ans = diStringMatch(s);
  printArr(ans);
}

// * Run the code
// * g++ --std=c++17 21-di-string-match.cpp -o output && ./output

