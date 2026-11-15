/*
 * String Matching
 * 
 * Description:
 * You are given an array of strings. For each string in the array. Calculate the sum of matching
 * characters b/w that 
 * 
 * Constraints:
 * 1 <= N <= 2*1e5
 * Sum of length of all strings will be less than 1e5
 * 
 * Example 1    :
 * Input        : N = 3, strs = {"abc", "ade", "bbc"}
 * Output       : [3,0,0]
 * 
 * Example 1    :
 * Input        : N = 3, strs = {"abc", "ade", "abc"}
 * Output       : [4,1,0]
 * 
 * Example 3    :
 * Input        : N = 5, strs = {"bbz", "zaz", "aaa", "zaa", "zzz"}
 * Output       : [2,5,2,1,0]
 * 
 * https://docs.google.com/document/d/1Vo7ClwGzUrNtg-J895Gpt5pSkF8C5qxU_MEBw3SrXco/edit?tab=t.0
 * https://drive.google.com/file/d/15u5tfKlXqQzd7csz-qV6QmQmY8kkwv7z/view
*/

// ! OA
// ! Uber

#include <map>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

// Macros
#define all(v) v.begin(), v.end()

template <typename T>
void printArr(vector<T> &arr) {
  int n = arr.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << "\n";
}

int getMatching(string s, string t) {
  int count = 0;
  for (int i = 0; i < min(s.length(), t.length()); ++i) {
    if (s[i] == t[i])
      count++;
  }
  return count;
}

// * |S| = sum of all the strings
// * TIME COMPLEXITY O(|S|^2)
// * SPACE COMPLEXITY O(1)
vi bruteForce(int N, vector<string> strs) {
  vi ans(N, 0);
  for (int i = N - 2; i >= 0; --i) {
    int count = 0;
    for (int j = i + 1; j < N; ++j) {
      // cout << strs[i] << " " << strs[j] << endl;
      count += getMatching(strs[i], strs[j]);
    }
    ans[i] = count;
    // cout << "--------------------\n";
  }
  return ans;
}

// * |S| = sum of all the strings
// * TIME COMPLEXITY O(26 * |S|)
// * SPACE COMPLEXITY O(26 * |S|) => O(|s|) since 26 is constant
vi matchingCnt(int N, vector<string> strs) {
  vi ans(N, 0);
  vector<vector<int>> g(2000005, vector<int>(28, 0));
  // vector<vector<int>> g(5, vector<int>(5, 0)); // * For debug
  for (int i = N - 1; i >= 0; --i) {
    string s = strs[i];
    int cnt = 0;
    for (int j = 0; j < s.size(); ++j) { // * column
      int ch = s[j] - 'a';
      cnt = cnt + g[j][ch]; // * since we don't need to add count from first string.
      g[j][ch] += 1;        // * Incr the char freq in that column
    }
    ans[i] = cnt;
  }
  
  // * For Debug
  // for (auto &vec: g)
  //   printArr(vec);

  return ans;
}

int main(void) {
  // * testcase 1
  // int N = 3;
  // vector<string> strs = {"abc", "ade", "bbc"};
  
  // * testcase 2
  // int N = 5;
  // vector<string> strs = {"bbz", "zaz", "aaa", "zaa", "zzz"};

  // * testcase 3
  int N = 3;
  vector<string> strs = {"abc", "ade", "abc"};

  cout << "N: " << N << endl;
  cout << "strs: ";
  printArr(strs);

  // vi ans = bruteForce(N, strs);
  vi ans = matchingCnt(N, strs);

  cout << "ans: ";
  printArr(ans);

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 17-matching-string-uber-oa.cpp -o output && ./output
