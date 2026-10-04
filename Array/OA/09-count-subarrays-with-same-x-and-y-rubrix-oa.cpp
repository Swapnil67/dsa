/*
 * NAME
 * 
 * Description:
 * 
 * Constraints:
 * 
 * Example 1    :
 * Input        : nums = [-1,1,2,3,1], target = 2
 * Output       : 3
 * Explanation  : There are 3 pairs of indices that satisfy the conditions in the statement:
 * 
 * Example 2    :
 * Input        : nums = [-6,2,5,-2,-7,-1,3], target = -2
 * Output       : 10
 * Explanation  : There are 10 pairs of indices that satisfy the conditions in the statement:
 *
 * https://docs.google.com/document/d/1KP3CPUphLvCsOtAQw-rBqCbrdbIUc5VWhbJJOyWpbzI/edit?tab=t.0
*/

#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

#define all(v) v.begin(), v.end()

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

// ! Problem 1
/*
 * You are given an array of size “N”, Array only consists of integers “x” and “y”
 * Find the count of subarrays which have equal number of “x” and “y” 
*/

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteFoce(vector<string> arr) {
  int n = arr.size();
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int count_of_x = 0, count_of_y = 0;
    for (int j = i; j < n; ++j) {
      if (arr[j] == "x")
        count_of_x++;
      if (arr[j] == "y")
        count_of_y++;

      // * Subarray with same number of 'x' and 'y'.
      if (count_of_x == count_of_y)
        ans++;
    }
  }

  return ans;
}

// * Replace x = -1 and y = 1 -> now find the number of subarrays with sum = 0
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int betterApproach(vector<string> arr) {
  int n = arr.size();

  // * Change a[i] = "x" to a[i] = -1
  // * Change a[i] = "y" to a[i] = 1
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    if (arr[i] == "x") 
      nums[i] = -1;
    else 
      nums[i] = 1;    
  }
  // printArr(nums);

  unordered_map<int, int> mp; // * Map to store prefix sums and their counts
  mp[0] = 1;

  int prefix_sum = 0; // * Current prefix sum
  int count = 0;      // * Count of valid subarrays
  for (int i = 0; i < n; ++i) {
    prefix_sum += nums[i];
    if (mp.count(prefix_sum)) {
      count += mp[prefix_sum];
    }
    mp[prefix_sum]++;
  }

  return count;
}

// * count of x in arr[i...j] = cx[j] - cx[i - 1]
// * count of y in arr[i...j] = cy[j] - cx[i - 1]
// * cy - cx = cy[i - 1] - cx[i - 1]
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int optimal(vector<string> arr) {
  int n = arr.size();

  // * mp = {cx - cy, count}
  unordered_map<int, int> mp;
  mp[0] = 1;
  int cx = 0, cy = 0, count = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == "x")
      cx++;
    else 
      cy++;

    int d = cy - cx; // * diff in cx and cy
    count += mp[d];
    mp[d]++;
  }
  return count;
}

// ! Follow Up 1
// ! Problem 2
/*
 * You are given an array of size “N”, Array only consists of integers “x”, “y” and "z"
 * Find the count of subarrays which have equal number of “x”, “y” and "z"
*/
int optimalFollowUp1(vector<string> arr) {
  int n = arr.size();

  // * mp = {{cy - cx, cz - cy}, count}
  map<pair<int, int>, int> mp;
  mp[{0, 0}] = 1;
  int cx = 0, cy = 0, cz = 0, count = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == "x")
    cx++;
    else if (arr[i] == "y")
      cy++;
    else
      cz++;

    int d1 = cy - cx; // * First condition difference
    int d2 = cz - cy; // * Second condition difference

    count += mp[{d1, d2}];
    mp[{d1, d2}]++;
  }

  return count;
}


// ! Follow Up 2
// ! Problem 3
/*
 * You are given an array of size “N”, Array only consists of integers “v”, “w”, "x", "y" and "z"
 * Find the count of subarrays which have equal number of “v”, “w”, "x", "y" and "z"
*/
int optimalFollowUp2(vector<string> arr) {
  int n = arr.size();

  // * mp = {{cy - cx, cz - cy}, count}
  map<tuple<int, int, int, int>, int> mp;
  mp[{0, 0, 0, 0}] = 1;
  int cv = 0, cw = 0, cx = 0, cy = 0, cz = 0, count = 0;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == "v") cv++;
    else if (arr[i] == "w") cw++;
    else if (arr[i] == "x") cx++;
    else if (arr[i] == "y") cy++;
    else cz++;

    int d1 = cw - cv; // * First condition difference
    int d2 = cx - cw; // * Second condition difference
    int d3 = cy - cx; // * third condition difference
    int d4 = cz - cy; // * fourth condition difference

    count += mp[{d1, d2, d3, d4}];
    mp[{d1, d2, d3, d4}]++;
  }

  return count;
}


int main(void) {
  cout << "subarrays with equal number of 'x' and 'y'\n";
  vector<string> arr1 = {"x", "x", "y", "y", "x"};
  cout << "arr1: ";
  printArr(arr1);
  
  // int ans = bruteFoce(arr1);
  // int ans = betterApproach(arr1);
  int ans = optimal(arr1);
  cout << "Answer: " << ans << endl;
  
  cout << " ------- Follow Up 1 ------- " << endl;
  cout << "subarrays with equal number of 'x', 'y' and 'z'\n";
  // vector<string> arr2 = {"x", "z", "y", "z", "y", "x"};
  vector<string> arr2 = {"x", "z", "y", "z", "x", "y", "z", "z", "y", "x"};
  cout << "arr2: ";
  printArr(arr2);
  ans = optimalFollowUp1(arr2);
  cout << "Answer: " << ans << endl;
  
  cout << " -------- Follow Up 2 ------- " << endl;
  cout << "subarrays with equal number of 'v', 'w', 'x', 'y' and 'z'\n";
  vector<string> arr3 = {"v", "w", "x", "y", "z", "z", "y", "x", "v", "w"};
  cout << "arr3: ";
  printArr(arr3);
  ans = optimalFollowUp2(arr3);
  cout << "Answer: " << ans << endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 09-count-subarrays-with-same-x-and-y-rubrix-oa.cpp -o output && ./output
