// TODO Add question

/*
 * Minimum no of days to make m bouquets

*/

#include <iostream>
using namespace std;

// * ------------------------- Utility Function -------------------------`

bool isPossibleDay(vector<int> arr, int day, int bouquetsRequired, int flowersInAbouquet) {
  int counter = 0, totalBouquetsFormed = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] <= day) {
      counter++;
    }
    else {
      // cout<<"counter: "<<counter<<endl;
      // cout<<"totalBouquetsFormed: "<<totalBouquetsFormed<<endl;
      totalBouquetsFormed += (counter / flowersInAbouquet);
      counter = 0;
    }
  }
  totalBouquetsFormed += (counter / flowersInAbouquet);
  // cout<<"counter out: "<<counter<<endl;
  // cout<<"totalBouquetsFormed: out "<<totalBouquetsFormed<<endl;

  if (totalBouquetsFormed >= bouquetsRequired)
    return true;
  return false;
}

vector<int> findMinMax(vector<int> arr)
{
  int min_val = INT_MAX, max_val = INT_MIN;
  vector<int> min_max_vector;
  for (int i = 0; i < arr.size(); i++) {
    min_val = min(min_val, arr[i]);
    max_val = max(max_val, arr[i]);
  }

  min_max_vector = {min_val, max_val};
  return min_max_vector;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O((max-min)+1) * O(N) [isPossible Day] 
// * SPACE COMPLEXITY O(1)
int bruteForce(vector<int> arr, int bouquetsRequired, int flowersInAbouquet) {
  if(bouquetsRequired*flowersInAbouquet > arr.size()) {
    return -1;
  }

  vector<int> min_max_vector = findMinMax(arr);
  int min_days = min_max_vector[0], max_days = min_max_vector[1];
  for (int i = min_days; i <= max_days; i++)  {
    bool isMinimumDay = isPossibleDay(arr, i, bouquetsRequired, flowersInAbouquet);
    if (isMinimumDay) {
      return i;
    }
  }
}

// * ------------------------- APPROACH 2: Optimal APPROACH -------------------------

// * TIME COMPLEXITY log((max-min)+1) * O(N) [isPossible Day] 
// * SPACE COMPLEXITY O(1)
int optimalApproach(vector<int> days, int bouquetsRequired, int flowersInAbouquet) {
  if(bouquetsRequired*flowersInAbouquet > days.size()) {
    return -1;
  }

  vector<int> min_max_vector = findMinMax(days);
  int min_days = min_max_vector[0], max_days = min_max_vector[1];

  while(min_days <= max_days) {
    int mid = min_days + (max_days - min_days)/2;
    bool isMinimumDay = isPossibleDay(days, mid, bouquetsRequired, flowersInAbouquet);
    // cout<<"mid: "<<mid<<endl;
    // cout<<"isMinimumDay: "<<isMinimumDay<<endl;
    if(isMinimumDay) {
      return mid;
    } 
    else {
      min_days = min_days+1;
    }
  }
  return -1;

}

int main()
{
  vector<int> arr = {7,7,7,7,13,11,12,7};
  int bouquetsRequired = 2;
  int flowersInAbouquet = 3;

  // int minimumdays = bruteForce(arr, bouquetsRequired, flowersInAbouquet);
  int minimumdays = optimalApproach(arr, bouquetsRequired, flowersInAbouquet);
  cout << "Minimum days to make " << bouquetsRequired << " bouquet of " << flowersInAbouquet << " flowers each is " << minimumdays << " days." << endl;

  // bool isMinimumDay = isPossibleDay(arr, 7, bouquetsRequired, flowersInAbouquet);
  // cout<<"isMinimumDay: "<<isMinimumDay<<endl;

  return 0;
}