/*
 * Minimum no of days to make m bouquets

 * You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith'
 * rose will bloom on the 'arr[i]th' day.
 * You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k'
 * adjacent bloomed roses to make a single bouquet.
 * 
 * Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses.
 * Return -1 if it is not possible.

* https://www.naukri.com/code360/problems/rose-garden_2248080
* https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
*/

#include<iostream>

std::vector<int> findMinMax(std::vector<int> arr)
{
  int min_val = INT_MAX, max_val = INT_MIN;
  std::vector<int> min_max_vector;
  for (int i = 0; i < arr.size(); i++) {
    min_val = std::min(min_val, arr[i]);
    max_val = std::max(max_val, arr[i]);
  }

  min_max_vector = {min_val, max_val};
  return min_max_vector;
}

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

bool findIsPossibleDay(std::vector<int> days, int roses, int bouquetsRequired, int day) {
  int cnt = 0, totalBouquets = 0;
  for (int i = 0; i < days.size(); i++) {
    if(days[i] <= day) {
      cnt++;
    }
    else {
      totalBouquets = totalBouquets + (cnt/roses);
      cnt = 0;
    }
  } 
  totalBouquets = totalBouquets + (cnt/roses);
  std::cout << "Days " << day << " no of Bouquets " << totalBouquets << std::endl;
  if(totalBouquets >= bouquetsRequired) return true;
  return false;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
int bruteForce(std::vector<int> days, int roses, int bouquets) {
  if (days.size() < roses * bouquets)
    return -1;

  std::vector<int> initialVal = findMinMax(days);
  int start = initialVal[0];
  int end = initialVal[1];
  for (int i = start; i <= end; i++) {
    bool isPossible = findIsPossibleDay(days, roses, bouquets, i);
    if(isPossible) return i;
  }
  return -1;
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------
int findMinimumDaysToMakeBouquets(std::vector<int> days, int roses, int bouquets) {
  if (days.size() < roses * bouquets)
    return -1;

  std::vector<int> intitialVal = findMinMax(days);
  int l = intitialVal[0], r = intitialVal[1];
  int ans = -1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    // std::cout << "Days " << m << std::endl;
    bool isPossible = findIsPossibleDay(days, roses, bouquets, m);
    std::cout << "isPossible " << isPossible << std::endl;
    if(isPossible) {
      // return m;
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

int main() {
  // * testcase 1
  // std::vector<int> bloomDays = {1, 2, 1, 2, 7, 2, 2, 3, 1};
  // int flowersInAbouquet = 3, bouquetsRequired = 2;

  // * testcase 2
  std::vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
  int bouquetsRequired = 2, flowersInAbouquet = 3;

  // * testcase 3
  // std::vector<int> bloomDays = {1, 10, 3, 10, 2};
  // int bouquetsRequired = 3, flowersInAbouquet = 1;

  // * testcase 4
  // std::vector<int> bloomDays = {1, 1, 1, 1};
  // int bouquetsRequired = 1, flowersInAbouquet = 1;

  printArr(bloomDays);
  // int minDays = bruteForce(days, k, m);
  int minDays = findMinimumDaysToMakeBouquets(bloomDays, flowersInAbouquet, bouquetsRequired);
  std::cout << "Minimum days required to make " << bouquetsRequired << " bouquets containing " << flowersInAbouquet << " roses each is " << minDays << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 02-rose-garden.cpp -o 02-rose-garden && ./02-rose-garden