/**
 * * Merge 2 Sorted Array
 * * Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, return the union of the arrays.
 * * The union of two sorted arrays can be defined as an array consisting of the common and the distinct elements
 * * of the two arrays. The final array should be sorted in ascending order.
 * * Note: 'a' and 'b' may contain duplicate elements, but the union array must contain unique elements.

 * * Example 1
 * * Input  : 'a '= [1, 2, 3, 4, 6], ‘b’ = [2, 3, 5]
 * * Output : [1, 2, 3, 4, 5, 6]

 * * https://www.naukri.com/code360/problems/sorted-array_6613259
*/

#include<set>
#include<iostream>

void printArr(std::vector<int> arr) {
  for(int i=0; i<arr.size(); i++) {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}

// * ------------------------- APPROACH 1: BRUTE FORCE APPROACH -------------------------`
// * TIME COMPLEXITY O(N1logN + N2logN) + O(N1+N2)
// * SPACE COMPLEXITY O(N1 + N2)
std::vector<int> mergeTwoArraysBruteForce(std::vector<int> a, std::vector<int> b) {
  std::set<int> st;
  std::vector<int> ans;

  // * O(N1logN)
  for(int i=0; i<a.size(); i++) {
    st.insert(a[i]);
  }

  // * O(N2logN)
  for(int i=0; i<b.size(); i++) {
    st.insert(b[i]);
  }

  // * O(N1+N2)
  for(int b: st) {
    ans.push_back(b);
  }
  return ans;
}


std::vector<int> mergeTwoArraysOptimal(std::vector<int> a, std::vector<int> b) {
  int n1 = a.size(), n2 = b.size();
  int i = 0, j = 0, last = -1;
  std::vector<int> ans;
  while(i < n1 && j < n2) {
    // std::cout<<"a[i] "<<a[i]<<" b[j] "<<b[j]<<std::endl;
    if(a[i] >= b[j]) {
      // * Push b[j]
      if(last != b[j]) {
        ans.push_back(b[j]);
        last = b[j];
      }
      j++;
    }
    else {
      // * Push a[i]
      if(last != a[i]) {
        ans.push_back(a[i]);
        last = a[i];
      }
      i++;
    }
  }

  while(i < n1) {
    if(last != a[i]) {
      ans.push_back(a[i]);
      last = a[i];
    }
    i++;
  }

  while(j < n2) {
    if(last != b[j]) {
      ans.push_back(b[j]);
      last = b[j];
    }
    j++;
  }

  return ans;
}

int main() {
  // std::vector<int> a = {1, 2, 3, 4, 6};
  // std::vector<int> b = {2, 3, 5};

  // * testcase 2
  std::vector<int> a = {3, 3, 4, 5, 6, 7, 8, 9, 9, 9};
  std::vector<int> b = {2, 4, 10, 10};

  std::cout << "a: ";
  printArr(a);
  std::cout << "b: ";
  printArr(b);

  // std::vector<int> unionArr = mergeTwoArraysBruteForce(a, b);
  std::vector<int> unionArr = mergeTwoArraysOptimal(a, b);
  std::cout<<"Union ";
  printArr(unionArr);
  return 0;
}

// * Run the code
// * g++ --std=c++17 08-merge-two-sorted-arr.cpp -o 08-merge-two-sorted-arr && ./08-merge-two-sorted-arr