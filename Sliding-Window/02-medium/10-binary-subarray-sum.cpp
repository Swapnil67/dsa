
/**
 * * Leetcode - 930
 * * Binary Subarrays With Sum
 * * Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
 * * A subarray is a contiguous part of the array.

 * * Example 1
 * * Input  : nums = [1,0,1,0,1], goal = 2
 * * Output : 4
 * * Explanation: The 4 subarray whose sum is equal to 2
 * * [1,0,1,0,1]
 * * ______
 * * [1,0,1,0,1]
 * * ________
 * * [1,0,1,0,1]
 * *   ______
 * * [1,0,1,0,1]
 * *      ______
 

 * * Example 2
 * * Input  : nums = [0,0,0,0,0], goal = 0
 * * Output : 15
 * * Explanation: The 15 subarray whose sum is equal to 0
 * 
 * * https://leetcode.com/problems/binary-subarrays-with-sum/description/
*/

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> arr, int goal) {
  int n = arr.size();
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int cur_sum = 0;
    for (int j = i; j < n; ++j) {
      cur_sum += arr[j];
      if(cur_sum == goal) {
        ans++;
      } else if(cur_sum > goal) {
        break;
      }
    }
  }
  return ans;
}

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`
// * Prefix Sum [Map Data Structure]
// * TIME COMPLEXITY O(NlogN) [Ordered Map]
// * TIME COMPLEXITY O(N) [Best Case Unordered Map] or O(N^2) [Worst Case Unordered Map]
// * SPACE COMPLEXITY O(N)
int betterApproach(std::vector<int> arr, int goal) {
  int n = arr.size();
  int ans = 0, cur_sum = 0;
  std::unordered_map<int, int> sum_count;
  sum_count[0] = 1; // * If first rem comes zero
  for(int &num : arr) {
    cur_sum += num;
    int rem = cur_sum - goal;
    if(sum_count.find(rem) != sum_count.end()) {
      ans += sum_count[rem];
    }
    sum_count[cur_sum]++;
  }
  return ans;
}

// * ------------------------- APPROACH 3A: Optimal APPROACH -------------------------`
// * Clever apprach
// * Sliding Window for ans <= goal
int helper(std::vector<int> arr, int goal) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  int cur_sum = 0;
  if (goal < 0)
    return 0;
  while(j < n) {
    cur_sum += arr[j];

    while (i < j && cur_sum > goal) {
      cur_sum -= arr[i];
      i++;
    }
    // * for all cur_sum <= goal
    ans += (j - i + 1);
    j++;
  }
  return ans;
}

// * Simple Math
// * imagine if ans1 = 10 for goal <= 2
// * imagine if ans2 = 5 for goal <= 1
// * then ans1 - ans2 for goal == 2
int numSubarraysWithSum(std::vector<int> arr, int goal) {
  return helper(arr, goal) - helper(arr, goal - 1);
}

// * ------------------------- APPROACH 3B: Optimal APPROACH -------------------------`
// * Sliding Window + Prefix Zeros count
int numSubarraysWithSum2(std::vector<int> arr, int goal) {
  int n = arr.size();
  int i = 0, j = 0, ans = 0;
  int cur_sum = 0, zero_cnt = 0;
  while(j < n) {
    cur_sum += arr[j];

    while (i < j && (arr[i] == 0 || cur_sum > goal)) {
      if (arr[i] == 0) {
        zero_cnt++;
      } else {
        zero_cnt = 0;
      }
      cur_sum -= arr[i];
      i++;
    }

    if (cur_sum == goal) {
      ans += (1 + zero_cnt);
    }

    j++;
  }
  return ans;
}

int main() {
  // * testcase 1
  int goal = 2;
  std::vector<int> arr = {1, 0, 1, 0, 1};

  // * testcase 2
  // int goal = 2;
  // std::vector<int> arr = {0, 1, 0, 0, 1};

  // * testcase 3
  // int goal = 0;
  // std::vector<int> arr = {0, 0, 0, 0, 0};

  printf("Goal: %d\n", goal);
  printf("Input Array\n");
  printArr(arr);

  // int ans = bruteForce(arr, goal);
  // int ans = betterApproach(arr, goal);
  int ans = numSubarraysWithSum(arr, goal);
  printf("%d Binary Subarrays With Sum equal to %d\n", goal, ans);

  return 0;
}

// * Run the code
// * g++ --std=c++20 10-binary-subarray-sum.cpp -o output && ./output
