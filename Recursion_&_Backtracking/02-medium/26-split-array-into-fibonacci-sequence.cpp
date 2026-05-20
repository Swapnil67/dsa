/*
 * Leetcode - 842
 * Split Array into Fibonacci Sequence
 * 
 * You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
 * 
 * Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
 * - 0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
 * - f.length >= 3, and
 * - f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
 * 
 * Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
 * 
 * Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
 * 
 * Example 1    :
 * Input        : num = "1101111"
 * Output       : [11,0,11,11]
 * Explanation  : The output [110, 1, 111] would also be accepted.
 * 
 * Example 2    :
 * Input        : nums = [1, -3, 2, 3, -4]
 * Output       : 5
 * Explanation  : 
 * 
 * https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
*/

#include <vector>
#include <climits>
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

bool dfs(int idx, string s, vector<int>& ans) {
  if (idx == s.length() && ans.size() > 2)
      return true;

  long num = 0;
  for (int i = idx; i < s.length(); ++i) {
    num = (num * 10) + s[i] - '0';
    if (num > INT_MAX) // * Pruning
      break;

    if (s[idx] == '0' && i > idx) // * Pruning
      break;

    if (ans.size() < 2 ||
        num == (long)(ans.back() * 1l + ans[ans.size() - 2])) {
      ans.push_back(num);
      if (dfs(i + 1, s, ans))
        return true;
      ans.pop_back();
    }
  }
  return false;
}

// * TIME COMPLEXITY O(N) on average valid inputs, and O(2^N) in the absolute worst-case scenario.
// * SPACE COMPLEXITY O(N)
vector<int> splitIntoFibonacci(string num) {
  int n = num.size();
  vector<int> ans;
  dfs(0, num, ans);
  return ans;
}

int main(void) {
  string num = "1101111";
  vector<int> ans = splitIntoFibonacci(num); 
  
  cout << "num: " << num << endl;
  cout << "Answer: ";
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 26-split-array-into-fibonacci-sequence.cpp -o output && ./output
