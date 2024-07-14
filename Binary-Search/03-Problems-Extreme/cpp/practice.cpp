#include<iostream>


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
  int mx = INT_MIN, mn = INT_MAX;
  for (int i = 0; i < arr.size(); i++) {
    mx = std::max(arr[i], mx);
    mn = std::min(arr[i], mn);
  }
  return {mx, mn};
}

// * ---------- Koko Eating Bananas ----------

int findHrsToCompletePile(std::vector<int> piles, int bananas, int maxH) {
  int n = piles.size();
  int curHr = 0;
  for (int i = 0; i < n; i++) {
    curHr += std::ceil((float)piles[i] / (float)bananas);
  }
  return curHr;
}

int findMinimumBananasToEat(std::vector<int> piles, int maxH) {
  int n = piles.size();
  std::pair<int, int> maxAndMin = getMaxMinOfArray(piles);
  int l = 0, r = maxAndMin.first;
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int hrsToCompletePile = findHrsToCompletePile(piles, m, maxH);
    if(hrsToCompletePile <= maxH) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return ans;
} 

// * ---------- Rose Garden ----------

bool findIsPossibleDay(std::vector<int> bloomDays, int days, int flowersInAbouquet, int bouquetsRequired) {
  int bouquets = 0, roses = 0;
  for (int i = 0; i < bloomDays.size(); i++) {
    if(bloomDays[i] <= days) {
      roses++;
    }
    else {
      bouquets = bouquets + (roses / flowersInAbouquet);
      roses = 0;
    }
  }
  bouquets = bouquets + (roses / flowersInAbouquet);
  if(bouquets >= bouquetsRequired) return true;
  return false;
}

int findMinimumDaysToMakeBouquets(std::vector<int> bloomDays, int flowersInAbouquet, int bouquetsRequired) {
  int n = bloomDays.size();
  if (n < flowersInAbouquet * bouquetsRequired)
    return -1;

  std::pair<int, int> minMaxVal = getMaxMinOfArray(bloomDays);
  int l = minMaxVal.second, r = minMaxVal.first;
  int ans = r;
  while (l <= r) {
    // * Days
    int m = l + (r - l) / 2;
    if(findIsPossibleDay(bloomDays, m, flowersInAbouquet, bouquetsRequired)) {
      ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

// * ---------- Smallest Divisor ----------

bool isPossibleDivisor(std::vector<int> arr, int divisor, int threshold) {
  int n = arr.size();
  int c = 0;
  for (int i = 0; i < n; i++) {
    c += std::ceil((float)arr[i] / (float)divisor);
  }
  if(c > threshold) return false;
  return true;
}

int findSmallestDivisor(std::vector<int> arr, int threshold) {
  int n = arr.size();
  std::pair<int, int> minMaxVal = getMaxMinOfArray(arr);
  int l = 1, r = minMaxVal.first;
  int ans = r;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(isPossibleDivisor(arr, m, threshold)) {
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

bool isPossibleWeight(std::vector<int> weights, long long capacity, int maxDays) {
  int  days = 1;
  long long curWeight = 0;
  for (int i = 0; i < weights.size(); i++) {
    if(curWeight + weights[i] > capacity)  {
      days++;
      curWeight = weights[i];
    }
    else {
      curWeight += weights[i];
    }
  }
  if(days > maxDays) return false;
  return true;
}

int findLeastPossileWeight(std::vector<int> weights, int maxDays) {
  int n = weights.size();
  std::pair<int, int> minMaxVal = getMaxMinOfArray(weights);
  long long l = minMaxVal.first, r = arraySum(weights);
  int ans = r;
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if(isPossibleWeight(weights, m, maxDays)) {
      // ans = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  // return ans;
  return l;
} 

// * ------------ Kth Missing Positive Number  ------------

int findKthMissingNumber(std::vector<int> arr, int k) {
  int n = arr.size();
  int l = 0, r = n - 1;
  while(l <= r) {
    int m = l + (r - l) / 2;
    int missingNos = arr[m] - (m + 1);
    if(missingNos > k) {
      r = m - 1;
    } 
    else {
      l = m + 1;
    }
  }
  return k + l;
}

// * ------------ Aggressive Cows  ------------

bool canWePlace(std::vector<int> arr, int distance, int threshold) {
  int n = arr.size();
  int lastPlaced = arr[0], placed = 1;
  for (int i = 1; i < n; i++) {
    if(arr[i] - lastPlaced >= distance) {
      placed++;
      lastPlaced = arr[i];
    }
    if (placed >= threshold)
      return true;
  }
  return false;
}

int AggressiveCows(std::vector<int> stalls, int cows) {
  std::sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  int l = 1, r = stalls[n - 1] - stalls[0];
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(canWePlace(stalls, m, cows)) {
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  return r;
}

// * ------------ Allocate Books  ------------

int canAllocatePages(std::vector<int> pages, int maxPages, int students) {
  int n = pages.size();
  int allocatedPages = pages[0], allocatedStudents = 1;
  for (int i = 1; i < n; i++) {
    if(allocatedPages + pages[i] <= maxPages) {
      allocatedPages += pages[i];
    }
    else {
      allocatedStudents++;
      allocatedPages = pages[i];
    }
  }
  if(allocatedStudents > students) return false;
  return true;
}

int findMaxPagesAssigned(std::vector<int> pages, int s) {
  int n = pages.size();
  std::pair<int, int> minMaxVal = getMaxMinOfArray(pages);
  int l = minMaxVal.second, r = arraySum(pages);
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(canAllocatePages(pages, m, s)) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

// * ------------ Painter's Partition Problem  ------------

int canPaintBoardInTime(std::vector<int> boards, int timeGiven, int maxPainters) {
  int n = boards.size();
  int paintersRequired = 1, boardsPainted = 0;
  for (int i = 0; i < n; i++) {
    if(boardsPainted + boards[i] <= timeGiven) {
      boardsPainted += boards[i];
    }
    else {
      paintersRequired++;
      boardsPainted = boards[i];
    }
  }
  if(paintersRequired > maxPainters) {
    return false;
  }
  return true;
}

int findMinTimeToPaintBoards(std::vector<int> boards, int painters) {
  int n = boards.size();
  int l = 1, r = arraySum(boards);
  while (l <= r) {
    int m = l + (r - l) / 2;
    if(canPaintBoardInTime(boards, m, painters)) {
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  // * Problem 1
  // std::cout << "Koko eating bananas" << std::endl;
  // int h = 2;
  // std::vector<int> piles = {1000000000};
  // std::cout << "Piles of bananas" << std::endl;
  // printArr(piles);
  // int minimumBananas = findMinimumBananasToEat(piles, h);
  // std::cout << "Koko need to eat " << minimumBananas << " bananas each hour to finish full pile in " << h << " hours." << std::endl;

  // * Problem 2
  // std::cout << "Rose Garden" << std::endl;
  // std::vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
  // int bouquetsRequired = 2, flowersInAbouquet = 3;
  // printArr(bloomDays);
  // int minDays = findMinimumDaysToMakeBouquets(bloomDays, flowersInAbouquet, bouquetsRequired);
  // std::cout << "Minimum days required to make " << bouquetsRequired << " bouquets containing " << flowersInAbouquet << " roses each is " << minDays << std::endl;

  // * Problem 3
  // std::cout << "Smallest Divisor" << std::endl;
  // int threshold = 6;
  // std::vector<int> arr = {1, 2, 5, 9};
  // printArr(arr);
  // int smallestDivisor = findSmallestDivisor(arr, threshold);
  // std::cout << "The smallest divisor is " << smallestDivisor << std::endl;

  // * Problem 4
  // std::cout << "Capacity To Ship Packages Within D Days" << std::endl;
  // std::vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int days = 5;
  // printArr(weights);
  // int leastWeight = findLeastPossileWeight(weights, days);
  // std::cout << "Ship should take atleast " << leastWeight << " weights to transfer all weights in " << days << " days." << std::endl;

  // * problem 5
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
  std::cout << "Painter's Partition Problem " << std::endl;
  int painters = 2;
  std::vector<int> boards = {2, 1, 5, 6, 2, 3};
  printArr(boards);

  int minTime = findMinTimeToPaintBoards(boards, painters);
  std::cout << "Minimum time required to paint above boards is " << minTime << " units." << std::endl;

  // * problem 9
  // std::cout << "Minimize Max Distance to Gas Station" << std::endl;
  // int extra = 5;
  // std::vector<int> gasStations = {1, 13, 17, 23};
  // printArr(gasStations);
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice
