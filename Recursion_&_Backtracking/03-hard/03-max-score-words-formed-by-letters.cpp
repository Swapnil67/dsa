/*
 * Leetcode - 1255
 * Maximum Score Words Formed by Letters
 * 
 * Given a list of words, list of  single letters (might be repeating) and score of every character.

 * Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

 * It is not necessary to use all characters in letters and each letter can only be used once. 
 * Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.


 * Example 1
 * input  : words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], 
 *          score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
 * output : 23

 * Example 2
 * input  : words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"]
 *          score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
 * output : 27
 * 
 * https://leetcode.com/problems/maximum-score-words-formed-by-letters
*/

#include <vector>
#include <iostream>
#include <unordered_map>
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


int ans;
void solve(vector<string> &words,
           vector<int> &score,
           vector<int> &freq,
           int i, int cur_score)
{

  if (i >= words.size()) {
    ans = max(ans, cur_score);
    return;
  }

  // * Choice 1: Include the word (if possible)
  int j = 0, temp_score = 0;
  bool can_form = true;
  while (j < words[i].length()) {
    char ch = words[i][j];
    freq[ch - 'a']--;
    temp_score += score[ch - 'a'];

    j++;

    if (freq[ch - 'a'] < 0) {
      can_form = false;
      break;
    }
  }

  if (can_form) {
    // * Valid to include: Move forward
    solve(words, score, freq, i + 1, cur_score + temp_score);
  }

  // * BACKTRACK: Restore the frequency array before trying the next choice
  for (int k = 0; k < j; ++k) {
    freq[words[i][k] - 'a']++;
  }

  // * Choice 2: Skip the word
  solve(words, score, freq, i + 1, cur_score);
}

// * ------------------------- Approach: Optimal Approach -------------------------`
// * L - maximum length of a word.
// * TIME COMPLEXITY O(2^n * L)
// * SPACE COMPLEXITY O(n)
int maxScoreWords(vector<string> &words,
                  vector<char> &letters,
                  vector<int> &score)
{
  // * create a letter freq map
  vector<int> freq(26, 0);
  for (char &c : letters)
    freq[c - 'a']++;

  ans = 0;
  int cur_score = 0;
  solve(words, score, freq, 0, cur_score);
  return ans;
}

int main(void) {
  // * testcase 1
  vector<string> words = {"dog", "cat", "dad", "good"};
  vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // * testcase 2
  // vector<string> words = {"xxxz", "ax", "bx", "cx"};
  // vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
  // vector<int> score = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};

  cout << "Words: ";
  printArr(words);
  cout << "Letters: ";
  printArr(letters);
  cout << "Score: " << endl;
  printArr(score);

  int res = maxScoreWords(words, letters, score);
  cout << "Result: " << res << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-max-score-words-formed-by-letters.cpp -o output && ./output