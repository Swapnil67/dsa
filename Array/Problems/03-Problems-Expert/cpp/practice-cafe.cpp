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

// * Time Complexity O(N^2)
void printMatrix(std::vector<std::vector<int>>&mat) {
  int n = mat.size();
  int m = mat[0].size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      std::cout<<mat[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}


// * ------------------------- Majority Element (n/2) -------------------------
// * Time Complexity O(N^2)
// * Space Complexity O(1)
int majorityElementBrute(std::vector<int> arr) {
  int n = arr.size();
  int occurence = n/2;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[i] == arr[j]) cnt++;
      if(cnt > occurence) {
        return arr[i];
      }
    }
  }
  return -1;
}

// * Time Complexity O(N) + O(N)
// * Space Complexity O(N)
int majorityElementBetter(std::vector<int> arr) {
  int n = arr.size();
  int occurence = n/2;
  std::unordered_map<int, int> occurenceMap;
  for (int i = 0; i < n; i++) {
    occurenceMap[arr[i]]++;
  }

  for (auto it : occurenceMap) {
    if(it.second > occurence) return it.first;
  }
  return -1;
}

// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
int majorityElementOptimal(std::vector<int> arr) {
  int n = arr.size(), cnt = 0, ele;
  for (int i = 0; i < n; i++) {
    if(cnt == 0) {
      ele = arr[i];
      cnt = 1;
    }
    else if(ele == arr[i]) {
      cnt++;
    }
    else {
      cnt--;
    }
  }

  if(cnt == 0) return -1;
  cnt = 0;
  int occurence = n/2;
  for (int i = 0; i < n; i++) {
    if(arr[i] == ele) cnt++; 
  }
  if (cnt > occurence)
    return ele;
  return -1;
}

// * ------------------------- Majority Element (n/3) -------------------------
// * Time Complexity O(N^2) * O(logN)
// * Space Complexity O(1)
std::vector<int> majorityElementB_Brute(std::vector<int> arr) {
  int n = arr.size(), occurence = n/3;
  std::set<int> majoritySet;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[i] == arr[j]) cnt++;
      if(cnt > occurence) {
        majoritySet.insert(arr[i]);
        break;
      }
    }
  }
  for (auto ele : majoritySet) {
    ans.push_back(ele);
  }
  return ans;
}

// * Time Complexity O(N) * O(N)
// * Space Complexity O(N)
std::vector<int> majorityElementB_Better(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  std::unordered_map<int, int> occurenceMap;
  for (int i = 0; i < n; i++) {
    occurenceMap[arr[i]]++;
  }
  int occurence = n/3;
  for (auto it : occurenceMap) {
    if(it.second > occurence) {
      ans.push_back(it.first);
    }
  }
  return ans;
}

// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<int> majorityElementB_Optimal(std::vector<int> arr) {
  int n = arr.size();
  int cnt1 = 0, cnt2 = 0, ele1, ele2;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    if(cnt1 == 0 && ele2 != arr[i]) {
      cnt1 = 1;
      ele1 = arr[i];
    }
    else if(cnt2 == 0 && ele1 != arr[i]) {
      cnt2 = 1;
      ele2 = arr[i];
    }
    else if(ele1 == arr[i]) cnt1++;
    else if(ele2 == arr[i]) cnt2++;
    else {
      cnt1--, cnt2--;
    }
  }

  int occurence = n/3;
  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if(arr[i] == ele1) cnt1++;
    if(arr[i] == ele2) cnt2++;
  }
  if(cnt1 > occurence) ans.push_back(ele1);
  if(cnt2 > occurence) ans.push_back(ele2);
  return ans;
}

// * ------------------------- Three Sum -------------------------

// * Time Complexity O(N^3) * log(no. of triplets)
// * Space Complexity O(no. of triplets)
std::vector<std::vector<int>> threeSumBrute(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> ansSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if(arr[i] + arr[j] + arr[k] == 0) {
          std::vector<int> ans = { arr[i], arr[j], arr[k] };
          std::sort(ans.begin(), ans.end());
          ansSet.insert(ans);
        }
      }
    }
  }
  std::vector<std::vector<int>> ans(ansSet.begin(), ansSet.end());
  return ans;
}

// * Time Complexity O(N^2) * log(size of set) = O(N^2) * log(m)
// * Space Complexity O(no. of triplets) + O(N) (hashSet)
std::vector<std::vector<int>> threeSumBetter(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    std::set<int> hashSet;
    for (int j = i + 1; j < n; j++) {
      int k = -(arr[i] + arr[j]);
      if(hashSet.find(k) != hashSet.end()) {
        // * found a triplet
        std::vector<int> temp = {arr[i], arr[j], k};
        std::sort(temp.begin(), temp.end());
        vectorSet.insert(temp);
      }
      hashSet.insert(arr[j]);
    }
  }
  std::vector<std::vector<int>> ans(vectorSet.begin(), vectorSet.end());
  return ans;
}

// * Time Complexity O(nlogn) + O(N^2);
// * Space Complexity O(no. of triplets) [For Answer only]
std::vector<std::vector<int>> threeSumOptimal(std::vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  int n = arr.size();;
  std::vector<std::vector<int>> ans;
  for (int i = 0; i < n; i++) {
    if(i > 0 && arr[i-1] == arr[i]) continue;
    int j = i + 1, k = n - 1;
    while(j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if(sum == 0) {
        ans.push_back({arr[i], arr[j], arr[k]});
        j++;
        k--;
        while (j < k && arr[k] == arr[k + 1]) {
          k--;
        }
        while (j < k && arr[j] == arr[j - 1]) {
          j++;
        }
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

// * ------------------------- Four Sum -------------------------

std::vector<std::vector<int>> fourSumBrute(std::vector<int> arr) {
  int n = arr.size();
  std::set<std::vector<int>> vectorSet;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
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
          // * found a quadraplet
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
          std::vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp); 
          k++;
          l--;
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l++;
        }
        else if(sum > 0) l--;
        else k++;
      }
    }
  }
  return ans;
}


int main() {
  // * Problem 1
  // std::cout << "Majority Element (n/2)" << std::endl;
  // std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2}; // * 2
  // printArr(arr);
  // int ans = majorityElementBrute(arr);
  // int ans = majorityElementBetter(arr);
  // int ans = majorityElementOptimal(arr);
  // std::cout << "Majority Element " << ans << std::endl;

  // * Problem 2
  // std::cout << "Majority Element (n/3)" << std::endl;
  // std::vector<int> arr = {1, 1, 1, 2, 2, 2}; // * [1, 2]
  // std::vector<int> arr = {2, 2, 1, 3, 1, 1, 3, 1, 1}; // * 1
  // printArr(arr);
  // std::vector<int> ans = majorityElementB_Brute(arr);
  // std::vector<int> ans = majorityElementB_Better(arr);
  // std::vector<int> ans = majorityElementB_Optimal(arr);
  // printArr(ans);

  // * Problem 3
  // std::cout << "Three sum" << std::endl;
  // std::cout << "Input vector" << std::endl;
  // std::vector<int> arr = {-1, 0, 1, 2, -1, -4};
  // std::vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
  // printArr(arr);
  // std::vector<std::vector<int>> ans = threeSumBrute(arr);
  // std::vector<std::vector<int>> ans = threeSumBetter(arr);
  // std::vector<std::vector<int>> ans = threeSumOptimal(arr);
  // std::cout << "Three Sum vectors" << std::endl;
  // printMatrix(ans);

  // * Problem 4
  std::cout << "Four sum" << std::endl;
  std::vector<int> arr = {1, 0, -1, 0, -2, 2};
  printArr(arr);
  // std::vector<std::vector<int>> ans = fourSumBrute(arr);
  // std::vector<std::vector<int>> ans = fourSumBetter(arr);
  std::vector<std::vector<int>> ans = fourSumOptimal(arr);
  std::cout << "Four Sum vectors cafe" << std::endl;
  printMatrix(ans);
  return 0;
}

// * Run the code
// * g++ --std=c++17 practice-cafe.cpp -o practice-cafe && ./practice-cafe