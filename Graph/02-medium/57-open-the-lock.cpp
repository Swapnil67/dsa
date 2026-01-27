/*
 * Leetcode - 752
 * Open the Lock 
 * 
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10 
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
 * The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
 * Each move consists of turning one wheel one slot.
 * 
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 * 
 * You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
 * the wheels of the lock will stop turning and you will be unable to open it.
 * 
 * Given a target representing the value of the wheels that will unlock the lock, 
 * return the minimum total number of turns required to open the lock, or -1 if it is impossible.
 * 
 * Example 1:
 * Input       : deadends = ["0201","0101","0102","1212","2002"], target = "0202"  
 * Output      : 6 
 * Explanation : Sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
 * 
 * Example 2:
 * Input       : deadends = ["8888"], target = "0009"
 * Output      : 1
 * Explanation : We can turn the last wheel in reverse to move from "0000" -> "0009".
 * 
 * Example 3:
 * Input       : deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
 * Output      : -1
 * Explanation : We cannot reach the target without getting stuck.
 * 
 * https://leetcode.com/problems/open-the-lock/description/
*/

// ! Meta, Uber

#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

template <typename T>
void printArr(std::vector<T> &arr) {
  int n = arr.size();
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i];
    if (i != n - 1)
      std::cout << ", ";
  }
  std::cout << " ]" << std::endl;
}

// * ------------------------- APPROACH: Optimal Approach -------------------------
// * n = no. of slots (We have 10)
// * w = no. of wheels (we have 4)
// * TIME COMPLEXITY O(n^w)
// * SPACE COMPLEXITY O(n^w)
int openLock(std::vector<std::string> &deadends, std::string target) {
  // * For checking deadends
  std::unordered_set<std::string> dead_st(begin(deadends), end(deadends));

  // * Edge case
  std::string start = "0000";
  if (dead_st.count(start))
    return -1;

  std::queue<std::string> q;
  q.push(start);

  int level = 0;
  while (!q.empty()) {
    int n = q.size();

    while (n--) {
      std::string s = q.front();
      q.pop();
 
      if (s == target) // * Reached target
        return level;

      // * Change all 4 wheels on lock 
      for (int i = 0; i < 4; ++i) {
        char ch = s[i];
        char dec = ch == '0' ? '9' : ch - 1;
        char inc = ch == '9' ? '0' : ch + 1;

        // * decr the cur wheel in lock and check
        s[i] = dec;
        if (!dead_st.count(s)) {
          dead_st.insert(s);
          q.push(s);
        }
        
        // * incr the cur wheel in lock and check
        s[i] = inc;
        if (!dead_st.count(s)) {
          dead_st.insert(s);
          q.push(s);
        }

        s[i] = ch;
      }
    }
    level += 1;
  }

  return -1;
}

int main(void) {
  std::string target = "0202";
  std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};

  std::cout << "Target: " << target << std::endl;
  std::cout << "Deadends: ";
  printArr(deadends);

  int ans = openLock(deadends, target);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}
 
// * Run the code
// * g++ --std=c++20 57-open-the-lock.cpp -o output && ./output


/*
* Similar Question :     1. Word Ladder (Leetcode) 
*                        2. Gene Mutation (Leetcode)
*                        3. Sequential Digits (Leetcode)
*                        4. Print all Jumping Numbers smaller than or equal to a given value (GFG)
*/

