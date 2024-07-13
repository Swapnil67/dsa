#include<iostream>


void printArr(std::vector<int> arr) {
  int n = arr.size();
  for(int i=0; i<n; i++) { 
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
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

int main() {
  // * Problem 1
  std::cout << "Koko eating bananas" << std::endl;
  int h = 2;
  std::vector<int> piles = {1000000000};
  std::cout << "Piles of bananas" << std::endl;
  printArr(piles);
  int minimumBananas = findMinimumBananasToEat(piles, h);
  std::cout << "Koko need to eat " << minimumBananas << " bananas each hour to finish full pile in " << h << " hours." << std::endl;
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice
