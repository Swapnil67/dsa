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
 * https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

template <typename T>
void printArr(std::vector<T> arr) {
  std::cout << "[ ";
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int ans;
void solve(std::vector<std::string> &words,
           std::vector<int> &score,
           std::vector<int> &freq,
           int i, int cur_score)
{

  if (i >= words.size()) {
    ans = std::max(ans, cur_score);
    return;
  }

  int j = 0, temp_score = 0;
  std::vector<int> temp_freq = freq;
  while (j < words[i].length()) {
    char ch = words[i][j];
    temp_freq[ch - 'a']--;
    temp_score += score[ch - 'a'];

    if (temp_freq[ch - 'a'] < 0)
      break;

    j++;
  }

  // * we were able to take this word
  if (j == words[i].length()) {
    // * take
    solve(words, score, temp_freq, i + 1, cur_score + temp_score);
  }
  
  // * not take
  solve(words, score, freq, i + 1, cur_score);
}


// * ------------------------- Approach: Optimal Approach -------------------------`
// * TIME COMPLEXITY O(2^n)
// * SPACE COMPLEXITY O(n)
int maxScoreWords(std::vector<std::string> &words,
                  std::vector<char> &letters,
                  std::vector<int> &score)
{
  // * create a letter freq map
  std::vector<int> freq(26, 0);
  for (char &c : letters)
    freq[c - 'a']++;

  ans = 0;
  int cur_score = 0;
  solve(words, score, freq, 0, cur_score);
  return ans;
}

int main(void) {
  // * testcase 1
  std::vector<std::string> words = {"dog", "cat", "dad", "good"};
  std::vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  std::vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // * testcase 2
  // std::vector<std::string> words = {"xxxz", "ax", "bx", "cx"};
  // std::vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
  // std::vector<int> score = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};

  std::cout << "Words: ";
  printArr(words);
  std::cout << "Letters: ";
  printArr(letters);
  std::cout << "Score: " << std::endl;
  printArr(score);

  int res = maxScoreWords(words, letters, score);
  std::cout << "Result: " << res << std::endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 03-max-score-words-formed-by-letters.cpp -o output && ./output