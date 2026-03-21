/*
 * Leetcode - ?
 * Alien Dictionary
 * 
 * There is a foreign language which uses the latin alphabet, but the order among letters is not "a", "b", "c" ... "z" as in English.
 * 
 * You receive a list of non-empty strings words from the dictionary, where the words are sorted lexicographically 
 * based on the rules of this new language.
 * 
 * Derive the order of letters in this language. If the order is invalid, return an empty string. 
 * If there are multiple valid order of letters, return any of them.
 * 
 * A string a is lexicographically smaller than a string b if either of the following is true:
 * 
 * - The first letter where they differ is smaller in a than in b.
 * - a is a prefix of b and a.length < b.length.
 *
 * 
 * Example 1    :
 * Input        : ["z","o"]
 * Output       : "zo"
 * 
 * Example 2    :
 * Input        : ["hrn","hrf","er","enn","rfnn"]
 * Output       : "hernf"
 * 
 * https://neetcode.io/problems/foreign-dictionary/question
*/

// * Amazon, Google, Meta, Microsoft, Apple, Tiktok, Oracle

#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

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

// * V is the number of unique characters, 
// * E is the number of edges and 
// * N is the sum of lengths of all the strings.
// * TIME COMPLEXITY  O(N + V + E)
// * SPACE COMPLEXITY O(V + E)
string foreignDictionary(vector<string> &words) {
  unordered_map<char, unordered_set<char>> adj;
  unordered_map<char, int> indegree_mp;
  int n = words.size();

  // * Populate Data 
  for (string w : words) {
    for (char c : w) {
      adj[c] = unordered_set<char>();
      indegree_mp[c] = 0;
    }
  }

  // * Construct Adj List
  for (int i = 0; i < n - 1; ++i) {
    string w1 = words[i], w2 = words[i + 1];
    
    /// * Edge case
    // * When a longer word appears before its own prefix (e.g., "abc" before "ab")
    int min_len = min(w1.length(), w2.length());
    if (w1.size() > w2.size() && w1.substr(0, min_len) == w2.substr(0, min_len)) {
      return "";
    } 

    for (int j = 0; j < min_len; ++j) {
      if (w1[j] != w2[j])   {
        // std::cout << w1[j] << " " << w2[j] << std::endl;
        if (!adj[w1[j]].count(w2[j])) {
          adj[w1[j]].insert(w2[j]);
          indegree_mp[w2[j]]++;
        }
        break;
      }
    }
  }

  
  queue<char> q;
  for (auto &[c, deg]: indegree_mp) {
    if (deg == 0)
      q.push(c);
  }
  
  string res = "";
  while (!q.empty()) {
    char ch = q.front();
    q.pop();

    res += ch;
    for (auto &ngbr: adj[ch]) {
      indegree_mp[ngbr]--;
      if (indegree_mp[ngbr] == 0) {
        q.push(ngbr);
      }
    }
  }

  return res;
} 

int main(void) {
  // * testcase 1
  vector<string> words = {"z", "o"};

  // * testcase 2
  // vector<string> words = {"hrn", "hrf", "er", "enn", "rfnn"};

  cout << "Words: ";
  printArr(words);

  string ans = foreignDictionary(words);
  std::cout << "Answer: " << ans << std::endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 13-foreign-dictionary.cpp -o output && ./output
