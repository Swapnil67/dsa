/*
 * Leetcode - 126
 * Word Ladder II
 * 
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a 
 * sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 * 
 * - Every adjacent pair of words differs by a single letter.
 * - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * - sk == endWord
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation 
 * sequences from beginWord to endWord, or an empty list if no such sequence exists. 
 * Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
 * 
 * Example 1:
 * Input     : beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * Output    : [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * 
 * 
 * https://leetcode.com/problems/word-ladder-ii/
 * https://www.geeksforgeeks.org/problems/word-ladder-ii/1
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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

void dfs(
    std::string word,
    std::string &target,
    std::vector<std::string> seq,
    std::unordered_map<std::string, int> &mpp,
    std::vector<std::vector<std::string>> &ans)
{
  // * Found the target word
  if (word == target) {
    std::reverse(seq.begin(), seq.end());
    ans.push_back(seq);
    std::reverse(seq.begin(), seq.end());
    return;
  }

  int steps = mpp[word];
  for (int i = 0; i < word.size(); ++i) {
    char og_char = word[i];
    for (char c = 'a'; c <= 'z'; ++c) {
      word[i] = c;
      if (mpp.count(word) && mpp[word] + 1 == steps) {
        seq.push_back(word);
        dfs(word, target, seq, mpp, ans);
        seq.pop_back();
      }
    }
    word[i] = og_char;
  }

}

// * ------------------------- APPROACH: Optimal  -------------------------`
// * Replace every char of work with 'a-z' char
// * hit -> ait, bit, cit, .... hit ... zit
// * hit -> hat, hbt, hct, .... hot ... hzt
// * hot -> aot, bot, cot, .... lot ... zot
// * lot -> loa, lob, loc, .... log ... lot
// * log -> aog, bog, cog

// * N = word list size
// * W = size of each word size
// * TIME COMPLEXITY  O(N * W * 26) * logN
// * SPACE COMPLEXITY O(N)
std::vector<std::vector<std::string>> bruteForce(
    std::string begin_word,
    std::string end_word,
    std::vector<std::string> &word_list)
{
  std::unordered_set<std::string> st(begin(word_list), end(word_list));

  std::queue<std::vector<std::string>> q;
  q.push({begin_word});

  std::vector<std::string> used_on_level;
  used_on_level.push_back(begin_word);

  int level = 0;
  std::vector<std::vector<std::string>> ans;
  while (!q.empty()) {
    std::vector<std::string> vec = q.front();
    q.pop();

    if (vec.size() > level) {
      level += 1;
      for (auto &it : used_on_level) {
        st.erase(it);
      }
      used_on_level.clear();
    }

    std::string word = vec.back();
    if (word == end_word) {
      if (ans.size() == 0) {
        ans.push_back(vec);
      }
      else if (ans[0].size() == vec.size()) {
        ans.push_back(vec);
      }
    }

    for (int i = 0; i < word.size(); ++i) {
      char og_char = word[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        word[i] = c;
        if (st.count(word)) {
          vec.push_back(word);
          q.push(vec);
          vec.pop_back();
          // * mark as visited
          used_on_level.push_back(word);
        }
      }
      word[i] = og_char;
    }
  }

  return ans;
}


// * ------------------------- APPROACH: Optimal  -------------------------`
// * N = word list size
// * W = size of each word size
// * TIME COMPLEXITY  O(N * W * 26) * logN
// * SPACE COMPLEXITY O(N)
std::vector<std::vector<std::string>> findLadders(
    std::string begin_word,
    std::string end_word,
    std::vector<std::string> &word_list)
{
  std::unordered_set<std::string> st(begin(word_list), end(word_list));
  st.erase(begin_word);

  std::queue<std::string> q;
  q.push(begin_word);

  std::unordered_map<std::string, int> mpp;
  mpp[begin_word] = 1;

  while (!q.empty()) {
    std::string word = q.front();
    int steps = mpp[word];
    q.pop();

    if (word == end_word)
      break;

    steps += 1;
    for (int i = 0; i < word.size(); ++i) {
      char og_char = word[i];
      for (char c = 'a'; c <= 'z'; ++c) {
        word[i] = c;
        if (st.count(word)) {
          st.erase(word);
          q.push(word);
          mpp[word] = steps;
        }
      }
      word[i] = og_char;
    }
  }
  // for (auto &[word, steps]: mpp) { // * For Debugging
  //   std::cout << word << ": " << steps << std::endl;
  // }

  std::vector<std::vector<std::string>> ans;
  if (mpp.count(end_word)) {
    std::vector<std::string> seq;
    seq.push_back(end_word);
    dfs(end_word, begin_word, seq, mpp, ans);
  }

  return ans;
}


int main(void) {
  // * testcase 1
  std::string beginWord = "hit", endWord = "cog";
  std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  // * testcase 2
  // std::string beginWord = "a", endWord = "c";
  // std::vector<std::string> wordList = {"a", "b", "c"};

  std::cout << "Begin Word: " << beginWord << ", End Word: " << endWord << std::endl;
  std::cout << "Wordlist" << std::endl;
  printArr(wordList);

  std::vector<std::vector<std::string>> ans = findLadders(beginWord, endWord, wordList);
  for (auto &words : ans)
    printArr(words);

  return 0;
}


// * Run the code
// * g++ --std=c++20 08-word-ladder-ii.cpp -o output && ./output