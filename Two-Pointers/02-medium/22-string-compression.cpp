/*
 * Leetcode - 455
 * String Compression
 * 
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * - If the group's length is 1, append the character to s.
 * - Otherwise, append the character followed by the group's length.

 * The compressed string s should not be returned separately, but instead, be stored in the input character 
 * array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 * 
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.

 * Example 1
 * Input  : chars = ["a","a","b","b","c","c","c"]
 * Output : ["a","2","b","2","c","3"]
 * 
 * Example 2
 * Input  : chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output : ["a","b","1","2"].

 * https://leetcode.com/problems/string-compression/description/
*/

// ! Amazon, Google, Meta, Microsoft, Apple, Oracle

#include <vector>
#include <string>
#include <iostream>

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

// * ------------------------- APPROACH 1: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int compress(vector<char>& chars) {
  int n = chars.size();

  int i = 0, j = 0;
  while (j < n) {
    char cur_char = chars[j];
    int cur_count = 0;

    // * Find duplicates count
    while (j < n && chars[j] == cur_char) {
      cur_count++;
      j++;
    }

    // * Now do the compression
    chars[i] = cur_char;
    i++;

    // * Only add length if greater than 1
    if (cur_count > 1) {
      string num_str = to_string(cur_count);
      for (char &ch : num_str) {
        chars[i] = ch;
        i++;
      }
    }

  }

  return i;
}

int main(void) {
  // * testcase 1
  // vector<char> chars = {'a', 'b', 'c'};

  // * testcase 2
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

  // * testcase 3
  // vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

  std::cout << "Chars: ";
  printArr(chars);
  
  int ans = compress(chars);
  printArr(chars);

  cout << "String Compression " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 22-string-compression.cpp -o output && ./output
