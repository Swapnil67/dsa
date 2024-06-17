#include<set>
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

// * ------------------------- Majority Element (N/3) -------------------------`
// * Moore's voting algorithm
// * Time Complexity O(2N)
// * Space Complexity O(1)
std::vector<int> majorityElementN3(std::vector<int> arr) {
  int n = arr.size();
  int cnt1 = 0, cnt2 = 0;
  int ele1 = INT_MIN, ele2 = INT_MIN;
  for (int i = 0; i < n; i++) {
    if(cnt1 == 0 && ele2 != arr[i]) {
      ele1 = arr[i];
      cnt1 = 1;
    }
    else if(cnt2 == 0 && ele1 != arr[i]) {
      ele2 = arr[i];
      cnt2 = 1;
    }
    else if (arr[i] == ele1)
      cnt1++;
    else if (arr[i] == ele2)
      cnt2++;
    else {
      cnt1--, cnt2--;
    }
  }

  // * Check if ele1 & ele2 are really majority elements
  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (ele1 == arr[i]) cnt1++;
    if (ele2 == arr[i]) cnt2++;
  }
  std::vector<int> ans;
  if(cnt1 > n/3) ans.push_back(ele1);
  if(cnt2 > n/3) ans.push_back(ele2);
  return ans;
}

// * -------------------------  3 Sum -------------------------`
// * Time Complexity O(N^3) * O(no of vectors) = O(N^3) * O(m)
// * Space Complexity O(no of vectors) + O(no of vectors)
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
  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * Time Complexity O(N^2) * O(no of vectors) = O(N^3) * O(m)
// * Space Complexity O(no of vectors) + O(no of vectors)
std::vector<std::vector<int>> threeSumBetter(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    std::set<int> st;
    for (int j = i + 1; j < n; j++) {
      int k = -(arr[i] + arr[j]);
      int sum = arr[i] + arr[j] + k;
      if(st.find(k) != st.end()) {
        std::vector<int> temp = { arr[i], arr[j], k };
        std::sort(temp.begin(), temp.end());
        vectorSet.insert(temp); 
      }
      st.insert(arr[j]);
    }
  }
  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

std::vector<std::vector<int>> threeSumOptimal(std::vector<int> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if(i != 0 && arr[i] == arr[i-1]) continue;
    int j = i + 1, k = n - 1;
    while(j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if(sum == 0) {
        ans.push_back({ arr[i], arr[j], arr[k] });
        k--;
        j++;
        while(arr[j] == arr[j-1]) j++;
        while(arr[k] == arr[k+1]) k--;
      }
      else if(sum > 0) {
        k--;
      }
      else {
        j++;
      }
    }
  }
  return ans;
}

// * -------------------------  4 Sum -------------------------`

std::vector<std::vector<int>> fourSumBrute(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          int sum = arr[i] + arr[j] + arr[k] + arr[l];
          if(sum == 0) {
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

std::vector<std::vector<int>> fourSumBetter(std::vector<int> arr) {
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

std::vector<std::vector<int>> fourSumOptimal(std::vector<int> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if (i != 0 && arr[i] == arr[i - 1])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (j != i + 1 && arr[j] == arr[j - 1])
        continue;
      int k = j + 1, l = n - 1;
      while(k < l) {
        int sum = arr[i] + arr[j] + arr[k] + arr[l];
        if(sum == 0) {
          ans.push_back({arr[i], arr[j], arr[k], arr[l]});
          k++;
          l--;
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l--;
        }
        else if (sum > 0)
          l--;
        else
          k++;
      }
    }
  }
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
  // std::cout << "3 Sum" << std::endl;
  // std::vector<int> arr = {-1, 0, 1, 2, -1, -4};
  // std::vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
  // std::cout<<"Input Array"<<std::endl;
  // printArr(arr);
  // std::vector<std::vector<int>> ans = threeSumBrute(arr);
  // std::vector<std::vector<int>> ans = threeSumBetter(arr);
  // std::vector<std::vector<int>> ans = threeSumOptimal(arr);
  // printMatrix(ans);

  // * Problem 3
  // std::cout << "--------- 4 Sum ---------" << std::endl;
  // std::vector<int> arr = {1, 0, -1, 0, -2, 2};
  // std::cout<<"Input Array"<<std::endl;
  // printArr(arr);
  // std::vector<std::vector<int>> ans = fourSumBrute(arr);
  // std::vector<std::vector<int>> ans = fourSumBetter(arr);
  // std::vector<std::vector<int>> ans = fourSumOptimal(arr);
  // printMatrix(ans);

  return 0;
}

// * Run the code 
// * g++ --std=c++17 practice.cpp -o practice && ./practice