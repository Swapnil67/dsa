/*
 * Delete Kth Node From End

 * You have been given a singly Linked List of 'N' nodes with integer data and an integer 'K'.
 * Your task is to remove the 'K'th node from the end of the given Linked List and return the head of the modified linked list.

 * You are given the 'head' of a singly linked list. Your task is to group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered list’s head.
 * The first node is considered odd, and the second node is even, and so on.

 * Example 1
 * Input  : 1 -> 2 -> 3 -> 4 -> 'NULL'  and  'K' = 2
 * Output : 1 -> 2 -> 4 -> 'NULL'
 * 
 
 * Example 2
 * Input  : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 'NULL'  and  'K' = 3
 * Output : 1 -> 2 -> 3 -> 5 -> 6 -> 'NULL'
 * 
 
 * https://www.naukri.com/code360/problems/delete-kth-node-from-end_799912
 * https://www.youtube.com/watch?v=3kMKYQ2wNIU&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=10
 
*/

#include<iostream>


class Node {
  public:
    int data;
    Node* next;

    Node(int d) {
      this->data = d;
      this->next = nullptr;
    }

    Node(int d, Node* n) {
      this->data = d;
      this->next = n;
    }

};

// * ------------------- Utility Functions ---------------------

// * Convert array to LL
Node* arrayToLL(std::vector<int> arr) {
  if(arr.size() == 0) return nullptr;
  Node* head = new Node(arr[0]);
  Node* temp = head;
  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

// * Traverse the LL
void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

// * Count the LL
int countLL(Node* head) {
  Node* temp = head;
  int c = 0;
  while(temp) {
    c++;
    temp = temp->next;
  }
  return c;
}

// * ------------------ Brute Force ---------------------
// * TIME COMPLEXITY O(2N)
// * SPACE COMPLEXITY O(N)
Node* removeLastKthNode(Node* head, int k) {
  // * Count the LL Nodes
  int count = countLL(head);

  if(k > count || k <= 0) {
    std::cout<<"Node doesn't exists"<<std::endl;
    return head;
  }

  if(count == k) {
    // * Remove Head
    Node* newHead = head->next;
    free(head);
    return newHead;
  }

  int nodeIdx = (count - k) - 1;
  std::cout<<"count: "<<count<<std::endl;
  std::cout<<"nodeIdx: "<<nodeIdx<<std::endl;


  Node* temp = head;
  // * Traverse to the node just before the one to delete
  while(nodeIdx != 0) {
    temp = temp->next;
    nodeIdx--;
  }

  // * Delete the Nth node from the end
  Node* deleteNode = temp->next;
  temp->next = temp->next->next;
  free(deleteNode);

  return head;
} 

// * ------------------ Optimal Solution ---------------------
// * TIME COMPLEXITY O(N)
// * SPACE COMPLEXITY O(1)
Node* optimalSolution(Node* head, int k) {
  // * Create two pointers, fast and slow
  Node* fast = head;
  Node* slow = head;

  // * Move the fast pointer N nodes ahead
  for(int i=0; i<k; i++) 
    fast = fast->next;

  // * If fastp becomes NULL,
  // * the Nth node from the end is the head
  if (fast == NULL)
      return head->next;

  // * Move both pointers until fast reaches the end
  while(fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
  }

  Node* deleteNode = slow->next;
  slow->next = slow->next->next;
  free(deleteNode);

  std::cout<<slow->data<<std::endl;
  return head;
}

int main() {
  std::vector<int> arr = { 1,2,3,4,5,6 };

  Node* head = arrayToLL(arr);

  std::cout<<"------------ Before Removing Node From Linked List ------------"<<std::endl;
  printLL(head);

  int node;
  std::cout<<"Enter a node to delete: ";
  std::cin>>node;

  std::cout<<"------------ After Removing Node From Linked List ------------"<<std::endl;
  // head = removeLastKthNode(head, node);
  head = optimalSolution(head, node);
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++17 03-delete-kth-node-from-end.cpp -o 03-delete-kth-node-from-end && ./03-delete-kth-node-from-end