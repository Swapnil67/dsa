#include<iostream>
using namespace std;

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
void bruteForce(vector<int> arr) {
  int n = arr.size();
  int repeating = -1, missing = -1;

  for(int i = 1; i <= n; i++) {
    int c = 0;
    for(int j = 0; j < n; j++) {
      if(i == arr[j]) {
        c++;
      }
    }
    if(c > 1) {
      repeating = arr[i-1];
    }
    if(c == 0) {
      missing = i;
    }
    if(repeating != -1 && missing != -1) {
      break;
    }
  }

  cout<<"Missing: "<<missing<<endl;
  cout<<"Repeating: "<<repeating<<endl;
}


// * ------------------------- APPROACH 2: Better APPROACH -------------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
void betterApproach(vector<int> arr) {
  int n = arr.size();
  int repeating = -1, missing = -1;

  int *hash = new int[n+1];
  // int hash[n+1] = {0};

  for(int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  for(int j = 1; j <= n; j++) {
    if(hash[j] > 1) {
      repeating = j;
    }
    else if(hash[j] == 0) {
      missing = j;
    }
  }

  cout<<"Missing: "<<missing<<endl;
  cout<<"Repeating: "<<repeating<<endl;
} 

// * ------------------------- APPROACH 3: Optimal APPROACH -------------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void optimalApproach(vector<int> arr) {
  long long n = arr.size();
  long long SN = (n*(n+1))/2; // * Sum of first n natural numbers
  long long S2N = (n*(n+1)*((2*n)+1))/6; // * Sum of square first n natural numbers
  long long S = 0; // * Sum of elements of arr
  long long S2 = 0; // * Sum of square elements of arr

  for(int i=0; i<n; i++) {
    S += arr[i];
    S2 += (long long)arr[i] * (long long)arr[i];
  }

  long long val1 =  S - SN;
  long long val2 =  S2 - S2N;
  val2 = val2/val1;
  long long x = (val1+val2)/2;
  long long y = val2 - x;

  cout<<"Missing: "<<y<<endl;
  cout<<"Repeating: "<<x<<endl;
}


void optimalApproach2(vector<int> arr) {
  int n = arr.size();
  int repeating = -1, missing = -1;
  long long S = 0, SN = 0, S2 = 0, S2N = 0;
  for(int i=0; i<n; i++) {
    S += arr[i];
    S2 += ((long long)arr[i] * (long long)arr[i]);
  }

  SN = (n*(n+1))/2;
  S2N = (n*(n+1)*(2*n+1))/6;

  long long val1 = S - SN; // * x - y
  long long val2 = S2 - S2N; // * x + y
  val2 = val2/val1;

  long long x = (val1 + val2) / 2;
  
  long long  y = x - val1;
  cout<<"x "<<x<<endl;
  cout<<"y "<<y<<endl;
  

  // cout<<"S "<<S<<endl;
  // cout<<"SN "<<SN<<endl;
  // cout<<"val1 "<<val1<<endl;

  // cout<<"S2 "<<S2<<endl;
  // cout<<"S2N "<<S2N<<endl;
  // cout<<"val2 "<<val2<<endl;

}

int main() {
  // vector<int> arr = { 4,3,2,6,1,1 };
  vector<int> arr = { 1,2,1,3,4,6 };
  // bruteForce(arr);
  // betterApproach(arr);
  optimalApproach2(arr);
  return 0;
}