#include<map>
#include<vector>
#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printVector(vector<int> v) {
  for(int i=0; i<v.size(); i++) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(vector<int> &a) {
  for(int i=1;i<a.size();i++) {
    bool swapped = false;
    for(int j=0;j<a.size()-i;j++) {
      if(a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        swapped = true;
      }
    }
    if(swapped == false) break;
  }
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`

// TODO

// * ------------------------- APPROACH 2: BETTER APPROACH -------------------------`

vector<int> betterApproach(vector<int> a, int target) {
  map<int, int> idxMap;
  for(int i=0; i<a.size(); i++) {
    int num = a[i];
    int check = target - num;
    if(idxMap.find(check) != idxMap.end()) {
      // cout<<idxMap[check]<<" "<<i;
      return {idxMap[check], i};
    }
    idxMap[num] = i;
  }
}

// * ------------------------- APPROACH 3: OPTIMAL APPROACH -------------------------`

// * TIME COMPLEXITY O(N) + O(NlogN) (for sorting)
// * SPACE COMPLEXITY O(N) (for map)
vector<int> optimalApproach(vector<int> a, int target) {
  // * Save the original Value & index in map
  map<int, int> ogMap;
  for(int i=0; i<a.size(); i++) {
    ogMap[a[i]] = i;
  }

  // * Sort the Vector
  bubbleSort(a);
  // sort(a.begin(), a.end()); // * C++ STL

  // * Two pointer
  int s = 0, e = a.size()-1;
  while(s<=e) {
    if(a[s] + a[e] == target) {
      return { ogMap[a[e]], ogMap[a[s]] };
    } else if(a[s] + a[e] > target) {
      e--;
    } else {
      s++;
    }
  }
  return { -1, -1 };
}

int main() {
  vector<int> v;
  vector<int> a;
  a.push_back(4);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(1);
  int target;
  cout<<"Enter a targer: ";
  cin>>target;

  // v = betterApproach(a, target);
  // printVector(v);

  v = optimalApproach(a, target);
  printVector(v);

  return 0;
}