/**
 * * Leetcode - 455
 * * String Compression
 * * Given an array of characters chars, compress it using the following algorithm:
 * * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * * - If the group's length is 1, append the character to s.
 * * - Otherwise, append the character followed by the group's length.

 * * The compressed string s should not be returned separately, but instead, be stored in the input character 
 * * array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 * 
 * * After you are done modifying the input array, return the new length of the array.
 * * You must write an algorithm that uses only constant extra space.

 * * Example 1
 * * Input  : chars = ["a","a","b","b","c","c","c"]
 * * Output : ["a","2","b","2","c","3"]
 * 
 * * Example 2
 * * Input  : chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * * Output : ["a","b","1","2"].

 * * https://leetcode.com/problems/string-compression/description/
*/

#include <vector>
#include <string>
#include <iostream>

template <typename T>
void printArr(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int compress(std::vector<char>& chars) {
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
      std::string num_str = std::to_string(cur_count);
      for (char &ch : num_str) {
        chars[i] = ch;
        i++;
      }
    }

  }

  return i;
}

int main(void) {
  // std::vector<char> chars = {'a'};
  std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  // std::vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
  printArr(chars);
  
  int ans = compress(chars);
  printArr(chars);
  std::cout << "String Compression " << ans << std::endl;
}

// * Run the code
// * g++ --std=c++20 22-string-compression.cpp -o output && ./output
