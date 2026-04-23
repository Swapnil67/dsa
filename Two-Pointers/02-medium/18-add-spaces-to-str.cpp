/*
 * Leetcode - 2109
 * Adding Spaces to a String
 * 
 * Example 1
 * Input  : s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
 * Output : "Leetcode Helps Me Learn"
 * 
 * Example 2
 * Input  : s = "icodeinpython", spaces = [1,5,7,9]
 * Output : "i code in py thon"
 * 
 * Example 3
 * Input  : s = "spacing", spaces = [0,1,2,3,4,5,6]
 * Output : " s p a c i n g"
 * 
 * https://leetcode.com/problems/adding-spaces-to-a-string
*/

#include <vector>
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


// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N) ~ Only for answer
string addSpaces(string s, vector<int> spaces) {
  int j = 0;

  string ans = "";
  for (int i = 0; i < s.length(); ++i) {
    // * check if the current char is space
    if (j < spaces.size() && i == spaces[j]) {
      ans += ' ';
      j++;
    }
    ans += s[i];
  }
  return ans;
}

int main(void) {
  // * testcase 1
  string s = "LeetcodeHelpsMeLearn";
  vector<int> spaces = {8, 13, 15};
  
  // * testcase 2
  // string s = "icodeinpython";
  // vector<int> spaces = {1, 5, 7, 9};
  
  // * testcase 3
  // string s = "spacing";
  // vector<int> spaces = {0, 1, 2, 3, 4, 5, 6};

  cout << "Input string: " << s << endl;
  cout << "Space vector: ";
  printArr(spaces);

  string ans = addSpaces(s, spaces);
  cout << "Answer: " << ans << endl;
}

// * Run the code
// * g++ --std=c++20 18-add-spaces-to-str.cpp -o output && ./output

