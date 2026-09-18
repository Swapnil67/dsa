/*
 * NDSA
 * Get minimum cost
 * 
 * Given n machine learning models. each with an associated cost and feature compatibility
 * - cost[i] represents the cost of ith model
 * - featureAvalibility[i] is a binary stirng indicating suitability for two distinct features:
 *  - "00" : not equipped for either feature.
 *  - "01" : suitable for feature A but not feature B.
 *  - "10" : suitable for feature B but not feature A.
 *  - "11" : suitable for both feature.
 * 
 * A Set of models is k-capable if the number of models suitable for feature A and 
 * number of models suitable for feature B are both greater than or equal to k.
 * 
 * For each value of k from 1 to n, determine the min cost required to assemble a k-capable
 * set of models. Return an array of n integers.
 * 
 * Example 1    :
 * Input        : cost = [3, 6, 9, 1, 2, 5], featureAvalibility = ["10", "01", "11", "01", "11", "10"]
 * Output       : [ 2, 6, 15, 26, -1, -1 ]
 *
 * https://www.desiqna.in/19335/visa-coding-oa-questions-and-solutions-sde-set-14-2026-kumar 
*/

// ! OA
// ! VISA, Amazon

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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)

vector<int> getMinimunCost(vector<int> &cost, vector<string> &featureAvalibility) {
  vector<int> bCostVec, aCostVec;
  int n = cost.size();
  // * Save the cost of 'A' and 'B' models in different arrays
  for (int i = 0; i < n; ++i) {
    if (featureAvalibility[i][0] == '0' && featureAvalibility[i][1] == '1') {
      aCostVec.push_back(cost[i]);
    }
    if (featureAvalibility[i][0] == '1' && featureAvalibility[i][1] == '0') {
      bCostVec.push_back(cost[i]);
    }
  }
  sort(begin(aCostVec), end(aCostVec));
  sort(begin(bCostVec), end(bCostVec));

  // printArr(aCostVec);
  // printArr(bCostVec);

  // * Merge the cost for min(aCostVec.size(), bCostVec.size())
  vector<int> finalCost;
  for (int i = 0; i < min(aCostVec.size(), bCostVec.size()); ++i) {
    finalCost.push_back(aCostVec[i] + bCostVec[i]);
  }
  // * Add the cost of both models to final cost array
  for (int i = 0; i < n; ++i) {
    if (featureAvalibility[i][0] == '1' && featureAvalibility[i][1] == '1') {
      finalCost.push_back(cost[i]);
    }
  }
  sort(begin(finalCost), end(finalCost));

  // * Find the cost for every k.
  vector<int> ans(n, -1);
  ans[0] = finalCost[0];
  for (int k = 1; k < finalCost.size(); ++k) {
    ans[k] = ans[k - 1] + finalCost[k];
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // vector<int> cost = {3, 6, 9, 1, 2, 5};
  // vector<string> featureAvalibility = {"10", "01", "11", "01", "11", "10"};

  // * testcase 2
  // vector<int> cost = {10, 10, 1, 1};
  // vector<string> featureAvalibility = {"01", "10", "11", "11"};

  // * testcase 3
  vector<int> cost = {20, 1, 2, 10};
  vector<string> featureAvalibility = {"11", "01", "01", "10"};

  vector<int> ans = getMinimunCost(cost, featureAvalibility);
  printArr(ans);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 rough.cpp -o output && ./output
