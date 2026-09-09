/*
 * Leetcode - 2398
 * Maximum Number of Robots Within Budget
 * 
 * 
 * Example 1    :
 * Input        : chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
 * Output       : 25
 * Explanation  : Valid Subarray [3, 6, 1] costs: 6 + 3 * (2 + 1 + 3) = 6 + 18 = 24 <= 25 (Size 3)
 * 
 * Example 2    :
 * Input        : chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
 * Output       : 0
 * Explanation  : No robot can be run that does not exceed the budget, so we return 0.
 * 
 * Example 3    :
 * Input        : chargeTimes = [4, 4, 4], runningCosts = [1, 2, 3], budget = 1000
 * Output       : 3
 * Explanation  : Valid Subarray [4, 4, 4] costs: 4 + 3 * (1 + 2 + 3) = 4 + 18 = 22 <= 1000 (Size 3)
 *
 * https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/?envType=problem-list-v2&envId=atv0wu4v
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

// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
	int n = chargeTimes.size();

	// * Deque stores indices of chargeTimes to find the maximum in the current window.
	// * It is kept monotonically decreasing so that the maximum value index is always at the front.
	deque<int> dq;

	int i = 0, j = 0, ans = 0;
	long long curSum = 0; // * Tracks the sum of running costs inside the current window

	while (j < n) {
		// * Expand the window by adding the current robot's running cost
		curSum += runningCosts[j];

		// * Maintain the monotonically decreasing order in the deque.
		// * Remove elements from the back that are smaller than or equal to the new charge time,
		// * because they can never be the maximum in this or any future window containing index j.
		while (!dq.empty() && chargeTimes[j] > chargeTimes[dq.back()]) {
				dq.pop_back();
		}
		dq.push_back(j); // * Add the current index to the deque

		// * If the left boundary 'i' has moved past the index stored at the front of the deque,
		// * that index is no longer part of our window, so remove it.
		if (i > dq.front())
			dq.pop_front();

		// * Calculate the total cost for the current window of consecutive robots:
		// * Max Charge Time + (Number of Robots * Sum of Running Costs)
		long long curCost = chargeTimes[dq.front()] + ((j - i + 1) * curSum);

		// * If the cost exceeds the budget, shrink the window from the left
		if (curCost > budget) {
			curSum -= runningCosts[i]; // * Subtract the left-most robot's cost from our sum
			i++;                       // * Move the left pointer forward
		}
		else {
			ans = max(ans, (j - i + 1));
		}

		j++; // * move to next robot
	}

	return ans;
}

int main(void) {
	// * testcase 1
	// int budget = 25;
	// vector<int> chargeTimes = {3, 6, 1, 3, 4}, runningCosts = {2, 1, 3, 4, 5};

	// * testcase 2
	int budget = 19;
	vector<int> chargeTimes = {11, 12, 19}, runningCosts = {10, 8, 7};

	// * testcase 3
	// int budget = 1000;
	// vector<int> chargeTimes = {4, 4, 4}, runningCosts = {1, 2, 3};

	cout << "chargeTimes";
	printArr(chargeTimes);
	cout << "runningCosts";
	printArr(runningCosts);
	cout << "Budget: " << budget << endl;

	int ans = maximumRobots(chargeTimes, runningCosts, budget);
	cout << "Maximum Number of Robots Within Budget: " << ans << endl;

	return 0;
}
 
// * Run the code
// * g++ --std=c++20 07-maximum-number-of-robots-within-budget.cpp -o output && ./output
