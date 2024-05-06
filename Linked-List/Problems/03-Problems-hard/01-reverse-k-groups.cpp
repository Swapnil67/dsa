/**
 * * Reverse List In K Groups
 * * You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.
 * * Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k',
 * * then the last group of nodes should remain unchanged.


 * * the previous and the next nodes in the sequence of nodes.
 *
 * * Example 1
 * * Input  : 1->2->3->4->5-> NULL, k = 3
 * * Output : 3->2->1->4->5->NULL
 * 
 * * Example 2
 * * Input  : 1->2->3->4-> NULL, k = 2
 * * Output : 2->1->4->3->NULL
 
 * * https://www.youtube.com/watch?v=Mh0NH_SD92k&list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&index=20
 * * https://www.naukri.com/code360/problems/reverse-list-in-k-groups_983644
 * * https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
*/

#include<iostream>

class Node {
  public: 
    int data;
    Node* next;
    Node* prev;

    Node() {
      this->data = 0;
      this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

// * ------------------- Utility Functions ---------------------

Node* arrayToLL(std::vector<int> arr) {
  if(!arr.size()) return nullptr;
  Node* head = new Node(arr[0]);
  Node* temp = head;

  for(int i=1; i<arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    temp->next = newNode;
    temp = newNode;
  }
  return head;
}

void printLL(Node* head) {
  Node* temp = head;
  while(temp) {
    if(temp->next)
      std::cout<<temp->data<<" -> ";
    else 
      std::cout<<temp->data<<" -> NULL";
    temp = temp->next;
  }
  std::cout<<std::endl;
}

Node* getKthNode(Node* head, int k) {
  k -= 1;
  Node* temp = head;
  while(temp != nullptr && k > 0) {
    temp = temp->next;
    k--;
  }
  return temp;
}


// * Reverse LL
// * using the 3-pointer approach
// * TIME COMPLEXITY  O(N) + O(N) = O(2N)
// * SPACE COMPLEXITY O(1)
Node* reverseLL(Node *head) {
   Node* temp = head;  
   
   // * Initialize pointer 'prev' to NULL,
   // * representing the previous node
   Node* prev = NULL;  
   
   while(temp != NULL){  
    // * Store the next node in
    // * 'front' to preserve the reference
    Node* front = temp->next;  
    
    // * Reverse the direction of the
    // * current node's 'next' pointer
    // * to point to 'prev'
    temp->next = prev;  
    
    // * Move 'prev' to the current
    // * node for the next iteration
    prev = temp;  
    
    // * Move 'temp' to the 'front' node
    // * advancing the traversal
    temp = front; 
   }
   return prev;  
}

Node* kReverse(Node* head, int k) {
  Node* temp = head;

  // * Initialize a pointer to track the
  // * last node of the previous group
  Node* prevNode = nullptr;

  while(temp) {
    // * Get the Kth node of the current group
    Node* kthNode = getKthNode(temp, k);

    // * If the Kth node is NULL
    // * (not a complete group)
    if(kthNode == nullptr) {
      if(prevNode) {
        // * If there was a previous group,
        // * link the last node to the current node
        prevNode->next = temp;
      }
      break;
    }

    // * Reverse group
    Node* nextNode = kthNode->next;
    kthNode->next = nullptr;
    reverseLL(temp);

    if(temp == head) {
      // * Check if first group
      head = kthNode;
    }
    else {
      // * Link the last node of the previous
      // * group to the reversed group
      prevNode->next = kthNode;
    }

    // * Update the pointer to the
    // * last node of the previous group
    prevNode = temp;

    // * Move to the next group
    temp = nextNode;
  }
  return head;
}

int main() {  
  // * testcase 1
  // int k = 2;
  // std::vector<int> arr = { 1,2,3,4,5 };

  // * testcase 2
  int k = 3;
  std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };

  Node* head = arrayToLL(arr);
  std::cout<<"Before Reversing"<<std::endl;
  printLL(head);

  std::cout<<"After Reversing"<<std::endl;
  head = kReverse(head, k);
  printLL(head);
}


// * Run the code
// * g++ --std=c++17 01-reverse-k-groups.cpp -o 01-reverse-k-groups && ./01-reverse-k-groups