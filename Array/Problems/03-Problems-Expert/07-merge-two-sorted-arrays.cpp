#include<iostream>
using namespace std;

// * ------------------------- UTILITY FUNCTIONS -------------------------`
void print(vector<int>arr) {
  for(int i=0; i<arr.size(); i++) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}


// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(n1 + n2) + O(n1 + n2)
/*
 * O(n1 + n2) => To create the ans array looping on n1+n2 elements
 * O(n1 + n2) => To split ans array looping on n1+n2 elements
*/
// * SPACE COMPLEXITY O(n1 + n2) for ans array
void bruteForce(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size();
  int n2 = arr2.size();
  vector<int> ans;

  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(arr1[i] > arr2[j]) {
      ans.push_back(arr2[j]);
      j++;
    } 
    else {
      ans.push_back(arr1[i]);
      i++;
    }
  }

  // * Push the remaining elements from arr1
  while(i < n1) {
    ans.push_back(arr1[i]);
    i++;
  }

  // * Push the remaining elements from arr2
  while(j < n2) {
    ans.push_back(arr2[j]);
    j++;
  }

  // * Put everthing into arr1
  for(int k = 0; k < n1+n2; k++) {
    if(k < n1) {
      arr1[k] = ans[k];
    } 
    else {
      arr2[k-(n2-1)] = ans[k];
    }
  }

  print(arr1);
  print(arr2);
}

// * ------------------------- APPROACH 2: Optimal APPROACH(A) -------------------------
// * TIME COMPLEXITY O(min(n1, n2)) + O(n1logn) + O(n2logn)
/*
 * O(min(n1, n2)) => Whichever breaks first
 * O(n1logn) => To sort arr1
 * O(n2logn) => To sort arr2
*/
// * SPACE COMPLEXITY O(1)
void optimalApproach1(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size();
  int n2 = arr2.size();

  int i = n1-1;
  int j = 0;

  while(i > 0 && j < n2) {
    if(arr1[i] > arr2[j]) {
      // * swap
      swap(arr1[i], arr2[j]);
      i--;
      j++;
    } else {
      break;
    }
  }

  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());

  print(arr1);
  print(arr2);
}

int main() {
  vector<int> arr1 = { 1, 9, 10 };
  vector<int> arr2 = { 2, 3, 4, 5 };
  // bruteForce(arr1, arr2);
  optimalApproach1(arr1, arr2);
  return 0;
}