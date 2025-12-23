/**
 * * Leetcode - 341
 * * Flatten Nested List Iterator
 * 
 * * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 */
#include <vector>
#include <iostream>

// ! Google, Meta, Netflix

// ! Solve this on leetcode platform
// * ------------------------- APPROACH 1: Optimal Approach -------------------------

// * Using Stack
// class NestedIterator {
// public:
//   stack<NestedInteger> st;
//   NestedIterator(vector<NestedInteger> &nestedList) {
//     int n = nestedList.size();
//     for (int i = n - 1; i >= 0; --i) {
//       st.push(nestedList[i]);
//     }
//   }

//   int next() {
//     int num = st.top().getInteger();
//     st.pop();
//     return num;
//   }

//   bool hasNext() {
//     if (st.empty()) {
//       return false;
//     }

//     while (!st.empty()) {
//       NestedInteger obj = st.top();
//       if (obj.isInteger())
//         return true;
//       st.pop();

//       vector<NestedInteger> list = obj.getList();
//       for (int i = list.size() - 1; i >= 0; --i) {
//         st.push(list[i]);
//       }
//     }

//     return false;
//   }
// };

// * ------------------------- APPROACH 2: Optimal Approach -------------------------

// * Using Recursion
// class NestedIterator {
// public:
//     stack<NestedInteger> st;
//     void flatten(vector<NestedInteger>& list) {
//         int n = list.size();
//         for (int i = n - 1; i >= 0; --i) {
//             bool res = list[i].isInteger();
//             if (res) {
//                 st.push(list[i].getInteger());
//             } else {
//                 flatten(list[i].getList());
//             }
//         }
//     }

//     NestedIterator(vector<NestedInteger>& nestedList) { flatten(nestedList); }

//     int next() {
//         int num = st.top().getInteger();
//         st.pop();
//         return num;
//     }

//     bool hasNext() {
//         if (st.empty()) {
//             return false;
//         }
//         return st.top().isInteger();
//     }
// };


int main() {
  return 0;
}