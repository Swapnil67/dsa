/*
 * Leetcode - 1405
 * Longest Happy String
 * 
 * A string s is called happy if it satisfies the following conditions:
 * - s only contains the letters 'a', 'b', and 'c'.
 * - s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * - s contains at most a occurrences of the letter 'a'.
 * - s contains at most b occurrences of the letter 'b'.
 * - s contains at most c occurrences of the letter 'c'.
 * 
 * Given three integers a, b, and c, return the longest possible happy string. 
 * If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

 * Example 1
 * input  : a = 1, b = 1, c = 7
 * output : "ccaccbcc"

 * Example 2
 * input  : a = 7, b = 1, c = 0
 * output : "aabaa"
 * 
 * https://leetcode.com/problems/longest-happy-string/description/
*/

// ! Microsoft

#include <queue>
#include <vector>
#include <iostream>

void printArr(std::vector<int> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// * ------------------------- Optimal Approach -------------------------`
// * using max_heap
// * k is the number of distinct characters in the input string s (maximum 26)
// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(1)
std::string longestDiverseString(int a, int b, int c) {
  std::priority_queue<std::pair<int, char>> max_heap;
  if (a > 0) max_heap.push({a, 'a'});
  if (b > 0) max_heap.push({b, 'b'});
  if (c > 0) max_heap.push({c, 'c'});

  std::string ans = "";
  while (!max_heap.empty()) {
    // * first take char with max freq
    auto [count, ch] = max_heap.top();
    max_heap.pop();
    
    // * check if prev 2 chars are same as 'ch'
    if (ans.size() > 1 && ans[ans.size() - 1] == ch && ans[ans.size() - 2] == ch) {
      if (max_heap.empty())
        break;
      
      // * If yes then take the next max freq char
      auto [count2, ch2] = max_heap.top();
      max_heap.pop();

      ans += ch2;
      if (--count2 > 0)
        max_heap.push({count2, ch2});
        
      max_heap.push({count, ch}); // * don't forget the push first popped pair
    }
    else {
      ans += ch;
      if (--count > 0)
        max_heap.push({count, ch});
    }
  }

  return ans;
}

int main(void) {
  // * testcase 1
  int a = 1, b = 1, c = 7;

  // * testcase 2
  // int a = 7, b = 1, c = 0;

  std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

  std::string ans = longestDiverseString(a, b, c);
  std::cout << "Longest Happy String: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 14-longest-happy-string.cpp -o output && ./output