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
// * Make pairs of smallest & largest numbers
long long dividePlayers(std::vector<int>& skill) {
  // * sort the array
  std::sort(skill.begin(), skill.end());
  
  int n = skill.size();
  int i = 0, j = n - 1;
  
  // * all pairs should have following chemistry
  long long chemistry = skill[i] + skill[j];
  
  long long ans = 0;
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

long long dividePlayers2(std::vector<int>& skill) {
  int n = skill.size();
  std::sort(skill.begin(), skill.end());

  long long total_sum = 0;

  // * count the frequency of array elements
  std::vector<int> freq_vec(1000, 0);
  for (int x : skill) {
    freq_vec[x]++;
    total_sum += x;
  }

  // * Sum per pair
  long long sum = total_sum / (n / 2); 

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    // * get the required sum needed for pair
    int required = sum - skill[i];
    if (freq_vec[required] <= 0)
      return -1;

    ans += (skill[i] * required);
  }

  // * This is because we also add duplicate pairs while we traverse the whole array
  return ans / 2;
}

int main() {
  // * testcase 1
  // std::vector<int> skill = {3, 4};

  // * testcase 2
  // std::vector<int> skill = {1, 1, 2, 3};

  // * testcase 3
  std::vector<int> skill = {3, 2, 5, 1, 3, 4};

  printArr(skill);

  // long long ans = dividePlayers(skill);
  long long ans = dividePlayers2(skill);
  std::cout << ans << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++20 11-divide-players-into-equal-teams.cpp -o output && ./output