/**
 * * Leetcode - 455
 * * Maximum Matching of Players With Trainers
 * * You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. 
 * * You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the
 * * jth trainer.

 * * The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's 
 * * training capacity. Additionally, the ith player can be matched with at most one trainer, 
 * * and the jth trainer can be matched with at most one player.
 * 
 * * Return the maximum number of matchings between players and trainers that satisfy these conditions.

 * * Example 1
 * * Input  : players = [4, 7, 9], trainers = [8, 2, 5, 8]
 * * Output : 2
 * 
 * * Example 2
 * * Input  : players = [1, 1, 1], trainers = [10]
 * * Output : 1

 * * https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/
*/

#include <vector>
#include <iostream>
#include <algorithm>

// ! Note: This question is the same as 445: Assign Cookies.

// * ------------------------- Optimal APPROACH -------------------------`
// * TIME COMPLEXITY O(nlogn + mlogm)
// * SPACE COMPLEXITY O(1)
int matchPlayersAndTrainers(std::vector<int> &players, std::vector<int> &trainers) {
	std::sort(players.begin(), players.end());
	std::sort(trainers.begin(), trainers.end());

	int i = 0, j = 0;
	while (i < players.size() && j < trainers.size()) {
		if (trainers[j] >= players[i]) {
			i++;
		}
		j++;
	}

	return i;
}

int main(void) {
  // * testcase 1
  std::vector<int> players = {4, 7, 9};
  std::vector<int> trainers = {8, 2, 5, 8};
  
  // * testcase 2
  // std::vector<int> players = {1, 1, 1};
  // std::vector<int> trainers = {10};

  int ans = matchPlayersAndTrainers(players, trainers);
  std::cout << ans << std::endl;

  return 0;
}