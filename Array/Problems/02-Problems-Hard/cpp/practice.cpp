#include<map>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0;i<arr.size();i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void dutchNationalFlag(std::vector<int> &arr) {
  int n = arr.size();
  int l = 0, m = 0, h = n-1;
  while(m <= h) {
    if(arr[m] == 0) {
      swap(arr[m++], arr[l++]);
    }
    else if(arr[m] == 1) {
      m++;
    }
    else if(arr[m] == 2) {
      swap(arr[m], arr[h--]);
    }
  }
}

// * --------------------- Majority Element --------------------- 

int majorityElementBrute(std::vector<int> arr) {
  int n = arr.size();
  int occurence = n / 2;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(arr[i] == arr[j]) cnt++;
      if(cnt > occurence) return arr[i];
    }
  }
  return -1;
}

int majorityElementBetter(std::vector<int> arr) {
  int n = arr.size();
  std::map<int, int> countMap;
  for (int i = 0; i < n; i++) {
    countMap[arr[i]]++;
  }

  int occurence = n / 2;
  for(auto it: countMap) {
    if(it.second > occurence) {
      return it.first;
    }
  }
  return -1;
}

int majorityElement(std::vector<int> arr) {
  int n = arr.size(), cnt = 1, majorityEle = arr[0];
  for (int i = 1; i < n; i++) {
    if(cnt == 0) {
      majorityEle = arr[i];
    }

    if(arr[i] == majorityEle) {
      cnt++;
    }
    else {
      cnt--;
    }
  }

  cnt = 0;
  int occurence = n/2;
  for (int i = 0; i < n; i++) {
    if(majorityEle == arr[i]) cnt++;
  }
  if(cnt > occurence) return majorityEle;
  return -1;
}

// * --------------------- Majority Element ---------------------

// * --------------------- Maximum Subarray Sum ---------------------

int maxSubarraySumBrute(std::vector<int> arr) {
  int n = arr.size(), maxSum = INT_MIN;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      maxSum = std::max(maxSum, sum);
    }
  }
  return maxSum;
}

int maxSubarraySum(std::vector<int> arr) {
  int n = arr.size(), sum = 0, maxSum = INT_MIN;
  for (int i = 0; i < n; i++) {
    sum = std::max(sum + arr[i], arr[i]);
    maxSum = std::max(maxSum, sum);
  }
  return maxSum;
}

// * Print maximum subarray sum
std::vector<int> maxSubarraySumPoints(std::vector<int> arr) {
  int n = arr.size();
  int sum = 0, maxSum = INT_MIN;
  int s = 0, e = 0;
  int ansStart = -1, ansEnd = -1;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if(sum == 0) {
      s = i;
    }

    if(sum > maxSum) {
      ansEnd = i;
      ansStart = s;
      maxSum = sum;
    }
  }
  return {ansStart, ansEnd};
}

int maxSubarraySumCircular(std::vector<int> arr) {
  int n = arr.size();
  int total = 0;
  int maxSum = 0, minSum = INT_MAX;
  int curSum = 0, curMin = arr[0];
  for (int i = 0; i < n; i++) {
    curSum = std::max(curSum + arr[i], arr[i]);
    maxSum = std::max(maxSum, curSum);
    curMin = std::min(curMin + arr[i], arr[i]);
    std::cout << curMin << std::endl;
    minSum = std::min(minSum, curMin);
    total += arr[i];
  }
  // std::cout<<maxSum<<std::endl;
  // std::cout<<minSum<<std::endl;

  if(maxSum < 0) {
    return maxSum;
  }
  else {
    return total - minSum;
  }

}
// * --------------------- Maximum Subarray Sum ---------------------

int main() {
  // * Problem 1
  // std::cout << "Sort 0s, 1s and 2s" << std::endl;
  // std::vector<int> arr = {2, 2, 2, 2, 0, 0, 1, 0};
  // printArr(arr);
  // dutchNationalFlag(arr);
  // printArr(arr);

  // * Problem 2
  // std::cout << "Majority element n/2" << std::endl;
  // std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  // std::vector<int> arr = {58, 58, 28, 95, 58, 15, 58, 58 };
  // printArr(arr);
  // int majorityEle = majorityElementBrute(arr);
  // int majorityEle = majorityElementBetter(arr);
  // int majorityEle = majorityElement(arr);
  // std::cout << "Majority Element n/2 times is " << majorityEle << std::endl;

  // * Problem 3
  // std::cout << "Maximum Subarray Sum" << std::endl;
  // std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // * 6
  // printArr(arr);
  // int maxSum = maxSubarraySumBrute(arr);
  // int maxSum = maxSubarraySum(arr);
  // std::cout << "Maximum subarray sum " << maxSum << std::endl;
  // std::vector<int> points = maxSubarraySumPoints(arr);
  // std::cout << "Maximum subarray sum exists between " << points[0] << " to " << points[1] << std::endl;

  // * Problem 4
  std::cout << "Maximum Subarray Sum Circular" << std::endl;
  // std::vector<int> arr = {5, -3, 5}; // * 10
  std::vector<int> arr = {-2, -3, -1}; // * -1
  printArr(arr);
  int maxSum = maxSubarraySumCircular(arr);
  std::cout << "Maximum subarray sum in circular array is " << maxSum << std::endl;

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