#include<queue>
#include<iostream>
#include<numeric>

void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

int arraySum(std::vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
  }
  return sum;
}

std::pair<int, int> getMaxMinOfArray(std::vector<int> arr) {
  int mx = *std::max_element(arr.begin(), arr.end());
  int mn = *std::min_element(arr.begin(), arr.end());
  return {mx, mn};
}

// * ---------- Koko Eating Bananas ----------

int calcuateHrsToComplete(std::vector<int> piles, int bananas) {
  int hoursTook = 0;
  for (int i = 0; i < piles.size(); i++) {
    hoursTook += std::ceil((float)piles[i] / (float)bananas);
  }
  return hoursTook;
}

int findMinimumBananasToEat(std::vector<int> piles, int hr) {
  int n = piles.size();
  if(n == 0) return -1;

  int l = 0, r = *std::max_element(piles.begin(), piles.end());
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int hoursTook = calcuateHrsToComplete(piles, m);
    // std::cout << m << " hours took " << hoursTook << std::endl;
    if(hoursTook <= hr) {
      ans = m;
      r = m - 1;
    }
    if(hoursTook > hr) {
      l = m + 1;
    }
  }

  return ans;
}

// * ---------- Rose Garden ----------

int findBouquetsMade(std::vector<int> bloomDays, int flowers, int days) {
  int totalFlowers = 0, bouquets = 0;
  for (int i = 0; i < bloomDays.size(); i++) {  
    if(days >= bloomDays[i]) {
      totalFlowers++;
    }
    else {
      bouquets += (totalFlowers / flowers);
      totalFlowers = 0;
    }
  }
  bouquets += (totalFlowers / flowers);
  return bouquets;
}

int findMinimumDaysToMakeBouquets(std::vector<int> bloomDays, int flowers, int bouquets) {
  int n = bloomDays.size();
  std::pair<int, int> minMaxVal = getMaxMinOfArray(bloomDays);
  int l = minMaxVal.second, r = minMaxVal.first;
  std::cout << l << "  " << r << std::endl;
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int bouquetsMade = findBouquetsMade(bloomDays, flowers, m);
    // std::cout << m << " bouquets made " << bouquetsMade << std::endl;
    if(bouquetsMade >= bouquets) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ---------- Smallest Divisor ----------

bool isValidDivisor(std::vector<int> arr, int divisor, int limit) {
  int n = arr.size();
  int divisorSum = 0;
  for (int i = 0; i < n; i++) {
    divisorSum += std::ceil((float)arr[i] / (float)divisor);
  }
  return divisorSum <= limit;
}

int findSmallestDivisor(std::vector<int> arr, int limit) {
  int n = arr.size();
  int l = 0, r = *std::max_element(arr.begin(), arr.end());
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    bool isValid = isValidDivisor(arr, m, limit);
    if(isValid) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ----------- Capacity To Ship Packages Within D Days ----------

bool isValidWeight(std::vector<int> weights, int days, int maxWeight) {
  int n = weights.size();
  int daysTook = 1, curWeight = 0;
  for (int i = 0; i < n; i++) {
    if(curWeight + weights[i] > maxWeight)   {
      daysTook++;
      curWeight = weights[i];
    }
    else {
      curWeight += weights[i];
    }
  }
  return daysTook <= days;
}

int findLeastPossileWeight(std::vector<int> weights, int days) {
  int n = weights.size();
  int l = 0, r = std::accumulate(weights.begin(), weights.end(), 0);
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    bool isValid = isValidWeight(weights, days, m);
    // std::cout << m << " " << isValid << std::endl;
    if(isValid) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
}

// * ------------ Kth Missing Positive Number  ------------

// * ------------ Aggressive Cows  ------------

// * ------------ Allocate Books  ------------

// * ------------ Painter's Partition Problem  ------------

// * ------------ Minimize Max Distance to Gas Station  ------------

// * ------------ Median of Two Sorted Arrays  ------------

int main() {
  // * Problem 1 - Koko eating bananas 
  // std::cout << "Koko eating bananas" << std::endl;
  // int h = 2;
  // std::vector<int> piles = {1000000000};
  // std::vector<int> piles = {3, 6, 7, 11};
  // int h = 8;
  // std::cout << "Piles of bananas" << std::endl;
  // printArr(piles);
  // int minimumBananas = findMinimumBananasToEat(piles, h);
  // std::cout << "Koko need to eat " << minimumBananas << " bananas each hour to finish full pile in " << h << " hours." << std::endl;

  // * Problem 2 - Rose Garden
  // std::cout << "Rose Garden" << std::endl;
  // std::vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
  // int bouquetsRequired = 2, flowersInAbouquet = 3;
  // printArr(bloomDays);
  // int minDays = findMinimumDaysToMakeBouquets(bloomDays, flowersInAbouquet, bouquetsRequired);
  // std::cout << "Minimum days required to make " << bouquetsRequired << " bouquets containing " << flowersInAbouquet << " roses each is " << minDays << std::endl;

  // * Problem 3 - Smallest Divisor
  // std::cout << "Smallest Divisor" << std::endl;
  // int threshold = 8;
  // std::vector<int> arr = {1, 2, 3, 4, 5};
  // printArr(arr);
  // int smallestDivisor = findSmallestDivisor(arr, threshold);
  // std::cout << "The smallest divisor is " << smallestDivisor << std::endl;

  // * Problem 4 - Capacity To Ship Packages Within D Days
  std::cout << "Capacity To Ship Packages Within D Days" << std::endl;
  std::vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int days = 5;
  printArr(weights);
  int leastWeight = findLeastPossileWeight(weights, days);
  std::cout << "Ship should take atleast " << leastWeight << " weights to transfer all weights in " << days << " days." << std::endl;

  // * problem 5 - Kth Missing Positive Number
  // std::cout << "Kth Missing Positive Number " << std::endl;
  // int k = 5;
  // std::vector<int> arr = {2, 3, 4, 7, 11};
  // printArr(arr);
  // int missingNumber = findKthMissingNumber(arr, k);
  // std::cout << k << " missing number is " << missingNumber << std::endl;

  // * problem 6
  // std::cout << "Aggressive Cows" << std::endl;
  // int cows = 2;
  // std::vector<int> stalls = {4, 2, 1, 3, 6};
  // printArr(stalls);
  // int minMaxDistance = AggressiveCows(stalls, cows);
  // std::cout << "Min Max Distance b/w cows is " << minMaxDistance << std::endl;
  // return 0;

  // * problem 7
  // std::cout << "Allocate Books" << std::endl;
  // int s = 4; 
  // std::vector<int> books = {25, 46, 28, 49, 24};
  // printArr(books);
  // int maxPagesAssigned = findMaxPagesAssigned(books, s);
  // std::cout << "maximum number of pages assigned to a student " << maxPagesAssigned << std::endl;

  // * problem 8
  // std::cout << "Painter's Partition Problem " << std::endl;
  // int painters = 2;
  // std::vector<int> boards = {2, 1, 5, 6, 2, 3};
  // printArr(boards);
  // int minTime = findMinTimeToPaintBoards(boards, painters);
  // std::cout << "Minimum time required to paint above boards is " << minTime << " units." << std::endl;

  // * problem 9
  // std::cout << "Minimize Max Distance to Gas Station" << std::endl;
  // int extra = 5;
  // std::vector<int> gasStations = {1, 13, 17, 23};
  // long double maxDistance = gasStationBrute(gasStations, extra);
  // long double maxDistance = gasStationBetter(gasStations, extra);
  // printArr(gasStations);
  // std::cout << "Maximum distance " << maxDistance << std::endl;

  // * Problem 10
  // std::cout << "Median of Two Sorted Arrays" << std::endl;
  // std::vector<int> a = {1, 3, 4, 7, 10, 12}, b = {2, 3, 6, 15};
  // std::vector<int> a = {1, 2}, b = {3, 4};
  // printArr(a);
  // printArr(b);
  // double median = findMedianBrute(a, b);
  // double median = findMedianBetter(a, b);
  // double median = findMedian(a, b);
  // std::cout << "Median of two sorted array is " << median << std::endl;

  // * Problem 11
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice
