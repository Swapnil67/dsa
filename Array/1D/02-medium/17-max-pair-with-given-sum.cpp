/*
 * Number Of Pairs With Given Sum
 * 
 * You have been given an integer array/list(arr) and a number 'Sum'. Find and return the total number of pairs
 * in the array/list which when added, results equal to the 'Sum'.
 * 
 * Given array/list can contain duplicate elements.
 * 
 * (arr[i],arr[j]) and (arr[j],arr[i]) are considered same.
 * 
 * Example 1:
 * Input: nums = [2, 8, 10, 5, -2, 5]
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [1, 3, 6, 2, 5, 4, 3, 2, 4]
 * Output: 0

 * https://www.naukri.com/code360/problems/number-of-pairs-with-given-sum_630509
 * https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1
*/

#include <unordered_map>
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

// * Hashmap
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
long long pairsWithGivenSum(vector<int> arr, int sum) {
  unordered_map<int, int> hash;
  long long c = 0;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    int rem = sum - arr[i];
    if (hash.count(rem)) {
      c = c + hash[rem];
    }
    hash[arr[i]]++;
  }
  return c;
}

int main() {
  vector<int> arr = {2, 8, 10, 5, -2, 5};
  int sum = 10;

  // vector<int> arr = {1, 3, 6, 2, 5, 4, 3, 2, 4};
  // int sum = 12;

  // vector<int> arr = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1};
  // int sum = 11;
  // * [10,1] [10,1], [10,1], [10,1] [10,1], [10,1] [12,-1]

  printArr(arr);
  long long ans = pairsWithGivenSum(arr, sum);
  cout << "Number Of Pairs With Given Sum are " << ans << endl;

  return 0;
}

// * run the code
// * g++ --std=c++20 17-max-pair-with-given-sum.cpp -o output && ./output