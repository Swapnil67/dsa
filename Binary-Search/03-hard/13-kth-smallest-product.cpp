/*
 * Leetcode - 2040
 * Kth Smallest Product of Two Sorted Arrays
 *
 * Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based)
 * smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 *
 * Example 1:
 * Input: nums1 = [2,5], nums2 = [3,4], k = 2
 * Output: 8
 *
 * Example 2:
 * Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
 * Output: 0
 *
 * https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/
 */

// ! Amazon, Google, Meta, Microsoft, LinkedIn, Bloomberg

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void printArr(vector<T> &nums)
{
  int n = nums.size();
  cout << "[ ";
  for (int i = 0; i < n; ++i)
  {
    cout << nums[i];
    if (i != n - 1)
      cout << ", ";
  }
  cout << " ]" << endl;
}

typedef long long ll;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// ! TLE
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
ll bruteForce(vector<int> &nums1, vector<int> &nums2, int k)
{
  int n1 = nums1.size(), n2 = nums2.size();

  // * Edge case
  if (k > n1 + n2)
    return -1;

  vector<ll> productVec;
  for (int i = 0; i < n1; ++i)
  {
    for (int j = 0; j < n2; ++j)
    {
      productVec.push_back((ll)nums1[i] * (ll)(nums2[j]));
    }
  }

  sort(productVec.begin(), productVec.end());
  // printArr(productVec);

  return productVec[k - 1];
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------
// ! TLE
// * kth Smallest = Max Heap
// * TIME COMPLEXITY O(N^2 * log(k))
// * SPACE COMPLEXITY O(k)
ll betterApproach(vector<int> &nums1, vector<int> &nums2, int k)
{
  int n1 = nums1.size(), n2 = nums2.size();
  // * Edge case
  if (k > n1 + n2)
    return -1;

  // * 1. Create a max heap (Sorted in Descending Order)
  priority_queue<ll> pq;

  // * 2. Push all the products into heap
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      pq.push((ll)(nums1[i] * nums2[j]));
      // * If heap size gets greater than k then pop from top
      if (pq.size() > k)
        pq.pop();
    }
  }

  // * 3. Since our heap size it 'k' then top most element will contain kth smallest element
  return pq.top();
}

/*
 * Helper function to check if there are AT LEAST 'maxPairs' (k) pairs
 * whose product is less than or equal to 'maxProduct'.
 */
bool isValid(vector<int> &a, vector<int> &b, ll &maxPairs, ll &maxProduct)
{
  int n1 = a.size(), n2 = b.size();
  ll pairs = 0; // Tracks total valid pairs found

  // * Iterate through each element in the first array
  for (int i = 0; i < n1; ++i) {
    ll l = 0, r = n2 - 1;

    // * CASE 1: The element from array 'a' is positive.
    // * Multiplying by a larger number increases the product.
    // * We want to find the largest index in 'b' where (a[i] * b[m] <= maxProduct).
    if (a[i] > 0) {
      ll pairIdx = -1; // * Stores the rightmost valid index in 'b'
      while (l <= r) {
        ll m = l + (r - l) / 2;
        ll curProduct = a[i] * 1ll * b[m];

        if (curProduct <= maxProduct) {
          pairIdx = m; // * 'm' is valid, record it
          l = m + 1;   // * Try to find a larger valid index to the right
        }
        else {
          r = m - 1; // * Product is too large, look to the left
        }
      }
      // * All elements from index 0 up to 'pairIdx' form valid pairs
      pairs += (pairIdx + 1);

      // * CASE 2: The element from array 'a' is negative or zero.
      // * Multiplying a negative number by a larger number DECREASES the product (makes it more negative).
      // * We want to find the smallest index in 'b' where (a[i] * b[m] <= maxProduct).
    }
    else {
      ll pairIdx = n2; // * Stores the leftmost valid index in 'b'
      while (l <= r) {
        ll m = l + (r - l) / 2;
        ll curProduct = a[i] * 1ll * b[m];

        if (curProduct <= maxProduct) {
          pairIdx = m; // * 'm' is valid, record it
          r = m - 1;   // * Try to find a smaller valid index to the left
        }
        else {
          l = m + 1; // * Product is too large, look to the right
        }
      }
      // * All elements from index 'pairIdx' up to the end of array 'b' form valid pairs
      pairs += (n2 - pairIdx);
    }
  }

  // * If the total number of valid pairs is >= k, then 'maxProduct' is a viable upper bound
  return pairs >= maxPairs;
}


// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * Binary Search
// * TIME COMPLEXITY: O(log(2 * 10^10) * n1 * log(n2))
// * SPACE COMPLEXITY: O(1)
ll kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
  int n1 = nums1.size(), n2 = nums2.size();

  // * The search space ranges from the minimum possible product (-10^10)
  // * to the maximum possible product (10^10) based on constraints (-10^5 * 10^5)
  ll l = -1e10, r = 1e10;
  // ll l = -50, r = 50; // * For debug
  ll ans = -1;

  // * Binary search to find the exact Kth smallest product
  while (l <= r) {
    ll m = l + (r - l) / 2; // * Current product threshold to test

    if (isValid(nums1, nums2, k, m)) {
      ans = m;   // * 'm' is a possible candidate since it has >= k pairs below/equal to it
      r = m - 1; // * Try to look for a smaller valid product threshold
    }
    else {
      l = m + 1; // * 'm' has fewer than k pairs; threshold is too small, look higher
    }
  }

  return ans;
}

int main(void)
{
  // * testcase 1
  // int k = 2;
  // vector<int> nums1 = {2, 5}, nums2 = {3, 4};

  // * testcase 2
  int k = 6;
  vector<int> nums1 = {-4, -2, 0, 3}, nums2 = {2, 4};

  // * testcase 3
  // int k = 3;
  // vector<int> nums1 = {-2, -1, 0, 1, 2}, nums2 = {-3, -1, 2, 4, 5};

  // * testcase 4
  // int k = 15;
  // vector<int> nums1 = {-9, 6, 10}, nums2 = {-7, -1, 1, 2, 3, 4, 4, 6, 9, 10};

  cout << "First Array" << endl;
  printArr(nums1);
  cout << "Second Array" << endl;
  printArr(nums2);

  // int ans = bruteForce(nums1, nums2, k);
  // long long ans = betterApproach(nums1, nums2, k);
  int ans = kthSmallestProduct(nums1, nums2, k);
  cout << "Kth Smallest product: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 13-kth-smallest-product.cpp -o output && ./output
