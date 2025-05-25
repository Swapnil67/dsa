/*
 * Leetcode - 22
 * Generate Parentheses
 * Given two integer arrays pushed and popped each with distinct values, return true if this could have 
 * been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
 * 
 * * Example 1
 * * Input  : n = 3
 * * Output : ["((()))","(()())","(())()","()(())","()()()"]

 * * Example 2
 * * Input  : n = 1
 * * Output : ["()"]

 * https://leetcode.com/problems/generate-parentheses/description/
*/

#include <iostream>
#include <stack>
#include <vector>

void printStringVector(std::vector<std::string> strs) {
  int n = strs.size();
  std::cout << "[ "; 
  for (std::string s : strs) {
    std::cout << s << ", ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- APPROACH 1A: BRUTE FORCE APPROACH -------------------------`

// * TIME COMPLEXITY O(N)
bool isValidParentheses(std::string s) {
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
void backtrackingBrute(std::vector<std::string> &ans, std::string &s, int n)
{
  if (s.size() == 2 * n) {
    if(isValidParentheses(s)) {
      ans.push_back(s);
    }
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
std::vector<std::string> bruteForce(int n) {
  std::string s = "";
  std::vector<std::string> ans;
  backtrackingBrute(ans, s, n);
  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(2^2N) ~ O(2^N)
void backtracking(std::vector<std::string> &ans, int open_count, int close_count, int n, std::string s)
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
std::vector<std::string> generateParenthesis(int n) {
  std::string s = "";
  std::vector<std::string> ans;
  int open_count = 0, close_count = 0;
  backtracking(ans, open_count, close_count, n, s);
  return ans;
}

int main() {
  // int n = 3;
  int n = 2;
  // std::vector<std::string> ans = bruteForce(n);
  std::vector<std::string> ans = generateParenthesis(n);
  printStringVector(ans);
  return 0;
}

// * Run the code
// * $CXX 04-generate-parantheses.cpp -o output && ./output