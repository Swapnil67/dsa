/**
 * * Leetcode - 904
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
 * * Example 4
 * * Input  : fruits = [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]
 * * Output : 5
 * * Explanation: Do Dry Run
 * 
 * * https://leetcode.com/problems/fruit-into-baskets/description/
 * * https://www.naukri.com/code360/problems/fruits-and-baskets_985356
*/

#include <vector>
#include <iostream>
#include <unordered_map>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}


// * ------------------------- APPROACH 1: Brute Force -------------------------`
// * Keep two fruits variable f1 & f2
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int bruteForce(std::vector<int> fruits) {
  int n = fruits.size();

  int max_fruits = 0;
  for (int i = 0; i < n; ++i) {
    int f1 = -1, f2 = -1;
    int j = i;
    for (; j < n; ++j) {
      if (f1 == -1) {
        f1 = fruits[j];
      }
      else if (f2 == -1) {
        f2 = fruits[j];
      }
      else if (f1 != fruits[j] && f2 != fruits[j]) {
        break;
      }
    }
    max_fruits = std::max(max_fruits, j - i);
  }

  return max_fruits;
}

// * ------------------------- APPROACH 2: Better Approach -------------------------`
// * Classic Sliding Window
// * keep fruits map and keep the map size to 2
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int betterApproach(std::vector<int> fruits) {
  int n = fruits.size();
  int i = 0, j = 0;
  int fruitsCollected = 0;
  std::unordered_map<int, int> fruitsFreq;

  while(j < n) {
    fruitsFreq[fruits[j]]++;
    
    // * Shrink window from left
    // * When we encounter more than two fruits
    while(fruitsFreq.size() > 2) {
      fruitsFreq[fruits[i]]--;
      if(fruitsFreq[fruits[i]] == 0) {
        fruitsFreq.erase(fruits[i]);
      }
      i++;
    }

    // * When we have two unique fruits
    if(fruitsFreq.size() <= 2) {
      fruitsCollected = std::max(fruitsCollected, j - i + 1);
    }

    j++;
  }
  return fruitsCollected;
}


// * ------------------------- APPROACH 3: Optimal Approach -------------------------`
// * Classic Sliding Window
// * keep frequency map for fruits
// * Only collect fruits if the frequency < 'k'
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
int totalFruit(std::vector<int> fruits) {
  int n = fruits.size();
  int i = 0, j = 0;
  int fruitsCollected = 0;
  std::unordered_map<int, int> fruitsFreq;
  while(j < n) {
    fruitsFreq[fruits[j]]++;

    // * Shrink window from left
    // * When we encounter more than two fruits
    if (fruitsFreq.size() > 2) {
      fruitsFreq[fruits[i]]--;
      if (fruitsFreq[fruits[i]] == 0) {
        fruitsFreq.erase(fruits[i]);
      }
      i++;
    }
    else {
      fruitsCollected = std::max(fruitsCollected, j - i + 1);
    }
    j++;
  }

  return fruitsCollected;
}
int main() {
  // * testcase 1
  std::vector<int> fruits = {1, 2, 3, 2, 2};

  // * testcase 2
  // std::vector<int> fruits = {0, 1, 2, 2};

  // * testcase 2
  // std::vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

  printArr(fruits);
  
  // int ans = bruteForce(fruits);
  // int ans = betterApproach(fruits);
  int ans = totalFruit(fruits);
  std::cout << "Fruits into baskets: " << ans << std::endl;
  return 0;
}


// * Run the code
// * g++ --std=c++17 05-fruits-into-basket.cpp -o output && ./output