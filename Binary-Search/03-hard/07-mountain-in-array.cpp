/*
* Leetcode - 1095
* Find in Mountain Array

* https://leetcode.com/problems/find-in-mountain-array/description/
*/

// ! Solve this on leetcode

#include <vector>
#include <iostream>
#include <unordered_map>

// * Leetcode class
class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int peakIdxMountainArr(MountainArray& mountainArr,
                           std::unordered_map<int, int> cache) {
        int n = mountainArr.length() - 1;

        int first_val = mountainArr.get(0);
        int second_val = mountainArr.get(1);
        if (first_val > second_val) {
            return 0;
        }

        int last_val = mountainArr.get(n);
        int second_last_val = mountainArr.get(n - 1);
        if (last_val > second_last_val) {
            return n;
        }

        int l = 1, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            // std::cout << m << std::endl;
            int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
            cache[m] = mid_val;

            int left_val =
                cache.count(m - 1) == 0 ? mountainArr.get(m - 1) : cache[m - 1];
            cache[m - 1] = left_val;

            int right_val =
                cache.count(m + 1) == 0 ? mountainArr.get(m + 1) : cache[m + 1];
            cache[m + 1] = right_val;

            // std::cout << left_val << " " << mid_val << " " << right_val
            //           << std::endl;

            if (left_val < mid_val && mid_val > right_val) {
                return m;
            } else if (left_val < mid_val) {
                // * increasing curve
                l = m + 1;
            } else {
                // * decreasing curve
                r = m - 1;
            }
        }
        return -1;
    }

    int binarySearch(int target, int l, int r, MountainArray& mountainArr,
                     std::unordered_map<int, int> cache) {

        while (l <= r) {
            int m = l + (r - l) / 2;
            int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
            cache[m] = mid_val;

            if (target == mid_val) {
                return m;
            } else if (target > mid_val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }

    int binarySearch2(int target, int l, int r, MountainArray& mountainArr,
                      std::unordered_map<int, int> cache) {

        while (l <= r) {
            int m = l + (r - l) / 2;
            int mid_val = cache.count(m) == 0 ? mountainArr.get(m) : cache[m];
            cache[m] = mid_val;

            if (target == mid_val) {
                return m;
            } else if (target > mid_val) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length() - 1;
        std::unordered_map<int, int> cache;

        int peak = peakIdxMountainArr(mountainArr, cache);
        // std::cout << "Peak: " << peak << std::endl;

        int ans = binarySearch(target, 0, peak, mountainArr, cache);
        if (ans != -1) {
            return ans;
        }

        return binarySearch2(target, peak + 1, n, mountainArr, cache);
    }
};