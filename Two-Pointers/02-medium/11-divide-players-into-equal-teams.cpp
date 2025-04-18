/*
 * Leetcode - 2491
 * Divide Players Into Teams of Equal Skill
 * 
 * You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. 
 * Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
 * 
 * The chemistry of a team is equal to the product of the skills of the players on that team.
 * 
 * Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into
 * teams such that the total skill of each team is equal.

 * Example 1:
 * Input: skill = [3,2,5,1,3,4]
 * Output: 22
 * Explanation: Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
 * The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.

 * Example 2:
 * Input: skill = [3,4]
 * Output: 12
 * Explanation: The two players form a team with a total skill of 7.
 * The chemistry of the team is 3 * 4 = 12.

 * Example 2:
 * Input: skill = [1,1,2,3]
 * Output: -1
 * Explanation: There is no way to divide the players into teams such that the total skill of each team is equal.
 * 
 * https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

// * Classic Two Pointers Approach
long long dividePlayers(std::vector<int>& skill) {
  int n = skill.size();
  std::sort(skill.begin(), skill.end());
  long long ans = 0;
  int i = 0, j = n - 1;
  long long chemistry = skill[i] + skill[j];
  while (i < j) {
    if((skill[i] + skill[j]) != chemistry) {
      return -1;
    }
    ans = ans + (long long)(skill[i] * skill[j]);
    i += 1;
    j -= 1;
  }
  return ans;
}

int main() {
  // std::vector<int> skill = {3, 4};
  std::vector<int> skill = {1, 1, 2, 3};
  // std::vector<int> skill = {3, 2, 5, 1, 3, 4};
  printArr(skill);
  long long ans = dividePlayers(skill);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-divide-players-into-equal-teams.cpp -o output && ./output