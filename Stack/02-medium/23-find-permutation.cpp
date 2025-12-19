/*
 * Find Permutation
 * 
 * A permutation perm of n integers of all the integers in the range [1, n] can be 
 * represented as a string s of length n - 1 where:
 * 
 * - If s[i] == 'I', then perm[i] < perm[i + 1].
 * - If s[i] == 'D', then perm[i] > perm[i + 1].
 
 * Given a string s, reconstruct the lexicographically smallest permutation perm and return it.

 * Example 1
 * input       : s = "I"
 * output      : [1,2]

 * Example 2
 * input       : s = "DI"
 * output      : [2,1,3]

 * https://neetcode.io/problems/find-permutation/question
*/

// ! Google

#include <stack>
#include <vector>
#include <iostream>

template <typename T>
void printArr(std::vector<T> &arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- Approach 1: Optimal Approach -------------------------`
// * Using Stack
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
std::vector<int> findPermutation(std::string s) {
  std::stack<int> st;
  std::vector<int> res(s.length() + 1);

  int j = 0;
  for (int i = 1; i <= s.length(); ++i) {
    st.push(i);
    if (s[i - 1] == 'I') {
      while (!st.empty()) {
        res[j++] = st.top();
        st.pop();
      }
    }
  }

  st.push(s.length() + 1);
  while (!st.empty()) {
    res[j++] = st.top();
    st.pop();
  }
  return res;
}

int main(void) {
  // * testcase 1
  // std::string s = "I";

  // * testcase 2
  // std::string s = "DI";
  
  // * testcase 3
  std::string s = "IDID";
  
  std::cout << "s: " << s << std::endl;
  std::vector<int> ans = findPermutation(s);
  std::cout << "Ans: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 23-find-permutation.cpp -o output && ./output