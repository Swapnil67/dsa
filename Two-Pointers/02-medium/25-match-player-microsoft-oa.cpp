/*
 * Leetcode - ?
 * Array Reversal Game
 * 
 * P1 and P2 are playing a turn-based game with an array of positive integers called nums. 
 * P1 always takes the first turn.
 * 
 * During a player's turn, they perform the following actions in order:
 * 1. Select & Remove: They take the first element of the current array and remove it.
 * 2. Score: They add the value of this removed element to their total score.
 * 3. Check & Reverse: If the removed element is even, the remaining elements in the 
 *    array are completely reversed before the next player's turn. If it is odd, 
 *    the array remains as it is.
 * 
 * The game ends when the array becomes empty. Both players play optimally to maximize 
 * their own final score. 
 * 
 * Return the final score of P1 minus the final score of P2 if both players play optimally.
 * 
 * Constraints:
 * - 1 <= nums.length <= 1000
 * - 1 <= nums[i] <= 10^5
 * 
 * Example 1    :
 * Input        : nums = [3, 4, 2]
 * Output       : 1
 * Explanation  : 
 * - Turn 1 (P1): Removes 3 (odd). P1 score = 3. Array left:.
 * - Turn 2 (P2): Removes 4 (even). P2 score = 4. Array left:. Reversed ->.
 * - Turn 3 (P1): Removes 2 (even). P1 score = 5. Array left: [].
 * Difference: 5 - 4 = 1.
 * 
 * Example 2    :
 * Input        : nums = [2, 4, 1, 3]
 * Output       : -4
 * Explanation  : 
 * - Turn 1 (P1): Removes 2 (even). P1 score = 2. Array left:. Reversed ->.
 * - Turn 2 (P2): Removes 3 (odd). P2 score = 3. Array left:.
 * - Turn 3 (P1): Removes 1 (odd). P1 score = 3. Array left:.
 * - Turn 4 (P2): Removes 4 (even). P2 score = 7. Array left: [].
 * Difference: 3 - 7 = -4.
 *
*/

// ! OA
// ! Microsoft


#include <set>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printArr(vector<T> &arr)
{
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
// * Simulation
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> &nums) {
  int n = nums.size();
  int p1 = 0, p2 = 0;
  bool p1_move = true;
  while (!nums.empty()) {
    int val = nums[0];
    if (p1_move) { // * P1 move
      p1 += val;
    } else { // * P2 move
      p2 += val;
    }
    nums.erase(nums.begin()); // * Remove the first element
    // * if removed element is even then reverse the array
    if (val % 2 == 0) {
      reverse(begin(nums), end(nums));
    }
    // printArr(nums); // * To debug
    p1_move = !p1_move;
  }
  return p1 - p2;
}



// * ------------------------- APPROACH 2: OPTIMAL APPROACH -------------------------
// * Simulate the feeling of reversal using reversed variable
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int matchPlayer(vector<int> &nums) {
  int p1 = 0, p2 = 0;
  bool p1_move = true;
  int left = 0, right = nums.size() - 1;
  bool reversed = false; // * Tracks if the array is virtually reversed

  while (left <= right) {
    // * If reversed, the "first" element is actually at the right pointer
    int val = (!reversed) ? nums[left++] : nums[right--];

    if (p1_move) { // * P1 move
      p1 += val;
    } else { // * P2 move
      p2 += val;
    }

    // * Reversing flips the virtual reading direction
    if (val % 2 == 0) { 
      reversed = !reversed; // * For next turn
    }
    p1_move = !p1_move;
  }
  return p1 - p2;
}


int main() {
	// * testcase 1
  // vector<int> nums = {3, 4, 2};

  // * testcase 2
	vector<int> nums = {2, 4, 1, 3};

	cout << "Array: ";
	printArr(nums);

  int ans = bruteForce(nums);
  cout << "Answer: " << ans << endl;
}



// * Run the code
// * g++ --std=c++20 04-match-player-microsoft-oa.cpp -o output && ./output
