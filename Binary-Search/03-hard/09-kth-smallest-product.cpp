/*
* Leetcode - 2040
* Kth Smallest Product of Two Sorted Arrays
* Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) 
* smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

* Example 1:
* Input: nums1 = [2,5], nums2 = [3,4], k = 2
* Output: 8

* Example 2:
* Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
* Output: 0

* https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/
*/

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout<<std::endl;
}

typedef long long ll;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// ! TLE
// * TIME COMPLEXITY O(N^2) + O(slog(s))
// * SPACE COMPLEXITY O(N)
ll bruteForce(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();

  // * Edge case
  if (k > n1 + n2)
    return -1;

  std::vector<ll> productVec;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      productVec.push_back((ll)nums1[i] * (ll)(nums2[j]));
    }
  }

  std::sort(productVec.begin(), productVec.end());
  // printArr(productVec);

  return productVec[k - 1];
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
// ! TLE
// * kth Smallest = Max Heap
// * TIME COMPLEXITY O(N^2 * log(k))
// * SPACE COMPLEXITY O(k)
ll betterApproach(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();
  // * Edge case
  if (k > n1 + n2)
    return -1;

  // * 1. Create a max heap (Sorted in Descending Order)
  std::priority_queue<ll> pq;

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

bool isKthSmallestProduct(std::vector<int> &nums1, std::vector<int> &nums2, ll product, ll k) {
  int n1 = nums1.size(), n2 = nums2.size();
  int pairs = 0;
  for (int i = 0; i < n1; ++i) {
    // * Binary Search on nums2
    if (nums1[i] >= 0) {
      ll l = 0, r = n2 - 1;
      ll curPairs = -1; // * Invalid index on the LHS
      while (l <= r) {
        ll m = l + (r - l) / 2;
        ll curProduct = 1ll * nums1[i] * nums2[m];
        if (curProduct <= product) {
          curPairs = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      pairs += (curPairs + 1);
    } else {
      // * curProduct will be -ve & RHS will contain smaller product & LHS Larger products
      ll l = 0, r = n2 - 1;
      ll curPairs = n2; // * Invalid index on the RHS
      while (l <= r) {
        ll m = l + (r - l) / 2;
        ll curProduct = 1ll * nums1[i] * nums2[m];
        if (curProduct <= product) {
          curPairs = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }

      // * Here on LHS of 'm' we have greater products so we take from count b/2 m to n2
                                // *             m    n2
      pairs += (n2 - curPairs); // * {-10, -15, -20, -30}
    }
  }

  // std::cout << "Product: " << product << ", Pairs: " << pairs << std::endl;
  return pairs >= k;
}

ll kthSmallestProduct(std::vector<int> &nums1, std::vector<int> &nums2, ll k) {
  int n1 = nums1.size(), n2 = nums2.size();

  // * Binary Search
  ll l = -1e10, r = 1e10;
  // ll l = -50, r = 50;

  ll ans = -1;
  while (l <= r) {
    // std::cout << "l: " << l << " r: " << r << std::endl;
    ll m = l + (r - l) / 2;
    if (isKthSmallestProduct(nums1, nums2, m, k)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
    // std::cout<<"------------ \n";
  }

  return ans;
}

int main(void) {
  // * testcase 1
  // int k = 2;
  // std::vector<int> nums1 = {2, 5}, nums2 = {3, 4};

  // * testcase 2
  int k = 6;
  std::vector<int> nums1 = {-4, -2, 0, 3}, nums2 = {2, 4};

  // * testcase 3
  // int k = 3;
  // std::vector<int> nums1 = {-2, -1, 0, 1, 2}, nums2 = {-3, -1, 2, 4, 5};

  // * testcase 4
  // int k = 15;
  // std::vector<int> nums1 = {-9, 6, 10}, nums2 = {-7, -1, 1, 2, 3, 4, 4, 6, 9, 10};

  std::cout << "First Array" << std::endl;
  printArr(nums1);
  std::cout << "Second Array" << std::endl;
  printArr(nums2);

  // int ans = bruteForce(nums1, nums2, k);
  // long long ans = betterApproach(nums1, nums2, k);
  int ans = kthSmallestProduct(nums1, nums2, k);
  std::cout << "Kth Smallest product: " << ans << std::endl;
  
  return 0;
}

// * Run the code
// * g++ --std=c++20 09-kth-smallest-product.cpp -o output && ./output
