#include <vector>
#include <iostream>

class Node {
  public:
    int val;
    Node *next;
    Node *prev;

    Node(int data) {
      val = data;
      next = nullptr;
      prev = nullptr;
    }

    Node(int data, Node *nextNode, Node *tailNode) {
      val = data;
      next = nextNode;
      prev = tailNode;
    }
};

void printLL(Node* head) {
  Node *temp = head;
  while(temp) {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

Node* arrayToLL(std::vector<int> &arr) {
  Node* head = new Node(arr[0]);
  Node* prev = head;

  for (int i = 1; i < arr.size(); ++i) {
    Node* newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }

  return head;
}

Node *removeHead(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return nullptr;
  
  Node *temp = head;
  head = head->next;

  head->prev = nullptr;
  temp->next = nullptr;

  // * Completely delete the node of dll
  free(temp);

  return head;
}

Node *removeTail(Node *head) {
  if (head == nullptr)
    return head;

  if (head->next == nullptr)
    return nullptr;

  Node *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  Node *back = temp->prev;
  back->next = nullptr;

  // * Completely delete the node of dll
  free(temp->next);
  temp->next = nullptr;
  temp->prev = nullptr;

  return head;
}

Node *removeKthIndex(Node *head, int k) {
  if (head == nullptr)
    return nullptr;

  int cnt = 0;
  Node* temp = head;
  while(temp) {
    cnt++;
    if (cnt == k)
      break;
    temp = temp->next;
  }

  Node *front = temp->next;
  Node *back = temp->prev;

  // * ll with single node
  if(front == nullptr && back == nullptr) {
    delete temp;
    return nullptr;
  } 
  else if(back == nullptr) {
    // * standing at head
    return removeHead(head);
  } 
  else if(front == nullptr) {
    // * standing at tail
    return removeTail(head);
  }

  back->next = front;
  front->prev = back;

  // * Completely delete the node of dll
  temp->next = nullptr;
  temp->prev = nullptr;
  delete temp;

  return head;
}

void removeNode(Node *temp) {
  Node *front = temp->next;
  Node *back = temp->prev;

  // * Deleting tail
  if (front == nullptr) {
    back->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return;
  }

  front->prev = back;
  back->next = front;

  // * Completely delete the node of dll
  temp->next = nullptr;
  temp->prev = nullptr;
  delete temp;
}

// * Insert a node before head
Node *insertBeforeHead(Node *head, int val) {
  // * create node who's next points to head and back to nullptr
  Node* newNode = new Node(val, head, nullptr);
  if (head == nullptr) {
    return newNode;
  }
  head->prev = newNode;
  return newNode;
}

// * Insert a node before tail
Node *insertBeforeTail(Node *head, int val) {
  // * LL with only one node
  if (head == nullptr) {
    Node* newNode = new Node(val, head, nullptr);
    return newNode;
  }

  // * Same as inserting before head
  if (head->next == nullptr) {
    return insertBeforeHead(head, val);
  }
  
  Node* tail = head;
  // * get the tail to tail of ll
  while (tail->next != nullptr) {
    tail = tail->next;
  }

  Node* back = tail->prev;
  Node* newNode = new Node(val, tail, back);
  // * back -> newNode -> tail
  // * back <- newNode <- tail
  back->next = newNode;
  tail->prev = newNode;

  return head;
}

Node *insertBeforeKthIndex(Node *head, int val, int k) {
  if (head == nullptr || k == 1) {
    return insertBeforeHead(head, val);
  }

  int cnt = 0;
  Node* kthNode = head;
  while (kthNode) {
    cnt++;
    if (cnt == k)
      break;
    kthNode = kthNode->next;
  }

  // * kthNode is tail
  if (kthNode->next == nullptr) {
    return insertBeforeTail(head, val);
  }

  Node* back = kthNode->prev;
  Node* newNode = new Node(val, kthNode, back);
  // * back -> newNode -> kthNode
  // * back <- newNode <- kthNode
  kthNode->prev = newNode;
  back->next = newNode;

  return head;
}

int main(void) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  Node* head = arrayToLL(arr);
  std::cout << "Elements In DLL" << std::endl;
  printLL(head);
    
  std::cout << "Remove head In DLL" << std::endl;
  head = removeHead(head);
  printLL(head);

  std::cout << "Remove tail In DLL" << std::endl;
  head = removeTail(head);
  printLL(head);

  std::cout << "Remove from kth index In DLL" << std::endl;
  head = removeKthIndex(head, 3);
  printLL(head);

  std::cout << "Remove by value in DLL" << std::endl;
  removeNode(head->next);
  printLL(head);

  std::cout << "Insert before head in DLL" << std::endl;
  head = insertBeforeHead(head, 0);
  printLL(head);

  std::cout << "Insert before tail in DLL" << std::endl;
  head = insertBeforeTail(head, 1);
  printLL(head);

  std::cout << "Insert before tail in DLL" << std::endl;
  head = insertBeforeKthIndex(head, 1, 3);
  printLL(head);

  return 0;
}

// * Run the code
// * g++ --std=c++20 dll.cpp -o practice && ./practice

