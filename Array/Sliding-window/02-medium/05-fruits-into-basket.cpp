/**
 * * Fruit Into Baskets
 * 
 * * Example 1
 * * Input  : fruits = [1,2,1]
 * * Output : 3
 * * Explanation: We can pick from all 3 trees.
 * 
 * * Example 2
 * * Input  : fruits = [0,1,2,2]
 * * Output : 3
 * * Explanation: We can pick from trees [1,2,2].
 * * If we had started at the first tree, we would only pick from trees [0,1].
 * 
 * * Example 3
 * * Input  : fruits = [1,2,3,2,2]
 * * Output : 4
 * * Explanation: We can pick from trees [2,3,2,2].
 * * If we had started at the first tree, we would only pick from trees [1,2].
 * 
 * * https://leetcode.com/problems/max-consecutive-ones-iii/description/
*/


#include<set>
#include<map>
#include<vector>
#include<iostream>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Check all k size windows with k zeros
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> fruits) {
  int n = fruits.size();
  int fruits_collected = 0;
  for (int i = 0; i < n; ++i) {
    int basket = 0;
    std::set<int> st;
    for (int j = i; j < n; ++j) {
      st.insert(fruits[j]);
      if(st.size() <= 2) {
        basket++;
      }
      else {
        break;
      }
    }
    fruits_collected = std::max(fruits_collected, basket);
  }
  return fruits_collected;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * keep fruits map and keep the map size to 2
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> fruits) {
  int n = fruits.size();
  int i = 0, j = 0;
  int fruits_collected = 0;
  std::map<int, int> freq_map;

  while(j < n) {
    freq_map[fruits[j]]++;

    // * When we encounter more than two fruits
    if (freq_map.size() > 2) {
      while(freq_map.size() > 2) {
        freq_map[fruits[i]]--;
        if(freq_map[fruits[i]] == 0) {
          freq_map.erase(fruits[i]);
        }
        i++;
      }
    }

    // * When we have two unique fruits
    if(freq_map.size() <= 2) {
      fruits_collected = std::max(fruits_collected, j - i + 1);
    }

    j++;
  }
  return fruits_collected;
}


// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * keep frequency map for fruits
// * Only collect fruits if the frequency map size is less than k
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int totalFruit(std::vector<int> fruits) {
  int n = fruits.size();
  int i = 0, j = 0;
  int fruits_collected = 0;
  std::map<int, int> freq_map;
  while(j < n) {
    freq_map[fruits[j]]++;

    if (freq_map.size() > 2) {
      freq_map[fruits[i]]--;
      if (freq_map[fruits[i]] == 0) {
        freq_map.erase(fruits[i]);
      }
      i++;
    }
    else {
      fruits_collected = std::max(fruits_collected, j - i + 1);
    }
    j++;
  }

  return fruits_collected;
}
int main() {

  // * testcase 1
  // std::vector<int> fruits = {1, 2, 3, 2, 2};
  // * testcase 2
  // std::vector<int> fruits = {0, 1, 2, 2};
  // * testcase 2
  std::vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

  printArr(fruits);
  
  // int ans = bruteForce(fruits);
  // int ans = betterApproach(fruits);
  int ans = totalFruit(fruits);
  std::cout << "Fruits into baskets: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 05-fruits-into-basket.cpp -o output && ./output