/*
 * Leetcode - 
 * Count Subarrays with given XOR
 * 
 * 
 * Example 1    :
 * Input        : nums = [4, 2, 2, 6, 4], target = 6
 * Output       : 4
 * Explanation  : The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
 * 
 * Example 2    :
 * Input        : nums = [5, 6, 7, 8, 9], k = 5
 * Output       : 2
 * Explanation  : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
 *
 * Example 3    :
 * Input        : nums = [1, 1, 1, 1], k = 0
 * Output       : 4
 * Explanation  : The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
 * 
 * https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1 
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

// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(N)


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums, int k) {
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int xr = 0;
		for (int j = i; j < n; ++j) {
			xr = xr ^ nums[j];
			if (xr == k)
				count += 1;
		}
	}

	return count;
}

// ! Intuition
// * let 'p' be the prefix XOR array
// * if   XOR(i...j) = k
// * then XOR(i...j) = p[j] ^ p[i - 1]
// * then k = p[j] ^ p[i - 1]
// * p[i - 1] = p[j] ^ k

// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * Use prefix xor array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
int betterApproach(vector<int> &nums, int k) {
	int n = nums.size();
	vector<int> prefixXor(n, 0);
	
	// * Step 1: Build the classic Prefix XOR array
	prefixXor[0] = nums[0];
	for (int i = 1; i < n; ++i)
		prefixXor[i] = prefixXor[i - 1] ^ nums[i];

	// cout << "Prefix XOR array: ";
	// printArr(prefixXor);

	int count = 0;
	unordered_map<int, int> xorMp;
	
	// * Base Case / Critical Edge Case:
	// * A prefix before index 0 has a cumulative XOR sum of 0.
	// * This ensures subarrays starting at index 0 (where i-1 = -1) are counted correctly.
	xorMp[0] = 1;
	
	// * Step 2: Iterate through the array using 'j' as the ending boundary
	for (int j = 0; j < n; ++j) {
		// * Based on our proof: p[i-1] = p[j] ^ k
		// * 'check' is the exact target prefix value we need to find to our left
		int check = prefixXor[j] ^ k;
		
		// * If 'check' exists in our map, it means we found valid starting points 'i'
		// * We add the number of times this required prefix has appeared so far
		if (xorMp.count(check)) 
			count += xorMp[check];
			
		// * Store the current prefix p[j] in the map for future iterations
		xorMp[prefixXor[j]]++;
	}

	return count;
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------
// * Use running prefix
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int subarrayXor(vector<int> &nums, int k) {
	int n = nums.size();
	int prefixXOR = 0, count = 0;
	unordered_map<int, int> xorMp;
	
	// * Base Case: A prefix before index 0 has a cumulative XOR sum of 0.
	// * This captures subarrays starting at index 0 that evaluate perfectly to 'k'.
	xorMp[0] = 1;
	
	for (int j = 0; j < n; ++j) {
		// * Update the running prefix XOR sum on the fly (representing p[j])
		prefixXOR = prefixXOR ^ nums[j];
		
		// * Use your math proof: p[i-1] = p[j] ^ k
		// * 'check' holds the value of the historical prefix needed to make the subarray evaluate to 'k'
		int check = prefixXOR ^ k;
		
		// * If 'check' exists in our map, we add its frequency to the total count
		if (xorMp.count(check)) 
			count += xorMp[check];
			
		// * Store the current prefix XOR in the map for future iterations
		xorMp[prefixXOR]++;
	}

	return count;
}


int main(void) {
	// * testcase 1
	// int k = 6;
	// vector<int> nums = {4, 2, 2, 6, 4};

	// * testcase 2
	// int k = 5;
	// vector<int> nums = {5, 6, 7, 8, 9};

	// * testcase 3
	int k = 0;
	vector<int> nums = {1, 1, 1, 1};

	cout << "k: " << k << endl;
	cout << "Array: ";
	printArr(nums);

	// int ans = bruteForce(nums, k);
	// int ans = betterApproach(nums, k);
	int ans = subarrayXor(nums, k);
	cout << "Number Subarrays with given XOR: " << ans << endl;

  return 0;
}

// * Run the code
// * g++ --std=c++20 01-count-subarray-with-given-xor.cpp -o output && ./output
