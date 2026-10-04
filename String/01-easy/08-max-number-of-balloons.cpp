/*
 * Leetcode - 1189
 * Maximum Number of Balloons
 * 
 * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

 * You can use each character in text atmost once. Return the maximum number of instances that can be formed.

 * Example 1
 * Input  : text = "nlaebolko"
 * Output : 1

 * Example 2
 * Input  : text = "loonbalxballpoon"
 * Output : 2

 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 * https://leetcode.com/problems/rearrange-characters-to-make-target-string/
 * https://leetcode.com/discuss/post/3114099/amazon-oa-intern-2024-by-anonymous_user-57od/
*/

// ! OA 
// ! Amazon

#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

// * ------------------------- Utility -------------------------`

bool findStringInMap(string str, unordered_map<char, int> &charCount) {
  for(char c : str) {
    if (charCount.find(c) != charCount.end() && charCount[c] > 0) {
      charCount[c]--;
    }
    else {
      return false;
    }
  }
  return true;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Use Hashmap and count characters
// * TIME COMPLEXITY O(N) + O(N * no of balloons)
// * SPACE COMPLEXITY O(1)
int bruteForce(string str, string findStr) {
  unordered_map<char, int> charCount;
  for(char c : str) {
    charCount[c]++;
  }

  int c = 0;
  while(findStringInMap(findStr, charCount)) {
    c++;
  }

  return c;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * Hashing Array + Basic Maths
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int maxNumberOfBalloons(string s, string t) {
  vector<int> sFreq(26, 0);
  for (auto &c : s)
    sFreq[c - 'a']++;

  vector<int> tFreq(26, 0);
  for (auto &c : t)
    tFreq[c - 'a']++;

  int ans = s.length();
  for (auto &c : t) {
    int freq = sFreq[c - 'a'] / tFreq[c - 'a'];
    ans = min(ans, freq);
  }
  return ans;
}

int main() {
  // * testcase 1
  // string str = "nlaebolko";

  // * testcase 2
  string str = "loonbalxballpoon";

  // * testcase 3
  // string str = "leetcode";
  
  string findStr = "balloon";
  // int ans = bruteForce(str, findStr);
  // int ans = betterApproach(str, findStr);
  int ans = maxNumberOfBalloons(str, findStr);
  cout << "There are " << ans << " " << findStr << " in " << str << endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-max-number-of-balloons.cpp -o 08-max-number-of-balloons && ./08-max-number-of-balloons