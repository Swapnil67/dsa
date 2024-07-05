#include<map>
#include<iostream>
#include<queue>

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

bool linearSearch(std::vector<int> arr, int t) {
  for (int i = 0; i < arr.size(); i++) {
    if(arr[i] == t) {
      return true;
    }
  }
  return false;
}

void printVectorString(std::vector<std::string> arr) {
  std::cout<<"[ ";
  for(std::string s: arr) {
    std::cout<<s;
    std::cout<<", ";
  }
  std::cout<<"]\n";
}

void printAnagramGroups(std::vector<std::vector<std::string>> ans) {
  for(int i=0; i<ans.size(); i++) {
    printVectorString(ans[i]);
  }
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

// * Maximum subarray sum [circular array]
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

// * --------------------- Rearrange Elements ---------------------

// * [+ve & -ve elements are equal]
std::vector<int> reArrangeElementsA(std::vector<int> &arr) {
  int n = arr.size();
  int pIdx = 0, nIdx = 1;
  std::vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) {
    if(arr[i] > 0) {
      ans[pIdx] = arr[i];
      pIdx = pIdx + 2;
    }
    else {
      ans[nIdx] = arr[i];
      nIdx = nIdx + 2;
    }
  }
  return ans;
}

// * [+ve & -ve elements are not equal]
std::vector<int> reArrangeElementsB(std::vector<int> &arr) {
  int n = arr.size();
  std::vector<int> pEle, nEle;
  for (int i = 0; i < n; i++) {
    if(arr[i] > 0) {
      pEle.push_back(arr[i]);
    }
    else {
      nEle.push_back(arr[i]);
    }
  }

  std::vector<int> ans(n, 0);
  int pSize = pEle.size(), nSize = nEle.size();
  if(pSize < nSize) {
    for (int i = 0; i < pSize; i++) {
      ans[i * 2] = pEle[i];
      ans[i * 2 + 1] = nEle[i];
    }

    int index = pSize * 2;
    for (int i = pSize; i < n; i++) {
      ans[index] = nEle[i];
      index++;
    }
  }
  else {
    for (int i = 0; i < nSize; i++) {
      ans[i * 2] = pEle[i];
      ans[i * 2 + 1] = nEle[i];
    }

    int index = nSize * 2;
    for (int i = nSize; i < n; i++) {
      ans[index] = pEle[i];
      index++;
    }
  }

  return ans;

}

// * --------------------- Rearrange Elements ---------------------

// * --------------------- Superior Elements ---------------------

std::vector<int> superiorElementsBrute(std::vector<int> arr) {
  int n = arr.size();
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool isSuperior = false;
    for (int j = i; j < n; j++) {
      if(arr[i] > arr[j+1]) {
        isSuperior = true;
      }
      else {
        isSuperior = false;
        break;
      }
    }

    if(i == (n-1)) isSuperior = true;

    if (isSuperior)
      ans.push_back(arr[i]);
  }
  return ans;
}

std::vector<int> superiorElements(std::vector<int> arr) {
  int n = arr.size();
  int max = INT_MIN;
  std::vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if(arr[i] > max) {
      max = arr[i];
      ans.push_back(arr[i]);
    }
  }

  std::sort(ans.begin(), ans.end());
  return ans;
}

// * --------------------- Rearrange Elements ---------------------

// * --------------------- Group Anagrams ---------------------

std::vector<std::vector<std::string>> groupAnagramsBrute(std::vector<std::string> strs) {
  std::map<std::vector<int>, std::vector<std::string>> anagramMap;
  for(std::string s : strs) {
    std::vector<int> alphabets(26, 0);
    for(char c : s) {
      int idx = (int)c - (int)'a';
      alphabets[idx]++;
    }
    anagramMap[alphabets].push_back(s);
  }

  std::vector<std::vector<std::string>> ans;
  for(auto it: anagramMap) {
    ans.push_back(it.second);
  }
  return ans;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs) {
  std::map<std::string, std::vector<std::string>> anagramMap;
  for(std::string s : strs) {
    std::string t = s;
    std::sort(t.begin(), t.end());
    anagramMap[t].push_back(s);
  }

  std::vector<std::vector<std::string>> ans;
  for(auto & [k, v]: anagramMap) {
    ans.push_back(v);
  }
  return ans;
}

// * --------------------- Group Anagrams ---------------------

// * --------------------- Most frequent Elements ---------------------

std::vector<int> mostFrequentElementsBrute(std::vector<int>  arr, int k) {
  int n = arr.size();
  // * Get the occurence Map of each element
  std::map<int, int> occurenceMap;
  for (int i = 0; i < n; i++) {
    occurenceMap[arr[i]]++;
  }

  // * Push the occrence map to priority queue
  std::priority_queue<std::pair<int, int>> pq;
  for(auto it : occurenceMap) {
    pq.push({ it.second, it.first });
  }

  // * Pop top k elements
  std::vector<int> ans;
  while(k--) {
    ans.push_back(pq.top().second);
    pq.pop();
  }

  return ans;
}

// * --------------------- Most frequent Elements ---------------------

// * --------------------- Longest Consecutive Sequence ---------------------

int longestConsecutiveBrute(std::vector<int> arr) {
  int n = arr.size();
  int longestSequence = 0;
  for (int i = 0; i < n; i++) {
    int curSequence = 0;
    int nextEle = arr[i]+1;
    while (linearSearch(arr, nextEle)) {
      nextEle++;
      curSequence++;
    }
    longestSequence = std::max(longestSequence, curSequence);
  }
  return longestSequence;
}

int findlongestConsecutiveBetter(std::vector<int> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  int longestSequence = 1, curSequence = 0;
  int nextEle = arr[0];
  for (int i = 1; i < n; i++) {
    if(i < n && arr[i] == nextEle) {
      nextEle++;
      curSequence++;
    }
    else {
      longestSequence = std::max(longestSequence, curSequence);
      nextEle = arr[i];
      curSequence = 1;
    } 
  }
  return longestSequence;
} 

// * --------------------- Longest Consecutive Sequence ---------------------

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
  // std::cout << "Maximum Subarray Sum Circular" << std::endl;
  // std::vector<int> arr = {5, -3, 5}; // * 10
  // std::vector<int> arr = {-2, -3, -1}; // * -1
  // printArr(arr);
  // int maxSum = maxSubarraySumCircular(arr);
  // std::cout << "Maximum subarray sum in circular array is " << maxSum << std::endl;

  // * Problem 5
  // std::cout << "Rearrange Array Elements by Sign" << std::endl;
  // std::vector<int> arr = {1, 2, -4, -5};
  // printArr(arr);
  // std::vector<int> ans = reArrangeElementsA(arr);
  // std::vector<int> arr = {-1, 2, 3, 4, -3, 1};
  // std::vector<int> arr = {3, 1, -2, -5, 2, -4, -7, -8, 3, -9};
  // printArr(arr);
  // std::vector<int> ans = reArrangeElementsB(arr);
  // printArr(ans);

  // * Problem 6
  // std::cout << "Superior Elements" << std::endl;
  // std::vector<int> arr = {1, 2, 2, 1};
  // std::vector<int> arr = {1, 2, 3, 2};
  // printArr(arr);
  // std::vector<int> ans = superiorElementsBrute(arr);
  // std::vector<int> ans = superiorElements(arr);
  // printArr(ans);

  // * Problem 7
  // std::cout << "Group anagrams" << std::endl;
  // std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // printVectorString(strs);
  // std::vector<std::vector<std::string>> ans = groupAnagramsBrute(strs);
  // std::vector<std::vector<std::string>> ans = groupAnagrams(strs);
  // std::cout<<"Anagram Groups"<<std::endl;
  // printAnagramGroups(ans);

  // TODO Problem 8
  // std::cout << "Most frequent elements" << std::endl;
  // int k = 2;
  // std::vector<int> arr = {1, 1, 1, 2, 2, 3};
  // printArr(arr);
  // std::vector<int> ans = mostFrequentElementsBrute(arr, k);
  // std::vector<int> ans = mostFrequentElements(arr, k);
  // printArr(ans);

  // TODO Problem 9
  // std::cout << "Longest Consecutive Sequence" << std::endl;
  // std::vector<int> arr = {100, 4, 200, 1, 3, 2};
  // std::vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // std::vector<int> arr = {15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3}; // * o/p = 6
  // printArr(arr);
  // int longestSequence = longestConsecutiveBrute(arr);
  // int longestSequence = findlongestConsecutiveBetter(arr);
  // int longestSequence = findlongestConsecutive(arr);
  // std::cout << "Longest consecutive sequence is " << longestSequence << std::endl;
  
  // TODO Problem 10
  // std::cout << "Count Subarray Sum" << std::endl;
  // int k = 6;
  // std::vector<int> arr = {3, 1, 2, 4};
  // printArr(arr);

  // TODO Problem 11
  // std::cout << "Maximum Product Subarray" << std::endl;
  // std::vector<int> arr = {2, 3, -2, 4};
  // printArr(arr);

  return 0;
}
// * Run the code
// * g++ --std=c++17 practice.cpp -o practice && ./practice