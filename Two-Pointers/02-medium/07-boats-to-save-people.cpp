/**
 * * Boats to Save People
 * * You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats
 * * where each boat can carry a maximum weight of limit. 
 * * Each boat carries at most two people at the same time, provided the sum of the weight of those people 
 * * is at most limit.

 * * Example 1
 * * Input  : nums = [3,2,2,1], limit = 3
 * * Output : 3
 * 
 * * Example 2
 * * Input  : nums = [5,1,4,2], limit = 6
 * * Output : 2

 * * https://leetcode.com/problems/boats-to-save-people/description/
 * * https://www.naukri.com/code360/problems/minimum-boats-to-cross-river_1402321
*/

#include<iostream>

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * My Approach partially correct
int myApproach(std::vector<int>& people, int limit) {
  std::sort(people.begin(), people.end());
  printArr(people);
  int n = people.size();
  int boats = 1, cur_people = 0;
  for (int i = 0; i < n; ++i) {
    if(cur_people + people[i] > limit) {
      std::cout << cur_people << std::endl;
      cur_people = people[i];
      boats++;
    } 
    else {
      cur_people += people[i];
    }
  }
  std::cout << cur_people << std::endl;
  return boats;
}


// * ------------------------- APPROACH: Optimal APPROACH -------------------------`
// * Take at most two people on boat
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int numRescueBoats(std::vector<int>& people, int limit) {
  std::sort(people.begin(), people.end());
  printArr(people);
  int n = people.size();
  int boats = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    // * at most two people are allowed in boat
    if((people[l] + people[r]) <= limit) {
      l++, r--;
    }
    else {
      r--;
    }
    boats++;
  }
  return boats;
}

int main() {
  // int limit = 6;
  // std::vector<int> arr = {5, 1, 4, 2};
  int limit = 9;
  std::vector<int> arr = {3, 8, 7, 1, 4};
  printArr(arr);
  // int ans = myApproach(arr, limit);
  int ans = numRescueBoats(arr, limit);
  std::cout << "minimum number of boats to carry every given person " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 07-boats-to-save-people.cpp -o output && ./output