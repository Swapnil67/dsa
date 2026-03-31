/*
 * Leetcode - 2070
 * Most Beautiful Item for Each Query
 * 
 * You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
 * You are also given a 0-indexed integer array queries. 
 * For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal
 * to queries[j]. If no such item exists, then the answer to this query is 0.
 * 
 * Return an array answer of the same length as queries where answer[j] is the answer to the jth query.
 * 
 * Example 1: 
 * Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
 * Output: [2,4,5,5,6,6]
 * 
 * Example 2:
 * Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
 * Output: [4]
 * 
 * https://leetcode.com/problems/most-beautiful-item-for-each-query/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<int>> matrix) {
  int r = matrix.size();
  if(r == 0) return;
  int c = matrix[0].size();
  for (int i = 0; i < r; ++i) {
    cout << "{ ";
    for (int j = 0; j < c; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "},";
    cout << endl;
  }
  cout << endl;
}

using namespace std;

template <typename T>
void printArr(vector<T> &nums) {
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i) {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

// * ------------------------- APPROACH 1: Brute Force -------------------------
// * TIME COMPLEXITY O(n^2)
// * SPACE COMPLEXITY O(1)
vector<int> bruteForce(vector<vector<int>> items, vector<int> queries) {
  int n = queries.size();
  vector<int> ans(n, 0);

  for (int i = 0; i < n; ++i) {  // * O(n)  => 'n' is size of queries
    int curQuery = queries[i];
    int curMax = 0;
    for (auto &it : items) {     // * O(m)  => 'm' is size of items
      if (it[0] <= curQuery) {
        curMax = max(curMax, it[1]);
      }
    }
    ans[i] = curMax;
  }

  return ans;
}

int helper(vector<vector<int>> &items, int cur_query) {
  int l = 0, r = items.size() - 1;
  int ans = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    // * if current item price is less than or equal cur_query
    if (items[m][0] <= cur_query) {
      ans = max(ans, items[m][1]);
      l = m + 1;
    } else {
      // * if current item price is greater than cur_query
      r = m - 1;
    }
  }

  return ans;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
// * Binary Search
// * TIME COMPLEXITY O(nlog(n) + m * log(n))
// * SPACE COMPLEXITY O(1)
vector<int> maximumBeauty(vector<vector<int>> items, vector<int> queries) {
  sort(items.begin(), items.end()); // * nlog(n)

  // * Pre Update the max beauty for each pair
  // * To get the max beauty in constant time
  int maxBeautySeen = items[0][1];
  for (int i = 1; i < items.size(); ++i) { // * O(n)
    maxBeautySeen = max(items[i][1], maxBeautySeen);
    items[i][1] = maxBeautySeen;
  }
  printMatrix(items);

  // * For every query find the highest price from items.
  int m = queries.size();
  vector<int> ans(m, 0);
  for (int i = 0; i < m; ++i) { // * O(m)
    ans[i] = helper(items, queries[i]);  // * O(log(n));
  }

  return ans;
}

int main(void) {
  // * testcase 1
  vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
  vector<int> queries = {1, 2, 3, 4, 5, 6};
  
  // * testcase 2
  // vector<vector<int>> items =
  //     {{193, 732}, {781, 962}, {864, 954}, {749, 627}, {136, 746}, {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388}, {487, 853}, {533, 554}, {247, 919}, {958, 150}, {193, 523}, {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}};
  // vector<int> queries = {985, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584};

  cout << "Items " << endl;
  printMatrix(items);
  cout << "Queries " << endl;
  printArr(queries);

  // vector<int> ans = bruteForce(items, queries);
  vector<int> ans = maximumBeauty(items, queries);
  printArr(ans);
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 23-most-beautiful-item-for-each-query.cpp -o output && ./output

