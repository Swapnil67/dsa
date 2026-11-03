/*
 * Sliding Window Minimum (CSES 3221)
 * 
 * Calculate the minimum of each sliding window of size k in an array of n integers, 
 * where the large input is generated pseudorandomly using linear congruential generation.
 * Return the bitwise XOR sum of all window minimums.
 * 
 * Constraints:
 * 1 <= k <= n <= 10^7, 0 <= x, a, b <= 10^9, 1 <= c <= 10^9
 * 
 * https://cses.fi/problemset/task/3221
*/


#include <set>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

// Macros
#define all(v) v.begin(), v.end()
#define VEC(name, size, ...) vector<__VA_ARGS__> name(static_cast<size_t>(size))
#define READ_VEC(name) for(size_t i = 0; i < (name).size(); ++i) cin >> (name)[i]

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

// ! Using multiset
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void bruteForce(vi nums, ll k) {
  ll n = nums.size();

  multiset<int> mst;
  for (int i = 0; i < k; ++i) {
    mst.insert(nums[i]);
  }

  ll answer = *mst.begin();
  for (int i = k; i < n; ++i) {
    mst.insert(nums[i]);
    mst.erase(mst.find(nums[i - k]));
    answer ^= *mst.begin();
  }

  cout << answer << '\n';
}

// ! Using Queue
// * TIME COMPLEXITY O(NlogN)
// * SPACE COMPLEXITY O(N)
void optimalApproach(vi nums, ll k) {
  ll n = nums.size();

  deque<int> dq;
  const auto push = [&](int i) {
    while (!dq.empty() && nums[dq.back()] >= nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
  };

  // * Smallest element will be in front of deque
  // * Push the first 'k' elements to deque
  for (int i = 0; i < k; ++i) {
    push(i);
  }
  ll answer = nums[dq.front()];
  // cout << answer << ' ';
  for (int i = k; i < n; ++i) {
    push(i);
    if (dq.front() == i - k) {
      dq.pop_front();
    }
    // cout << nums[dq.front()] << ' ';
    answer ^= nums[dq.front()];
  }
  cout << '\n';

  cout << answer << '\n';
}

int main(void) {
  ll n, k;
  cin >> n >> k;
  ll A, B, C;
  VEC(a, n, ll);
  cin >> a[0] >> A >> B >> C;
  for (int i = 1; i < n; ++i) { // * input generator
    // cout << a << " * " << x[i - 1] << " + " << b << " % " << c << '\n';
    a[i] = (1LL * A * a[i - 1] + B) % C;
  }
  // cout << "nums: ";
  // printArr(a); // * For debug

  // bruteForce(a, k);
  optimalApproach(a, k);
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 02-sliding-window-minimum.cpp -o output && ./output


/*
* Input:
8 5
3 7 1 11

8 1
3 7 1 11

* Output:
3

13

* Explanation:
* The input array is [3,0,1,8,2,4,7,6]. 
* The windows are [3,0,1,8,2], [0,1,8,2,4], [1,8,2,4,7] and [8,2,4,7,6], 
* and their minimums are 0, 0, 1 and 2. Thus, the answer is 0 ^ 0 ^ 1 ^ 2 = 3.
*/