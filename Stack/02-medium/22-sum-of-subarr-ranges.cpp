// TODO
// * https://leetcode.com/problems/sum-of-subarray-ranges/description/
// * https://www.naukri.com/code360/problems/subarray-range-sum_8365419

#include <stack>
#include <vector>
#include <iostream>

void printArr(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
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

// * Previous Smaller or Equal Element
// * TC = O(N)
void prevSmaller(std::vector<int> &nums, std::vector<int> &pse) {
  int n = nums.size();
  std::stack<int> st;

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
}

// * Next Smaller element
// * TC = O(N)
void nextSmaller(std::vector<int> &nums, std::vector<int> &nse) {
  int n = nums.size();
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {

    while (!st.empty() && nums[st.top()] > nums[i]) {
      nse[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }
}

// * Previous Greater Element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void prevGreater(std::vector<int> &nums, std::vector<int> &pge) {
  int n = nums.size();
  std::stack<int> st;

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
      st.pop();
    }

    if (st.size()) {
      pge[i] = st.top();
    } 

    st.push(i);
  }

}

// * Next Greater Element
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(N)
void nextGreater(std::vector<int> &nums, std::vector<int> &nge) {
  int n = nums.size();

  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    
    while (!st.empty() && nums[st.top()] < nums[i]) {
      nge[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }
}


long long subArrayRanges2(std::vector<int>& nums) {
  int n = nums.size();

  // * next/prev smaller elements
  
  std::vector<int> pse(n, -1);
  prevSmaller(nums, pse);
  // std::cout << "Previous Smaller Elements" << std::endl;
  // printArr(pse);
  
  std::vector<int> nse(n, n);
  nextSmaller(nums, nse);
  // std::cout << "Next Smaller Elements" << std::endl;
  // printArr(nse);
  
  // * next/prev greater elements
  std::vector<int> nge(n, n);
  nextGreater(nums, nge);
  std::vector<int> pge(n, -1);
  prevGreater(nums, pge);

  int M = 1e9 - 7;
  long long largestSum = 0;
  long long smallestSum = 0;
  for (int i = 0; i < n; ++i) {
    // * subarray of maximums
    int ng = nge[i] - i;
    int pg = i - pge[i];
    long long total_subarrays = ng * pg;
    long long cur_sum = (total_subarrays * nums[i]) % M;
    largestSum = (largestSum + cur_sum) % M;

    // * subarray of minimums
    int ps = i - pse[i];  // * Left mai kitne elements honge
    int ns = nse[i] - i;  // * Right mai kitne elements honge
    total_subarrays = ps * ns ;
    // * itne total_subarrays subarrays honge jinka minimum is arr[i]
    cur_sum = (total_subarrays * nums[i]) % M;
    smallestSum = (smallestSum + cur_sum) % M;
  }

  // std::cout << "Largest Sum: " << largestSum << std::endl;
  // std::cout << "Smallest Sum: " << smallestSum << std::endl;

  return (largestSum - smallestSum) % M;
}


long long subArrayRanges(std::vector<int>& nums) {
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
  std::cout << "Input Array" << std::endl;
  // * testcase 1
  // std::vector<int> nums = {1, 2, 3};

  // * testcase 1
  // std::vector<int> nums = {1, 3, 3};

  // * testcase 3
  // std::vector<int> nums = {4, -2, -3, 4, 1};

  // * testcase 3
  std::vector<int> nums = {-37988, -14446, -34454, -85916, 44628, -63469, 2405, 76071, 43291, 499, -43933, -10950, 22587, 45756, 36078, 49794, 81866, -70327, 80649, 19025, 82130, -53646, 99394, 63520, 20667, 41291, 80388, -82451, -17666, 52744, -84498, 30104, 41847, 67932, -89959, -42134, -79079, 80796, -27089, 9691, -26248, -31934, -20681, 33506, 16422, -98706, -16321, 847, 55516, -85834, -3479, -58562, 77791, 62111, -15830, 33478, 79046, -47470, -54997, -56231, 11301, 3998, 73631, 47168, 66983, 98655, -31405, -11411, 50967, -15908, 37346, 73429, -95644, 83331, 74868, -23201, 70451, 73304, 38820, -32124, 80413, -23607, 65237, 88536, 29905, -35443, -36683, 64419, -25056, 73050, 17960, 16070, 54748, 76597, 74972, -73098, 74704, 55261, -38420, -42739, 15098, -8078, 82487, -34954, -38895, 39994, 35077, -36851, 87932, 7216, -87758, -27817, 66742, 77803, -16270, 41596, -14558, 28610, 4151, -2590, -73414, 56156, 93465, 31128, -19581, -44840, -87553, -79674, -2016, 3190, 62008};

  printArr(nums);

  // long long ans = bruteForce(nums);
  long long ans = subArrayRanges(nums);
  std::cout << "Sum of Subarray Ranges " << ans << std::endl;
}

// * run the code
// * g++ --std=c++17 22-sum-of-subarr-ranges.cpp -o output && ./output
