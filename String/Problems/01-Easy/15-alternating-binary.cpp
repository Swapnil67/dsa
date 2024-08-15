/**
 * * Minimum Changes To Make Alternating Binary String
 * * You are given a string s consisting only of the characters '0' and '1'. 
 * * In one operation, you can change any '0' to '1' or vice versa.

 * * Example 1
 * * Input  : s = "0100"
 * * Output : 1
 * * Explanation : If you change the last character to '1', s will be "0101", which is alternating.
 * 
 * * Example 2
 * * Input  : s = "10"
 * * Output : 0
 * 
 * * https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/
*/

#include<iostream>

// * ------------------------- APPROACH B: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::string s) {
  int changeCnt = 0;
  char nextChar = s[0];
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) { // * Even Index
      if (s[i] == '1')
        changeCnt++;
    }
    else { // * Odd Index
      if (s[i] == '0')
        changeCnt++;
    }
  }
  int ans = std::min(changeCnt, n - changeCnt);
  return ans;
}

// * ------------------------- APPROACH B: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int get_ops(std::string s, char flipStart) {
  char flip = flipStart;  
  int c = 0;
  for (char ch : s) {
    if(ch != flip) {
      c++;
    }
    flip = flip == '0' ? '1' : '0';
  }
  return c;
}

int minOperations(std::string s) {
  return std::min(
      get_ops(s, '0'),
      get_ops(s, '1'));
}

int main() {
  // std::string s = "0100";
  std::string s = "1111";
  // std::string s = "10";
  std::cout << s << std::endl;
  // int count = bruteForce(s);
  int count = minOperations(s);
  std::cout << "Minimum change required is " << count << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 15-alternating-binary.cpp -o 15-alternating-binary && ./15-alternating-binary