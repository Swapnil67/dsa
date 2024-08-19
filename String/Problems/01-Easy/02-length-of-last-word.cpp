/**
 * * Length of Last Word
 * * Given a string s consisting of words and spaces, return the length of the last word in the string.

 * * Example 1
 * * Input : str = "Hello World"
 * * Output : 5
 * * Explanation: The last word is "World" with length 5.

 * * Example 2
 * * Input : str = "   fly me   to   the moon  "
 * * Output : 4
 * * Explanation: The last word is "moon" with length 4.

 * * https://leetcode.com/problems/length-of-last-word/description/
*/

#include<string>
#include<iostream>

bool isValidChar(char ch) {
  return (
    ((int)ch >= (int)'A' && (int)ch <= (int)'Z') || 
    ((int)ch >= (int)'a' && (int)ch <= (int)'z') || 
    ((int)ch >= 0 && (int)ch <= 9));
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * From start count every word length then return the last count
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::string str) { 
  int n = str.size();
  int curC = 0, maxC = 0;
  for (int i = 0; i < n; ++i) {
    if(isValidChar(str[i])) {
      curC++;
    }
    else {
      maxC = std::max(maxC, curC);
      curC = 1;
      while(!isValidChar(str[i]))
        i++;
    }
  }
  maxC = std::max(maxC, curC);
  return maxC;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * Loop from backwards
// * TIME COMPLEXITY O(N) [Worst case]
// * TIME COMPLEXITY O(len of last word) [Best case]
// * SPACE COMPLEXITY O(1)
int lengthOfLastWord(std::string s) {
  int n = s.size(), cnt = 0;

  // * Step 1: Get i to the first char of last word
  int i = n-1;
  while(!isValidChar(str[i]))
    --i;

  // * Step 2: Count then length of last word
  for (; i >= 0; i--) {
    if (isValidChar(s[i]))
      cnt++;
    else
      break;
  }
  return cnt;
}


int main() {
  // * testcase 1
  // std::string str = "Hello World";
  // * testcase 2
  std::string str = "luffy is still joyboy";
  // * testcase 3
  // std::string str = "   fly me   to   the moon  ";
  std::cout << str << std::endl;
  // int len = bruteForce(str);
  int len = lengthOfLastWord(str);
  std::cout << "Length of last word is " << len << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-length-of-last-word.cpp -o 02-length-of-last-word && ./02-length-of-last-word