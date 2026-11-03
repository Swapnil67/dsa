/*
 * Sliding Window Median
 * 
 * Description  : Given an array of n integers, calculate the median of each sliding window 
 *                of k elements from left to right. The median is the middle element when 
 *                the elements are sorted. If k is even, there are two middle elements; 
 *                choose the smaller value among them.
 * 
 * Constraints  : 1 <= k <= n <= 2 * 10^5
 *                1 <= x_i <= 10^9
 * 
 * Example 1    :
 * Input        : n = 8, k = 3
 *                array = [2, 4, 3, 5, 8, 1, 2, 1]
 * Output       : 3 4 5 5 2 1
 * Explanation  : The medians for each window of size k = 3 are calculated as follows:
 *                - [2, 4, 3] -> Sorted: [2, 3, 4] -> Median is 3
 *                - [4, 3, 5] -> Sorted: [3, 4, 5] -> Median is 4
 *                - [3, 5, 8] -> Sorted: [3, 5, 8] -> Median is 5
 *                - [5, 8, 1] -> Sorted: [1, 5, 8] -> Median is 5
 *                - [8, 1, 2] -> Sorted: [1, 2, 8] -> Median is 2
 *                - [1, 2, 1] -> Sorted: [1, 1, 2] -> Median is 1
 * 
 * https://cses.fi/problemset/task/1076
*/

#include <set>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

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

// * Use 2 set
void solve(vector<ll> nums, ll n, ll k) {
  multiset<ll> s1, s2;
  const auto s2_to_s1 = [&]() { // * move from s2 to s1
    s1.insert(*s2.begin());
    s2.erase(s2.begin());
  };
  const auto s1_to_s2 = [&]() { // * move from s2 to s1
    s2.insert(*s1.rbegin());
    s1.erase(prev(s1.end()));
  };

  const auto insert = [&](int i) {
    s2.insert(nums[i]);
    s2_to_s1(); // * move from s2 to s1
    if (s1.size() >= s2.size() + 2)
      s1_to_s2();  // * move from s1 to s2
  };
  
  const auto erase = [&](int i) {
    if (s1.count(nums[i])) {
      s1.erase(s1.find(nums[i]));
    } else {
      s2.erase(s2.find(nums[i]));
    }

    if (s1.size() >= s2.size() + 2) 
      s1_to_s2();
    if (s2.size() > s1.size()) 
      s2_to_s1();
  };

  const auto getMedian = [&]() {
    return *s1.rbegin();
  };

  // * For first 0...k
  for (int i = 0; i < k; ++i) {
    insert(i);
  }
  cout << getMedian() << ' ';

  // * For every next k size window
  for (int i = k; i < n; ++i) {
    insert(i);
    erase(i - k);
    cout << getMedian() << ' ';
  }
  cout << '\n';
}

// * TIME COMPLEXITY O(nlogk)
// * SPACE COMPLEXITY O(n)
int main() {
  // * Optimize standard I/O operations for competitive programming
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  vector<ll> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  printArr(nums);

  solve(nums, n, k);

  return 0;
}

// * Run the code
// * g++ --std=c++20 08-sliding-window-median.cpp -o output && ./output
