/*
 * Leetcode - 22
 * Generate Parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * Example 1
 * Input  : n = 3
 * Output : ["((()))","(()())","(())()","()(())","()()()"]

 * Example 2
 * Input  : n = 1
 * Output : ["()"]

 * https://leetcode.com/problems/generate-parentheses/description/
 * https://www.geeksforgeeks.org/problems/generate-all-possible-parentheses/1
*/

// ! Google, Microsoft, Amazon, Meta, Oracle, Adobe, Apple

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

// * ------------------------- APPROACH 1A: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(N)
bool isValidParentheses(string s) {
  int n = 0;
  for (char &ch : s) {
    if (n < 0)
      return false;
    if(ch == '(')
      n += 1;
    else if(ch == ')') 
      n -= 1;
  }
  return n == 0;
}

// * TIME COMPLEXITY O(2^2N) ~ O(2^N)
// * Using Recursion & Backtracking
void backtrackingBrute(vector<string> &ans, string &s, int n) {
  if (s.size() == 2 * n) {
    if (isValidParentheses(s))
      ans.push_back(s);
    return;
  }

  s.push_back('(');
  backtrackingBrute(ans, s, n);
  s.pop_back();

  s.push_back(')');
  backtrackingBrute(ans, s, n);
  s.pop_back();
}

// * Backtracking
// * TIME COMPLEXITY O(N * 2^2N)
// * SPACE COMPLEXITY O(2N) (Recursion width)
vector<string> bruteForce(int n) {
  string s = "";
  vector<string> ans;
  backtrackingBrute(ans, s, n);
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(2^2N) ~ O(2^N)
void backtracking(vector<string> &ans, int open_count, int close_count, int n, string s)
{
  // * No need to check isValidParentheses here
  if (s.size() == 2 * n) {
    ans.push_back(s);
    return;
  }

  // * open_count cannot become greater than n
  if (open_count < n) {
    s.push_back('(');
    backtracking(ans, open_count + 1, close_count, n, s);
    s.pop_back();
  }
  
  // * close_cnt cannot become greater than open_count
  if(close_count < open_count) {
    s.push_back(')');
    backtracking(ans, open_count, close_count + 1, n, s);
    s.pop_back();
  }
}

// * Backtracking With Safety Check
// * TIME COMPLEXITY O(2^2N)
// * SPACE COMPLEXITY O(2N) (Recursion width)
vector<string> generateParenthesis(int n) {
  string s = "";
  vector<string> ans;
  int open_count = 0, close_count = 0;
  backtracking(ans, open_count, close_count, n, s);
  return ans;
}

int main() {
  // * testcase 1
  // int n = 3;

  // * testcase 2
  int n = 2;

  // vector<string> ans = bruteForce(n);
  vector<string> ans = generateParenthesis(n);

  std::cout << "Valid Parentheses: " << std::endl;
  printArr(ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 25-generate-parantheses.cpp -o output && ./output