/**
 * * Find pairs with given sum in doubly linked list
 * * You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.
 * * Find out all the pairs in the doubly linked list with sum equal to 'k'.
 *
 * * Example 1
 * * Input  : 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5
 * * Output : (1, 4) and (2, 3)

 *
 * * Example 2
 * * Input  : 1 <-> 10 <-> 11 <-> 12 <-> 27 and 'k' = 7
 * * Output : 0
 
 * * https://www.youtube.com/watch?v=Mh0NH_SD92k&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20
 * * https://www.youtube.com/watch?v=YitR4dQsddE&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20
*/

#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
      this->data = d;
      this->next = nullptr;
      this->prev = nullptr;
    }

    Node(int d, Node* n, Node* p) {
      this->data = d;
      this->next = n;
      this->prev = p;
    }
};

// * ------------------- Utility Functions ---------------------

// * Array to DLL
Node* arrayToDLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;

  Node* head = new Node(arr[0]);
  Node* prev = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}

// * Print DLL
void printDLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * Returns the Tail of DLL
Node* findTail(Node* head) {
  if(head == NULL) return nullptr;
  Node* temp = head;
  while(temp->next) {
    temp = temp->next;
  }
  return temp;
}

// * ------------------ Brute Force Approach ---------------------
// * TIME COMPLEXITY  O(N^2)
// * SPACE COMPLEXITY O(1)
std::vector<std::pair<int, int>> bruteForce(Node* head, int k) {
  std::vector<std::pair<int, int>> ans;
  if(head == NULL || head->next == NULL) return ans;
  Node* temp1 = head;
  while(temp1) {
    Node* temp2 = temp1->next;
    while(temp2 && (temp1->data + temp2->data) <= k) {
      if((temp1->data + temp2->data) == k) {
      // std::cout<<temp1->data<<" "<<temp2->data<<std::endl;
        ans.push_back(std::make_pair(temp1->data, temp2->data));
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }

  return ans;
}

// * ------------------ Optimal Approach ---------------------
// * Two Pointer Approach
// * TIME COMPLEXITY  O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(1)
std::vector<std::pair<int, int>> optimal(Node* head, int k) {

  std::vector<std::pair<int, int>> ans;
  if(head == NULL || head->next == NULL) return ans;

  Node* left = head;
  // * O(N)
  Node* right = findTail(head);
  if(head == NULL || head->next == NULL) return ans;

  // * O(N)
  while(left->data < right->data) {
    int sum = left->data + right->data;
    if(sum == k) {
      ans.push_back(std::make_pair(left->data, right->data));
      left = left->next;
      right = right->prev;
    } else if(sum < k) {
      left = left->next;
    } else {
      right = right->prev;
    }
  }

  return ans;
}

int main() {
  std::vector<int>arr = { 1,2,3,4,9 };
  int k = 5;
  Node* head = arrayToDLL(arr);
  printDLL(head);

  // std::vector<std::pair<int, int>> ans = bruteForce(head, k);
  std::vector<std::pair<int, int>> ans = optimal(head, k);
  for (const auto& pair: ans) {
    std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
  }
  return 0;
}

// * Run the code
// * g++ --std=c++17 11-find-pair-sum-in-dll.cpp -o 11-find-pair-sum-in-dll && ./11-find-pair-sum-in-dll

// * Resource on vector pair in c++
// * https://www.scaler.com/topics/vector-pair-in-cpp/