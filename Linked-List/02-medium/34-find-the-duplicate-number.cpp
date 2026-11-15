/*
 * Leetcode - 287
 * Find the Duplicate Number
 * 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
 * inclusive.
 * 
 * There is only one repeated number in nums, return this repeated number.
 * 
 * You must solve the problem without modifying the array nums and using only constant extra space.
 * 
 * Example 1    :
 * Input        : nums = [1,3,4,2,2]
 * Output       : 2
 * 
 * Example 2    :
 * Input        : nums = [3,1,3,4,2]
 * Output       : 3
 * 
 * Example 3    :
 * Input        : nums = [3,3,3,3,3]
 * Output       : 3
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
*/

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

/*
* Start --------> Entrance -------> Meeting Point
*          L                 X
*                    <------------>
*                     (Remaining: C - X)
*/


// * Floyd’s Cycle Detection Algorithm or Hare and Tortoise algorithm
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int findDuplicate(vector<int>& nums) {
	// * Phase 1: Initialize both pointers to the starting position
	// * We treat the array values as links/pointers to other indices
	int slow = nums[0];
	int fast = nums[0];

	// * Move pointers until they intersect inside the cycle
	while (true) {
		slow = nums[slow];			 // * Slow pointer moves 1 step
		fast = nums[nums[fast]]; // * Fast pointer moves 2 steps

		if (slow == fast) // * They met! A cycle is confirmed
			break;
	}

	// * Phase 2: Find the entrance of the cycle (the duplicate number)
	// * Keep 'slow' at the meeting point, and place a new pointer at the start
	int slow2 = nums[0];

	// * Move both pointers at the same speed (1 step at a time)
	// * Mathematically, they are guaranteed to meet exactly at the cycle entrance
	while (slow != slow2) {
		slow = nums[slow];
		slow2 = nums[slow2];
	}

	// * Both pointers now point to the cycle entrance, which is the duplicate value
	return slow;
}

// * Binary Search Solution
// * TIME COMPLEXITY O(nlogn)
// * SPACE COMPLEXITY O(1)
int findDuplicate(vector<int> &nums) {
	int n = nums.size();
	int l = 1, r = n;

	int ans = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;

		// * check how many numbers are smaller by current 'm'
		// * If 3 is duplicate then there should be atleast 4 numbers <= m (1,2,3,3)
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] <= m)
				cnt++;
		}

		if (cnt <= m) { // * m is not duplicate is check bigger
			l = m + 1;
		}
		else {
			// * m can be duplicate, go to left
			ans = m;
			r = m - 1;
		}
	}
	return ans;
}

int main(void) {
    // * testcase 1
    // vector<int> nums = {1, 3, 4, 2, 2};
    
    // * testcase 2
    // vector<int> nums = {3, 1, 3, 4, 2};

    // * testcase 3
    vector<int> nums = {3, 3, 3, 3, 3};

    cout << "Nums: ";
    printArr(nums);

    int ans = findDuplicate(nums);
    cout << "Duplicate: " << ans << endl;

    return 0;
}
 
// * Run the code
// * g++ --std=c++20 34-find-the-duplicate-number.cpp -o output && ./output
