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

// * 01 - Unique Paths
// int uniquePaths(int m, int n) {
// TODO
// }

// * 02 - Unique Paths II
// int uniquePaths(vector<vector<int>> &grid) {
// TODO
// }

// * 03 - Minimum Path Sum
// int minPathSum(vector<vector<int>> &grid) {
// TODO
// }

// * 07 - Stone Game I
// bool stoneGame(vector<int> &piles) {
// TODO
// }

// * 08 - Stone Game II
// bool stoneGameII(vector<int> &piles) {
// TODO
// }

// * 09 - Last Stone Weight II
// bool lastStoneWeightII(vector<int> &stones) {
// TODO
// }

// * 10 - Best Time to Buy and Sell Stock II
// int maxProfit(vector<int> &prices, int fee) {
// TODO
// }

// * 11 - Best Time to Buy and Sell Stock with Cooldown
// int maxProfit(vector<int> &prices) {
// TODO
// }

// * 12 - Best Time to Buy and Sell Stock with Transaction Fee
// int maxProfit(vector<int> &prices, int fee) {
// TODO
// }

// * 13 - Minimum Falling Path Sum
// int minFallingPathSum(vector<vector<int>> &mat) {
// TODO
// }

// * 24 - Print Longest Common Subsequence
// string findLCS(string &s, string &t) {
// TODO
// }

// * 25 - Longest Common Substring
// string longCommSubstr(string &s, string &t) {
// TODO
// }

int main(void) {
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 practice.cpp -o output && ./output
