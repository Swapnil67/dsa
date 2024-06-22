#include <map>
#include <set>
#include <unordered_set>
#include <iostream>

void printArr(std::vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

bool linearSearch(std::vector<int> arr, int target) {
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == target) return true;
  }
  return false;
}

// * Sort 0s, 1s and 2s
void dutchNationalFlag(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, m = 0, h = n-1;
  while(m <= h) {
    if(arr[m] == 0) {
      swap(arr[m], arr[l]);
      l++;
      m++;
    }
    else if(arr[m] == 1) {
      m++;
    }
    else if(arr[m] == 2) {
      swap(arr[m], arr[h]);
      h--;
    }
  }
}

// * Majority ELement n/2
int majorityElementA(std::vector<int> arr) {
  int n = arr.size();
  int occurence = n / 2, cnt = 0, ele;
  for(int i=0; i<n; i++) {
    if(cnt == 0) {
      ele = arr[i];
      cnt++;
    }
    else if(ele == arr[i]) {
      cnt++;
    }
    else {
      cnt--;
    }
  }
  int count = 0;
  for(int i=0; i<n; i++) {
    if(ele == arr[i])
      count++;
  }
  if(count > occurence) return ele;
  return -1;
}

// * Maximum Subarray Sum
std::vector<int> maxSubarraySum(std::vector<int> arr) {
  int n = arr.size();
  int sum = 0, maxSum = INT_MIN;
  int start = 0, end = 0;
  for(int i=0; i<n; i++) {
    if(sum == 0) {
      start = i;
    }
    sum += arr[i];
    if(maxSum < sum) {
      end = i;
      maxSum = sum;
    }
    if(sum < 0) {
      sum = 0;
    }
  }
  return { start, end };
}

// * Maximum Subarray Sum circular
int maxSubarraySumCircular(std::vector<int> arr) {
  int curMax = 0, curMin = 0, total = 0;
  int globalMax = arr[0], globalMin = arr[0];
  int n = arr.size();
  for(int i=0; i<arr.size(); i++) {
    curMax = std::max(curMax + arr[i], arr[i]);
    curMin = std::min(curMin + arr[i], arr[i]);
    total += arr[i];
    globalMax = std::max(globalMax, arr[i]);
    globalMin = std::min(globalMin, arr[i]);
  }
  if(globalMax < 0) {
    // * All the elements in array is negative
    return globalMax;
  }
  return total - globalMin;
}

// * ReArrange +ve and -ve elements
// ! Same number of +ve and -ve elements
std::vector<int> reArrangeElementsA(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<int> ans(n, 0);
  int p_idx = 0, n_idx = 1;
  for (int i = 0; i < n; i++) {
    if(arr[i] > 0) {
      ans[p_idx] = arr[i];
      p_idx += 2;
    }
    else {
      ans[n_idx] = arr[i];
      n_idx += 2;
    }
  }
  return ans;
}

// * Different number of +ve and -ve elements
std::vector<int> reArrangeElementsB(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<int> ans(n);
  std::vector<int> posArr, negArr;

  for (int i = 0; i < n; i++) {
    if(arr[i] < 0)
      negArr.push_back(arr[i]);
    else 
      posArr.push_back(arr[i]);
  }

  int positives = posArr.size(), negatives = negArr.size();
  // std::cout << "positives " << positives << std::endl;
  // std::cout << "negatives " << negatives << std::endl;
  if(positives > negatives) {
    // * More positive elements
    for (int i = 0; i < negatives; i++) {
      ans[i * 2] = posArr[i];
      ans[i * 2 + 1] = negArr[i];
    }
    int nextIndex = negatives*2;
    for (int i = negatives; i < positives; i++) {
      ans[nextIndex] = posArr[i];
      nextIndex++;
    }
  } else {
    // * More negative elements
    for (int i = 0; i < positives; i++) {
      ans[i * 2] = posArr[i];
      ans[i * 2 + 1] = negArr[i];
    }
    int nextIndex = positives*2;
    for (int i = positives; i < negatives; i++) {
      ans[nextIndex] = negArr[i];
      nextIndex++;
    }
  }
  return ans;
}

// * Superior elements Brute
std::vector<int> superiorELementsBrute(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool isLeader = true;
    for (int j = i + 1; j < n; j++) {
      if(arr[j] >= arr[i]) {
        isLeader = false;
        break;
      }
    }
    if(isLeader) ans.push_back(arr[i]);
  }
  std::sort(ans.begin(), ans.end());
  return ans;
}

// * Superior elements Optimal
std::vector<int> superiorElements(std::vector<int> arr) {
  int n = arr.size();
  int maxI = INT_MIN;
  std::vector<int> ans;
  for (int i = n-1; i >= 0; i--) {
    if(arr[i] > maxI) {
      maxI = arr[i];
      ans.push_back(arr[i]);
    }
  }
  std::sort(ans.begin(), ans.end());
  return ans;
}

// * Longest Consecutive Sequence Brute
int longestConsecutiveBrute(std::vector<int> arr) {
  int n = arr.size(), longestSequence = INT_MIN;
  for (int i = 0; i < n; i++) {
    int nextVal = arr[i]+1, cnt = 1;
    while(linearSearch(arr, nextVal)) {
      cnt++;
      nextVal += 1;
      longestSequence = std::max(longestSequence, cnt);
    }
  }
  return longestSequence;
}

// * Longest Consecutive Sequence Optimal
int findlongestConsecutiveBetter(std::vector<int> &arr) {
  std::sort(arr.begin(), arr.end());
  int n = arr.size();
  int maxSeq = 1, lastSmaller = INT_MIN, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (lastSmaller == arr[i] - 1) {
      cnt++;
      lastSmaller = arr[i];
    }
    else if (lastSmaller != arr[i]) {
      cnt = 1;
      lastSmaller = arr[i];
    }
    maxSeq = std::max(maxSeq, cnt);
  }
  return maxSeq;
}

int findlongestConsecutive(std::vector<int> &arr) {
  int n = arr.size(), maxSeq = 1;
  if(n == 0) return 0;
  std::unordered_set<int> stArr;
  // * O(N)
  // * Put all the elements into a set
  for (int i = 0; i < n; i++) {
    stArr.insert(arr[i]);
  }

  // * O(2N)
  for(auto it: stArr) {
    if(stArr.find(it-1) == stArr.end()) {
      // * You are a first element
      int nextEle = it + 1, cnt = 1;
      while (stArr.find(nextEle) != stArr.end()) {
        cnt++;
        nextEle += 1;
      }
      maxSeq = std::max(maxSeq, cnt);
    }
    else {
      // * Not a first element
    }
  }
  return maxSeq;
}


int main() {
  // * Problem 1
  // std::cout << "Sort 0s, 1s and 2s" << std::endl;i
  // std::vector<int> arr = {2, 2, 2, 2, 0, 0, 1, 0};
  // printArr(arr);
  // dutchNationalFlag(arr);
  // printArr(arr);

  // * Problem 2
  // std::cout << "Majority element n/2" << std::endl;
  // std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  // std::vector<int> arr = {58, 58, 28, 95, 58, 15, 58, 58 };
  // printArr(arr);
  // int majorityEle = majorityElementA(arr);
  // std::cout << "Majority Element n/2 times is " << majorityEle << std::endl;

  // * Problem 3
  // std::cout << "Maximum Subarray Sum" << std::endl;
  // std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6
  // printArr(arr);
  // std::vector<int> points = maxSubarraySum(arr);
  // std::cout << "Maximum subarray sum exists between " << points[0] << " to " << points[1] << std::endl;

  // * Problem 4
  // std::cout << "Maximum Subarray Sum Circular" << std::endl;
  // std::vector<int> arr = {5, -3, 5}; // * 10
  // std::vector<int> arr = {-2, -3, -1}; // * -1
  // printArr(arr);
  // int maxSum = maxSubarraySumCircular(arr);
  // std::cout << "Maximum subarray sum in circular array is " << maxSum << std::endl;

  // * Problem 5
  // std::cout << "Rearrange Array Elements by Sign" << std::endl;
  // std::vector<int> arr = {1, 2, -4, -5};
  // std::vector<int> ans = reArrangeElementsA(arr);
  // printArr(arr);
  // std::vector<int> arr = {-1, 2, 3, 4, -3, 1};
  // std::vector<int> arr = {3, 1, -2, -5, 2, -4, -7, -8, 3, -9};
  // std::vector<int> ans = reArrangeElementsB(arr);
  // printArr(ans);

  // * Problem 6
  // std::cout << "Superior Elements" << std::endl;
  // std::vector<int> arr = {1, 2, 2, 1};
  // std::vector<int> arr = {1, 2, 3, 2};
  // printArr(arr);
  // std::vector<int> ans = superiorELementsBrute(arr);
  // std::vector<int> ans = superiorElements(arr);
  // printArr(ans);

  // * Problem 7
  // std::cout << "Replace elements with greatest" << std::endl;
  // std::vector<int> arr = {17, 18, 5, 4, 6, 1};
  // printArr(arr);
  // replaceGreatest(arr);
  // printArr(arr);

  // * Problem 8
  // std::cout << "Longest Consecutive Sequence" << std::endl;
  // std::vector<int> arr = {100, 4, 200, 1, 3, 2};
  // std::vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // std::vector<int> arr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3}; // * o/p = 6
  // printArr(arr);
  // int longestSequence = longestConsecutiveBrute(arr);
  // int longestSequence = findlongestConsecutiveBetter(arr);
  // int longestSequence = findlongestConsecutive(arr);
  // std::cout << "Longest consecutive sequence is " << longestSequence << std::endl;
  
  return 0;
}
// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice