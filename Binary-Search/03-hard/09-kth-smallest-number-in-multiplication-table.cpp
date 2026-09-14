/*
 * Leetcode - 668
 * Kth Smallest Number in Multiplication Table
 * 
 * Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an 
 * integer matrix mat where mat[i][j] == i * j (1-indexed).
 * 
 * Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
 * 
 * Example 1    :
 * Input        : m = 3, n = 3, k = 5
 * Output       : 3
 * Explanation  : The 5th smallest number is 3. -> [1,2,2,3,3,4,6,6,9]
 * 
 * Example 2    :
 * Input        : m = 2, n = 3, k = 6
 * Output       : 6
 * Explanation  : The 6th smallest number is 6. -> [1,2,2,3,4,6]
 * 
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
*/

// ! BS on Answers

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

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(n * m + log(n * m))
// * SPACE COMPLEXITY O(n * m)
int bruteForce(int m, int n, int k) {
    vector<int> table;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            table.push_back(i * j);
        }
    }
    sort(begin(table), end(table));
    return table[k - 1];
}

// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * TIME COMPLEXITY O(k(logk))
// * SPACE COMPLEXITY O(k)
int betterApproach(int m, int n, int k) {
    priority_queue<int> pq;
    for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				pq.push(i * j);
				if (pq.size() > k)
					pq.pop();
			}
    }
    return pq.top();
}

/**
 * Helper function to check if a given value (maxProduct) is large enough
 * to be the k-th smallest number in the m x n multiplication table.
 * 
 * It does this by counting how many elements in the table are <= maxProduct.
 */
bool isValid(int m, int n, int k, int maxProduct) {
	int pairs = 0; // * Cumulative count of numbers that are <= maxProduct

	// * Iterate through each row of the multiplication table (1-indexed)
	for (int i = 1; i <= m; ++i) {
		// * In row i, elements are: i*1, i*2, i*3, ..., i*n.
		// * We want to find how many column indices 'j' satisfy: i * j <= maxProduct.
		// * Solving for j: j <= maxProduct / i.
		// * Since there are only 'n' columns in a row, the count cannot exceed 'n'.
		pairs += std::min(maxProduct / i, n);
	}

	// * If the total count of numbers <= maxProduct is at least k,
	// * then the true k-th smallest number must be <= maxProduct.
	return pairs >= k;
}

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
//  * Finds the k-th smallest number in an m x n multiplication table using Binary Search.
//  * Time Complexity: O(m * log(m * n))
//  * Space Complexity: O(1)
int findKthNumber(int m, int n, int k) {
	// * Define the binary search search space.
	// * The smallest possible value in the table is 1 (1 * 1)
	// * The largest possible value in the table is m * n
	int l = 1;
	int r = m * n;
	int ans = 0; // * Tracks the best valid candidate found so far

	// * Binary search to isolate the exact boundary
	while (l <= r) {
		// * Calculate mid-point safely to avoid potential integer overflow
		int mid = l + (r - l) / 2;

		// * Check if there are at least 'k' numbers in the table <= mid
		if (isValid(m, n, k, mid)) {
			ans = mid;	 // * 'mid' is a valid candidate for the k-th smallest number
			r = mid - 1; // * Try to find a smaller valid number on the left side
		}
		else {
			l = mid + 1; // * 'mid' is too small (fewer than k numbers are <= mid), look right
		}
	}

	// * The binary search guarantees that the final 'ans' will converge to
	// * a value that actually exists inside the multiplication table.
	return ans;
}

int main(void) {
	// * testcase 1
	// int m = 3, n = 3, k = 5;

	// * testcase 1
	int m = 2, n = 3, k = 6;

	int ans = findKthNumber(m, n, k);
	cout << "Kth Smallest Number in Multiplication Table: " << ans << endl;

  return 0;
}
 
// * Run the code
// * g++ --std=c++20 09-kth-smallest-number-in-multiplication-table.cpp -o output && ./output


/*
* ================================================================================
* DRY RUN: findKthNumber(m = 2, n = 3, k = 4)
* ================================================================================
* 
* The Multiplication Table Visualised:
* Row 1:  1  2  3
* Row 2:  2  4  6
* Sorted elements: [1, 2, 2, 3, 4, 6] -> Expected 4th smallest element (k=4) is 3.
* 
* --------------------------------------------------------------------------------
* INITIAL STATE:
* --------------------------------------------------------------------------------
* l = 1
* r = m * n = 2 * 3 = 6
* ans = 0
* 
* --------------------------------------------------------------------------------
* ITERATION 1:
* --------------------------------------------------------------------------------
* 1. Calculate mid:
*    mid = 1 + (6 - 1) / 2 = 3
* 
* 2. Execute isValid(m=2, n=3, k=4, maxProduct=3):
*    - Row 1 (i = 1): min(3 / 1, 3) = min(3, 3) -> 3 elements (1, 2, 3)
*    - Row 2 (i = 2): min(3 / 2, 3) = min(1, 3) -> 1 element  (2)
*    - Total pairs = 3 + 1 = 4
*    - Check condition: pairs >= k -> 4 >= 4 is TRUE
* 
* 3. Update Pointers (isValid returned TRUE):
*    - ans = mid = 3
*    - r = mid - 1 = 3 - 1 = 2
* 
* State at end of Iteration 1: [l = 1, r = 2, ans = 3]
* 
* --------------------------------------------------------------------------------
* ITERATION 2:
* --------------------------------------------------------------------------------
* 1. Calculate mid:
*    mid = 1 + (2 - 1) / 2 = 1
* 
* 2. Execute isValid(m=2, n=3, k=4, maxProduct=1):
*    - Row 1 (i = 1): min(1 / 1, 3) = min(1, 3) -> 1 element (1)
*    - Row 2 (i = 2): min(1 / 2, 3) = min(0, 3) -> 0 elements
*    - Total pairs = 1 + 0 = 1
*    - Check condition: pairs >= k -> 1 >= 4 is FALSE
* 
* 3. Update Pointers (isValid returned FALSE):
*    - l = mid + 1 = 1 + 1 = 2
* 
* State at end of Iteration 2: [l = 2, r = 2, ans = 3]
* 
* --------------------------------------------------------------------------------
* ITERATION 3:
* --------------------------------------------------------------------------------
* 1. Calculate mid:
*    mid = 2 + (2 - 2) / 2 = 2
* 
* 2. Execute isValid(m=2, n=3, k=4, maxProduct=2):
*    - Row 1 (i = 1): min(2 / 1, 3) = min(2, 3) -> 2 elements (1, 2)
*    - Row 2 (i = 2): min(2 / 2, 3) = min(1, 3) -> 1 element  (2)
*    - Total pairs = 2 + 1 = 3
*    - Check condition: pairs >= k -> 3 >= 4 is FALSE
* 
* 3. Update Pointers (isValid returned FALSE):
*    - l = mid + 1 = 2 + 1 = 3
* 
* State at end of Iteration 3: [l = 3, r = 2, ans = 3]
* 
* --------------------------------------------------------------------------------
* TERMINATION:
* --------------------------------------------------------------------------------
* The loop condition (l <= r) breaks because l (3) is now greater than r (2).
* 
* Final Returned Answer: ans = 3
* ================================================================================
*/