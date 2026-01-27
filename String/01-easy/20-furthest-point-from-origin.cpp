/*
 * Leetcode - 2833
 * Furthest Point From Origin
 * 
 * You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. 
 * The string represents your movement on a number line starting from the origin 0.
 * 
 * In the ith move, you can choose one of the following directions:
 * 
 * - move to the left if moves[i] = 'L' or moves[i] = '_'
 * - move to the right if moves[i] = 'R' or moves[i] = '_'
 * 
 * Return the distance from the origin of the furthest point you can get to after n moves.

 * Example 1
 * Input  : moves = "L_RL__R"
 * Output : 3
 * 
 * Example 2
 * Input  : moves = "_R__LL_"
 * Output : 5
 * 
 * Example 3
 * Input  : moves = "_______"
 * Output : 7

 * https://leetcode.com/problems/furthest-point-from-origin/description/
*/

#include <iostream>

int furthestDistanceFromOrigin(std::string moves) {
  int cur = 0, d = 0;
  for (auto &m : moves) {
    if (m == 'L') {
      cur -= 1;
    }
    else if (m == 'R') {
      cur += 1;
    }
    else {
      d += 1;
    }
  }
  return abs(cur) + d;
}


int main(void) {
  // * testcase 1
  std::string moves = "L_RL__R";

  // * testcase 2
  // std::string moves = "_R__LL_";

  // * testcase 3
  // std::string moves = "_______";

  int ans = furthestDistanceFromOrigin(moves);
  std::cout << "Ans: " << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 20-furthest-point-from-origin.cpp -o output && ./output