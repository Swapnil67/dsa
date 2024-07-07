#include<set>
#include<map>
#include<iostream>


// * ------------------------- UTILITY FUNCTIONS -------------------------`

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

void printMatrix(std::vector<std::vector<int>> matrix) {
  int n = matrix.size(), m = matrix[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

bool linearSearch(std::vector<int> arr, int target) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if(arr[i] == target) return true;
  }
  return false;
}

int merge(std::vector<int> arr, int l, int m, int h) {
  std::vector<int> temp;
  int i = l, j = m + 1, cnt = 0;
  while(i <= m && j <= h) {
    if(arr[i] >= arr[j]) {
      cnt = cnt + (m - i + 1);
      temp.push_back(arr[j++]);
    }
    else {
      temp.push_back(arr[i++]);
    }
  }

  while(i <= m) {
    temp.push_back(arr[i++]);
  }

  while(j <= h) {
    temp.push_back(arr[j++]);
  }

  for (int i = l; i <= h; i++) {
    arr[i] = temp[i - l];
  }

  return cnt;
}

int mergeSort(std::vector<int> arr, int l, int h) {
  int c = 0;
  if(l == h) return c;
  int mid = (l + h) / 2;
  c += mergeSort(arr, l, mid);
  c += mergeSort(arr, mid+1, h);
  c += merge(arr, l, mid, h);
  return c;
}

// * --------------------- Majority Element [n/3] ---------------------

std::vector<int> majorityElementN3(std::vector<int> arr) {
  int n = arr.size();
  int c1 = 0, c2 = 0;
  int num1, num2;
  for (int i = 0; i < n; i++) {
    if(arr[i] == num1) {
      c1++;
    }
    else if(arr[i] == num2) {
      c2++;
    }
    else if(c1 == 0  && num2 != arr[i]) {
      c1 = 1;
      num1 = arr[i];
    }
    else if(c2 == 0 && num1 != arr[i]) {
      c2 = 1;
      num2 = arr[i];
    }
    else {
      c1--, c2--;
    }
  }

  int occurence = n/3;
  c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if(arr[i] == num1) c1++;
    if(arr[i] == num2) c2++;
  }

  std::vector<int> ans;
  if(c1 > occurence) ans.push_back(num1);
  if(c2 > occurence) ans.push_back(num2);

  return ans;
}

// * --------------------- 3 Sum ---------------------

// * Nested Loop
std::vector<std::vector<int>> threeSumBrute(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = arr[i] + arr[j] + arr[k];
        if(sum == 0) {
          std::vector<int> temp = { arr[i], arr[j], arr[k] };
          std::sort(temp.begin(), temp.end());
          vectorSet.insert(temp);
        }
      }
    }
  }
  std::vector<std::vector<int>> ans;
  for(auto it: vectorSet) {
    ans.push_back(it);
  }

  return ans;
}

std::vector<std::vector<int>> threeSumBetter(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> tripletSet;
  for (int i = 0; i < n; i++) {
    std::set<int> st;
    for (int j = i + 1; j < n; j++) {
      int k = -(arr[i] + arr[j]);
      if(st.find(k) != st.end()) {
        std::vector<int> temp = {arr[i], arr[j], k};
        std::sort(temp.begin(), temp.end());
        tripletSet.insert(temp);
      }
      st.insert(arr[j]);
    }
  }

  std::vector<std::vector<int>> ans(tripletSet.begin(), tripletSet.end());
  return ans;
}

// * Using pointers
std::vector<std::vector<int>> threeSum(std::vector<int> arr) {
  int n = arr.size();
  std::vector<std::vector<int>> ans;
  std::sort(arr.begin(), arr.end());
  printArr(arr);

  for (int i = 0; i < n; i++) {
    while(i > 0 && arr[i] == arr[i-1]) {
      i++;
    }
    int j = i + 1, k = n - 1;
    while(j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if(sum == 0) {
        ans.push_back({ arr[i], arr[j], arr[k] });
        k--, j++;
        while(j < k && arr[j] == arr[j-1]) {
          j++;
        }
        while(j < k && arr[k] == arr[k+1]) {
          k--;
        }
      }
      else if(sum < 0) {
        j++;
      }
      else {
        k--;
      }
    }
  }
  return ans;
}

// * --------------------- 4 Sum ---------------------

// * Nested Loop
std::vector<std::vector<int>> fourSumBrute(std::vector<int> arr, int target) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          int sum = arr[i] + arr[j] + arr[k] + arr[l];
          if(sum == target) {
            std::vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            std::sort(temp.begin(), temp.end());
            vectorSet.insert(temp);
          }
        }
      }
    }
  }

  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * Using little maths
std::vector<std::vector<int>> fourSumBetter(std::vector<int> arr, int target) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      std::set<int> st;
      for (int k = j + 1; k < n; k++) {
        int l = -(arr[i] + arr[j] + arr[k]);
        if(st.find(l) != st.end()) {
          std::vector<int> temp = {arr[i], arr[j], arr[k], l};
          std::sort(temp.begin(), temp.end());
          vectorSet.insert(temp);
        }
        st.insert(arr[k]);
      }
    }
  }
  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * Using pointers
std::vector<std::vector<int>> fourSum(std::vector<int> arr, int target) {
  int n = arr.size();
  // * Sort the input arr
  sort(arr.begin(), arr.end());
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (j != i && arr[j] == arr[j - 1])
        continue;
      int k = j + 1, l = n - 1;
      while(k < l) {
        int sum = arr[i] + arr[j] + arr[k] + arr[l];
        if(sum == target) {
          ans.push_back({arr[i], arr[j], arr[k], arr[l]});
          k++, l--;
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l--;
        }
        else if(sum > target) l--;
        else k++;
      }
    }
  }
  return ans;
}

// * --------------------- Merge overlapping intervals ---------------------

// * Nested loop
// * TIME COMPLEXITY O(nlogn) +  O(2N)
std::vector<std::vector<int>> mergeOverlappingIntervalsBrute(std::vector<std::vector<int>> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());

  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    int s = arr[i][0], e = arr[i][1];

    if(!ans.empty() && e <= ans.back()[1]) {
      continue;
    }

    for (int j = i + 1; j < n; j++) {
      if(e >= arr[j][0]) {
        e = std::max(e, arr[j][1]);
      }
      else {
        break;
      }
    }

    ans.push_back({s, e});
  }
  return ans;
}

// * Base Interval & Compare
// * TIME COMPLEXITY O(nlogn) +  O(N)
std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  std::vector<int> interval = arr[0];
  std::vector<std::vector<int>> ans;
  for (int i = 1; i < n; i++) {
    if(interval[1] > arr[i][0]) {
      interval[1] = std::max(interval[1], arr[i][1]);
    }
    else {
      ans.push_back(interval);
      interval = arr[i];
    }
  }
  ans.push_back(interval);
  return ans;
}


// * --------------------- Merge Two Sorted Arrays Without Extra Space ---------------------

// * Create a merged array
// * TIME COMPLEXITY O(n1 + n2) + O(n1 + n2) 
// * SPACE COMPLEXITY O(n1 + n2)
void mergeTwoSortedArraysWithoutExtraSpaceBrute(std::vector<int> &a, std::vector<int> &b) {
  int n1 = a.size(), n2 = b.size();
  int i = 0, j = 0;
  std::vector<int> mergedArr;
  while(i < n1 && j < n2) {
    if(a[i] > b[j]) {
      mergedArr.push_back(b[j++]);
    }
    else {
      mergedArr.push_back(a[i++]);
    }
  }

  // * Push remaining from a
  while(i < n1) {
    mergedArr.push_back(a[i++]);
  }

  // * Push remaining from b
  while(j < n2) {
    mergedArr.push_back(b[j++]);
  }

  for (int i = 0; i < n1; i++) {
    a[i] = mergedArr[i];
  }

  for (int i = n1; i < n1 + n2; i++) {
    b[i-n1] = mergedArr[i];
  }
}

void mergeTwoSortedArraysWithoutExtraSpace(std::vector<int> &a, std::vector<int> &b) {
  int n1 = a.size(), n2 = b.size();
  int i = n1 - 1, j = 0;
  while(i >= 0 && j < n2) {
    if(a[i] > b[j]) {
      swap(a[i], b[j]);
      j++, i--;
    } else {
      break;
    }
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
}

// * --------------------- Missing And Repeating Numbers ---------------------

// * Nested loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<int> findMissingRepeatingNumbersBrute(std::vector<int> arr) {
  int n = arr.size();
  int missing = -1, repeating = -1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[j] == i) cnt++;
    }

    if(cnt == 2) repeating = i;
    else if(cnt == 0) missing = i;

    if (missing != -1 && repeating != -1)
      break;
  }

  return { missing, repeating };
}

// * Hashed Array
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
std::vector<int> findMissingRepeatingNumbersBetter(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> hashArr(n+1, 0);
  for (int i = 0; i < n; i++) {
    hashArr[arr[i]]++;
  }

  int missing = -1, repeating = -1;
  for (int i = 1; i <= n; i++) {
    int cnt = hashArr[i];
    if(cnt > 1) repeating = i;
    else if(cnt == 0) missing = i;
    if (missing != -1 && repeating != -1)
      break;
  }

  return {missing, repeating};
}

// * Maths & Equations 
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
std::vector<int> findMissingRepeatingNumbers(std::vector<int> arr) {
  int n = arr.size();
  
  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

  long long S = 0, S2 = 0;
  for (int i = 0; i < n; i++) {
    S += arr[i];
    S2 += (long long)arr[i] * (long long)arr[i];  
  }

  int val1 = S - SN;
  int val2 = S2 - S2N;
  val2 = val2 / val1;

  int x = (val1 + val2) / 2;
  int y = x - val1;

  return { y, x };
}

// * --------------------- Number of Inversions ---------------------

// * Nested loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
int numberOfInversionsBrute(std::vector<int> arr) {
  int n = arr.size(), c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if(arr[i] > arr[j]) c++;
    }
  }
  return c;
}

// * Merge Sort & Count Pairs
// * TIME COMPLEXITY O(NLogN)
// * SPACE COMPLEXITY O(N)
int numberOfInversions(std::vector<int> arr) {
  int n = arr.size();
  int ans = mergeSort(arr, 0, n-1);
  return ans;
}


int main() {
  // * Problem 1
  // std::cout << "Majority Element n/3" << std::endl;
  // std::vector<int> arr = {1, 1, 1, 2, 2, 2};
  // printArr(arr);
  // std::vector<int> ans = majorityElementN3(arr);
  // printArr(ans);

  // * Problem 2
  // std::cout << "--------- 3 Sum ---------" << std::endl;
  // std::vector<int> arr = {-1, 0, 1, 2, -1, -4};
  // std::vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
  // std::cout<<"Input Array"<<std::endl;
  // printArr(arr);
  // std::vector<std::vector<int>> ans = threeSumBrute(arr);
  // std::vector<std::vector<int>> ans = threeSumBetter(arr);
  // std::vector<std::vector<int>> ans = threeSum(arr);
  // printMatrix(ans);

  // * Problem 3
  // std::cout << "--------- 4 Sum ---------" << std::endl;
  // int target = 0;
  // std::vector<int> arr = {1, 0, -1, 0, -2, 2};
  // int target = 8;
  // std::vector<int> arr = {2, 2, 2, 2, 2};
  // std::cout << "Input Array" << std::endl;
  // printArr(arr);
  // std::cout << "--------- Ans vectors ---------" << std::endl;
  // std::vector<std::vector<int>> ans = fourSumBrute(arr, target);
  // std::vector<std::vector<int>> ans = fourSumBetter(arr, target);
  // std::vector<std::vector<int>> ans = fourSum(arr, target);
  // printMatrix(ans);

  // * Problem 4
  // std::cout << "--------- Merge overlapping intervals ---------" << std::endl;
  // std::vector<std::vector<int>> arr = {{1, 3}, {1, 5}, {6, 7}};
  // std::vector<std::vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
  // std::cout << "Input Matrix" << std::endl;
  // printMatrix(arr);
  // std::vector<std::vector<int>> ans = mergeOverlappingIntervalsBrute(arr);
  // std::vector<std::vector<int>> ans = mergeOverlappingIntervals(arr);
  // std::cout << "Output Matrix" << std::endl;
  // printMatrix(ans);

  // * Problem 5
  // std::cout << "Merge Two Sorted Arrays Without Extra Space" << std::endl;
  // std::vector<int> a = {1, 8, 8}, b = {2, 3, 4, 5};
  // std::cout << "Input vectors" << std::endl;
  // std::cout<<"A vector: ";
  // printArr(a);
  // std::cout<<"B vector: ";
  // printArr(b);
  // std::cout << "After Merging Sorted Arrays" << std::endl;
  // mergeTwoSortedArraysWithoutExtraSpaceBrute(a, b);
  // mergeTwoSortedArraysWithoutExtraSpace(a, b);
  // std::cout<<"A vector: ";
  // printArr(a);
  // std::cout<<"B vector: ";
  // printArr(b);

  // * Problem 6
  // std::cout << " --------------- Missing And Repeating Numbers ---------------" << std::endl; 
  // std::vector<int> arr = {4, 3, 6, 2, 1, 1};
  // printArr(arr);
  // std::vector<int> ans = findMissingRepeatingNumbersBrute(arr);
  // std::vector<int> ans = findMissingRepeatingNumbersBetter(arr);
  // std::vector<int> ans = findMissingRepeatingNumbers(arr);
  // printArr(ans);

  // * Problem 7
  // std::cout << " --------------- Number of Inversions  ---------------" << std::endl;
  // std::vector<int> arr = {5, 3, 2, 1, 4};
  // printArr(arr);
  // int inversions = numberOfInversionsBrute(arr);
  // int inversions = numberOfInversions(arr);
  // std::cout << "Number of inversions are " << inversions << std::endl;

  // * Problme 8

  return 0;
}

// * Run the code 
// * g++ --std=c++17 practice.cpp -o practice && ./practice