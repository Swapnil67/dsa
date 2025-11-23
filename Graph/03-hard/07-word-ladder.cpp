/*
 * Leetcode - 127
 * Word Ladder
 * 
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a 
 * sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 * 
 * - Every adjacent pair of words differs by a single letter.
 * - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * - sk == endWord
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the 
 * shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 * 
 * 
 * https://leetcode.com/problems/word-ladder/
 * https://www.geeksforgeeks.org/problems/word-ladder/1
 * https://www.naukri.com/code360/problems/word-ladder_1102319
*/

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

// ! Google, Microsoft, Amazon, Salesforce

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}



// * ------------------------- APPROACH: Optimal  -------------------------`
// * Replace every char of work with 'a-z' char
// * hit -> ait, bit, cit, .... hot ... zit
// * hot -> aot, bot, cot, .... lot ... zot
// * lot -> loa, lob, loc, .... log ... lot
// * log -> aog, bog, cog


// * N = word list size
// * W = size of each word size
// * TIME COMPLEXITY  O(N * W * 26) * logN
// * SPACE COMPLEXITY O(N)
int ladderLength(
    std::string begin_word,
    std::string end_word,
    std::vector<std::string> &word_list)
{
  // * 1. Add wordlist to set
  std::unordered_set<std::string> st(begin(word_list), end(word_list));
  st.erase(begin_word);

  // * 2. Create a queue for words & steps
  std::queue<std::pair<std::string, int>> q;
  q.push({begin_word, 1});

  // * 3. BFS
  while (!q.empty()) {
    auto [word, level] = q.front();
    q.pop();

    if (word == end_word) // * Found the end word
      return level;

    for (int i = 0; i < word.size(); ++i) {
      char og_char = word[i];
      std::cout << "Word: " << word << std::endl;
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        word[i] = ch;
        std::cout << word << ", ";
        if (st.count(word)) { // * word exist's in set
          st.erase(word);
          q.push({word, level + 1});
        }
      }
      word[i] = og_char;
      std::cout << "\n---------------\n" << std::endl;
    }
  }

  return 0; // * cannot found end_word
}

int main(void) {
  // * testcase 1
  // std::string beginWord = "hit", endWord = "cog";
  // std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  
  // * testcase 2
  std::string beginWord = "a", endWord = "c";
  std::vector<std::string> wordList = {"a", "b", "c"};

  std::cout << beginWord << " " << endWord << std::endl;
  std::cout << "Wordlist" << std::endl;
  printArr(wordList);

  int ans = ladderLength(beginWord, endWord, wordList);
  std::cout << "Answer " << ans << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 07-word-ladder.cpp -o output && ./output