/**
 * * Maximum Score After Splitting a String
 * * Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty 
 * * substrings (i.e. left substring and right substring).

 * * Example 1
 * * Input  : s = "011101"
 * * Output : 5
 * * Explanation : When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
 * 
 * * Example 2
 * * Input  : s = "1111"
 * * Output : 3
 * 
 * * https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
*/

#include<iostream>

using std::string;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int maxScoreBrute(string s) {
  int n = s.size();
  int mScore = 0, zeroCnt = 0;
  for (int i = 0; i < n; i++) {
    if(s[i] == '0') {
      zeroCnt++;
    }
    int oneCnt = 0;
    for (int j = i + 1; j < n; j++) {
      if(s[j] == '1') oneCnt++;
    }
    mScore = std::max(mScore, oneCnt + zeroCnt);
  }
  return mScore;
}

// * ------------------------- APPROACH 3: Optimal FORCE APPROACH -------------------------`
// * Count ones
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxScore(string s) {
  int n = s.size();
  int oneCnt = 0, zeroCnt = 0;
  int mScore = 0;
  // * Count number of ones
  for(char c : s) {
    if (c == '1')
      oneCnt += 1;
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '0')
      zeroCnt -= 1;
    else
      oneCnt -= 1;

    mScore = std::max(mScore, zeroCnt + oneCnt);
  }
  return mScore;
}

int main() {
  string s = "011101";
  // string s = "00111";
  // string s = "1111";
  std::cout << s << std::endl;
  // int ans = maxScoreBrute(s);
  int ans = maxScore(s);
  std::cout << "Max Score " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 13-max-score-after-split.cpp -o 13-max-score-after-split && ./13-max-score-after-split