/**
 * * Leetcode - 2058
 * * Find the Minimum and Maximum Number of Nodes Between Critical Points

 * * A critical point in a linked list is defined as either a local maxima or a local minima.
 * * A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
 * * A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
 * * Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

 * * Given a linked list head, return an array of length 2 containing [minDistance, maxDistance]
 * * where minDistance is the minimum distance between any two distinct critical points and maxDistance is the
 * * maximum distance between any two distinct critical points. If there are fewer than two critical points,
 * * return [-1, -1].

 * * Example 1
 * * Input  : head = [5,3,1,2,5,1,]
 * * Output : [1, 3]

 * * Example 2
 * * Input  : head = [1,3,2,2,3,2,2,2,7]
 * * Output : [3, 3]

 * * Example 3
 * * Input  : head = [3, 1]
 * * Output : [-1, -1]

 * * https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
*/

#include <vector>
#include <climits>
#include <iostream>

// struct ListNode ListNode;

struct ListNode {
  public:
    int data;
    ListNode* next;

    ListNode(int val) {
      data = val;
      next = nullptr;
    }
};

void printLL(ListNode* head) {
  ListNode* temp = head;
  while (temp) {
    std::cout << temp->data << " -> ";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

ListNode* arrayToLL(std::vector<int> &arr) {
  ListNode *head = new ListNode(arr[0]);
  ListNode *mover = head;

  int n = arr.size();

  for (int i = 1; i < n; ++i) {
    ListNode *node = new ListNode(arr[i]);
    mover->next = node;
    mover = node;
  }

  return head;
}

std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
  if (!head || !head->next)
    return {};

  ListNode *prev = head;
  ListNode *cur = head->next;

  int i = 1;
  int first_critical_point = -1, prev_critical_point = -1;
  int min_nodes = INT_MAX;

  while (cur->next) {
    bool local_minima =
        prev->data > cur->data && cur->next->data > cur->data;
    bool local_maxima =
        prev->data < cur->data && cur->next->data < cur->data;

    if (local_minima || local_maxima) { // * check if local minima or local maxima
      if (first_critical_point == -1) {
        first_critical_point = i;
      } else {
        min_nodes = std::min(min_nodes, i - prev_critical_point);
      }
      prev_critical_point = i;  // * keep the last critical point
    }

    i++;
    prev = cur;
    cur = cur->next;
  }

  // std::cout << first_critical_point << " " << prev_critical_point << std::endl;
  if (min_nodes == INT_MAX)
    return {-1, -1};

  int max_nodes = prev_critical_point - first_critical_point;

  return {min_nodes, max_nodes};
}

int main(void) {
  // std::vector<int> arr = {3, 1};
  // std::vector<int> arr = {2, 3, 3, 2};
  std::vector<int> arr = {5, 3, 1, 2, 5, 1, 2};
  // std::vector<int> arr = {1, 3, 2, 2, 3, 2, 2, 2, 7};

  ListNode *head = arrayToLL(arr);
  std::cout << "Linked List" << std::endl;
  printLL(head);

  std::vector<int> ans = nodesBetweenCriticalPoints(head);
  std::cout << "Find the Minimum and Maximum Number of Nodes Between Critical Points" << std::endl;
  std::cout << '{' << ans[0] << ", " << ans[1] << '}' << std::endl;

  return 0;
}


// * Run the code
// * g++ --std=c++20 09-max-and-min-between-critical-points.cpp -o output && ./output

