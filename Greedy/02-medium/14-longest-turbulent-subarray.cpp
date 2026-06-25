/*
 * Leetcode - 978
 * Longest Turbulent Subarray
 * 
 * Given an integer array arr, return the length of a maximum size turbulent subarray of arr.
 * A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.
 * 
 * More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:
 * 
 * Example 1
 * input            : arr = [9,4,2,10,7,8,8,1,9]
 * output           : 5
 * Explanation      : arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
 * 
 * Example 2
 * input            : arr = [4,8,12,16]
 * output           : 2
 * 
 * Example 3
 * input            : arr = [10]
 * output           : 1
 * 
 * https://leetcode.com/problems/longest-turbulent-subarray/description/
 * https://neetcode.io/problems/longest-turbulent-subarray/
*/

// ! Amazon, Google

#include <queue>
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

// * ------------------------- Approach: Optimal Approach -------------------------
// * Greedy (Two Queues)
// * TIME COMPLEXITY O(n)
// * SPACE COMPLEXITY O(n)
string predictPartyVictory(string senate) {
  int n = senate.length();

  // * Create two queues R and D to store indices of Radiant and Dire senators.
  queue<int> R, D;
  for (int i = 0; i < n; ++i) {
    if (senate[i] == 'R') {
      R.push(i);
    }
    else {
      D.push(i);
    }
  }

  while (!R.empty() && !D.empty()) {
    int rTurn = R.front();
    R.pop();
    int dTurn = D.front();
    D.pop();

    // * Compare the front indices from both queues.
    // * The senator with the smaller index survives and gets re-added with index + n.
    // * The other senator is banned (removed permanently).
    if (rTurn < dTurn) {
      R.push(rTurn + n);
    } else {
      D.push(dTurn + n);
    }
  }

  return R.empty() ? "Dire" : "Radiant";
}

int main(void) {
  // * testcase 1
  string senate = "RD";
  
  // * testcase 2
  // string senate = "RDD";
  
  // * testcase 3
  // string senate = "RRDDD";

  cout << "senate: " << senate << endl;

  string ans = predictPartyVictory(senate);
  cout << "Answer: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++17 13-dota2-senate.cpp -o output && ./output

