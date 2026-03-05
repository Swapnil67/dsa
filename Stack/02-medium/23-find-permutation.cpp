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

// * ------------------------- Approach 1: Optimal Approach -------------------------
// * we want to place smaller numbers as early as possible
// *  When we encounter a sequence of 'D's, we need to reverse the order of those numbers.
// * Using Stack
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
vector<int> findPermutation(string s) {
  int n = s.length();
  stack<int> st;
  vector<int> res(n + 1);

  int j = 0;
  for (int i = 1; i <= n; ++i) {
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
  // string s = "I";

  // * testcase 2
  // string s = "DI";
  
  // * testcase 3
  string s = "IDID";
  
  cout << "s: " << s << endl;
  vector<int> ans = findPermutation(s);
  cout << "Ans: ";
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 23-find-permutation.cpp -o output && ./output