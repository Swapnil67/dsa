
/*
 * Leetcode - 2104
 * Sum of Subarray Ranges 
 * 
 * You are given an integer array nums. The range of a subarray of nums is the difference between the largest and 
 * smallest element in the subarray.
 * 
 * Return the sum of all subarray ranges of nums.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * Example 1:
 * Input       : nums = [1,2,3]
 * Output      : 4
 * Explanation :  The 6 subarrays of nums are the following:
 *               [1], range = largest - smallest = 1 - 1 = 0 
 *               [2], range = 2 - 2 = 0
 *               [3], range = 3 - 3 = 0
 *               [1,2], range = 2 - 1 = 1
 *               [2,3], range = 3 - 2 = 1
 *               [1,2,3], range = 3 - 1 = 2
 *               So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
              
 * https://leetcode.com/problems/sum-of-subarray-ranges/description/
 * https://www.naukri.com/code360/problems/subarray-range-sum_8365419
 * https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1
 */

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// * Previous Smaller or Equal Element
std::vector<int> get_pse(std::vector<int> &nums) {
  int n = nums.size();
  std::stack<int> st;
  std::vector<int> pse(n, -1);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] > nums[i]) {
      st.pop();
    }
    // * top will be smaller than current element
    // * since stack is in increasing order
    if (st.size())
      pse[i] = st.top();

    st.push(i);
  }
  return pse;
}

// * Next Smaller element
std::vector<int> get_nse(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> nse(n, n);
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] > nums[i]) {
      nse[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return nse;
}

// * Previous Greater Element
std::vector<int> get_pge(std::vector<int> &nums) {
  int n = nums.size();
  std::stack<int> st;
  std::vector<int> pge(n, -1);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] <= nums[i]) {
      st.pop();
    }
    if (st.size())
      pge[i] = st.top();
    
    st.push(i);
  }
  return pge;
}

// * Next Greater Element
std::vector<int> get_nge(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> nge(n, n);
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    
    while (!st.empty() && nums[st.top()] <= nums[i]) {
      nge[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }
  return nge;
}

// * ------------------------- APPROACH 1: Brute Approach -------------------------
// * Nested Loop
// * TIME COMPLEXITY O(N^2)
// * SPACE COMPLEXITY O(1)
long long bruteForce(std::vector<int>& arr) {
  int n = arr.size();
  long long sum = 0;
  for(int i = 0; i < n; ++i) {
    int largest = arr[i], smallest = arr[i];
    for (int j = i + 1; j < n; ++j) {
      largest = std::max(largest, arr[j]);
      smallest = std::min(smallest, arr[j]);
      sum += (largest - smallest);
    }
  }
  return sum;
}


// * ------------------------- APPROACH 1: Optimal Approach -------------------------
// * Sum of Subarray Maximum + Sum of Subarray Minimum
long long subArrayRanges(std::vector<int>& nums) {
  int n = nums.size();

  // * next/prev smaller elements
  std::vector<int> pse = get_pse(nums);
  // std::cout << "Previous Smaller Elements" << std::endl;
  // printArr(pse);

  std::vector<int> nse = get_nse(nums);
  // std::cout << "Next Smaller Elements" << std::endl;
  // printArr(nse);
  
  // * next/prev greater elements
  std::vector<int> nge = get_nge(nums);
  std::vector<int> pge = get_pge(nums);

  long long largest_elements_sum = 0, smallest_elements_sum = 0;
  for (int i = 0; i < n; ++i) {
    // * subarray of maximums
    int left = i - pge[i];
    int right = nge[i] - i;
    // * itne total_subarrays subarrays honge jinka maximum is arr[i]
    largest_elements_sum += ((right * left) * 1LL * nums[i]);
    
    // * subarray of minimums
    left = i - pse[i];  // * Left mai kitne elements honge
    right = nse[i] - i; // * Right mai kitne elements honge
    // * itne total_subarrays subarrays honge jinka minimum is arr[i]
    smallest_elements_sum += ((right * left) * 1LL * nums[i]);
  }

  // std::cout << "Largest Sum: " << largest_elements_sum << std::endl;
  // std::cout << "Smallest Sum: " << smallest_elements_sum << std::endl;

  return largest_elements_sum - smallest_elements_sum;
}

// * ------------------------- APPROACH 2: Optimal Approach ------------------------
long long subArrayRanges2(std::vector<int>& nums) {
  int n = nums.size();
  long long ans = 0;
  std::stack<int> st;

  // * Find the sum of all the minimum.
  for(int right = 0; right <= n; ++right) {
    while (!st.empty() &&
           (right == n || nums[st.top()] >= nums[right]))
    {
      int mid = st.top();                          // * next smaller index in left
      st.pop();
      int left = st.empty() ? -1 : st.top();       // * next smaller index in left
      ans -= (long long)nums[mid] * (right - mid) * (mid - left);
    }
    st.push(right);
  }

  st.pop();

  // * Find the sum of all the maximum. [Decreasing Stack]
  for (int right = 0; right <= n; ++right) {
    while (!st.empty() &&
           (right == n || nums[st.top()] <= nums[right]))
    {
      int mid = st.top(); 
      st.pop();
      int left = st.empty() ? -1 : st.top();       // * next greater index in left
      ans += (long long)nums[mid] * (right - mid) * (mid - left);
    }
    st.push(right);
  }

  return ans;
}

int main() {  
  // * testcase 1 (Ans 4)
  // std::vector<int> nums = {1, 2, 3};
  
  // * testcase 2 (Ans 4)
  // std::vector<int> nums = {1, 3, 3};
  
  // * testcase 3 (Ans 59)
  // std::vector<int> nums = {4, -2, -3, 4, 1};
  
  // * testcase 4 (Ans 1537100894)
  std::vector<int> nums = {-37988, -14446, -34454, -85916, 44628, -63469, 2405, 76071, 43291, 499, -43933, -10950, 22587, 45756, 36078, 49794, 81866, -70327, 80649, 19025, 82130, -53646, 99394, 63520, 20667, 41291, 80388, -82451, -17666, 52744, -84498, 30104, 41847, 67932, -89959, -42134, -79079, 80796, -27089, 9691, -26248, -31934, -20681, 33506, 16422, -98706, -16321, 847, 55516, -85834, -3479, -58562, 77791, 62111, -15830, 33478, 79046, -47470, -54997, -56231, 11301, 3998, 73631, 47168, 66983, 98655, -31405, -11411, 50967, -15908, 37346, 73429, -95644, 83331, 74868, -23201, 70451, 73304, 38820, -32124, 80413, -23607, 65237, 88536, 29905, -35443, -36683, 64419, -25056, 73050, 17960, 16070, 54748, 76597, 74972, -73098, 74704, 55261, -38420, -42739, 15098, -8078, 82487, -34954, -38895, 39994, 35077, -36851, 87932, 7216, -87758, -27817, 66742, 77803, -16270, 41596, -14558, 28610, 4151, -2590, -73414, 56156, 93465, 31128, -19581, -44840, -87553, -79674, -2016, 3190, 62008};

  std::cout << "Input Array" << std::endl;
  printArr(nums);

  // long long ans = bruteForce(nums);
  long long ans = subArrayRanges(nums);
  // long long ans = subArrayRanges2(nums);
  std::cout << "Sum of Subarray Ranges " << ans << std::endl;
}

// * run the code
// * g++ --std=c++17 22-sum-of-subarr-ranges.cpp -o output && ./output
