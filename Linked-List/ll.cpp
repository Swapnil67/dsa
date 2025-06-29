/*
* Convert array to from Linked List
*/

#include <iostream>
#include <vector>

class Node {
  public:
    int data;
    Node* next;

    // * constructor
    Node(int d) {
      data = d;
      next = NULL;
    }

    // * constructor
    Node(int d, Node* nextNode) {
      data = d;
      next = nextNode;
    }
};

// * Print the LL
void printLL(Node* head) {
  Node* temp = head;
  while (temp) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

// * Converty Array to Linked List
Node* arrayToLL(std::vector<int>arr) {
  Node* head = NULL;
  head = new Node(arr[0]);
  Node* mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

// * Remove head from linked list
Node* removeHead(Node* head) {
  if (head == nullptr)
    return head;

  Node *temp = head;
  head = head->next;
  delete temp; // * free the previous head node
  return head;
}

// * Remove tail from linked list
Node* removeTail(Node* head) {
  // * Edge cases
  if (head == nullptr || head->next == nullptr)
    return nullptr;

  Node* temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  
  // * free the tail node
  delete temp->next;
  temp->next = nullptr;
  
  return head;
}

// * Remove kth index from linked list
Node* removeKthIndex(Node* head, int k) {
  // * Edge cases
  if (head == nullptr)
    return head;
  
  if (k == 1)
    return removeHead(head);

  int cnt = 0;
  Node* temp = head;
  Node* prev = nullptr;
  while (temp) {
    cnt++;
    if (cnt == k) {
      prev->next = prev->next->next;
      // * free the kth node
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }

  return head;
}

// * Insert at the head of linked list
Node* insertAtHead(Node* head, int val) {
  Node* node = new Node(val);
  node->next = head;
  return node;
}

// * Insert at the tail of linked list
Node* insertAtTail(Node* head, int val) {
  Node* newNode = new Node(val);
  if (head == nullptr)
    return newNode;
  
  // * Go the last node in ll
  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// * Insert at the kth element in linked list
Node* insertAtKthIndex(Node* head, int k, int val) {
  if (head == nullptr && k == 1) {
    Node* newNode = new Node(val);
    return newNode;
  }
  
  if(k == 1) {
    Node* newHead = new Node(val, head);
    return newHead;
  }

  // * Go the last node in ll
  int cnt = 0;
  Node* temp = head;
  while (temp) {
    cnt++;
    if (cnt == k - 1) {
      Node* newNode = new Node(val);
      newNode->next = temp->next;
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}


int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  Node* head = arrayToLL(arr);
  std::cout << "Elements In LL" << std::endl;
  printLL(head);
  
  std::cout << "Insert at head In LL" << std::endl;
  head = insertAtHead(head, 0);
  printLL(head);
  
  std::cout << "Insert at tail In LL" << std::endl;
  head = insertAtTail(head, 6);
  printLL(head);
  
  std::cout << "Insert at k In LL" << std::endl;
  head = insertAtKthIndex(head, 3, 100);
  printLL(head);
  
  std::cout << "Remove head In LL" << std::endl;
  head = removeHead(head);
  printLL(head);

  std::cout << "Remove tail In LL" << std::endl;
  head = removeTail(head);
  printLL(head);

  std::cout << "Remove fron kth index In LL" << std::endl;
  head = removeKthIndex(head, 5);
  printLL(head);
  return 0;
}

// * Run the code
// * g++ --std=c++20 ll.cpp -o practice && ./practice

